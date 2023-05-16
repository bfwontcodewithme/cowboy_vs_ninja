#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

namespace ariel {
    class Point{

        public:

            double x;
            double y;
            Point(double x,double y){
                this->x = x;
                this->y = y;
            }
            Point(){};

            double distance(const Point& other){return 0;};
            void print(){};
            Point moveTowards(){return Point();};

            friend bool operator==(const Point& a, const Point& b);
    };
}
#endif