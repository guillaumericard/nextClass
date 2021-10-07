//
// Created by Guillaume Ricard on 2021-10-05.
//

#ifndef NEXTCLASS_COURS_H
#define NEXTCLASS_COURS_H
#include <string>

using namespace std;

class Cours {
public:
    Cours();
    Cours(string _nom, string _sigle, string _local,string _jour, string _heure, string _minute);
    void setNom(string _nom);
    void setSigle(string _sigle);
    void setLocal(string _local);
    void setJour(string _jour);
    void setHeure(string _heure);
    void setMinute(string _minute);
    string getJour();
    string getHeure();
    string getMinute();
    void printCours();
private:
    string nom;
    string sigle;
    string local;
    string jour;
    string heure;
    string minute;
};


#endif //NEXTCLASS_COURS_H
