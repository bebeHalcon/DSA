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
         x = 0; y = 0;
         
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */this -> x = x, 
            this -> y = y;
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */this -> x = x;
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
         this -> y = y;
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
         return x;
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
         return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: calculate the distance from this point to point A in the coordinate plane
         */
         double X = x - pointA.x,
                Y = y - pointA.y;
         
         return sqrt(X*X + Y*Y);
    }

};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero center's x-y and radius
         */
        //center.setX(0);
        //center.setY(0);
        radius = 0;
    }

    Circle(Point center, double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this -> center.setX(center.getX());
        this -> center.setY(center.getY());
        this -> radius = radius;
    
    }

    Circle(const Circle &circle)
    {
        /*  
         * STUDENT ANSWER
         */
        //center.setX(circle.getCenter().getX());
        //center.setY(circle.getCenter().getY());
        center = circle.getCenter();
        radius = circle.getRadius();
    }
    
    void setCenter(Point point)
    {
        /*  
         * STUDENT ANSWER
         */
        this -> center.setX(point.getX());
        this -> center.setY(point.getY());
    }

    void setRadius(double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this -> radius = radius;
    }

    Point getCenter() const
    {
        /*  
         * STUDENT ANSWER
         */
        return center;
    }

    double getRadius() const
    {
        /*  
         * STUDENT ANSWER
         */
        return radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this -> center.getX(), this -> center.getY(), this -> radius);
    }
};