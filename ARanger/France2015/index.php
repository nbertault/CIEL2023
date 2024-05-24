<!DOCTYPE html>
<html>
    <head>
        <title>TD2_PHP_PDO</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script src="libs/bootstrap/js/bootstrap.min.js" ></script>
        <link href="libs/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css"/>
    </head>
    <body>
        <div class="">
            <form action="traitement.php" method="post">
                <label for="code_postal">Code Postal :</label>
                <input type="text" id="code_postal" name="code_postal" maxlength="5" pattern="[0-9]{5}" required>
                <button type="submit">Rechercher</button>
            </form>
        </div>
        <div class="col-md-6">
            <h1>Liste des utilisateurs</h1>
            <?php
            require_once 'PHP/france2015.php';
            afficherPersonnes();
            ?>
        </div>
    </body>
</html>

