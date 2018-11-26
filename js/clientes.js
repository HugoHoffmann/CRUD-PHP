function atualizaTabela(){
    var oDados;
    var retorno;
    $.ajax({
        url: 'index.php?pagina=clientes&ajax=true',
        type: 'POST',
        async: false,
        data: oDados,
        success: function (res) {
            retorno = res;
        }
    });
}
