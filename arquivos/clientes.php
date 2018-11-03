<?php
       
    include "conecta.php";
    $query= "SELECT * FROM locacao.tbclientes";
    $result= mysqli_query($conn, $query);
    
?>
<!DOCTYPE html>
<html>
    <head>
        <title>Clientes</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href='../estilo/clientes.css'>
    </head>
    <section>
        <h1>Clientes</h1>
        <hr>
        <table id="tabela">
            <tr>
                <td>Código</td>
                <td>Name completo</td>
                <td>CPF/CNPF</td>
                <td>Ações</td>
            </tr>
    <?php
        while ($linha= mysqli_fetch_array($result)){
    ?>
            <tr>
                <td><?=$linha["cli_id"]?></td>
                <td><?=$linha["cli_nome"]?></td>
                <td><?=$linha["cli_documento"]?></td>
                <td>
                    <a href="clientes.php?id=<?=$linha["cli_id"]?>">Remover</a>
                    <br>
                    <a href="clientes.php?id=<?=$linha["cli_id"]?>">Atualizar</a>
                </td>
            </tr>

    <?php       
        }
    ?>
        </table>
        <hr>
        <br>
        <form action="index.php?pagina=clientes" method="POST">
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
