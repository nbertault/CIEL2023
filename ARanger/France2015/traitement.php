<?php
require_once('PHP/config.inc.php');
require_once('PHP/france2015.php');

// Traitement pour la recherche par code postal
if(isset($_POST['code_postal'])) {
    $code_postal = $_POST['code_postal'];
    afficherVillesFromCp($code_postal);
    afficherCompteVillesFromCp($code_postal);
}

// Traitement pour la mise à jour de la date de naissance
if(isset($_POST['personne_id']) && isset($_POST['nouvelle_date_naissance'])) {
    $personne_id = $_POST['personne_id'];
    $nouvelle_date_naissance = $_POST['nouvelle_date_naissance'];

    try {
        $pdo = connecterBdd();

        $requete = $pdo->prepare("UPDATE utilisateurs SET dateNaissance = :nouvelle_date_naissance WHERE utilisateur_id = :personne_id");
        $requete->bindParam(':nouvelle_date_naissance', $nouvelle_date_naissance);
        $requete->bindParam(':personne_id', $personne_id);
        $requete->execute();

        echo "La date de naissance a été mise à jour avec succès.";
    } catch (Exception $ex) {
        echo "Erreur lors de la mise à jour de la date de naissance : " . $ex->getMessage();
    }
}

afficherNombreCommuneParDepartement();

// Fonction pour afficher les villes correspondant à un code postal
function afficherVillesFromCp($code_postal) {
    try {
        $pdo = connecterBdd();
        
        $requete = $pdo->prepare("SELECT ville_nom FROM villes WHERE ville_code_postal = :code_postal");
        $requete->bindParam(':code_postal', $code_postal, PDO::PARAM_STR);
        $requete->execute();
        
        if ($requete->rowCount() > 0) {
            echo "<h2>Villes correspondant au code postal $code_postal :</h2>";
            echo "<ul>";
            while ($row = $requete->fetch(PDO::FETCH_ASSOC)) {
                echo "<li>" . $row['ville_nom'] . "</li>";
            }
            echo "</ul>";
        } else {
            echo "<p>Aucune ville trouvée pour le code postal $code_postal.</p>";
        }
    } catch (Exception $ex) {
        print "La connexion a échoué : " . $ex->getMessage() . "</br>";
        die();
    }
}