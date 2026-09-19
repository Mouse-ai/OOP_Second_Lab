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


class Point3D : public Point
{
private:
    int z;

public:
    Point3D(int xValue, int yValue, int zValue) : Point(xValue,yValue), z(zValue) {
        std::cout << "Constructor initialization Point3D" << std::endl;

    }
    Point3D(const Point3D &other):Point(other), z(other.z) {
        std::cout << "Copy constructor Point3D" << std::endl;
    }
    void print()
    {
        Point::print();
        std::cout << " z = " << z << std::endl;
    }
    ~Point3D()
    {
        std::cout << "Destructor: x = " << getX() << " y = " << getY()<<" z = " << z << std::endl;
    }
};

int main()
{
    Point *point = new Point();
    Point *point2 = new Point(10,20);
    Point *point3 = new Point(*point);
    {
        Point staticPoint(5, 7);
        staticPoint.print();
    }
    point->print();
    point2->print();
    point3->print();
    delete point;
    delete point2;
    delete point3;

    Point3D point3D(10, 20, 30);
    point3D.print();
    Point3D *point3D2 = new Point3D(point3D);
    point3D2->print();
    delete point3D2;
    return 0;
}