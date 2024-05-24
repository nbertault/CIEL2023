<?php

require_once '../Modele/ModeleProfs.php';
require_once '../Modele/ModeleUsers.php';

$prof = new ModeleProfs();
$stage = new ModeleUsers();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
    header('Content-Type: application/json');
    // récupération de la donnée 'commande'
    $commande = filter_input(INPUT_GET, 'commande');
    switch ($commande) {
        case 'getProfs':
            echo json_encode($prof->obtenirListeProfs());
            break;
        case 'getStages':
            $idProf = filter_input(INPUT_GET, 'idProf', FILTER_VALIDATE_INT);
            if ($idDepartement != false) {
                echo json_encode($stage->obtenirListeStages($idProf));
            }
            break;
        default:
            echo json_encode("commande inconnue");
    }
}