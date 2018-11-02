<!DOCTYPE html>
<html>
    <head>
        <title>Sistema Locatário</title>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href='../estilo/index.css'>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    </head>
    <header>
        <h2>Sistema de Locação de Carros</h2>
        <img src="../img/logo.png" >
    </header>
    <nav>
        <ul>
            <li><a href="index.php?pagina=home">Início</a></li>
            <li><a href="index.php?pagina=clientes">Clientes</a></li>
            <li><a href="index.php?pagina=carros">Carros</a></li>
            <li><a href="index.php?pagina=locacoes">Locações</a></li>
        </ul>
    </nav>

<?php
    include './verifica.php';
?>
    <footer><hr>Todos os direitos reservados</footer>
</html>