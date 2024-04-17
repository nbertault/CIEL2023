<?php

function afficherPersonnes() {
    require_once 'PHP/config.inc.php';
    echo "<table border='1'>";
    echo '<tr><th>Nom</th><th>Prénom</th><th>Date de naissance</th><th>Nom de la ville</th><th>Nom du département</th><th>Nom de la région</th></tr>';
    
    $pdo = connecterBdd();
    $retour = $pdo->query("set lc_time_names = 'fr_FR';");
    $retour = $pdo->query("select * from utilisateurs,villes,departements,regions "
            . "where utilisateurs.ville_id = villes.ville_id "
            . "and ville_departement_id=departement_id and departement_region_id = regions_id;");
    
    while ($ligne = $retour->fetch(PDO::FETCH_ASSOC)) {
        echo"<tr>";
        echo"<td>" . $ligne['nom'] . "</td>";
        echo"<td>" . $ligne['prenom'] . "</td>";
        echo"<td>" . $ligne['dateNaissance'] . "</td>";
        echo"<td>" . $ligne['ville_nom'] . "</td>";
        echo"<td>" . $ligne['departement_nom'] . "</td>";
        echo"<td>" . $ligne['region_nom'] . "</td>";
        echo"</tr>\n";
    }
    echo "</table>\n";
}

function connecterBdd() {
    try {
        $dsn = "mysql:host=" . SERVEUR_BDD . ";dbname=" . NOM_DE_LA_BASE;
        $pdo = new PDO($dsn, LOGIN, MOT_DE_PASSE);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $pdo->exec("set names utf8");
        
        return $pdo;
    } catch (Exception $excep) {
        print "la connexion à échouée : " . $excep->getMessage() . "</br>";
        die();
    }
}
