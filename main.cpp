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
    Point *basePointer = &point3D;

    std::cout << "Point3D object:" << std::endl;
    point3D.print();

    std::cout << "Point pointer:" << std::endl;
    basePointer->print();
    Point3D *point3D2 = new Point3D(point3D);
    Point *dynamicBasePointer = point3D2;
    point3D2->print();
    std::cout << "dinamicBasePointer:" << std::endl;
    dynamicBasePointer->print();
    Point slicedPoint = point3D;
    slicedPoint.print();
    delete point3D2;



    Point a(1, 2);
    Point b(50, 60);

    b = a;

    std::cout << "a:" << std::endl;
    a.print();

    std::cout << "b:" << std::endl;
    b.print();
    a.setX(100);

    a.print();
    b.print();


    Point *p1 = new Point(1, 2);
    Point *p2 = p1;

    p1->print();
    p2->print();

    p1->setX(100);

    p1->print();
    p2->print();
    delete p1;
    p1 = nullptr;
    p2 = nullptr;
    return 0;
}