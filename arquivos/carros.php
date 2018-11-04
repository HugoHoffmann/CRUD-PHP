<?php
       
    include "conecta.php";
    $sql= "SELECT * FROM locacao.tbcarros";
    $resultado= pg_query($conn, $sql);
    
?>
<!DOCTYPE html>
<html>
    <head>
        <title>Carros</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href='../estilo/carros.css'>
    </head>
    <section>
        <h1>Carros</h1>
        <hr>
        <table id="tabela">
            <tr>
                <td>Código</td>
                <td>Valor diário R$</td>
                <td>Modelo</td>
                <td>Ano</td>
                <td>Quantidade</td>
                <td>Ações</td>
            </tr>
    <?php
        while ($linha= pg_fetch_array($resultado)){
    ?>
            <tr>
                <td><?=$linha["car_id"]?></td>
                <td><?=$linha["car_valor_diaria"]?></td>
                <td><?=$linha["car_modelo"]?></td>
                <td><?=$linha["car_ano"]?></td>
                <td><?=$linha["car_qtd"]?></td>
                <td>
                    <a href="carros.php?id=<?=$linha["car_id"]?>">Remover</a>
                    <br>
                    <a href="carros.php?id=<?=$linha["car_id"]?>">Atualizar</a>
                </td>
            </tr>

    <?php
            
        }
    ?>
        </table>
        <hr>
        <br>
        <form action="index.php?pagina=carros" method="POST">
            <br>
            <label for="valor_diaria">Valor diário R$:*</label>
            <input type="number" name="valor_diaria" required="required">
            <br>
            <label for="modelo">Modelo:*</label>
            <input type="text" name="modelo" required="required">
            <br>
            <label for="ano">Ano de Fabricação:*</label>
            <input type="number" name="ano" required="required">
            <br>
            <label for="qtd">Quantidade disponível:*</label>
            <input type="number" name="qtd" required="required">
            <br>
            <input type="reset" value='Limpar'>
            <input type="submit" value='Gravar' name="gravar">
        </form>
    </section>
</html>
<?php
    if(isset($_POST['gravar'])){
        $insert = 'insert into tbcarros(car_valor_diaria,car_modelo,car_ano,car_qtd)'
    }
?>
