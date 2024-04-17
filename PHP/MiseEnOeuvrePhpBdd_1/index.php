<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Mise en oeuvre</title>
    </head>
    <body>
        <?php
        require_once './config.inc.php';
        try {
            $dsn = "mysql:host=" . SERVEUR_BDD . ";dbname=" . NOM_DE_LA_BASE;
            $pdo = new PDO($dsn, LOGIN, MOT_DE_PASSE);
            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $pdo->exec("set names utf8");
            $requete = $pdo->query("select * from cours;");

            echo "<h2>Liste des cours</h2>";
            echo "<table border='1'>";
            echo '<tr><th>ID</th><th>Titre</th><th>Niveau</th><th>Session</th></tr>';

            while ($ligne = $requete->fetch(PDO::FETCH_ASSOC)) {
                echo"<tr>";
                echo"<td>" . $ligne['idcours'] . "</td>";
                echo"<td>" . $ligne['titre'] . "</td>";
                echo"<td>" . $ligne['niveau'] . "</td>";
                echo"<td>" . $ligne['session'] . "</td>";
                echo"</tr>\n";
            }
            echo"</table>\n";
        } catch (PDOException $excep) {
            print "la connexion à échouée : " . $excep->getMessage() . "</br>";
            die();
        }
        ?>
    </body>
</html>