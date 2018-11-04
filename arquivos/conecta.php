<?php
    $host = "localhost";
    $port = "5432";
    $dbname = "locacao";
    $user = "postgres";
    $password = "hoffmannhugo";
    $pg_opcao = "--client_encoding=UTF8";

    $conexao = "host={$host} port={$port} dbname={$dbname} user={$user} passaword={$password} options={$pg_opcao}";
    $conn = pg_connect($conexao);

    if($conn){
        echo "Conexão efetuada com sucesso ".pg_host($conn) ;        
    }
    else{
        echo "Erro ao estabelecer conexão! "; 
    }

    echo "<br>";
