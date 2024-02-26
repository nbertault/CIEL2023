#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    double tempCapteur1 = 68.5697;
    printf("Température obtenue du capteur\t\t: %f °F\n", tempCapteur1);
    printf("Température convertie en degrés Celcius : %+.2f °C\n\n", (tempCapteur1 - 32)*5 / 9);


    double tempCapteur2 = 17.568;
    printf("Température obtenue du capteur\t\t: %f °F\n", tempCapteur2);
    printf("Température convertie en degrés Celcius : %+.2f °C\n\n", (tempCapteur2 - 32)*5 / 9);

    double tempCapteurC = -8.02;
    printf("Température obtenue du capteur\t\t: %.2f °C\n", tempCapteurC);
    printf("Température convertie en degrés Fahrenheit : %+f °F\n", ((tempCapteurC * 9 / 5) + 32));
    
    return (EXIT_SUCCESS);
}

