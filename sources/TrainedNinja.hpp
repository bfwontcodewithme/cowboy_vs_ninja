#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Character.hpp"
#include <iostream>

namespace ariel {

    class TrainedNinja : public Ninja{

        public:
            TrainedNinja(std::string nickname, Point loc): Ninja(nickname, loc){
                this->speed = trainedSpeed;
                this->hitPoints = trainedHP;
            };
            ~TrainedNinja(){};              
    };
}
#endif