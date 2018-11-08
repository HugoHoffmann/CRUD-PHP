var fTotal    = 0;
var aProdutos = [];

function onClickAdicionarProduto(){
    geraTabela();
    gravaProdutos();
}

function geraTabela(){
   var sProduto = document.getElementById('proSelecao').value.split('-');
   var iQtd = document.getElementById('qtd').value;
   
    
   var eTabela = document.getElementById('miniTabela');
   var eTr = document.createElement('tr');
   eTabela.appendChild(eTr);
   
   var eTd1 = document.createElement('td');
   eTd1.setAttribute("class", "linha");
   eTd1.innerHTML = sProduto[1];
   eTr.appendChild(eTd1);
   
   var eTd2 = document.createElement('td');
   eTd2.innerHTML = iQtd;
   eTd2.setAttribute("class", "linha");
   eTr.appendChild(eTd2);
   
   var eTd3 = document.createElement('td');
   eTd3.innerHTML = 'R$' + parseInt(sProduto[2])*iQtd + ' Reais';
   eTd3.setAttribute("class", "linha");
   eTr.appendChild(eTd3);
   
   fTotal += parseInt(sProduto[2])*iQtd; 
   var eTotal = document.getElementById('total');
   eTotal.setAttribute('value', fTotal);
}

function limpaTabela(){
   var eTotal = document.getElementById('total');
   eTotal.setAttribute('value', '0');
   $("td").remove(".linha");
   fTotal =0;
}

function gravaProdutos(){
    var sProCodigo  = document.getElementById('proSelecao').value.split('-');
    var sQuantidade = document.getElementById('qtd').value;
    
    var oProduto    = new Object();
    oProduto.codigo = sProCodigo[0];
    oProduto.qtd    = sQuantidade;
    
    aProdutos.push(oProduto);

    var sJson = JSON.stringify(aProdutos); //[{"produto"="1", "qdt"="10"}, {"produto"="2", "qdt"="9"}]

// gravar o sJson no campo escondido
    var eCampo = document.getElementById('produtos');
    eCampo.setAttribute('value', sJson);
    

//json do arquivo .txt "produtos"="[{"produto"="1", "qdt"="10"}, {"produto"="2", "qdt"="9"}]"
}


