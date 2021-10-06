//
// Created by Guillaume Ricard on 2021-10-05.
//

#ifndef NEXTCLASS_LECTUREFICHIER_H
#define NEXTCLASS_LECTUREFICHIER_H

#include <string>
#include <vector>
#include "Cours.h"
using namespace std;

class lectureFichier {
public:
    lectureFichier(string _path);
    vector<Cours> getListeCours();
private:
    string path;
    vector<Cours> listeCours;
    vector<Cours> lignesFichier(string path);
};


#endif //NEXTCLASS_LECTUREFICHIER_H
