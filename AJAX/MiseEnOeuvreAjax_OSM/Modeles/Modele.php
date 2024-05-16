<?php

require_once '../Modeles/config.inc.php';

class Modele {

    protected $bdd;

    public function __construct() {
        try {
            $dsn = 'mysql:host=' . SERVEUR_BDD . ';dbname=' . NOM_DE_LA_BASE;
            $this->bdd = new PDO($dsn, LOGIN, MOT_DE_PASSE);
            $this->bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $this->bdd->exec("set names utf8");  
        } catch (PDOException $ex) {
            echo ('</br>Erreur de connexion au serveur BDD : ' . $ex->getMessage());
            die();
        }
    }

    public function __destruct() {
        unset($this->bdd);
    }
}
