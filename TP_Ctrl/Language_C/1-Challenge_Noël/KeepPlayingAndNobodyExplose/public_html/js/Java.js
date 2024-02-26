let NB_LOGIN = 1;
var id = ["7355608"];

function connexion() {
    var ID = document.getElementById('code').value;
    let loginStatus = false;
    SESSION = null;
    for (let i = 0; i < NB_LOGIN; i++) {
        if (String(ID) === String(id[i])) {

            loginStatus = true;
            SESSION = i;
            var Hacker = window.open('Fin.html');

        }
    }
    return SESSION
}