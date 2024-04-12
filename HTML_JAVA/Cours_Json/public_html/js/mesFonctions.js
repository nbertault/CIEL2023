$(document).ready(function () {

    $.getJSON('eleves.json')
            .done(function (lesEleves)
    {
        console.log("Données chargées: ", lesEleves);
        // traitement pour chaque élément

        lesEleves.forEach(function (unEleve)
        {
            console.log(unEleve.nom + " " + unEleve.prenom + " " + unEleve.age);
        });
    })
    
            .fail(function (jqXHR, textStatus, errorThrown) {
        console.error("Erreur de chargement des données:", textStatus, errorThrown);
    });
});