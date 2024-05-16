function verifierAuthentification()
{
    // appel du script verifLogin.php via ajax
    $.ajax({
        url: '../Controleurs/controleur_N.1.php',
        data: {
            "commande": 'verifLogMdp',
            "login": $("#login").val(),
            "mdp": $("#mdp").val()
        },
        type: 'POST',
        dataType: 'json',
        success: // si la requete fonctionne, mise à jour de la couleur de pastille
                function (donnees, status, xhr) {

                    $("#pastille").removeClass();
                    switch (donnees) {
                        case 'v':
                            $("#pastille").toggleClass("bg-success");
                            break;
                        case 'r':
                            $("#pastille").toggleClass("bg-danger");
                            break;
                        case 'j':
                            $("#pastille").toggleClass("bg-warning");
                            break;
                    }
                },
        error:
                function (xhr, status, error) {
                    console.log("param : " + JSON.stringify(xhr));
                    console.log("status : " + status);
                    console.log("error : " + error);

                }
    });
}

$(document).ready(function ()
{
    // gestion du click sur le bouton d'authentification
    $("#verifLogin").click(verifierAuthentification);
    $("#reset").click(function ()
    {
        $("#pastille").removeClass();
        $("#pastille").toggleClass("bg-light");
    });
});

