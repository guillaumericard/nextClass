#include <iostream>
#include <ctime>
#include <string>
#include "Cours.h"
#include "lectureFichier.h"
#include <map>


#define FILE_PATH "./data/ListeCours"

#define DIMANCHE 0
#define LUNDI 1
#define MARDI 2
#define MERCREDI 3
#define JEUDI 4
#define VENDREDI 5
#define SAMEDI 6

int returnDifference(int, int, int);
Cours findDelaiMin(vector <Cours>);

int main() {
    lectureFichier x = lectureFichier(FILE_PATH);
    Cours newListMinfindDelaiMin = findDelaiMin(x.getListeCours());
    newListMinfindDelaiMin.printCours();

    return 0;
}

int switchJourtoInt(string jour){

    if(jour.compare("DIMANCHE") == 0) return DIMANCHE;
    if(jour.compare("LUNDI") == 0) return LUNDI;
    if(jour.compare("MARDI") == 0) return MARDI;
    if(jour.compare("MERCREDI") == 0) return MERCREDI;
    if(jour.compare("JEUDI") == 0) return JEUDI;
    if(jour.compare("VENDREDI") == 0) return VENDREDI;
    if(jour.compare("SAMEDI") == 0) return SAMEDI;

    return -1;
}

Cours findDelaiMin(vector<Cours> listeCours){
    time_t now = time(0);
    tm *timenow = localtime(&now);
    int jourSemaine = timenow->tm_wday, heure = timenow->tm_hour;
    std::map<float,Cours> difference;
    //Boucle pour retirer les jours
    for(Cours courant : listeCours){

        int jourCourant = switchJourtoInt(courant.getJour());
        int heureCourant = std::stoi(courant.getHeure());
        int diffJour = returnDifference(jourSemaine,jourCourant,6);
        int diffHeure = returnDifference(heure,heureCourant,23);
        //Si le jour est aujourd'hui et que l'heure est passée l'heure du cours, alors le jour est == 7
        if(diffJour == 0 &&  heure > heureCourant) {
            diffJour = 7;
        }
        string differenceJour = std::to_string(diffJour);
        string differenceHeure = std::to_string(diffHeure);
        string diff = differenceJour+"."+differenceHeure;
        float differenceFloat = std::stof(diff);
        difference.insert(pair<float,Cours>(differenceFloat,courant));

    }

    return difference.begin()->second;
}

int returnDifference(int val1, int val2, int maxBound){
    int compteurValeur=val1;
    int compte=0;
    bool estMemeValeur = false;

    while(estMemeValeur == false){
        if(compteurValeur == val2){
            estMemeValeur = true;
        }else{
            if(compteurValeur == maxBound){
                compteurValeur = 0 ;
            }else {
                compteurValeur++;
            }
            compte++;
        }
    }
    return compte;
}

