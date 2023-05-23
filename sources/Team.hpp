#ifndef TEAM_HPP
#define TEAM_HPP
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <iostream>
#include <vector>
int const MAX_MEM = 10;
int const START_MEM = 0;
namespace ariel{
    class Team{
        
        public:
            Character* leadman;
            std::vector<Character *> group;
            int teamSize = START_MEM;
            Team(Character* leader);
           virtual ~Team();
            virtual void add(Character* new_member);
            virtual void attack(Team* other);
            int stillAlive();
            void print()const;
            ariel::Character* chooseVictim(Character *leadman, Team *other);
    };

}
#endif