<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Login</title>
    <link rel="stylesheet" href="estilo/login.css">
</head>
<body onload="carrega();">
    <div id="loginCampo">
        <form action="" method="POST">
            <legend id="login">Login</legend>
            <label class="entrar" for="usuario">Usuário</label>
            <input type="text" name="usuario">
            <label class="entrar" for="senha">Senha</label>
            <input type="password" name="senha">
            <input id="submeter" type="submit" value='Entrar  ' name="entrar">
        </form>
    </div>
</body>
</html>