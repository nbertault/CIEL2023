$(document).ready(function () {
    $.getJSON('../Controleurs/controleur.php', {action:'obtenirUtilisateurs'})
        .done(function (data) {
            data.forEach(function (utilisateur) {
                $('tbody').append(
                    `<tr class="align-middle">
                        <td>${utilisateur.nom}</td>
                        <td>${utilisateur.prenom}</td>
                        <td class="text-center">${utilisateur.dateFormatee}</td>
                        <td class="text-center">${utilisateur.ville_nom}</td>
                        <td class="text-center">${utilisateur.departement_nom}</td>
                        <td class="text-center">${utilisateur.region_nom}</td>
                    </tr>`
                );
            });
        })
        .fail(function (jqxhr, textStatus, error) {
            const err = textStatus + ", " + error;
            console.error("Erreur de chargement des données : " + err);
            alert("Erreur lors du chargement des données... Veuillez réessayer.");
    });
    
    $("#retour").click(function(){
        window.location.href = '../index.php';
    });
});