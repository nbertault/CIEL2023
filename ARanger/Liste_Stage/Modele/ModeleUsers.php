<?php

require_once '../Modele/Modele.php';

class ModeleUsers extends Modele {

    public function obtenirListeStages($idProf) {
        try {
            if ($idProf === -1) {
                $requete = $this->bdd->query('SELECT users.nom, users.prenom, entreprises.nomContact, entreprises.nom ,entreprises.adresse FROM users, entreprises WHERE users.idEntreprise = entreprises.idEntreprise;');
                $requete->execute();

                $listeStages = array();
                while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                    array_push($listeStages, $reponse);
                }
                $requete->closeCursor();
            } else {
                $requete = $this->bdd->prepare('SELECT users.nom, users.prenom, entreprises.nomContact, entreprises.nom ,entreprises.adresse FROM users, entreprises WHERE users.idEntreprise = entreprises.idEntreprise AND users.tuteurLycee = :idProf;');
            $requete->bindParam(":idProf",$idProf);
                $requete->execute();

                $listeStages = array();
                while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                    array_push($listeStages, $reponse);
                }
                $requete->closeCursor();
            }

            return $listeStages;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirListeProfs :" . $exc->getMessage());
            die();
        }
    }
}
