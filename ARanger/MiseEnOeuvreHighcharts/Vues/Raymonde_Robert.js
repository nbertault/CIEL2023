function afficherGraphAjax() {
    $.getJSON('../Controleurs/Controleur.php',
            {
                action: 'getConsommations'
            })
            .done(function (donnees, stat, xhr) {
                var categories = donnees.categories;
                var serie = donnees.series;
                const chart = Highcharts.chart('graphe',
                        {
                            chart: {
                                type: 'bar'
                            },
                            title: {
                                text: 'Consommation de fruits'
                            },
                            xAxis: {
                                categories: categories
                            },
                            yAxis: {
                                title: 'Quantité'
                            },
                            series: serie
                        });
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
            });
}

$(document).ready(function () {
    afficherGraphAjax();
});