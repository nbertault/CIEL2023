function afficherGraph() {
    var categories = ['Pommes', 'Bananes', 'Oranges', 'Poires'];
    var serie = [{
            name: 'Raymonde',
            data: [1, 0, 4, 3]
        }];
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

}

function afficherGraphAjax() {
    $.getJSON('../Controleurs/Controleur.php',
            {
                action: 'getConsommation',
                idUser: 2
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
    $('#menu').load('Menu.html');
    afficherGraphAjax();
});

