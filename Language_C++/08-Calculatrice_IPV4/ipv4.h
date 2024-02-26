/* 
 * @file    Ipv4.cpp
 * @brief   Déclaration de la classe Ipv4
 * @author  nbertault
 * @version 1.0
 * @date    14/02/2024
 */

#ifndef IPV4_H
#define IPV4_H
#include <math.h>

class IPv4 {
public:
    IPv4(const unsigned char * _adresse, const unsigned char _cidr);
    IPv4(const unsigned char * _adresse, const unsigned char * _masque);
    ~IPv4();
    
    void ObtenirMasque(unsigned char * _masque);
    void ObtenirAdresseReseau(unsigned char * _reseau);
    void ObtenirAdresseDiffusion(unsigned char * _diffusion);
    void operator= (const char * _adresse);
    void ObtenirPremiereAdresse(unsigned char * _premiere);
    void ObtenirDerniereAdresse(unsigned char * _derniere);
    int CalculerNombreHote(unsigned char *_masque);
private:
    /// Addresse du tableau dynamique contenant l'adresse Ipv4
    unsigned char * adresse;
    
    /// Addresse du tableau dynamique contenant le masque
    unsigned char * masque;
    
    void CalculerMasque(unsigned char _cidr); // _cidr est utilisé en tant que variable locale dans la
    // méthode (pas de const devant)
};

#endif /* IPV4_H */

