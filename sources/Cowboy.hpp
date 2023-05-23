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
                if(!target->isAlive()) throw std::runtime_error("target already dead");
                if(!this->isAlive()) throw std::runtime_error("dead can't shoot");
                if(target == this) throw std::runtime_error("can shoot itself");
                if(this->isAlive() && this->hasboolets()){
                    bulletLeft--;
                    target->hit(bulletHit);
                }
                else reload();
            }
            bool hasboolets(){return bulletLeft>0;}
            void reload(){
                if(this->isAlive())this->bulletLeft = magSize;
                else throw std::runtime_error("dead cowboy can't reload");
                }
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