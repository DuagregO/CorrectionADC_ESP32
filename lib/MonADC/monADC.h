#ifndef monADC_h
#define monADC_h

#include <Arduino.h>

// Complétez ce tableau avec les valeurs que vous avez mesuré pour Nreel.
//pour compléter ce tableau, faire le relevé Nreel = analogRead(Vin) avec Vin, les tensions placées
// en entrée d l'ADC sont :
//0V, 0.1V, 0.2V, 0.3V........3.1V, 3.2V, 3.3V
//
//
//
const float tab_mesures_reelles[34] = {
    0, 0, 80, 203, 321, 448, 567, 684, 814, 929, 1057, 1183, 1300, 1426, 1548,
    1672, 1793, 1914, 2034, 2162, 2283, 2400, 2524, 2644, 2771, 2896, 3043, 3194,
    3358, 3550, 3766, 4000, 4095, 4095};


//Ne pas toucher à la suite du programme.

const float tab_mesures_theoriques[34] =
    {0.000, 124.091, 248.182, 372.273, 496.364, 620.455, 744.545, 868.636, 992.727, 1116.818,
     1240.909, 1365.000, 1489.091, 1613.182, 1737.273, 1861.364, 1985.455, 2109.545, 2233.636,
     2357.727, 2481.818, 2605.909, 2730.000, 2854.091, 2978.182, 3102.273, 3226.364, 3350.455,
     3474.545, 3598.636, 3722.727, 3846.818, 3970.909, 4095.000};



class MonADC
{
public:
    MonADC(int pin);
    void init();
    float correction(int);

private:
    int _pin;
    float _tab_mesures_corrigees[4096];
};

#endif