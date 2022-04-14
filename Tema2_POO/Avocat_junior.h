//
// Created by Andrei on 4/14/2022.
//

#ifndef TEMA2_POO_AVOCAT_JUNIOR_H
#define TEMA2_POO_AVOCAT_JUNIOR_H

#include <iostream>
#include <cstring>
#include "Avocat.h"
#include<vector>

class Avocat_Junior:public Avocat{
protected:
public:
    Avocat_Junior(int cod, std::string nume, int nr_procese, int *vector_procese);

};



#endif //TEMA2_POO_AVOCAT_JUNIOR_H
