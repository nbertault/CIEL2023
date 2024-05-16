<?php

require_once '../Modeles/ModeleUtilisateurs.php';
$utilisateur = new ModeleUtilisateurs();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
    // récupération de la donnée 'commande'
    header('Content-Type: application/json');
    $commande = filter_input(INPUT_GET, 'commande');

    switch ($commande) {
        
        case 'obtenirAdresse' :
            // récupération du numéro de département
            $id = filter_input(INPUT_GET, 'idUser', FILTER_VALIDATE_INT);
            // $numero est bien un entier
            if ($id != false) {
                echo json_encode($utilisateur->obtenirAdresse($id));
            }
            break;
            
        case 'listeUtilisateurs' :
            echo json_encode($utilisateur->obtenirListeUtilisateurs());
            break;
        
        default:
            echo json_encode("commande inconnue");
    }
}