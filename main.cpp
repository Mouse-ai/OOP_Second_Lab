#include <iostream>

class Point
{
private:
    int x;
    int y;

public:
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void setX(int value);
    void setY(int value);
    void print();
    Point() {
        x = 0;
        y = 0;
        std::cout << "Default constructor" << std::endl;
    };
    Point(int xValue, int yValue) {
        x = xValue;
        y = yValue;
        std::cout << "Constructor initialization" << std::endl;
    };
    Point(const Point &other) {
        x = other.x;
        y = other.y;
        std::cout << "Copy constructor" << std::endl;
    };
    ~Point() {
        std::cout << "Destructor: x = "<< x << " y = " << y << std::endl;
    };

};
void Point::setX(int value)
{
    x = value;
}
void Point::setY(int value) {
    y = value;
}
void Point::print() {
    std::cout <<"Point: " << "x = " << x << " y = " << y << std::endl;
}

int main()
{
    Point *point = new Point();
    Point *point2 = new Point(10,20);
    Point *point3 = new Point(*point);
    point->print();
    point2->print();
    point3->print();
    delete point;
    delete point2;
    delete point3;
    return 0;
}