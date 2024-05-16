function afficherAdresse()
{
    var idUser = $(this).val(); // on récupère la valeur de l'option de la liste
    $("#adresse").empty();  // vider la zone de texte
    if (idUser !== '-1') { // si l'utilisateur n'est pas le premier (choisissez....)

        $.getJSON('../Controleurs/controleur_1.1.php',
                {
                    'commande': 'obtenirAdresse',
                    'idUser': idUser
                }
        )
                .done(function (donnees, stat, xhr) {
                    //$("#adresse").text(donnees.adresse);
                    $("#adresse").text(donnees);

                })
                .fail(function (xhr, text, error) {
                    console.log("param : " + JSON.stringify(xhr));
                    console.log("status : " + text);
                    console.log("error : " + error);
                });
    }
}

function genererListeUser()
{
    $.getJSON('../Controleurs/controleur_1.1.php',
            {
                'commande': 'listeUtilisateurs'
            }
    )
            .done(function (donnees, stat, xhr) {
                // génération de la liste déroulante des utilisateurs
                $("#listeUtilisateur").append($('<option>', {value: -1}).text("Sélectionnez une personne"));
                $.each(donnees, function (index, ligne) {
                    // ligne contient un objet json de la forme
                    // {"id" : "id de la personne"},
                    // {"nom" : "nom de la personne"}                        
                    var utilisateur = ligne.nom + " " + ligne.prenom;
                    $("#listeUtilisateur").append($('<option>', {value: ligne.id}).text(utilisateur));
                });
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
                console.log("status : " + text);
                console.log("error : " + error);
            });
}



$(document).ready(function ()
{
    // génération de la liste déroulante au chargement de la page
    genererListeUser();
    // gestion de la selection d'un nom
    $("#listeUtilisateur").change(afficherAdresse);
});