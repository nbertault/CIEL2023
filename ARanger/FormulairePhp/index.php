<!DOCTYPE html>
<html>
    <head>
        <title>Premier formulaire</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="css/bootstrap.min.css" rel="stylesheet" type="text/css"/>
        <script src="js/bootstrap.min.js"></script>
        <script src="js/libs/jquery/jquery.min.js"></script>
        <script src="js/mesFonction.js"></script>
    </head>
    <body>
        <?php 
        if (isset($_COOKIE["Nom_Prenom"]))
        {
        ?>
        <form class="was-validated" id="inscription" action="php/traitement.php" method="post">
            <div class="container mt-5">
                <div class="row">
                    <fieldset class="border border-dark rounded-3 col-sm-6 p-3">
                        <legend class="float-none w-auto px-3">Civilité</legend>

                        <div class="form-group mb-3">
                            <label for="nom">Nom</label>
                            <input type="text" class="form-control" id="nom" placeholder="Votre Nom" name="nom" required="">
                        </div>

                        <div class="form-group mb-3">
                            <label for="prenom">Prénom</label>
                            <input type="text" class="form-control" name="prenom" id="prenom" placeholder="Votre Prénom" required="" />
                        </div>

                        <div class="form-group mb-3">
                            <label for="ville">Ville</label>
                            <select class="form-select">
                                <option selected>Selectionnez votre Ville</option>
                                <option value="72000">Le Mans</option>
                                <option value="72200">La Flèche</option>
                                <option value="72300">Sablé-sur-Sarthe</option>
                            </select>
                        </div>

                        <div class="form-group mb-3">
                            <label for="email">Adresse Mail</label>
                            <input type="email" class="form-control" name="email" id="email" placeholder="Votre E-mail" required=""/>
                        </div>

                        <div class="form-group mb-3">
                            <label for="Site">Site Internet</label>
                            <input type="url" class="form-control" name="site" id="site" placeholder="Votre Site Internet">
                        </div>

                        <label class="form-label">Sexe</label>

                        <div class="form-inline">
                            <input type="radio" name="homme" class="form-check-input" id="check_masculin" value="masculin" />
                            <label class="form-check-label" for="check_masculin">Masculin</label>
                            <input type="radio" name="femme" class="ms-2 form-check-input" id="check_feminin" value="feminin" />
                            <label class="form-check-label" for="check_feminin">Feminin</label>
                            <input type="radio" name="autre" class="ms-2 form-check-input" id="check_ne_souhaite_pas_le_preciser" value="pas_preciser" />
                            <label class="form-check-label" for="check_ne_souhaite_pas_le_preciser">Ne souhaite pas le préciser</label>
                        </div>

                        <div class="form-group mb-3">
                            <label class="form-label" for="photo">Photo</label>
                            <label for="file" class="form-label"></label>
                            <input class="form-control" type="file" id="file">
                        </div>

                        <div class="form-check mb-3">
                            <input class="form-check-input" type="checkbox" name="condition" id="condition" required>
                            J'ai lu les conditions d'utilisation
                            <div class="invalid-feedback">
                                Vous devez accepter avant de valider
                            </div>
                        </div>

                    </fieldset>
                    
                    <div class="col-sm-6">
                        <fieldset class="border border-dark rounded-3 p-3">
                            <legend id="savoirs" class="float-none w-auto px-3">Savoirs</legend>

                            <div class="form-group mb-3">
                                <label for="systeme">Système d'exploitation
                                    <select id="exploitation" class="form-select">
                                        <option selected>Selectionnez le système</option>
                                        <option value="win">Windows</option>
                                        <option value="lin">Linux</option>
                                        <option value="mac">Mac Osx</option>
                                    </select>
                                </label>
                                <label for="version">Version
                                    <select name="version" id="version" class="form-select">
                                        <option selected>Selectionnez la version</option>
                                    </select>
                                </label>
                            </div>


                            <label class="form-label">Langage de Programmation</label>
                            <div class="form-check">
                                <input type="checkbox" class="form-check-input" id="check_java" value="java" />
                                <label class="form-check-label" for="check_java">Java</label>
                            </div>
                            <div class="form-check">
                                <input type="checkbox" class="form-check-input" id="check_C/C++" value="C/C++" />
                                <label class="form-check-label" for="check_C/C++">C/C++</label>
                            </div>
                            <div class="form-check">
                                <input type="checkbox" class="form-check-input" id="check_PHP" value="PHP" />
                                <label class="form-check-label" for="check_PHP">PHP</label>
                            </div>
                            <div class="form-check">
                                <input type="checkbox" class="form-check-input" id="check_autre" value="autre" />
                                <label class="form-check-label" for="check_autre">autre</label>
                            </div>
                        </fieldset>

                        <fieldset class="border border-dark rounded-3 p-3"> 
                            <legend id="parametre" class="float-none w-auto px-3">Paramètres de connexion</legend>
                            <div class="form-group mb-3">
                                <label for="nom">Login</label>
                                <input type="text" class="form-control" id="nom" placeholder="Votre login" required="">
                            </div>

                            <div class="form-group mb-3">
                                <label for="mdp">Mot de Passe</label>
                                <div class="input-group mb-3">
                                    <input type="password" class="form-control" id="mdp" name="mdp" placeholder="Mot de Passe" required/>
                                    <span class="input-group-text oeilMdp" id="affmdp" data-target="mdp">&#128065;</span>
                                </div>
                            </div>

                            <div class="form-group mb-3">
                                <label for="confmdp">Confirmation du Mot de Passe</label>
                                <div class="input-group mb-3">
                                    <input type="password" class="form-control" id="confmdp" name="confmdp" placeholder="Mot de Passe" required/>
                                    <span class="input-group-text oeilMdp" id="affconfmdp" data-target="confmdp">&#128065;</span>
                                </div>
                            </div>
                        </fieldset>

                    </div>
                </div>

                <div class="text-end me-2">
                    <button type="submit" class="btn btn-primary" id="soumettre">Inscription</button>
                    <button type="reset" class="btn btn-warning" >Effacer les informations de ce formulaire</button>
                </div>

            </div>
        </form>
        <?php
        }
        else
        {
          echo $_COOKIE["Nom_Prenom"]  ;
        }
        ?>
    </body>
</html>