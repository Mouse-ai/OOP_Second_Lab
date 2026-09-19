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
    Point point;
    point.setX(10);
    point.setY(20);
    point.print();
    std::cout << point.getX() << std::endl;
    std::cout << point.getY() << std::endl;

    return 0;
}