#include "Team2.hpp"

void ariel::Team2::add(Character *fighter)
{
    if(teamSize == MAX_MEM) throw std::runtime_error("Already full team");
    if(fighter->inTeam) throw std::runtime_error("Already belong to a team");
   Cowboy *new_cboy = dynamic_cast<Cowboy *>(fighter);
   Ninja *new_ninja = dynamic_cast<Ninja *>(fighter);
   if(new_cboy||new_ninja){
        fighter->inTeam = true;
        teamSize++;
   }
   else throw std::runtime_error("Character not defined correctly.");
}

void ariel::Team2::attack(Team *other)
{
    Team::attack(other);
}