#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class Figure
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure
{
public:
    Rectangle(double length, double width)
        : _length(length), _width(width) {}

    void display() const
    {
        cout << "Rectangle::display" << endl;
    }

    double area() const
    {
        return _length * _width;
    }

private:
    double _length;
    double _width;
};

class Circle : public Figure
{
public:
    Circle(double radius)
        : _radius(radius) {}

    void display() const
    {
        cout << "Circle::display" << endl;
    }

    double area() const
    {
        return 3.14 * _radius * _radius;
    }

private:
    double _radius;
};

class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c)
        : _a(a), _b(b), _c(c) {}

    void display() const
    {
        cout << "Triangle::display" << endl;
    }

    double area() const
    {
        double p = (1.0 / 2) * (_a + _b + _c);
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

private:
    double _a;
    double _b;
    double _c;
};

int main()
{
    Rectangle rec(2, 10);
    Circle cir(2);
    Triangle tri(3, 4, 5);

    rec.display();
    cir.display();
    tri.display();

    return 0;
}