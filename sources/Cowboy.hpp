#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
#include <iostream>
namespace ariel{

    class Cowboy : public Character{

        public:
            int bulletLeft;
            Cowboy(std::string nickname, Point loc): Character(nickname, loc){
                this->hitPoints = cowboyHP;
                this->bulletLeft = magSize;
            };
            ~Cowboy(){};
            void shoot(Character* target){
                if(this->isAlive() && this->hasboolets()){
                    bulletLeft--;
                    target->hit(bulletHit);
                }
                else reload();
            }
            bool hasboolets(){return bulletLeft>0;}
            void reload(){this->bulletLeft = magSize;}
            std::string print() override {
                std::string str;
                if(this->isAlive()){
                    str += "\n(C)";
                    str += name;
                    str +=",";
                    str += hitPoints;
                    str += ",";
                    str += getLocation().print();

                    return str;
                }
                else {
                    str += "\n(C)(";
                    str += name;
                    str +="),";
                    str += getLocation().print();

                    return str;
                }
            }; 
    };

}

#endif