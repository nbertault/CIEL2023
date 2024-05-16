<?php

/**
 * Description of ModeleRegion
 *
 * @author pcruchet
 */

require_once '../Modeles/Modele.php';

class ModeleRegions extends Modele {
    
    public function ObtenirListeRegions() {
        try {
            $requete = $this->bdd->query('SELECT regions_id, region_nom FROM regions;');
            $requete->execute();
            
            $lesRegions = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($lesRegions, $reponse);
            }
            $requete->closeCursor();
            return $lesRegions;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirPersonnes :" . $exc->getMessage());
            die();
        }
    }
}
