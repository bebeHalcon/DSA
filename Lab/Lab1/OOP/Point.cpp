#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double x, y;

public:
    Point()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero x-y coordinate
         */
        this -> x = 0;
        this -> y = 0;
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */
        this -> x = x;
        this -> y = y;
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
        this -> x = x;
        //this -> y = 0;
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
        //this -> x = 0;
        this -> y = y;
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
        return this -> x;
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
        return this -> y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
        double  X = x - pointA.x,
                Y = y - pointA.y;
        return sqrt(X*X + Y*Y);
    }
};