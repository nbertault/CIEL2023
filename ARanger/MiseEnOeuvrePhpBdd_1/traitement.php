<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Liste des cours</title>
    </head>
    <body>
        <?php
        require_once './config.inc.php';
        try {
            $dsn = "mysql:host=" . SERVEUR_BDD . ";dbname=" . NOM_DE_LA_BASE;
            $pdo = new PDO($dsn, LOGIN, MOT_DE_PASSE);
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $pdo->exec("set names utf8");
            if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') == 'GET') {

                $nom = filter_input(INPUT_GET, 'nom');
                echo "nom = $nom </br>";
                if (!empty($nom)) {
                    $idCours = filter_input(INPUT_GET, 'numCours', FILTER_VALIDATE_INT);
                    if ($idCours === false) {
                        echo "ID du cours n'est pas dans le bon format ou non présent";
                    } else {
                        $requete = $pdo->prepare("INSERT INTO participants (nom,idcours) VALUES (:nom, :idCours);");
                        $requete->bindParam(':nom', $nom);
                        $requete->bindParam(':idCours', $idCours, PDO::PARAM_INT);
                        $requete->execute();
                        echo "L'insertion a été réalisée avec succès.";
                    }
                } else {
                    echo "Le nom n'a pas été renseigné";
                }
            }
        } catch (PDOException $excep) {
            print "Une erreur est survenue : " . $excep->getMessage() . "</br>";
            die();
        }
        ?>

    </body>
</html>
