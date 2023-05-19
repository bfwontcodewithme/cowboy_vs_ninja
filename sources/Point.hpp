#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
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

            double distance(const Point& other){
                double pow_x = std::pow(this->x - other.x, 2);
                double pow_y = std::pow(this->y - other.y, 2);
                return std::sqrt(pow_x+pow_y);
            }
            void print(){
                std::cout << "(" << x << "," << y << ")" << std::endl;
            };
            static Point moveTowards(Point from, Point toPoint, double distance){
                double from_to = from.distance(toPoint);
                if(from_to <= distance) return toPoint;
                else {  // distance allowed not enough
                    
                }

                return Point();
            }

            friend bool operator==(const Point& a, const Point& b){
                return (a.x == b.x) && (a.y == b.y);
            }
    };
}
#endif