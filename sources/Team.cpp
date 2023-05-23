#include <iostream>
#include <limits.h>
#include "Team.hpp"
#include "Character.hpp"

ariel::Team::Team(Character* leader){
    this->leadman = leader;
    add(leader);
    leader->inTeam = true;
}
void ariel::Team::add(Character *fighter){
    if(teamSize == MAX_MEM) throw std::runtime_error("Already full team");
    if(fighter->inTeam) throw std::runtime_error("Already belong to a team");

    Cowboy *new_cowboy = dynamic_cast<Cowboy *>(fighter);
    Ninja *new_ninja = dynamic_cast<Ninja *>(fighter);
    if(new_cowboy){
        group.insert(group.begin(), new_cowboy);
        teamSize++;
        new_cowboy->inTeam = true;
    }
    else if(new_ninja){
        group.push_back(new_ninja);
        teamSize++;
        new_ninja->inTeam = true;
    }
    else{
        throw std::runtime_error("Character not defined correctly.");
    }


}

void ariel::Team::attack(Team *other){
    if(!other) throw std::invalid_argument("pointer NULL");    //if team empty
    if(other == this) throw std::runtime_error("ca't attack itself"); //if attacking itself
    if(this->stillAlive() == 0) throw std::runtime_error("dead team can't attack"); //team dead
    if(other->stillAlive() == 0) throw std::runtime_error("target already dead"); //target already dead
    
    Character *victim = chooseVictim(this->leadman, other);
    if(victim == NULL) return;
    for(const auto &fighter : group){
        if(fighter->isAlive() && victim->isAlive()){
            Cowboy *cboy = dynamic_cast<Cowboy*>(fighter);
            Ninja *ninja = dynamic_cast<Ninja*>(fighter);
            if(cboy) cboy->shoot(victim);
            if(ninja) {
                if(ninja->distance(victim)<= 1) ninja->slash(victim);
                else ninja->move(victim);
            }
        }
        if(!this->leadman->isAlive()){
            Character *heir = chooseVictim(this->leadman, this);
            this->leadman = heir;
        }
        if(!victim->isAlive() && other->stillAlive()>0){
            //dead in the middle of round
            victim = chooseVictim(this->leadman, other);
        }
    }
}

void ariel::Team::print()const {
    for(const auto &fighter : group){
        if(fighter == leadman) std::cout << "team leader: ";
        std::cout <<  fighter->print() << std::endl;
    }
}

ariel::Character *ariel::Team::chooseVictim(Character *leadman, Team *other)
{
    //finding the closest rival to lead_group
    Character* closest_fighter = NULL;
    int min_distance = INT_MAX;
    for(const auto &fighter : other->group){
        if(fighter->isAlive()){
            int current = fighter->distance(this->leadman);
            if(current < min_distance){
                min_distance = current;
                closest_fighter = fighter;
            };
        }
    }
    return closest_fighter;
}

int ariel::Team::stillAlive(){
    int num_alive = 0;
    for(const auto fighter : group){
        if(fighter->isAlive() && fighter != NULL) num_alive++;
    }
    return num_alive;
}

ariel::Team::~Team(){
    for(const auto &fighter : group){
        delete fighter;
    }
    leadman = NULL;
}