//
// Created by Andrei on 4/6/2022.
//

#include "Avocat.h"
#include <iostream>
#include <string>

using namespace std;

int Avocat::nr_av;

Avocat::Avocat() {
    cod = 0;
    nume = "no_name";
    nr_procese = 0;
    vector_procese = nullptr;

}
Avocat::Avocat(const Avocat& avocat1){
    cod = avocat1.cod;
    nr_procese = avocat1.nr_procese;
    vector_procese = new int[avocat1.nr_procese];
    for(int i = 0; i < avocat1.nr_procese;i++)
    vector_procese[i] = avocat1.vector_procese[i];
    nume = avocat1.nume;
    nr_av++;
}
Avocat::Avocat(int cod_, std::string nume_,int nr_procese_,int *vector_procese_) {
    cod = cod_;
    nume = nume_;
    nr_procese = nr_procese_;
    vector_procese = new int[nr_procese_];
    for(int i = 0; i < nr_procese_;i++)
        vector_procese[i] = vector_procese_[i];
    nr_av++;
}
Avocat::~Avocat() {
    delete[] vector_procese;
}

string Avocat::getNume() const{
    return nume;
}

void Avocat::setNume(string nume_) {
    nume = nume_;
}
int Avocat::getCod() const {
    return cod;
}
void Avocat::setCod(int cod_) {
    cod = cod_;
}
int Avocat::getNr_procese() const {
    return nr_procese;
}
void Avocat::setNr_procese(int nr_procese_) {
    nr_procese = nr_procese_;
}

ostream &operator<<(ostream &os, const Avocat &Avocat1){
    os<< "Avocat = "<<Avocat1.nume<<endl;
    os<< "Cod = "<<Avocat1.cod<<endl;
    os<< "Numar de procese = "<<Avocat1.nr_procese<<endl;
    if(Avocat1.nr_procese<0)
        throw MyOutOfBoundsException();
    os<< "Sume incasate = "<<endl;
    if(Avocat1.nr_procese == 0) os<<"Fara sume!!!"<<endl;
    else
        for(int i = 0; i < Avocat1.nr_procese;i++){
            os<<Avocat1.vector_procese[i]<<" "<<endl;
        }
    os<<endl;
    return os;
}

istream& operator >>(istream& in, Avocat& Avocat1)
{
    cout <<"Nume avocat:  ";
    in >> Avocat1.nume;
    cout <<"Cod avocat?  ";
    in >> Avocat1.cod;
    cout<<"Cate procese a avut?  ";
    in >> Avocat1.nr_procese;
    if(Avocat1.nr_procese<0)
        throw MyOutOfBoundsException();
    Avocat1.vector_procese = new int[Avocat1.nr_procese];
    for(int i = 0; i < Avocat1.nr_procese;  i++) {
        cout << "Cat a incasat dupa procesul " << i << "?  ";
        in >> Avocat1.vector_procese[i];
    }
    Avocat1.nr_av++;
    return in;
}
Avocat& Avocat :: operator = (const Avocat &Avocat1) {
    nume = Avocat1.nume;
    cod = Avocat1.cod;
    nr_procese = Avocat1.nr_procese;
    vector_procese = new int[Avocat1.nr_procese];
    for(int i = 0; i < Avocat1.nr_procese; i++){
        vector_procese[i] = Avocat1.vector_procese[i];
    }
    return *this;
};


bool operator >(const Avocat& avocat1, const Avocat& avocat2){
    if(avocat1.nr_procese > avocat2.nr_procese) return 1;
    cout<<avocat1.nr_procese<<" "<<avocat2.nr_procese<<" ";
    return 0;
};


void Avocat::sortare(Avocat lista[], int n){
    for(int i = 0; i<n-1; i++)
        for(int j = i+1; j<n; j++){
            if(lista[i]>lista[j]){
                Avocat swap = lista[i];
                lista[i] = lista[j];
                lista[j] = swap;
            }
        }
}
void Avocat::afisare() {
    cout<<"Nume avocat: "<<nume<<endl;
    cout<<"Cod avocat: "<<cod<<endl;
    cout<<"Numar de procese: "<<nr_procese<<endl;
    for(int i = 0; i< nr_procese; i++){
        cout<<"Suma pentru procesul "<<i<<" : ";
        cout<<vector_procese[i]<<endl;
    }
}

void Avocat::afisare_nr_av(){
    cout<<"numarul de avocati incarcati este "<<nr_av<<endl;
};

int Avocat::getNr_av()const{
    return nr_av;
};