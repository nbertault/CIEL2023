<?php

require_once '../Modeles/Modele.php';

class ModeleEssence extends Modele {

    public function ObtenirTarifEssence() {
        try {
            $requete = $this->bdd->query('SELECT * FROM prixEssence;');
            $requete->execute();
            $tabTotal = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {

                $prix = array(
                    'gazoil' => $reponse['gazoil'],
                    'super95' => $reponse['super95'],
                    'super98' => $reponse['super98'],
                    'brent' => $reponse['brent']
                );
                
                $tabTotal[$reponse['annee']] = $prix;
            }
            $requete->closeCursor();
            
            return $tabTotal;
        } catch (Exception $exc) {
            print("Erreur : " . $exc->getMessage() . "</br>");
            die();
        }
    }
}
