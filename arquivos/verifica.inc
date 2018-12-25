<?php
    // verificacao de requisicao de pagina
    $sPagina = isset($_GET['pagina']) ? $_GET['pagina'] : 'home';
    //se for requisitada pagina home
    if($sPagina=='home'){
        // caso o usuario for do tipo adm, mostra mensagem especifica
        if($sUser == 'adm'){
            echo '<h3>Seja bem vindo Administrador, hoje é dia '.date('d/m/Y').'</h3>';
        }
        //caso não seja adm
        else{
            echo '<h3>Seja bem vindo '.$sUser['pesnome'].', hoje é dia '.date('d/m/Y').'</h3>';
        }
    }
    // abertura da pagina home
    else{
        include_once $sPagina.'.inc';
    }
