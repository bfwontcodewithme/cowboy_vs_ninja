#include <iostream>
#include "Team.hpp"

ariel::Team::Team(Character* leader){
    this->leadman = leader;

}
void ariel::Team::add(Character *fighter){
    if(teamSize == members) throw std::runtime_error("Already full team");
    if(fighter->inTeam) throw std::runtime_error("Already belong to a team");
}

void ariel::Team::attack(Team *other){

}

void ariel::Team::print(){

}

int ariel::Team::stillAlive(){

}

ariel::Team::~Team(){

}