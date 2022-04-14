//
// Created by Andrei on 4/13/2022.
//

#include "Avocat_Oficiu.h"
#include "Avocat.h"
#include <iostream>
#include <string>

Avocat_Oficiu :: Avocat_Oficiu(){
    nume_client = "No_name";
    durata = 0;
}

Avocat_Oficiu :: Avocat_Oficiu(int cod_, std::string nume_,int nr_procese_,int *vector_procese_,std::string nume_client_, int durata_): Avocat(cod_, nume_, nr_procese_, vector_procese_){
    nume_client = nume_client_;
    durata = durata_;
}
Avocat_Oficiu :: Avocat_Oficiu(Avocat_Oficiu &avocat_oficiu1): Avocat(avocat_oficiu1){
        nume_client = avocat_oficiu1.nume_client;
        durata = avocat_oficiu1.durata;
};

Avocat_Oficiu::~Avocat_Oficiu() {
    delete[] vector_procese;
}

Avocat_Oficiu &Avocat_Oficiu :: operator = (const Avocat_Oficiu Avocat_oficiu){
    Avocat::operator=(Avocat_oficiu);
    nume_client = Avocat_oficiu.nume_client;
    durata = Avocat_oficiu.durata;
    return *this;
};

std::ostream &operator<<(std::ostream &os, const Avocat_Oficiu &Avocat_Oficiu1){
    os<< "Client = "<<Avocat_Oficiu1.nume_client<<std::endl;
    os<< "Durata = "<<Avocat_Oficiu1.durata<<std::endl;
    os<< "Avocat = "<<Avocat_Oficiu1.nume<<std::endl;
    os<< "Cod = "<<Avocat_Oficiu1.cod<<std::endl;
    os<< "Numar de procese = "<<Avocat_Oficiu1.nr_procese<<std::endl;
    os<< "Sume incasate = "<<std::endl;
    if(Avocat_Oficiu1.nr_procese == 0) os<<"Fara sume!!!"<<std::endl;
    else
    for(int i = 0; i < Avocat_Oficiu1.nr_procese;i++){
        os<<Avocat_Oficiu1.vector_procese[i]<<" "<<std::endl;
    }
    os<<std::endl;
    return os;
};
std::istream &operator>>(std::istream &is, Avocat_Oficiu &Avocat_oficiu1){
    is >> (Avocat&) Avocat_oficiu1;
    std::cout << "Nume client? ";
    is >> Avocat_oficiu1.nume_client;
    std::cout << "Durata procesului? ";
    is >> Avocat_oficiu1.durata;
    return is;
};


void Avocat_Oficiu:: maxim_durata(Avocat_Oficiu lista[], int n ){
    int maxim, poz_max;
    maxim = lista[0].durata;
    poz_max = 0;
    for(int i = 0; i < n ;i++)
        if(lista[i].durata> maxim) {
            maxim = lista[i].durata;
            poz_max = i;
        }
    std::cout<<"Avocatul_Oficiu cu durata cea mai mare este "<< poz_max<<" cu durata de "<< maxim;
};

void Avocat_Oficiu::afisare(){
    Avocat::afisare();
    std::cout<<"Numele Clientului: "<<nume_client<<std::endl;
    std::cout<<"Durata procesului: "<<durata<<std::endl;
}