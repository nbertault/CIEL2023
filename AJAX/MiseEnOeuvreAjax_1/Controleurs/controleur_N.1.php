<?php
require_once  '../Modeles/ModeleUtilisateurs.php';
$utilisateur = new ModeleUtilisateurs();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'POST') {
    // récupération de la donnée 'commande'
    header('Content-Type: application/json');
    $commande = filter_input(INPUT_POST, 'commande');
    switch ($commande) {
        case 'verifLogMdp' :
            // récupération du numéro de département
            $log = filter_input(INPUT_POST, 'login');
            $mdp = filter_input(INPUT_POST, 'mdp');
            echo json_encode($utilisateur->verifierLogin($log, $mdp));
            
            break;
        default:
            
            echo json_encode("commande inconnue");
    }
}

