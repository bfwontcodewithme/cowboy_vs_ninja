#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include "Character.hpp"
#include <iostream>

namespace ariel{

    class YoungNinja : public Ninja{

        public:
            YoungNinja(std::string nickname, Point loc): Ninja(nickname, loc){
                this->speed = youngSpeed;
                this->hitPoints = youngHP;
            };
            ~YoungNinja(){};
    };
}
#endif