#include <iostream>
#include <ctime>
#include <string>
#include "Cours.h"
#include "lectureFichier.h"
#include <fstream>

#define FILE_PATH "../data/ListeCours"

#define DIMANCHE 0
#define LUNDI 1
#define MARDI 2
#define MERCREDI 3
#define JEUDI 4
#define VENDREDI 5
#define SAMEDI 6


int main() {

    lectureFichier x = lectureFichier(FILE_PATH);
    for (Cours line : x.getListeCours()){
        line.printCours();
    }
    //Établir journée / heure
    time_t now = time(0);
    tm *timenow = localtime(&now);
    int jourSemaine = timenow->tm_wday;
    int heure = timenow->tm_hour, minutes = timenow->tm_min;
    std::cout << heure << std::endl;

    return 0;
}
