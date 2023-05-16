#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include <cmath>
#include <iostream>
using namespace ariel;

TEST_CASE("Basic Point Methods"){
    //add here 2 point to test in all the subcase
    Point p1(1,2);
    Point p2(1,1);
    SUBCASE("Initialize points"){

        Point p2(4.23,1.01);
        // Point p3; default ctor
        CHECK(p1.x == 1.0);
        CHECK(p1.y == 2.0);
        CHECK(p2.x == 4.23);
        CHECK(p2.y == 1.01);
    }
    SUBCASE("Distance between points"){

        CHECK(p1.x == 1.0);
        CHECK(p1.y == 2.0);
        CHECK(p1.distance(p2) == 1);
        CHECK_EQ(p1.distance(p2),p2.distance(p1));
        //distance between the same point
        CHECK(p1.distance(p1) == 0);

    }
    //SUBCASE("Printing points"){}
    SUBCASE("Closest Point"){
        Point p3(0,0);
        double d12 = p1.distance(p2);
        double d32 = p3.distance(p2);
        CHECK_GT(d32,d12);
        CHECK_EQ(d12,1);
        CHECK_EQ(d32,std::sqrt(5));
        CHECK_EQ(p2.moveTowards(),p1);
        CHECK_EQ(p3.moveTowards(),p1);
        //check case the distances equal
    }
}
TEST_CASE("Cowboy methods test"){
    Point p1(1,2);
    Cowboy *eren = new Cowboy("eren", p1);
    Point p2(1,4);
    Cowboy *armin = new Cowboy("armin", p2);

    SUBCASE("initialize test"){
        CHECK_EQ(eren->getName(),"eren");
        CHECK_EQ(eren->getLocation().x,1);
        CHECK_EQ(eren->bulletLeft,6);
        CHECK_EQ(eren->hitPoints, 110);
        CHECK_FALSE(!eren->hasBoolets());
        CHECK_FALSE(!eren->isAlive());
    }
    SUBCASE("Distance between fighters"){
        CHECK_EQ(eren->distance(armin), 2);
        CHECK_EQ(eren->distance(armin), armin->distance(eren));
    }
    //SUBCASE("Printing format"){}
    SUBCASE("Single Shoot result"){
        armin->shoot(eren);
        CHECK_EQ(eren->hitPoints, 100);
    }
    SUBCASE("Death of a cowboy"){
        int counter = 110;
        while(counter > 0){
            armin->shoot(eren);
            if (armin->bulletLeft == 0) armin->reload();
            counter -= 10;
        }
        CHECK_FALSE(eren->isAlive());
    }
    SUBCASE("Shoot and Reload results"){
        eren->shoot(armin);
        CHECK(eren->bulletLeft == 5);
        CHECK(armin->bulletLeft == 6);
        eren->reload();
        CHECK(eren->bulletLeft == 6);
    }
    SUBCASE("Delete correctly"){} 
}
TEST_CASE("Ninja methods test"){
    Point p1(-1,4);
    Point p2(-1,0);
    Point p3(2,0);
    Point p4(-1,6);
    Cowboy *eren = new Cowboy("eren", p4);
    OldNinja *hange = new OldNinja("hange", p1);
    YoungNinja *mikasa = new YoungNinja("mikasa", p3);
    TrainedNinja *levi = new TrainedNinja("levi", p2);    
    SUBCASE("initialize test"){
        CHECK_EQ(hange->getLocation().x, p1.x);
        CHECK_EQ(mikasa->getLocation().x,2);
        CHECK(levi->getLocation().y == 0);
        CHECK(levi->hitPoints == 120);
        CHECK(mikasa->hitPoints == 100);
        CHECK(hange->speed == 8);
    }
    SUBCASE("isAlive return correct"){
        CHECK_FALSE(!hange->isAlive());

    }
    SUBCASE("Distance between fighters"){
        CHECK(hange->distance(mikasa) == 5);
        CHECK(levi->distance(mikasa) == 3);

    }
    //SUBCASE("Printing format"){}
    SUBCASE("Death of a ninja"){
        int counter = 150;
        while(counter > 0){
            eren->shoot(hange);
            if (eren->bulletLeft == 0) eren->reload();
            counter -= 10;
        }
        CHECK_FALSE(hange->isAlive());
    }
    SUBCASE("slash results"){
        CHECK(mikasa->hitPoints == 100);
        levi->slash(mikasa);
        CHECK(mikasa->hitPoints == 60);
    }
    SUBCASE("Delete correctly"){} 

}
TEST_CASE("Team methods"){
    Point p1(1,3);
    Cowboy *eren = new Cowboy("eren", p1);
    Point p2(0,0);
    Point p3(2,3);
    YoungNinja *mikasa = new YoungNinja("mikasa", p3);
    TrainedNinja *levi = new TrainedNinja("levi", p2);
    Team a_team(levi);
    Team titan(eren); 
    SUBCASE("Initialize correctly"){
        //CHECK_EQ(titan.leadman, eren);
        //CHECK_EQ(a_team.leadman, levi);
    }
    SUBCASE("Adding new to the team"){
        CHECK_NOTHROW(a_team.add(mikasa));

    }
    SUBCASE("Adding already a member to team"){
        CHECK_THROWS(titan.add(eren));
        CHECK_THROWS(a_team.add(eren));
    }
    SUBCASE("Attacking valid target"){
        a_team.attack(&titan);
        titan.attack(&a_team);
        CHECK(mikasa->hitPoints == 90);

    }
    SUBCASE("Check members stat"){}
    SUBCASE("Battle end after entire team dead"){}
    SUBCASE("methods non valid after battle ended"){}
    //SUBCASE("Printing format"){}
    SUBCASE("Delete correctly"){} 
}