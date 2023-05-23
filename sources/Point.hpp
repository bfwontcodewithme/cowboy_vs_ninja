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
            double getX(){return this->x;}
            double getY(){return this->y;}
            std::string print(){
                std::string str;
                str = "(";
                str += this->getX();
                str += ",";
                str += this->getY();
                str= ")";
                return str;
            };
            static Point moveTowards(Point from, Point toPoint, double distance){
                double from_to = from.distance(toPoint);
                if(from_to <= distance) return toPoint;
                if(distance < 0) throw std::invalid_argument("distance can't be negative");
             // distance allowed not enough
                double ratio = distance / from_to;
                double move_x = ((1-ratio)*from.x) +(ratio*toPoint.x);
                double move_y = ((1-ratio)*from.y) +(ratio*toPoint.y);
                return Point(move_x, move_y);
            }

            friend bool operator==(const Point& a, const Point& b){
                return (a.x == b.x) && (a.y == b.y);
            }
    };
}
#endif