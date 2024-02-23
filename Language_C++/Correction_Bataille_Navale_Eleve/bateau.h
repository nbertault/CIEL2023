/* 
 * @file   Bateau.h
 * @brief Déclaration de la classe Bateau
 * @author nbertault
 * @version 1.0
 * @date 14/02/2024
 */

#ifndef BATEAU_H
#define BATEAU_H

#include <string>

using namespace std;

class Bateau {
    
public:

    enum ETATS_BATEAU {
        /// manqué
        MANQUE,
        /// touché
        TOUCHE,
        /// bateau coulé
        COULE
    };

    Bateau(const string &_nom, const char _vertical, const int _horizontal, const int _taille, const char _sens = 'H');
    ~Bateau();

    ETATS_BATEAU Torpiller(const char _vertical, const int _horizontal);
    string ObtenirNom();
    ETATS_BATEAU ObtenirEtatBateau();

private:
    /// Représente le nom du bateau
    string nom;
    
    /// Coordonnée vertical de la proue du bateau
    char vertical;
    
    /// Coordonnée horizontal de la proue du bateau
    int horizontal;
    
    /// Nombre de cases occupées par le bateau
    int taille;
    
    /// Orientation du bateau, Horizontale 'H' ou verticale 'V'
    char sens;
    
    /// Adresse du tableau dynamique contenant chaque case du bateau
    int * coque;
    
    /// Etat du bateau en général
    ETATS_BATEAU etatBateau;
};

#endif /* BATEAU_H */

