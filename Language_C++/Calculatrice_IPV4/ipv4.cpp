/* 
 * @file    Ipv4.cpp
 * @brief   Implémentation de la classe Ipv4
 * @author  nbertault
 * @version 1.0
 * @date    14/02/2024
 */

#include "ipv4.h"

/**
 * @brief  IPv4::IPv4
 * @details Constructeur de la classe IPv4. Alloue dynamiquement la mémoire dans des tableaux 
 * Permet l'affectaion de l'addresse Ipv4 et du masque dans leur tableau si le masque est écrit en CIDR
 * @param _adresse Addresse Ipv4 de base
 * @param _cidr Masque de l'addresse Ipv4 (en notation CIDR)
 */
IPv4::IPv4(const unsigned char * _adresse, const unsigned char _cidr) {
    adresse = new unsigned char [4];
    masque = new unsigned char [4];
    for (int indice = 0; indice < 4; indice++)
        adresse[indice] = _adresse[indice];
    if (_cidr <= 32)
        CalculerMasque(_cidr);
}

/**
 * @brief  IPv4::IPv4
 * @details Constructeur de la classe IPv4. Alloue dynamiquement la mémoire dans des tableaux 
 * Permet l'affectaion de l'addresse Ipv4 et du masque dans leur tableau
 * @param _adresse Addresse Ipv4 de base
 * @param _masque Masque de l'addresse Ipv4
 */
IPv4::IPv4(const unsigned char * _adresse, const unsigned char * _masque) {
    adresse = new unsigned char [4];
    masque = new unsigned char [4];
    for (int indice = 0; indice < 4; indice++) {
        adresse[indice] = _adresse[indice];
        masque[indice] = _masque[indice];
    }
}

/**
 * @brief  IPv4::~IPv4
 * @details Destructeur de la classe IPv4. Libère la mémoire alloué
 */
IPv4::~IPv4() {
    delete [] adresse;
    delete [] masque;
}

/**
 * @brief  IPv4::CalculerMasque
 * @details Calcul du masque si celui inscrit est en CIDR
 * @param _cidr Masque entré en CIDR
 */
void IPv4::CalculerMasque(unsigned char _cidr) {
    int indice;
    // Le masque est remis à 0 -> 0.0.0.0
    for (indice = 0; indice < 4; indice++)
        masque[indice] = 0;
    indice = 0;
    // tant que le cidr est un multiple de 8
    while (_cidr >= 8) {
        masque[indice++] = 255;
        _cidr -= 8;
    }
    // Complément pour la fin du cidr (<8)
    unsigned char puissance = 128;
    while (_cidr-- > 0) // Après le test la variable _cidr est décrémentée
    { // les puissances de 2 sont ajoutées à l'octet par valeur décroissante
        masque[indice] += puissance;
        puissance /= 2;
    }
}

/**
 * @brief  IPv4::ObtenirMasque
 * @details Copie du masque dans le tableau _masque
 * @param _masque Adresse du tableau recevant le masque
 */
void IPv4::ObtenirMasque(unsigned char * _masque) {
    for (int indice = 0; indice < 4; indice++)
        _masque[indice] = masque[indice];
}

/**
 * @brief  IPv4::ObtenirAddresseReseau
 * Calcul l'adresse réseau et la copie dans le tableau _reseau
 * @param _reseau Adresse du tableau recevant l'addresse réseau
 */
void IPv4::ObtenirAdresseReseau(unsigned char * _reseau) {
    for (int indice = 0; indice < 4; indice++)
        _reseau[indice] = adresse[indice] & masque[indice];
}

/**
 * @brief  IPv4::ObtenirAddresseDiffusion
 * @details Calcul l'adresse de diffusion et la copie dans le tableau _diffuson
 * @param _diffusion Adresse du tableau recevant l'addresse de diffusion
 */
void IPv4::ObtenirAdresseDiffusion(unsigned char *_diffusion) {
    unsigned char adresseDuReseau[4];
    ObtenirAdresseReseau(adresseDuReseau);
    for (int indice = 0; indice < 4; indice++)
        _diffusion[indice] = adresseDuReseau[indice] | ~masque[indice];
}

/**
 * @brief IPv4::operator=
 * @details Permet d'utiliser l'opérateur '=' pour copier les tableau d'adresse IPv4
 * @param _adresse Adresse du tableau qui prend l'adresse donnée
 */
void IPv4::operator=(const char * _adresse) {
    for (int i = 0; i < 4; i++)
        adresse[i] = _adresse[i];
}

/**
 * @brief IPv4::PremiereAdresse
 * @details Calcul la première adresse disponible dans le réseau
 * @param _première Adresse du tableau recevant la première adresse
 */

void IPv4::ObtenirPremiereAdresse(unsigned char * _premiere) {
    unsigned char reseau[4];
    ObtenirAdresseReseau(reseau);

    for (int i = 0; i < 4; i++)
        _premiere[i] = reseau[i];

    _premiere[3] = _premiere[3] + 1;
    for (int i = 1; i < 4; i++) {
        if (_premiere[i] > 255) {
            _premiere[i] = 0;
            _premiere[i - 1] += 1;
        }
    }
}

/**
 * @brief IPv4::DerniereAdresse
 * @details Calcul la dernière adresse disponible dans le réseau
 * @param _dernière Adresse du tableau recevant la dernière adresse
 */

void IPv4::ObtenirDerniereAdresse(unsigned char * _derniere) {
    unsigned char diffusion[4];
    ObtenirAdresseDiffusion(diffusion);

    for (int i = 0; i < 4; i++)
        _derniere[i] = diffusion[i];

    _derniere[3] = _derniere[3] - 1;
    for (int i = 0; i < 3; i++) {
        if (_derniere[i] < 0) {
            _derniere[i] = 255;
            _derniere[i + 1] -= 1;
        }
    }
}

/**
 * @brief IPv4::CalculerNombreHote
 * @details Calcul le nombre d'hôtes grace au masque
 * @param _masque Adresse du tableau du masque
 * @return Retourne le nombre d'hôte du réseau
 */
int IPv4::CalculerNombreHote(unsigned char *_masque) {
    int hote = 0;
    int nbHote = 1;
    for (int i = 0; i < 4; i++) {
        if (_masque[i] != 255 && _masque[i] != 0) {
            while(_masque[i] > 0) {
                _masque[i] = _masque[i]/2;
                hote++;
            }
        }
        if (_masque[i] = 0)
            hote += 8;
    }
    nbHote = pow(2,32-hote)-2;
    return nbHote;
}