<?php

require_once '../Modeles/ModeleEssence.php';

$essence = new ModeleEssence();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
    header('Content-Type: application/json');
    // récupération de la donnée 'commande'
    $commande = filter_input(INPUT_GET, 'commande');
    switch ($commande) {
        case 'getTarifEssence':
            echo json_encode($essence->ObtenirTarifEssence());
            break;
        default:
            echo json_encode("commande inconnue");  
    }
}