//
// Created by Guillaume Ricard on 2021-10-05.
//

#include <iostream>
#include "Cours.h"

Cours::Cours() {

}

Cours::Cours(string _nom,  string _sigle, string _local, string _jour, string _heure, string _minute)
: nom(_nom),sigle(_sigle),local(_local), jour(_jour), heure(_heure), minute(_minute)
{
}

void Cours::setNom(string _nom) {this->nom = _nom;}
void Cours::setSigle(string _sigle) {this->sigle = _sigle;}
void Cours::setLocal(string _local) {this->local = _local;}
void Cours::setJour(string _jour) {this->jour = _jour;}
void Cours::setHeure(string _heure) {this->heure = _heure;}
void Cours::setMinute(string _minute) {this->minute = _minute;}

void Cours::printCours() {
    std::cout << "NOM COURS : " << this->nom << std::endl;
    std::cout << "SIGLE COURS : " << this->sigle << std::endl;
    std::cout << "LOCAL COURS : " << this->local << std::endl;
    std::cout << "JOURNÉE COURS : " << this->jour << std::endl;
    std::cout << "HEURE COURS : " << this->heure << ":" << this->minute << std::endl <<std::endl;
}


