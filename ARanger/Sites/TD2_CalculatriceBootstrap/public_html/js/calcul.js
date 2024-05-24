$(document).ready(function ()
{
    var expression = 0;
    $(".btn-secondary, .btn-primary").click(function () {

        if (expression === 0 || expression === "0") {
            expression = $(this).text();
            $('#ecran').val(expression);
        } else {
            expression += $(this).text();
            $('#ecran').val(expression);
        }
    });

    $(".btn-danger").click(function () {
        expression = 0;
        $('#ecran').val(expression);
    });

    $(".btn-info").click(function () {
        expression = expression.replace("×", "*");
        expression = expression.replace("÷", "/");
        resultat = eval(expression);
        $('#ecran').val(resultat);
        expression = resultat;
    });
});