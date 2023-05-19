#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP
#include "Character.hpp"
#include <iostream>

namespace ariel{
    int oldSpeed = 8;
    int oldHP = 150;
    class OldNinja : public Ninja{

        public:
            OldNinja(std::string nickname, Point loc): Ninja(nickname, loc){
                this->speed = oldSpeed;
                this->hitPoints = oldHP;
            };
            ~OldNinja(){};
    };

}
#endif