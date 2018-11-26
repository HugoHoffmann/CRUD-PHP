var fTotal    = 0;
var aCarros = [];

// funcao acionada por um mesmo botao que deve executar outras duas funcoes
function onClickAdicionarCarro(){
    chamaAjax();
}
// geracao de tabela de pedidos de produtos e a quantidade
function geraTabela(){
    // obtencao do carro selecionado, separando o mesmo em um vetor, onde será pega somente uma posição
   var sCarro = document.getElementById('carSelecao').value.split('-');
    // obtendo somente o valor da quantidade de carro
   var iQtd = document.getElementById('qtd').value;

    // obtendo tabela pré-pronta
   var eTabela = document.getElementById('miniTabela');
   //criando uma linha e realizando a insercao da mesma na tabela
    var eTr = document.createElement('tr');
   eTabela.appendChild(eTr);

   var eTd1 = document.createElement('td');
   eTd1.setAttribute("class", "linha");
    //setando o somente o carro na td
   eTd1.innerHTML = sCarro[1];
   eTr.appendChild(eTd1);

   var eTd2 = document.createElement('td');
    // setando a quantidade na td de quantidade
   eTd2.innerHTML = iQtd;
   eTd2.setAttribute("class", "linha");
   eTr.appendChild(eTd2);

   var eTd3 = document.createElement('td');
    // realizando a multiplicao da quantidade pelo preco do carro
   eTd3.innerHTML = 'R$' + parseInt(sCarro[2])*iQtd + ' Reais';
   eTd3.setAttribute("class", "linha");
   eTr.appendChild(eTd3);
   // incrementando a quantidade total de pedidos de carros
   fTotal += parseInt(sCarro[2])*iQtd;
   var eTotal = document.getElementById('total');
   eTotal.setAttribute('value', fTotal);
}
// funcao para limpar a tabela gerada utilizando ajax para remover todas as td
function limpaTabela(){
   var eTotal = document.getElementById('total');
   eTotal.setAttribute('value', '0');
   $("td").remove(".linha");
   fTotal =0;
}

function gravaCarros(){
    var sCarCodigo  = document.getElementById('carSelecao').value.split('-');
    var sQuantidade = document.getElementById('qtd').value;
    // transformando a variável em objeto para que se possa transformar em json
    var oCarro    = new Object();
    oCarro.codigo = sCarCodigo[0];
    oCarro.qtd    = sQuantidade;

    aCarros.push(oCarro);
// armazenamento de json para o php obter o mesmo
    var sJson = JSON.stringify(aCarros ); //[{"carro"="1", "qdt"="10"}, {"carro"="2", "qdt"="9"}]

// gravar o sJson no campo escondido
    var eCampo = document.getElementById('carros');
    eCampo.setAttribute('value', sJson);


//json do arquivo .txt "carro"="[{"carro"="1", "qdt"="10"}, {"carro"="2", "qdt"="9"}]"
}

function buscaCreditoCliente(){
    var xRetorno = false;
    var iCliCodigo = document.getElementById('cliente').value;
    var oDados = {'iClicodigo':iCliCodigo};
    $.ajax({
        url: 'index.php?pagina=clientes&ajax=true',
        type: 'POST',
        async: false, //aguarda o php processar
        data: oDados,
        success: function(res) {
            xRetorno = res;
        }
    });
    return xRetorno;
}

function chamaAjax(){
    var fCreditoCliente = buscaCreditoCliente();
    var fTotal = document.getElementById('total').value;
    fTotal = parseFloat(fTotal);
    var fValorProduto = document.getElementById('proSelecao').value.split('-');
    var iValorQtd = document.getElementById('qtd').value;
    iValorQtd = parseInt(iValorQtd);
    fValorProduto = parseFloat(fValorProduto[2]);
    fValorMomento = iValorQtd * fValorProduto;
    fValorMomento = fValorMomento + fTotal;

    if(fCreditoCliente>=fValorMomento){

        if(fCreditoCliente>=fTotal){
            geraTabela();
            gravaProdutos();
        }
        else{
        alert('Não possui mais crédito');
        }
    }
    else{
        alert('Não possui mais crédito');
    }

}
