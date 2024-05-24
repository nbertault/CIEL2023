<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
// Traitement pour le nom
echo 'Nom : ' .filter_input(INPUT_POST, "nom"). '</br>';
// Traitement pour le prénom
echo 'Prénom : ' .filter_input(INPUT_POST, "prenom"). '</br>';
// Traitement pour l'e-mail
echo 'E-mail : ' .filter_input(INPUT_POST, "email",FILTER_VALIDATE_EMAIL). '</br>';
// Traitement pour le site
echo 'Site : ' .filter_input(INPUT_POST, "site"). '</br>';
// Traitement pour la condition
echo 'Condition : ' .filter_input(INPUT_POST, "condition"). '</br>';
// Traitement pour la version
echo 'Version : ' .filter_input(INPUT_POST, "version"). '</br>';
// Traitement pour le mdp
echo 'Mot de passe : ' .filter_input(INPUT_POST, "mdp"). '</br>';
$mdp1=filter_input(INPUT_POST, "mdp");
// Traitement pour la confirmation mdp
echo 'Confirmation mot de passe : ' .filter_input(INPUT_POST, "confmdp"). '</br>';
$mdp2=filter_input(INPUT_POST, "confmdp");

require './fonctions.inc.php';

verifierDoubleMotPasse($mdp1, $mdp2);
verifierDoubleMotPasse2($mdp1, $mdp2);

$value=filter_input(INPUT_POST, "nom") .", " .filter_input(INPUT_POST, "prenom");

//setcookie("Nom_Prenom",$value);
setcookie("Nom_Prenom",$value,time()+3600); /* expire dans une heure */
//setcookie("Nom_Prenom",$value,time()+3600,"/~rasmus/",".utoronto.ca",1);

echo $_COOKIE["Nom_Prenom"];
}