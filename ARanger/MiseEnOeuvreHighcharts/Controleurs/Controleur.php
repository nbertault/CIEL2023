<?php

require_once '../Modeles/ModeleConsommation.php';
require_once '../Modeles/ModeleUsers.php';

$conso = new ModeleConsommation();
$users = new ModeleUsers();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
    $action = filter_input(INPUT_GET, "action");
    header('Content-type: application/json; charset=utf-8');
    switch ($action) {
        case 'getConsommation':
            $idUtilisateur = filter_input(INPUT_GET, "idUser", FILTER_VALIDATE_INT);
            if ($idUtilisateur !== false) {
                $tabConso = $conso->ObtenirConsommation($idUtilisateur);
                echo json_encode($tabConso, JSON_NUMERIC_CHECK);
            }
            break;
        case 'getUsers':
            echo json_encode($users->obtenirUtilisateurs());
            break;
        
        case 'getConsommations':
            echo json_encode($conso->obtenirLesConsommations());
            break;

        default:
            echo 'Commande inconnue';
            break;
    }
}


