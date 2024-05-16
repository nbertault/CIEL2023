<?php

require_once '../Modeles/ModeleRegions.php';
require_once '../Modeles/ModeleDepartements.php';
require_once '../Modeles/ModeleVilles.php';

$regions = new ModeleRegions();
$departements = new ModeleDepartements();
$villes = new ModeleVilles();


if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') === 'GET') {
    header('Content-Type: application/json');
    // récupération de la donnée 'commande'
    $commande = filter_input(INPUT_GET, 'commande');

    switch ($commande) {
        case 'getRegions' :
            echo json_encode($regions->ObtenirListeRegions());
            break;
        case 'getDepartements' :
            // récupération du numéro de département
            $idRegion = filter_input(INPUT_GET, 'idRegion', FILTER_VALIDATE_INT);
            // $numero est bien un entier
            if ($idRegion != false) {
                echo json_encode($departements->obtenirDepartementsDeLaRegion($idRegion));
            }
            break;
        
            case 'getVilles' :
            // récupération du numéro de département
            $idDepartement = filter_input(INPUT_GET, 'idDepartement', FILTER_VALIDATE_INT);
            // $numero est bien un entier
            if ($idDepartement != false) {
                echo json_encode($villes->obtenirVillesDuDepartement($idDepartement));
            }
            break;
            case 'getDepartementsPourVille' :
            // récupération du numéro de département
            $nomVille = filter_input(INPUT_GET, 'nomVille');
            // $numero est bien un entier
            if ($nomVille != false) {
                echo json_encode($villes->obtenirDepartementsPourVille($nomVille));
            }
            break;
            
        default:

            echo json_encode("commande inconnue");
    }
}