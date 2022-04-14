#include <iostream>
#include "Avocat.h"
#include "Avocat_Oficiu.h"
#include<exception>

using namespace std;


void indicatii(){
    cout<<"Apasati tasta '0' pentru a vedea instructiunile de utilizare a meniului"<<endl;
    cout<<"Apasati tasta '1' pentru a incheia navigarea in meniu"<<endl;

}
void meniu_interactiv(){
    int OK = 1,optiune,  nr;
    bool ceva = false;
    Avocat_Oficiu avocat_oficiu;
    cout<<"Introduceti numarul de avocati: ";
    while(ceva == false) {
        try {
            cin >> nr;
            if (nr <= 0)
                throw 1;
            ceva = true;
        }
        catch (int n) {
            cout << "Numarul de avocati trebuie sa fie > 0!!!"<<endl;
        }
    }
    Avocat **avocat = new Avocat*[nr];
    for(int i  = 0; i<nr;i++){
      cout<<"Doriti sa adaugati un avocat sau sau un avocat_oficiu? ";
      int decizie;
      cin>>decizie;
      if(decizie == 0){
          avocat[i] = new Avocat();
          ceva = false;
          while(ceva == false) {
              try {
                  cin >> *avocat[i];
                  ceva = true;
              }
              catch (const MyOutOfBoundsException &e) {
                  cout << e.what();
              }
          }
      }
      else{
         avocat[i] =  new Avocat_Oficiu();
          ceva = false;
          while(ceva == false) {
              try {
                  cin >> *dynamic_cast<Avocat_Oficiu*>(avocat[i]);
                  ceva = true;
              }
              catch (const MyOutOfBoundsException &e) {
                  cout << e.what();
              }
          }
      }
    }
    indicatii();
//    while(OK){
//        cout<<"Alege optiunea dorita: "<<endl;
//        cin>>optiune;
//        switch(optiune){
//            case 1:
//                OK = 0;
//            case 0:
//                indicatii();
//            case 2:
//                //lista_av[0].afisare_nr_av();
//                for(int i = 0; i<nr;i++){
//                    cout<<lista_av[i];
//                }
//            case 3:
//                ceva = false;
//                while(ceva == false) {
//                    try {
//                        cout<<"Introduceti Avocat_Oficiu "<<avocat_oficiu<<endl;
//                        ceva = true;
//                    }
//                    catch (const MyOutOfBoundsException &e) {
//                        cout << e.what();
//                    }
//                }
//
//
//        }
//    }

}
int main() {
//    int y[] = {3,5};
//    int x[] = {3,5, 74, 12, 56};
//     Avocat  Tom;
//    Avocat Tim(12, "tim", 2, y);
//    Avocat Tem(15, "tem", 5, x);
//    Avocat Avocati[] = {Tom, Tim, Tem};
//    Tim.sortare(Avocati, 3);
//    for(int i = 0; i < 3; i++){
//        cout<<Avocati[i];
//    }
//    Avocat_Oficiu Rob(12, "tim", 2, y, "Rob1", 45);
//    Avocat_Oficiu Bob(12, "tim", 2, y, "Bob1", 75);
//    Avocat_Oficiu Tob(12, "tim", 2, y, "Rob1", 25);
//    Avocat_Oficiu Avocati_Oficiu[] = {Rob, Bob, Tob};
//    Avocati_Oficiu[0].maxim_durata(Avocati_Oficiu, 3);
//     return 0;

    meniu_interactiv();
    return 0;
}
