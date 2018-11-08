<?php

    $sPagina = isset($_GET['pagina']) ? $_GET['pagina'] : 'home';
    
    if($sPagina=='home'){
        if($sUser == 'adm'){
            echo '<h3>Seja bem vindo Administrador, hoje é dia '.date('d/m/Y').'</h3>';
        }
        else{
            $sSQL = 'select pesnome from tbpessoa where pesmail = '.trataValores($sUser).'; ';
            $aResultado = executa($sSQL);
            echo '<h3>Seja bem vindo '.$aResultado[0]['pesnome'].', hoje é dia '.date('d/m/Y').'</h3>';
        }
    }
    else{
        include_once $sPagina.'.inc';
    }
