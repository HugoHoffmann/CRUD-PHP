<?php

    $sPagina = isset($_GET['pagina']) ? $_GET['pagina'] : 'index';
    
    include_once $sPagina.'.php';
    
