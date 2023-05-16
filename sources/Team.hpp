#ifndef TEAM_HPP
#define TEAM_HPP
#include "Point.hpp"
#include "Character.hpp"
#include <iostream>
int const members = 10;

namespace ariel{
    class Team{
        
        public:
            Character* leadman[members];

            Team(Character* leader){
                
            };
            ~Team(){};
            void add(Character* new_member){};
            void attack(Team* other){};
            int stillAlive(){return 0;};
            void print(){};
    };

}
#endif