$(document).ready(function () {
    $.getJSON('../Controleurs/controleur.php', {action: 'obtenirNomPrenom'})
            .done(function (data) {
                data.forEach(function (utilisateur) {
                    $('#utilisateur').append(
                            `<option value="${utilisateur.utilisateur_id}">${utilisateur.nom} ${utilisateur.prenom}</option>`
                            );
                });
            })
            .fail(function (jqxhr, textStatus, error) {
                const err = textStatus + ", " + error;
                console.error("Erreur de chargement des données : " + err);
                alert("Erreur lors du chargement des données... Veuillez réessayer.");
            });
    $('#utilisateur').change(function () {
        $val = $('#utilisateur').val();
        $.getJSON('../Controleurs/controleur.php', {action: 'obtenirDateNaissance', id: $val})
                .done(function (data) {
                    $('#naissance').val(data.dateNaissance);
                })
                .fail(function (jqxhr, textStatus, error) {
                    const err = textStatus + ", " + error;
                    console.error("Erreur de chargement des données : " + err);
                    alert("Erreur lors du chargement des données... Veuillez réessayer.");
                });
    });


    $("#retour").click(function () {
        window.location.href = '../index.php';
    });
});

