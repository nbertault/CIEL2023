function afficher()
{
    window.document.forms["monForm"].loginBis.value = window.document.forms["monForm"].login.value;
}

function demanderNom() 
{
    nom = prompt("Quel est votre nom ? ");
    alert("Salut : " + nom);
}

function confirmer() 
{
    envoyer = confirm("Etes vous certain de vouloir envoyer les données ? ");
    if (envoyer === true ){
        document.forms["monForm"].submit();
    }
}

function afficherInfo()
{
    var texteDeLaDiv = document.getElementById("divClique").textContent;
    alert("Texte dans la div :" + texteDeLaDiv);
}