<?php

function verifierDoubleMotPasse ($motDePasse, $ConfMotDePasse){
    if($motDePasse === $ConfMotDePasse){
        echo 'ok'.'<br/>';
    }else{
        echo 'ko'.'<br/>';
    }
}

function verifierDoubleMotPasse2 ($motDePasse, $ConfMotDePasse){
    $ok=false;
    if($motDePasse === $ConfMotDePasse){
        $ok=true;
    }
    return $ok;
}
