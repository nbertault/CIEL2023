<?php

require_once '../Modeles/Modele.php';
/**
 * Description of ModeleDepartement
 *
 * @author pcruchet
 */
class ModeleDepartements extends Modele {
    
    public function obtenirDepartementsDeLaRegion($idRegion) {
        try {
            
            $requete = $this->bdd->prepare('SELECT departement_id, departement_nom FROM departements where departement_region_id = :id;');
            $requete->bindParam(":id",$idRegion);
            $requete->execute();
            
            $departements = array();
            while($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($departements,$reponse);
            }
            $requete->closeCursor();
            return $departements;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirDepartementsDeLaRegion :" . $exc->getMessage());
            die();
        }
    }
}
