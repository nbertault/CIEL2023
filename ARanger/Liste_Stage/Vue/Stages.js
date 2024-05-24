function genererListeProfs()
{
    $.getJSON('../Controleur/controleur.php',
            {
                'commande': 'getProfs'
            }
    )
            .done(function (donnees, stat, xhr) {
                // génération de la liste déroulante des utilisateurs
                $("#TuteursLycee").append($('<option>', {value: -1}).text("Tous les enseignants"));
                $.each(donnees, function (index, ligne) {
                    // ligne contient un objet json de la forme
                    // {"id" : "id de la personne"},
                    // {"nom" : "nom de la personne"}                        
                    var enseignant = ligne.nom + " " + ligne.prenom;
                    $("#TuteursLycee").append($('<option>', {value: ligne.id}).text(enseignant));
                });
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
                console.log("status : " + text);
                console.log("error : " + error);
            });
}

function remplirTable(e)
{
    e.preventDefault();
    var idProf = $("#TuteursLycee").val();
    $.getJSON('../Controleur/controleur.php',
            {commande: 'getStages',
            idProf: idProf})
            .done(function (donnees, stat, xhr) {
                if ($.fn.dataTable.isDataTable('#listeStage')) {
                    $('#listeStage').DataTable().clear().destroy();
                }
                $('#listeStage').DataTable(
                        {
                            "data": donnees,

                            "columns": [
                                {title: "Étudiant"},
                                {title: "Entreprise"},
                                {title: "Adresse"},
                                {title: "Tuteur"},
                                {title: "Téléphone"}
                            ],
                            "lengthMenu": [[5, 10, 15, 25, 50, 100, -1], [5, 10, 15, 25, 50, 100, "Tous"]],
                            "pageLength": 10,
                            "language": {
                                "lengthMenu": "Afficher _MENU_ lignes par page",
                                "info": "page _PAGE_ sur _PAGES_",
                                "infoEmpty": "pas de résultat",
                                "search": "Recherchez: ",
                                "paginate": {
                                    "first": "Premier ",
                                    "last": "Dernier ",
                                    "next": "Suivant ",
                                    "previous": "Précédent "
                                },
                            }
                        }
                );
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
                console.log("status : " + text);
                console.log("error : " + error);
            })
}

$(document).ready(function ()
{
    genererListeProfs();
    $('#TuteursLycee').change(remplirTable);
});