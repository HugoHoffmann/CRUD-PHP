<?php
    // conexao.inc
    // inserção das credencias de acesso ao banco de dados em uma variável global
    $aConfig = [];
    $aConfig['host']     = '127.0.0.1';
    $aConfig['port']     = '5432';
    $aConfig['dbname']   = 'locacao';
    $aConfig['user']     = 'postgres';
    $aConfig['password'] = 'hoffmannhugo';

       // mail.inc
    $aConfig['SMTPSecure'] = 'ssl';
    $aConfig['Host']       = 'smpt.gmail.com';
    $aConfig['Port']       =  '465';//'587';
    $aConfig['Username']   = 'enviophp05@gmail.com';
    $aConfig['Password']   = 'envio123';
    $aConfig['From']       = 'enviophp05@gmail.com';
    $aConfig['FromName']   = 'LocaCar';
