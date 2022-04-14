//
// Created by Andrei on 4/13/2022.
//

#ifndef TEMA2_POO_AVOCAT_OFICIU_H
#define TEMA2_POO_AVOCAT_OFICIU_H


#include <iostream>
#include <cstring>
#include "Avocat.h"
#include<vector>

class Avocat_Oficiu : public Avocat{
protected:
    std::string nume_client;
    int durata;
public:
    Avocat_Oficiu();
    Avocat_Oficiu(int cod_, std::string nume_,int nr_procese_,int *vector_procese_,std::string nume_client_, int durata_);
    Avocat_Oficiu(Avocat_Oficiu &avocat_oficiu1);
    ~Avocat_Oficiu();

    Avocat_Oficiu &operator = (const Avocat_Oficiu &avocatOficiu);

    friend std::ostream &operator<<(std::ostream &os, const Avocat_Oficiu &Avocat_Oficiu1);
    friend std::istream &operator>>(std::istream &is, Avocat_Oficiu &Avocat_oficiu1);

    void maxim_durata(Avocat_Oficiu lista[], int n);
    void afisare();

//    Avocat_Oficiu(Avocat *pAvocat);
};

#endif //TEMA2_POO_AVOCAT_OFICIU_H