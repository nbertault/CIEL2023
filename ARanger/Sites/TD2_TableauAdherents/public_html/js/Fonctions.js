$(document).ready(function ()
{
    const adherentsParPage = 10;
    $.getJSON('adherents.json', function (data) {

        fabriquerPagination(data, adherentsParPage);
        afficherAdherents(data, 0, adherentsParPage);

        $(document).on("click", ".page-link", function () {
            event.preventDefault();
            var numpage = $(this).text();
            afficherAdherents(data, parseInt(numpage) - 1, adherentsParPage);
            $("#checkGeneral").prop('checked', false);
        });

        $("#checkGeneral").on("click", function () {
            var etat = $(this).is(':checked');
            $(".form-check-input").prop('checked', etat);
        });

//        adherents.forEach(function (adherent) {
//            $("tbody").append(`
//            <tr class="align-middle">
//                <td class="text-center"><input type="checkbox" class="form-check-input"></td>
//                <td>${adherent.nom}</td>
//                <td>${adherent.prenom}</td>
//                <td>${adherent.adresse}, ${adherent.codePostal} ${adherent.ville}</td>
//                <td class="text-center">${adherent.telephone}</td>
//                <td class="text-center">${adherent.mail}</td>
//                <td class="text-center">
//                <div class="btn-group">
//                    <button class="btn btn-light me-2">&#128394;</button>
//                    <button class="btn btn-light">&#128465;</button>
//                </div>
//                </td>
//            </tr>
//            `);
//        });

    }).fail(function (jqxhr, textStatus, error)
    {
        const err = textStatus + ", " + error;
        console.error("Erreur de chargement des adhérents: " + err);
    });
});

function fabriquerPagination(adherents, nb_adherents)
{
    total_adherents = adherents.length;
    nb_page = Math.ceil(total_adherents / nb_adherents);
    for (i = 1; i < nb_page + 1; i++) {
        $("#pagination").append(`<li class="page-item"><a class="page-link" href="#"> ${i} </a></li>`);
    }
    ;
}

function afficherAdherents(adherents, page, nb_adherents)
{
    $("tbody").empty();
    prm_adherent = page * nb_adherents;
    drn_adherents = (page + 1) * nb_adherents;
    adherents.slice(prm_adherent, drn_adherents).forEach(function (adherents) {
        $("tbody").append(`
            <tr class="align-middle">
                <td class="text-center"><input type="checkbox" class="form-check-input"></td>
                <td>${adherents.nom}</td>
                <td>${adherents.prenom}</td>
                <td>${adherents.adresse}, ${adherents.codePostal} ${adherents.ville}</td>
                <td class="text-center">${adherents.telephone}</td>
                <td class="text-center">${adherents.mail}</td>
                <td class="text-center">
                <div class="btn-group">
                    <button class="btn btn-light me-2 btn-edit">&#128394;</button>
                    <button class="btn btn-light">&#128465;</button>
                </div>
                </td>
            </tr>
        `);

        $('.btn-edit').on('click', function () {
            var parentRow = $(this).closest('tr');
            var nom = parentRow.find('td:eq(1)').text();
            var prenom = parentRow.find('td:eq(2)').text();
            var coordonnees = parentRow.find('td:eq(3)').text();
            var telephone = parentRow.find('td:eq(4)').text();
            var email = parentRow.find('td:eq(5)').text();

//            $('#detailsModal .modal-body').html(`<p>Nom: ${nom}</p>`);
//            $('#detailsModal .modal-body').append(`<p>Adresse: ${prenom}</p>`);
//            $('#detailsModal .modal-body').append(`<p>Adresse: ${adresse}</p>`);
//            $('#detailsModal .modal-body').append(`<p>Téléphone: ${telephone}</p>`);
//            $('#detailsModal .modal-body').append(`<p>Email: ${email}</p>`);
            
            var adresse = coordonnees.split(',');
            if (adresse.length === 3) {
                rue = adresse[0] + ', ' + adresse[1];
                var scpart = adresse[2];
            } else {
                var scpart = adresse[1];
            }
            var code = scpart.slice(0, 6);
            var ville = scpart.slice(6);

            $('#Modal-AjouterModifier .modal-body #nom').val(nom);
            $('#Modal-AjouterModifier .modal-body #prenom').val(prenom);
            $('#Modal-AjouterModifier .modal-body #email').val(email);
            $('#Modal-AjouterModifier .modal-body #adresse').val(rue);
            $('#Modal-AjouterModifier .modal-body #code_postal').val(code);
            $('#Modal-AjouterModifier .modal-body #ville').val(ville);
            $('#Modal-AjouterModifier .modal-body #telephone').val(telephone);
            
            $('#Modal-AjouterModifier').modal('show');
            
            $('#enregistrer').off('click').click( function () {
                parentRow.find('td:eq(1)').text(nom);
                parentRow.find('td:eq(2)').text(prenom);
                parentRow.find('td:eq(3)').text(rue + code + ' ' + ville);
                parentRow.find('td:eq(4)').text(telephone);
                parentRow.find('td:eq(5)').text(email);
            });
            
        });


    });
}