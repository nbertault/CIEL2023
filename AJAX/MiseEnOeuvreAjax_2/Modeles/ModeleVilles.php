<?php

require_once '../Modeles/Modele.php';

class ModeleVilles extends Modele {
    
    public function obtenirVillesDuDepartement($idDepartement) {
        try {
            
            $requete = $this->bdd->prepare('SELECT ville_nom FROM villes where ville_departement_id = :id;');
            $requete->bindParam(":id",$idDepartement);
            $requete->execute();
            
            $villes = array();
            while($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($villes,$reponse);
            }
            $requete->closeCursor();
            return $villes;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirVillesDuDepartement :" . $exc->getMessage());
            die();
        }
    }
    
    public function obtenirDepartementsPourVille($nomVille) {
try {

    $requete = $this->bdd->prepare('SELECT ville_nom, ville_code_postal, departement_nom  FROM villes, departements WHERE ville_nom = :nom AND ville_departement_id = departement_id;');
        
            $requete->bindParam(":nom", $nomVille);
            $requete->execute();
            $departements = array();
            while ($reponse = $requete->fetch()) {
                array_push($departements, array(
                    // Elements à mettre dans le tableau pour le DataTables
                    $reponse['ville_nom'],
                    $reponse['ville_code_postal'],
                    $reponse['departement_nom']
                ));
            }
            $requete->closeCursor();
            return $departements;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirDepartementsDeLaRegion :" . $exc->getMessage());
            die();
        }
    }
}

