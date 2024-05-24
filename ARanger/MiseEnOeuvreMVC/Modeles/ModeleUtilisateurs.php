<?php

require_once '../Modeles/Modele.php';

class ModeleUtilisateurs extends Modele {

    public function obtenirUtilisateurs() {
        try {
            $requete = $this->bdd->query('SELECT u.nom, u.prenom, DATE_FORMAT(u.dateNaissance, "%d/%m/%Y") AS dateFormatee,'
                    . 'v.ville_nom, r.region_nom, d.departement_nom FROM utilisateurs u '
                    . 'JOIN villes v ON u.ville_id = v.ville_id JOIN departements d '
                    . 'ON v.ville_departement_id = d.departement_id JOIN regions r '
                    . 'ON departement_region_id = regions_id;');
            $requete->execute();

            $lesUtilisateurs = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($lesUtilisateurs, $reponse);
            }
            $requete->closeCursor();

            return $lesUtilisateurs;
        } catch (PDOException $exc) {

            print("<br/> Pd obtenirPersonnes :" . $exc->getMessage());
            die();
        }
    }

    public function obtenirNomPrenom() {
        try {
            $requete = $this->bdd->query('SELECT nom, prenom, utilisateur_id FROM utilisateurs;');
            $requete->execute();

            $nomPrenom = array();
            while ($reponse = $requete->fetch(PDO::FETCH_ASSOC)) {
                array_push($nomPrenom, $reponse);
            }
            $requete->closeCursor();

            return $nomPrenom;
        } catch (PDOException $exc) {

            print("<br/> Pd obtenir nom et prénom :" . $exc->getMessage());
            die();
        }
    }

    public function obtenirDateNaissance($id) {
        try {
            
            $requete = $this->bdd->prepare("SELECT dateNaissance FROM utilisateurs WHERE utilisateur_id = :id;");
            $requete->bindParam(':id',$id);
            $requete->execute();
            $reponse = $requete->fetch(PDO::FETCH_ASSOC);
            //$reponse = ["dateNaissance" => "24/04/2024"];
            $requete->closeCursor();
            return $reponse;

            
        } catch (PDOException $exc) {

            print("<br/> Pd obtenir nom et prénom :" . $exc->getMessage());
            die();
        }
    }
}
