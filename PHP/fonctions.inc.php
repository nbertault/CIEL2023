<?php

function afficherBonjour()
{
    echo "Hello world";
}

function VerifierLogin($log, $mdp){
    $retour = FALSE;
    
    if($log == "toto" && $mdp == "toto"){
        $retour = TRUE;
    }
    return $retour;
}