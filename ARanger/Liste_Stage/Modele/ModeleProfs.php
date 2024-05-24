<?php

require_once '../Modele/Modele.php';

class ModeleProfs extends Modele {
    
    public function obtenirListeProfs() {
        try {
            $requete = $this->bdd->query('SELECT idprof, nom, prenom FROM profs;');
            $requete->execute();

            $listeProfs = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($listeProfs, $reponse);
            }
            $requete->closeCursor();
            return $listeProfs;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirListeProfs :" . $exc->getMessage());
            die();
        }
    }
}