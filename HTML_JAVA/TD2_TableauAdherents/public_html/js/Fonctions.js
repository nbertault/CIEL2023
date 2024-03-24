$(document).ready(function ()
{
    $.getJSON('adherents_10.json', function (adherents)
    {
        adherents.forEach(function (adherent) {
            $("tbody").append(`
            <tr class="align-middle">
            <td class="text-center"><input type="checkbox" class="form-check-input"></td>
            <td>${adherent.nom}</td>
            <td>${adherent.prenom}</td>
            <td>${adherent.adresse}, ${adherent.codePostal} ${adherent.ville}</td>
            <td class="text-center">${adherent.telephone}</td>
            <td class="text-center">${adherent.mail}</td>
            <td class="text-center">
            <div class="btn-group">
            <button class="btn btn-light me-2">&#128394;</button>
            <button class="btn btn-light">&#128465;</button>
            </div>
            </td>
            </tr>
            `);
        });

    }).fail(function (jqxhr, textStatus, error)
    {
        const err = textStatus + ", " + error;
        console.error("Erreur de chargement des adhérents: " + err);
    });
});