<?php

require_once '../Modeles/Modele.php';

/**
 * Description of ModeleConsommation
 *
 * @author pcruchet
 */
class ModeleConsommation extends Modele {

    public function ObtenirConsommation($idUser) {
        try {
            $tabSeries = array();
            // generation des tableaux des series et categories pour l'utilisateur
            $requete = $this->bdd->prepare("SELECT prenom, quantite, nomFruit FROM fruits,users,consommation"
                    . " WHERE users.idUser=:id AND fruits.idFruit = consommation.idFruit AND "
                    . "users.idUser = consommation.idUser;");
            $requete->bindParam(":id", $idUser);
            $requete->execute();
            $tabSerieCourante = array();
            $tabCategorie = array();
            while ($ligne = $requete->fetch()) {
                array_push($tabSerieCourante, $ligne['quantite']);
                array_push($tabCategorie, $ligne['nomFruit']);
                $prenom = $ligne['prenom'];
            }
            $requete->closeCursor();
            array_push($tabSeries, array(
                'name' => $prenom,
                'data' => $tabSerieCourante
            ));

            $tabDonnees = array(
                "series" => $tabSeries,
                "categories" => $tabCategorie
            );
            return $tabDonnees;
        } catch (Exception $exc) {
            print("Erreur : " . $exc->getMessage() . "</br>");
            die();
        }
    }

    protected $utilisateur;

    public function __construct() {
        parent::__construct();
        $this->utilisateur = new ModeleUsers();
    }

    public function __destruct() {
        unset($this->utilisateur);
        parent::__destruct();
    }

    public function obtenirLesConsommations() {
        try {
            $tabUsers = $this->utilisateur->obtenirUtilisateurs();
            $tabSeries = array();
// generation des tableaux des series et categories pour chaque user
            foreach ($tabUsers as $user) {
                $requete = $this->bdd->prepare("SELECT quantite , nomFruit "
                        . "from consommation, fruits "
                        . "where fruits.idFruit=consommation.idFruit "
                        . "and consommation.idUser=:id order by fruits.idFruit; ");
                $requete->bindParam(":id", $user['idUser']);
                $requete->execute();
                $tabSerieCourante = array();
                $tabCategorie = array();
                while ($ligne = $requete->fetch()) {
                    array_push($tabSerieCourante, $ligne['quantite']);
                    array_push($tabCategorie, $ligne['nomFruit']);
                }
                $requete->closeCursor();
                array_push($tabSeries, array(
                    'name' => $user['prenom'],
                    'data' => $tabSerieCourante
                ));
            }
            $tabDonnees = array(
                "series" => $tabSeries,
                "categories" => $tabCategorie
            );
            return $tabDonnees;
        } catch (PDOException $e) {
            print "Erreur !: " . $e->getMessage() . "<br/>";
            die();
        }
    }
}
