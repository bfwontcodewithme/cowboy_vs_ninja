#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <iostream>
int const ninjaHit = 40;
int const cowboyHP = 110;
int const magSize = 6;
int const bulletHit = 10;
int const oldSpeed = 8;
int const oldHP = 150;
int const trainedSpeed = 12;
int const trainedHP = 120;
int const youngSpeed = 14;
int const youngHP = 100;
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
            void setLocation(Point point_new){ this->location = point_new;}
            bool isAlive(){return hitPoints>0;}
            double distance(Character* target){
                return this->location.distance(target->getLocation());}
            void hit(int hits){ 
                if(hits < 0) throw std::invalid_argument("");
                this->hitPoints -= hits;}
            std::string getName(){return name;};
            Point getLocation(){return location;};
            virtual std::string print() = 0;


    };


    class Ninja : public Character{

        public:
            int speed;
            Ninja(std::string nickname, Point loc): Character(nickname,loc){};
            Ninja(){};
            ~Ninja(){};

            int getSpeed(){return this->speed;}
            void move(Character* target){
                double distance = std::min(this->distance(target), double(this->getSpeed()));
                Point new_point = Point::moveTowards(this->getLocation(), target->getLocation(), distance);
                this->setLocation(new_point);
            };
            void slash(Character* target){
                if(!target) throw std::runtime_error("target NULL");
                if(target == this) throw std::runtime_error("can't slash itself");
                if(!target->isAlive()) throw std::runtime_error("dead target");
                if(!this->isAlive()) throw std::runtime_error("dead can't attack");
                if(this->distance(target) < 1){
                    target->hit(ninjaHit);
                }

            };
            std::string print(){
                std::string str;
                if(this->isAlive()){
                    str += "\n(N)";
                    str += name;
                    str +=",";
                    str += hitPoints;
                    str += ",";
                    str += getLocation().print();

                    return str;
                }
                else {
                    str += "\n(N)";
                    str += name;
                    str +=",";
                    str += getLocation().print();

                    return str;
                }
            }; 
    };

}
#endif