<?php
    function getConexao(){
        // vetor com todos os dados para a conexão ao banco de dados
        global $aConfig;
        
        $sHost     = $aConfig['host'];
        $sPort     = $aConfig['port'];
        $sDbName   = $aConfig['dbname'];
        $sUser     = $aConfig['user'];
        $sPassword = $aConfig['password'];

        $sConexao = "host=$sHost
                     port=$sPort
                     dbname=$sDbName
                     user=$sUser
                     password=$sPassword";
        
        return $sConexao;
    }
    // funcao com retorno para a conexão com o banco de dados
    function conecta(){
        // retorno da conexão com o uso da funcao getconexao
        return pg_connect(getConexao());
    }
    // funcao para o fechamento da conexao 
    function desconecta(){
        return pg_close(conecta());
    }
    // funcao para a execucao de comandos SQLs
    function executa($sSQL){
        $oConexao = conecta();
        
        $oQuery = pg_query($oConexao, $sSQL);
        
        $aRetorno = [];
        
        while ($oResultado = pg_fetch_array($oQuery, null, PGSQL_ASSOC)){
            $aRetorno[] = $oResultado;
        }
        
        desconecta();
        //retorno do vetor com todos os dados do SQL
        return $aRetorno;
    }
    // funcao para o insercao de dados
    function insere($sTabela, $aColunas, $aValores){
        executa('INSERT INTO '.$sTabela.' ('.implode(',',$aColunas).') VALUES ('.implode(',', trataValores($aValores)).');');
    }
    // funcao para deletar dados
    function deleta($sTabela, $aColuna, $aValor){
        executa('DELETE FROM '.$sTabela.' WHERE '.$aColuna.'= '.$aValor.';');
    }
    // funcao para update de dados
    function atualiza($sTabela, $aColuna, $aValor, $aColunaCondicao, $aCondicao){
        executa('UPDATE '.$sTabela.' set '.$aColuna.'= '.trataValores($aValor).' where '.$aColunaCondicao.'= '.$aCondicao.' ;');
    }

// função para o tratamento de valores, sempre que os valores a serem armazenado ao banco fores strings, os mesmos será concatenados com aspas para aceitação 
// do banco
    function trataValores($aValores){
        if(is_array($aValores)){
                foreach ($aValores as $iIndice => $xValor){
                if(is_string($xValor)){
                    $aValores[$iIndice] = '\''.$xValor.'\'';
                }
            }
            return $aValores;
        }
        $aValores = '\''.$aValores.'\'';
        return $aValores;
    }
