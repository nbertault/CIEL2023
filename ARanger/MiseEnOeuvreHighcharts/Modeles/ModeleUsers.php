<?php

require_once '../Modeles/Modele.php';

class ModeleUsers extends Modele {

    public function ObtenirUtilisateurs() {
        try {
                $requete = $this->bdd->prepare('SELECT idUser, prenom FROM users;');
                $requete->execute();

                $listeUsers = array();
                while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                    array_push($listeUsers, $reponse);
                }
                $requete->closeCursor();
            

            return $listeUsers;
        } catch (PDOException $exc) {
            print("<br/> Pb obtenirListeProfs :" . $exc->getMessage());
            die();
        }
    }
}