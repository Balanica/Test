//
// Created by Andrei on 4/6/2022.
//

#ifndef TEMA2_POO_AVOCAT_H
#define TEMA2_POO_AVOCAT_H


#include <string>
#include <iostream>
#include <vector>
#include<exception>
#include<memory>

class MyOutOfBoundsException : public std::exception{
public:
    MyOutOfBoundsException() = default;

    const char* what() const noexcept override{
        return "DE CE NU POTI SA DAI UN INPUT VALIDDD!?";
    }

};

class Avocat{
protected:
    static int nr_av;
    int cod;
    std::string nume;
    int nr_procese;
    int *vector_procese;

public:
    Avocat();
    Avocat(int cod_, std::string nume_,int nr_procese,int *vector_procese_ );
    Avocat(const Avocat &avocat1);
    ~Avocat();

    std::string getNume() const;
    void setNume(std::string nume_);
    int getCod() const;
    void setCod(int cod_);
    int getNr_procese() const;
    void setNr_procese(int nr_procese_);
    int getVector_procese() const;
    void setVector_procese();
//    virtual std::string getTitle() const = 0;
    int getNr_av()const;

    friend std::ostream &operator<<(std::ostream &os, const Avocat &Avocat1);
    friend std::istream& operator >>(std::istream& in, Avocat& Avocat1);
    Avocat &operator=(const Avocat &Avocat1);
    friend bool operator >(const Avocat& avocat1, const Avocat& avocat2);

    void sortare(Avocat lista[], int n);
    virtual void afisare();
    static void afisare_nr_av();
};

#endif //TEMA2_POO_AVOCAT_H