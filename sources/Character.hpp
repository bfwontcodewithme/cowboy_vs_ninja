#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <iostream>

namespace ariel {
    class Character{
        
        public:
            Point location;
            std::string name;
            int hitPoints;
            bool inTeam = false;;
            Character(std::string nickname, Point loc): name(nickname), location(loc){};
            Character(){};
            virtual ~Character(){};

            bool isAlive(){return hitPoints>0;}
            double distance(Character* target){
                return this->location.distance(target->getLocation());}
            void hit(int hits){ this->hitPoints -= hits;}
            std::string getName(){return name;};
            Point getLocation(){return location;};
            virtual void print() = 0;


    };
    class Ninja : public Character{

        public:
            int speed;
            Ninja(std::string nickname, Point loc): Character(nickname,loc){};
            Ninja(){};
            ~Ninja(){};


            void move(Character* target){
                Point::moveTowards(this->location, target->getLocation(), speed);
            };
            void slash(Character* target){
                if(this->isAlive() && this->distance(target) < 1){
                    target->hit(ninjaHit);
                }
                else return;
            };
            void print(){
                if(this->isAlive()){
                    std::cout <<"(N)" << name << "," << hitPoints << ",(" << location.x << "," << location.y << ")" << std::endl;
                }
                else {
                    std::cout <<"(N)(" << name << "),(" << location.x << "," << location.y << ")" << std::endl;
                }
            }; 
    };
    int ninjaHit = 40;
}
#endif