<!DOCTYPE html>
<html>
    <head>
        <title>Carros</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href='../estilo/estiloCarros.css'>
    </head>
    <section>
        <h1>Carros</h1>
        <hr>
        <?php
        // funcao para gerar tabela de carros cadastrados
            function geraTabela(){
                echo '<table id="tabela">
                        <tr>
                            <th>Código</th>
                            <th>Descrição</th>
                            <th>Valor Diária</th>
                            <th>Ação</th>';
                // selecao de todos os carros para mostragem na tabela            
                $select = 'select * from tbcarro';
                //uso da funcao para obtencao de todos os carros cadastrados
                $aResult = executa($select);
                echo '</tr>';
                // percore os resultados do select
                foreach($aResult AS $aResultado){
                    // insercao de dados em cada linha da tabela
                    echo '<tr>
                            <td>'.$aResultado['carcodigo'].'</td>
                            <td>'.$aResultado['cardescricao'].'</td>
                            <td>'.$aResultado['carvalor'].'</td>
                            <td><a class="acao" href="index.php?pagina=carros&remove='.$aResultado['carcodigo'].'">Remover</a></td>
                          </tr>';
                }
                echo '</table>';
            }
            // funcao para geracao de tabela de pedidos 
            function geraTabelaPedido(){
                echo '<table id="tabela">
                        <tr>
                            <th>Código</th>
                            <th>Descrição</th>
                            <th>Valor</th>
                            <th>Quantidade</th>
                            <th>Ação</th>';
                if(isset($_GET['pedido'])){
                    $iPedidoTabela = $_GET['pedido'];
                    echo'<h2>Pedido número '.$iPedidoTabela.'</h2>';
                    //selecao de carros de acordos com os do pedidos
                    $sSelect = 'select tbcarro.carcodigo, tbcarro.cardescricao, tbcarro.carvalor, tbpedidocarro.pepquantidade 
                                from tbcarro 
                                 inner join tbpedidocarro 
                                  on(tbcarro.carcodigo = tbpedidocarro.carcodigo)
                                where pedcodigo = '.$iPedidoTabela.';';
                    $aResultados = executa($sSelect);
                    // percorrendo resultados
                    foreach ($aResultados AS $aResultado){
                        echo ' <tr>
                                <td>'.$aResultado['carcodigo'].'</td>
                                <td>'.$aResultado['cardescricao'].'</td>
                                <td>'.$aResultado['carvalor'].'</td>
                                <td>'.$aResultado['pepquantidade'].'</td>
                                <td><a class="acao" href="index.php?pagina=carros&codigo='.$aResultado['carcodigo'].'">Remover</a></td>
                               </tr>';
                    }
                    echo '</table>';
                }
            }
            // verificao para geração de tabela de pedidos
            if(isset($_GET['pedido'])){
                geraTabelaPedido();
            }
            else{
                geraTabela();
            }
            // verificacao para remocao de carro
            if(isset($_GET['remove'])){
                $iCodigoCarro = $_GET['remove'];
                // uso da funcao para remoção de carro de acordo com 
                deleta('tbcarro', 'carcodigo', $iCodigoCarro);
            }
            // exclusao do determinado carro em pedidos
            if(isset($_GET['codigo'])){
                $iCodigoCarro = $_GET['codigo'];
                deleta('tbpedidocarro', 'carcodigo', $iCodigoCarro);
                geraTabelaPedido();
            }
        ?>
        <hr>
        <br>
        <form action="index.php?pagina=carros" method="POST">
            <label for="codigo">Código:<span>*</span></label>
            <input type="number" name="codigo" required="required">
            <br>
            <label for="descricao">Descrição:<span>*</span></label>
            <input type="text" name="descricao" required="required">
            <br>
            <label for="valor">Valor:<span>*</span></label>
            <input type="number" name="valor" required="required">
 
            <input type="reset" value='Limpar'>
            <input type="submit" value='Gravar' name="gravar">
        </form>
    </section>
</html>
<?php
    // verificao para gravar dados de carro no banco
    if(isset($_POST['gravar'])){
        // obtencao de dados para gravar
        $iCod = (int) $_POST['codigo'];
        $sDescricao = $_POST['descricao'];
        $iValor = (float) $_POST['valor'];
        
        $aColunas = ['carcodigo', 'cardescricao', 'carvalor'];
        $aValores = [$iCod, $sDescricao, $iValor];
        // uso da funcao insere para insercao de dados para cadastro
        insere('tbcarro', $aColunas, $aValores);
    }
