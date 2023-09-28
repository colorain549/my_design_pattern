// 使用普通函数创建对象

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

/* step 1 */
Rectangle *getRectangle()
{
    Rectangle *pRec = new Rectangle(2, 10);
    return pRec;
}

Circle *getCircle()
{
    Circle *pCir = new Circle(2);
    return pCir;
}

Triangle *getTriangle()
{
    Triangle *pTri = new Triangle(3, 4, 5);
    return pTri;
}

int main()
{
    // Rectangle rec(2, 10);
    // Circle cir(2);
    // Triangle tri(3, 4, 5);

    // rec.display();
    // cir.display();
    // tri.display();

    /* step 1 */
    Rectangle *pRec = getRectangle();
    Circle *pCir = getCircle();
    Triangle *pTri = getTriangle();

    pRec->display();
    pCir->display();
    pTri->display();

    delete pRec;
    delete pCir;
    delete pTri;

    return 0;
}