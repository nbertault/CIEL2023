$(document).ready(function ()
{
    $('#soumettre').click(verifierMdp);
    afficherMdp();
    $('#exploitation').change(mettreAJourVersion);
});

function verifierMdp()
{
    if ($(`#mdp`).val() !== $(`#confmdp`).val())
    {
        alert("Les mots de passe ne correspondent pas");
        event.preventDefault();
    } else {
        $('#inscription').submit(verifierMdp);
    }
}

function afficherMdp()
{
    $('.oeilMdp').mouseenter(function () {
        var inputId = $(this).data('target');
        $(`#` + inputId).attr('type', 'text');
    });
    
    $('.oeilMdp').mouseleave(function () {
        var inputId = $(this).data('target');
        $(`#` + inputId).attr('type', 'password');
    });
}

function mettreAJourVersion()
{
        console.log($(`#exploitation`).val())
    $("#version").empty();
    
    if($(`#exploitation`).val() === "win"){
        $("#version").append(` <option selected>Selectionnez la version</option>`);
        $("#version").append(` <option value="win7">Windows 7</option>`);
        $("#version").append(` <option value="win10">Windows 10</option>`);
        $("#version").append(` <option value="win11">Windows 11</option>`);
        $("#version").append(` <option value="wins">Windows Server</option>`);
        
    }
    if($(`#exploitation`).val() === "lin"){
        $("#version").append(` <option selected>Selectionnez la version</option>`);
        $("#version").append(` <option value="mint">Mint</option>`);
        $("#version").append(` <option value="debian">Debian</option>`);
        $("#version").append(` <option value="suze">Suze</option>`);
        $("#version").append(` <option value="ubuntu">Ubuntu</option>`);
    }
    if($(`#exploitation`).val() === "mac"){
        $("#version").append(` <option selected>Selectionnez la version</option>`);
        $("#version").append(` <option value="sonoma">Sonoma</option>`);
        $("#version").append(` <option value="ventura">Ventura</option>`);
        $("#version").append(` <option value="monterey">Monterey</option>`);
        $("#version").append(` <option value="bigsur">Big Sur</option>`);
    }
}
