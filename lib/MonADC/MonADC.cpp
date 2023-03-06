#include "MonADC.h"

MonADC::MonADC(int pin)
{
  pinMode(pin,INPUT);
  _pin=pin;
  init();
}


void MonADC::init()
{
  int i;                      // variable de boucle pour tab_mesures_corrigées
  int j;                      // variable de boucle pour tab_mesures_reelles et tab_mesures_theo

  _tab_mesures_corrigees[0] = 0;
  _tab_mesures_corrigees[4095] = 4095;

  // trouver la 1ère valeur non nulle de tab_mesures_reelles
  j = 0;
  while (tab_mesures_reelles[j] == 0)
  {
    j++;
  }
 //générer le 1er tronçon

  for (i = 0; i < tab_mesures_reelles[j]; i++)
  {
    _tab_mesures_corrigees[i] = tab_mesures_theoriques[j] * i / tab_mesures_reelles[j];
  }
 // générer les tronçons suivants
  for (j = j + 1; j < 34; j++)
  {

    for (i; i < tab_mesures_reelles[j]; i++)
    {
      _tab_mesures_corrigees[i] = (tab_mesures_theoriques[j] - tab_mesures_theoriques[j - 1]) * (i - tab_mesures_reelles[j - 1]) / (tab_mesures_reelles[j] - tab_mesures_reelles[j - 1]) + tab_mesures_theoriques[j - 1];
    }
  }

  //Affichage du tableau_mesures_corrigees
  // Serial.println("Tableau des valeurs corrigées");
  //   j = 0;
  // while (tab_mesures_reelles[j] == 0)
  // {
  //   j++;
  // }
  // for(int k=0;k<4096;k++)
  // {
  //     Serial.print(_tab_mesures_corrigees[k]);
  //     Serial.print(" ");
  //     if(k==tab_mesures_reelles[j])
  //     {
  //       Serial.println();
  //       j++;
  //     }

  // }

}

float MonADC::correction(int n)
{
    return _tab_mesures_corrigees[n];
}


