#ifndef TEAM2_HPP
#define TEAM2_HPP
#include "Team.hpp"
namespace ariel{
    class Team2 : public Team{
        
        public:

        Team2(Character *leadman) : Team(leadman){};
        void add(Character *fighter) override;
        void attack(Team *other) override;
        ~Team2(){};
    };
}
#endif