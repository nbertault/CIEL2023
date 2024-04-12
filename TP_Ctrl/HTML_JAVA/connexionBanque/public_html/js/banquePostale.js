$(document).ready(function ()
{
    var valeurInitiale = '----------';
    intialiser(valeurInitiale);
    $('#identifiant').on('input', function ()
    {
        $('#effaceIdentifiant').show(); // Affichage du bouton avec la croix pour effacer l'identifiant
        $("#erreur").empty(); // Suppression du message d'erreur
        $(".input-group").removeClass("border-danger text-danger").addClass("border-primary");
        var inputVal = $('#identifiant').val(); // récupération de la valeur de la zone de saisie
        inputVal = inputVal.replace(/[^0-9]/g, ""); // conserver seulement les chiffres

        if (inputVal.length > 10) {
            inputVal = inputVal.substring(0, 10); // Limiter à 10 chiffres
        }
        inputVal = inputVal + '-----------';
        var valeurAffichee = inputVal.substring(0, 10); // Reconstitution de la valeur à afficher
        $("#identifiant").val(valeurAffichee); // Affichage de cette valeur
        this.setSelectionRange(inputVal.length, inputVal.length);
    });
    $('#effaceIdentifiant').on('click', function ()
    {
        $("#identifiant").val(valeurInitiale);
    }
    );
    $('#continuer').on('click', function ()
    {

        var identifiant = $('#identifiant').val();
        if (identifiant.indexOf('-') === -1) {
            if (identifiant.length === 10) {
                $("#erreur").empty();
                console.log("Affichage du clavier");
                afficherClavier();
            }
        } else {
            event.preventDefault();
            identifiant = identifiant.replace(/[^0-9]/g, "");
            $(".input-group").removeClass("border-primary").addClass("border-danger text-danger");
            if (identifiant.length === 0) {
                $('#erreur').text('⊗ Veuillez renseigner votre identifiant.');
            } else {
                $('#erreur').text('⊗ Votre identifiant est incomplet.');
            }
        }
        $('#identifiant').focus();
    }
    );

    $('#clavier').on('click', 'button', function () {
        $('#effaceMdp').show();
        let puceVide = $('#mdp .vide:first');
        mdp = mdp + $(this).text();
        console.log(mdp);
    }
    );

    $('#effaceMdp').on('click', function ()
    {
        $('#mdp span').each(function () {
            $('span').text("°"); // traitement pour chaque <span>
        });
        mdp = null;
        $('#effaceMdp').hide();
    }
    );
});

function intialiser(placeholder)
{
    $("#identifiant").val(placeholder);
    $('#identifiant').focus();
    $('#effaceIdentifiant').hide();
    $('#motDePasse').hide();
    $("#erreur").empty();
}

function afficherClavier() {
    if ($('#motDePasse').is(':hidden')) {
        let chiffres = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
        chiffres = melangerTableau(chiffres);

        for (var j = 0; j < 6; j++) {
            $('#clavier').append('\
            <div class="row"></div>\n\
            <div class="row"></div>\n\
            ');
        }// Pour chaque ligne du tableau ajouter le code HTML <div class="row"></div> à
// la balise <div id="clavier">
// Pour chaque colonne ajouter au dernier élément ayant une classe row du
// clavier le code HTML suivant en incrustant la valeur de la touche obtenu
// dans le tableau de chiffres mélangés :

        for (var i = 0; i < 6; i = i + 5) {
            $("#clavier .row").last(
                    $('#clavier').append(`<div class="col p-1">
                                        <button type="button" id="chiffre" class="btn btn-light text-primary fs-4 border border-primary" w-25>${chiffres[i]}
                                        </button>
                                        <button type="button" id="chiffre" class="btn btn-light text-primary fs-4 border border-primary">${chiffres[i + 1]}
                                        </button>
                                        <button type="button" id="chiffre" class="btn btn-light text-primary fs-4 border border-primary">${chiffres[i + 2]}
                                        </button>
                                        <button type="button" id="chiffre" class="btn btn-light text-primary fs-4 border border-primary">${chiffres[i + 3]}
                                        </button>
                                        <button type="button" id="chiffre" class="btn btn-light text-primary fs-4 border border-primary ">${chiffres[i + 4]}
                                        </button>
                                        </div>`)
                    );
        }
        $('#motDePasse').show();
        $('#effaceMdp').hide();
    }
}

function melangerTableau(tableau) {
    for (let i = tableau.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
// Échange des éléments
        [tableau[i], tableau[j]] = [tableau[j], tableau[i]];
    }
    return tableau;
}