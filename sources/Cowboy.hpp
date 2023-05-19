#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
#include <iostream>
namespace ariel{
    int cowboyHP = 110;
    int magSize = 6;
    int bulletHit = 10;
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
            void print() override {
                if(this->isAlive()){
                    std::cout <<"(C)" << name << "," << hitPoints << ",(" << location.x << "," << location.y << ")" << std::endl;
                }
                else {
                    std::cout <<"(C)(" << name << "),(" << location.x << "," << location.y << ")" << std::endl;
                }
            }; 
    };

}

#endif