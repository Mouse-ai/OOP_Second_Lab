#include <iostream>

class Point
{
private:
    int x;
    int y;
protected:
    void protectedMethod()
    {
        std::cout << "Protected Point method" << std::endl;
    }

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
    void testProtected()
    {
        protectedMethod();
    }
    int getZ()
    {
        return z;
    }
    Point3D()
    : Point(), z(0)
    {
        std::cout << "Default constructor Point3D" << std::endl;
    }
    ~Point3D()
    {
        std::cout << "Destructor: x = " << getX() << " y = " << getY()<<" z = " << z << std::endl;
    }
};
class Circle
{
private:
    Point center;
    int radius;

public:
    Circle(int x, int y, int radiusValue)
    : center(x, y), radius(radiusValue)
    {
        std::cout << "Circle constructor" << std::endl;
    }
    void print() {
        std::cout << "Circle" << std::endl;
        center.print();
        std::cout << "radius = " << radius << std::endl;
    }
    ~Circle()
    {
        std::cout << "Circle destructor" << std::endl;
    }
};
class DynamicCircle
{
private:
    Point *center;
    int radius;

public:
    DynamicCircle(int x, int y, int radiusValue)
    : radius(radiusValue)
    {
        center = new Point(x,y);

        std::cout << "DynamicCircle constructor" << std::endl;
    }
    void print() {
        std::cout << "Circle" << std::endl;
        center->print();
        std::cout << "radius = " << radius << std::endl;
    }
    ~DynamicCircle() {
        std::cout << "DynamicCircle destructor" << std::endl;
        delete center;
    }
};
class SimplePointChild : public Point
{
};
int main()
{
    std::cout << "\n=== 1. Point constructors ===" << std::endl;
    {
        Point point1;
        Point point2(10, 20);
        Point point3(point2);

        point1.print();
        point2.print();
        point3.print();
    }


    std::cout << "\n=== 2. Dynamic Point ===" << std::endl;
    {
        Point *point = new Point(30, 40);

        point->print();

        delete point;
    }


    std::cout << "\n=== 3. Child without constructor/destructor ===" << std::endl;
    {
        SimplePointChild child;
        child.print();
    }


    std::cout << "\n=== 4. Inheritance ===" << std::endl;
    {
        Point3D point3D(10, 20, 30);
        Point3D copiedPoint3D(point3D);

        point3D.print();
        copiedPoint3D.print();

        point3D.testProtected();
    }


    std::cout << "\n=== 5. Base pointer to derived object ===" << std::endl;
    {
        Point3D point3D(1, 2, 3);
        Point *basePointer = &point3D;

        point3D.print();
        basePointer->print();

        std::cout << "z = " << point3D.getZ() << std::endl;

        
    }


    std::cout << "\n=== 6. Dynamic derived object ===" << std::endl;
    {
        Point3D *derivedPointer = new Point3D(4, 5, 6);
        Point *basePointer = derivedPointer;

        derivedPointer->print();
        basePointer->print();

        delete derivedPointer;
    }


    std::cout << "\n=== 7. Object slicing ===" << std::endl;
    {
        Point slicedPoint = Point3D(7, 8, 9);

        slicedPoint.print();
    }


    std::cout << "\n=== 8. Object assignment ===" << std::endl;
    {
        Point a(1, 2);
        Point b(50, 60);

        b = a;

        std::cout << "After assignment:" << std::endl;
        a.print();
        b.print();

        a.setX(100);

        std::cout << "After changing a:" << std::endl;
        a.print();
        b.print();
    }


    std::cout << "\n=== 9. Pointer assignment ===" << std::endl;
    {
        Point *p1 = new Point(1, 2);
        Point *p2 = p1;

        p1->setX(100);

        p1->print();
        p2->print();

        delete p1;

        p1 = nullptr;
        p2 = nullptr;
    }


    std::cout << "\n=== 10. Composition with object ===" << std::endl;
    {
        Circle circle(10, 20, 5);

        circle.print();
    }


    std::cout << "\n=== 11. Composition with pointer ===" << std::endl;
    {
        DynamicCircle circle(30, 40, 8);

        circle.print();
    }


    return 0;
}