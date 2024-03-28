var cpt=3;

$(document).ready(function ()
{
    $("#duTexte").click(changerCouleur);
    //$(":button").mouseover(afficherValeur);
    $(document).on("mouseover", ":button", afficherValeur);
});

function changerCouleur()
{
    $(this).css("background-color", "red");
    $("form").append(` <input type="button " value=${cpt} >` );
    cpt++;
}

function afficherValeur()
{
    var valBouton = $(this).val();
    $("#duTexte").css("background-color", "white");
    $("#duTexte").css("color", "red");
    $("#duTexte").text(valBouton);
    console.log(valBouton);
}

