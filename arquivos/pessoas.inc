<!DOCTYPE html>
<html>
    <head>
        <title>Clientes</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href='../estilo/estiloPessoas.css'>
    </head>
    <section>
        <h1>Pessoas</h1>
        <hr>
        <table id='tabela' border="1px">
            <tr>
                <th>Código</th>
                <th>Nome</th>
                <th>E-mail</th>
                <th>Ação</th>
                <th>Gerar senha</th>
            </tr>
        <?php
            // Função para gerar tabela
            function geraTabela(){
                $sSQL = 'select * from tbpessoa';
                $aResultados = executa($sSQL);
                foreach($aResultados AS $aResultado){
                    echo '<tr>
                            <td>'.$aResultado['pescodigo'].'</td>
                            <td>'.$aResultado['pesnome'].'</td>
                            <td>'.$aResultado['pesmail'].'</td>
                            <td><a class="acao" href="index.php?pagina=pessoas&remove='.$aResultado['pescodigo'].'">Remover</a></td>
                            <td><a class="acao" href="index.php?pagina=pessoas&gerar='.$aResultado['pescodigo'].'">Gerar</a></td>
                          </tr>';
                }
            }
            
            //Condição para para realizar a exclusão de alguma pessoa    
            if(isset($_GET['remove'])){
                $iCodigoPessoa = $_GET['remove'];
                deleta('tbpessoa', 'pescodigo', $iCodigoPessoa);
            }
            // verificacao se fora clicado na opção de geracao de senha
            if(isset($_GET['gerar'])){
                // query de consulta do email
                $sSelectEmail     = 'select pesmail from tbpessoa where pescodigo = '.$_GET['gerar'].'; ';
                $aResultado       = executa($sSelectEmail);
                $sEmail           = $aResultado[0]['pesmail'];
                // caracteres para geração de senha
                $sCaracteres      = '123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKMNOPQRSTUVWXYZ';
                // funcao para mistura de posições da string
                $sMistura         = str_shuffle($sCaracteres);
                // retorna 10 caracteres
                $sSenha           = substr($sMistura,0,10);
                // monstragem de senha já que a funcao mail não funcionou
                echo 'Senha '.$sSenha;
                // funcao para o envio de email
                enviaEmail($sEmail, 'Login e Senha Gerados', 'Seja bem vindo, para logar no sistema dever� utilizar como usu�rio o e-mail: '.$sEmail.' e a senha: '.$sSenha.' ');
                // codificação da senha gerada para md5
                $sSenhaCodificada = md5($sSenha);
                // codigo da pessoa a qual fora gerada a senha
                $iCodigoPessoa    = $_GET['gerar'];
                // funcao de atualização para gravar a senha gerada
                atualiza('tbpessoa','pessenha',$sSenhaCodificada,'pescodigo',$iCodigoPessoa);
            }
            geraTabela();
            echo '</table>';
        ?>
        <hr>
        <br>
        <form action="index.php?pagina=pessoas" method="post">
            <label for="codigo">Código:<span>*</span></label>
            <input  type="number" name="codigo" required="required">
            <br>
            <label for="nome">Nome:<span>*</span></label>
            <input type="text" name="nome" required="required">
            <br>
            <label for="email">E-mail:<span>*</span></label>
            <input type="email" name="email" required="required">
            <hr>
            <input type="reset" value='Limpar'name='limpar' >
            <input type="submit" value='Gravar' name='gravar'>
        </form>
    </section>
</html>
<?php
    //Verifica se fora acionado o botão gravar
    if(isset($_POST['gravar'])){
        $iCodigoPessoa = (int) $_POST['codigo'];
        $iNomePessoa   = $_POST['nome'];
        $iEmailPessoa  = $_POST['email'];
        
        // colunas a serem inseridas 
        $aColunas = ['pescodigo', 'pesnome', 'pesmail'];
        // valores que irão preencher as colunas
        $aValores = [$iCodigoPessoa, $iNomePessoa, $iEmailPessoa];
        // funcao para inserção de dados na tabela tbpessoa
        insere('tbpessoa', $aColunas, $aValores);
    }
