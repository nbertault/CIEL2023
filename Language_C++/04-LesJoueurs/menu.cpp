#include <future>

#include "menu.h"

Menu::Menu(const string &_nom) : nom(_nom), longueurMax(0)
{
    char option[50];

    ifstream leFichier("Menu.txt"); // ouvrir le fichier

    if (!leFichier.is_open())
    {// Si il y a une erreur

        cerr << "Erreur lors de l'ouverture du fichier" << endl; // alors Afficher un message indiquant une erreur de lecture
        nbOptions = 0; // et mettre nbOptions à 0

    }
    else
    {

        int nbLignes = static_cast<int> (count(istreambuf_iterator<char>(leFichier), istreambuf_iterator<char>(), '\n')); // Sinon calculer nbOptions, le nombre d’options dans le fichier
        leFichier.seekg(0, ios::beg);
        nbOptions = nbLignes;
        options = new string[nbLignes]; // allouer dynamiquement le tableau options en fonction de nbOptions

        for (int i = 0; i < nbLignes; i++)
        {// Pour chaque option dans le fichier
            if (leFichier.good())
            {
                leFichier.getline(option, 50);
                options[i] = option; // Lire l’option et l’affecter dans le tableau options
                if (options[i].length() > longueurMax)
                {// Si la taille de l’option est plus grande que longueurMax
                    longueurMax = options[i].length(); // alors longueurMax reçoit la taille de l’option
                }
            }// FinSi
        }// FinPour
    }// FinSi
}

int Menu::AfficherEtAttendreChoix()
{
    int choix;

    cout << right << '+' << setfill('-') << setw(6) << '+' << setw(24) << '+' << endl;

    for (int i = 0; i < nbOptions; i++)
    {
        int chiffre = i + 1;
        cout << '|' << setfill(' ') << setw(3) << chiffre << "  " << '|' << setw(22) << left << options[i] << ' ' << '|' << endl;
    }

    cout << right << '+' << setfill('-') << setw(6) << '+' << setw(24) << '+' << endl;

    cout << endl << endl;
    cout << "Entrer un nombre entre 1 et " << nbOptions << " : ";

    if (!(cin >> choix))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        choix = -1;
    }

    return choix;
}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;

    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin, uneChaine);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    system("clear");
}

void Menu::EffacerEcran()
{
    system("clear");
}

Menu::~Menu()
{
    delete [] options;
}

