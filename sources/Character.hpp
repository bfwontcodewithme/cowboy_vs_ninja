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
            Character(std::string nickname, Point loc): name(nickname), location(loc){};
            Character(){};
            ~Character(){};

            bool isAlive(){return true;};
            double distance(Character* target){return 0;};
            void hit(int hits){};
            std::string getName(){return name;};
            Point getLocation(){return location;};
            void print(){};
            friend bool operator==(const Character& a, const Character& b);


    };
    int cowboyHP = 110;
    int magSize = 6;
    int bulletHit = 10;
    int ninjaHit = 40;
    int oldSpeed = 8;
    int oldHP = 150;
    int trainedSpeed = 12;
    int trainedHP = 120;
    int youngSpeed = 14;
    int youngHP = 100;

    class Cowboy : public Character{

        public:
            Character c;
            int bulletLeft;
            Cowboy(std::string nickname, Point loc){
                this->name = nickname;
                this->location = loc;
                this->hitPoints = cowboyHP;
                this->bulletLeft = magSize;
            };
            ~Cowboy(){};
            void shoot(Character* target){};
            bool hasBoolets(){return true;};
            void reload(){};
    };

    class Ninja : public Character{

        public:
            Character c;
            int speed;
            Ninja(std::string nickname, Point loc){};
            Ninja(){};
            ~Ninja(){};


            void move(Character* target){};
            void slash(Character* target){};
    };

    class OldNinja : public Ninja{

        public:
            Ninja n;

            OldNinja(std::string nickname, Point loc){
                this->name = nickname;
                this->location = loc;
                this->speed = oldSpeed;
                this->hitPoints = oldHP;

            };
            ~OldNinja(){};

    };

    class TrainedNinja : public Ninja{

        public:
            Ninja n;
            TrainedNinja(std::string nickname, Point loc){
                this->name = nickname;
                this->location = loc;
                this->speed = trainedSpeed;
                this->hitPoints = trainedHP;
            };
            ~TrainedNinja(){};
    };

    class YoungNinja : public Ninja{

        public:
            Ninja n;
            YoungNinja(std::string nickname, Point loc){
                this->name = nickname;
                this->location = loc;
                this->speed = youngSpeed;
                this->hitPoints = youngHP;
            };
            ~YoungNinja(){};

    };
}
#endif