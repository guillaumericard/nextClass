//
// Created by Guillaume Ricard on 2021-10-05.
//

//FORMAT FICHIER : nom,sigle,local,jour,heure,minute

#include "lectureFichier.h"
#include <fstream>
#include <iostream>

#define SIZE_FORMAT_CSV 6

lectureFichier::lectureFichier(string _path) : path(_path)
{
    this->listeCours = lignesFichier(_path);
}

vector<Cours> lectureFichier::getListeCours(){
    return this->listeCours;
}

vector<Cours> lectureFichier::lignesFichier(string path) {

    vector<Cours> listeCours;
    ifstream file(path);
    string line;
    string lineSplit[6];

    if(file.is_open()){
        while (getline(file,line)){
            Cours *_cours = new Cours();
            for(int i=0; i < SIZE_FORMAT_CSV ; i++){
                if(i == SIZE_FORMAT_CSV - 1){
                    lineSplit[i] = line;
                }else{
                    int index = line.find(",");
                    lineSplit[i] = line.substr(0,index);
                    line.erase(0,index+1);
                }
            }

            _cours->setNom(lineSplit[0]);
            _cours->setSigle(lineSplit[1]);
            _cours->setLocal(lineSplit[2]);
            _cours->setJour(lineSplit[3]);
            _cours->setHeure(lineSplit[4]);
            _cours->setMinute(lineSplit[5]);
            listeCours.push_back(*_cours);
        }
    }else{std::cout << "NOPE" << std::endl;}
   return listeCours;
}
