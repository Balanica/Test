#include <iostream>
#include "Avocat.h"
#include "Avocat_Oficiu.h"
#include<exception>

using namespace std;


void indicatii(){
    cout<<"Apasati tasta '0' pentru a vedea instructiunile de utilizare a meniului"<<endl;
    cout<<"Apasati tasta '1' pentru a incheia navigarea in meniu"<<endl;
    cout<<"Apasati tasta '2' pentru a vizualiza lista de obiecte"<<endl;
    cout<<"Apasati tasta '3' pentru a vizualiza lista de Avocati"<<endl;
    cout<<"Apasati tasta '4' pentru a vizualiza lista de Avocati_Oficiu"<<endl;
    cout<<"Apasati tasta '5' pentru a sorta avocatii din lista de obiecte si a afisa ordinea crescatoare a acestora"<<endl;
    cout<<"Apasati tasta '6' pentr a emite maximul si pozitia pe care se afla maximul"<<endl;

}
void meniu_interactiv(){
    int OK = 1,optiune,  nr;
    int cnt_1 = 0 , cnt_2 = 0;
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
    int type[nr];
    for(int i  = 0; i<nr;i++){
      cout<<"Doriti sa adaugati un avocat sau un avocat_oficiu? ";
      int decizie;
      cin>>decizie;
      if(decizie == 0){
          type[i] = 0;
          cnt_1++;
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
          type[i] = 1;
          cnt_2++;
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
    while(OK){
        cout<<"Alege optiunea dorita: "<<endl;
        cin>>optiune;
        switch(optiune){
            case 1:
                OK = 0;
                break;
            case 0:
                indicatii();
                break;
            case 2:
                for(int i = 0; i<avocat[0]->getNr_av();i++){
                    avocat[i]->afisare();
                    cout<<endl;
                }
                break;
            case 3:
                for(int i = 0; i<avocat[0]->getNr_av();i++)
                    if(type[i]==0){
                    avocat[i]->afisare();
                    cout << endl;
                }
//                Avocat_Oficiu case3;
//                case3.maxim_durata(reinterpret_cast<Avocat_Oficiu *>(avocat), cnt_2);
                break;
            case 4:
                for(int i = 0; i<avocat[0]->getNr_av();i++)
                    if(type[i]==1){
                        avocat[i]->afisare();
                        cout << endl;
                    }
                break;
            case 5:
                for(int i = 0; i < nr-1;i++){
                    if(type[i] == 0)
                        for(int j = i+1; j < nr; j++){
                            if(type[j] == 0)
                                if(*avocat[i] > *avocat[j]){
                                    Avocat *aux = avocat[i];
                                    avocat[i] = avocat[j];
                                    avocat[j] = aux;
                                }

                        }
                }
                for(int i = 0; i< nr;i++)
                    if(type[i] == 0){
                        avocat[i]->afisare();
                        cout<<endl;
                    }
                break;
        }
    }

}
int main() {
//    int y[] = {3,5};
//    int x[] = {3,5, 74, 12, 56};
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
