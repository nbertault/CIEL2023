<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Traitement PHP</title>
    </head>
    <body>
        <?php
//        if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
//            echo "Votre login est : " . $_GET["login"] . "<br/>";
//            echo "Votre mot de passe est : " . $_GET["pwd"] . "<br/>";
//        }
        require_once './fonctions.inc.php';
        
        if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
            
            $login = filter_input(INPUT_GET, 'login');
            $motDePasse = filter_input(INPUT_GET, 'pwd');
            
            if(VerifierLogin($login, $motDePasse)){
                echo 'Utilisateur identifié';
            }else{
                echo 'Mauvais login ou mot de passe';
            }
        }
        ?>
    </body>
</html>
