// 使用普通函数创建对象
// 将普通函数封装到类Factory中
// 再抽象
// 使用智能指针

#include <iostream>
#include <math.h>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

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
// Rectangle *getRectangle()
// {
//     Rectangle *pRec = new Rectangle(2, 10);
//     return pRec;
// }

// Circle *getCircle()
// {
//     Circle *pCir = new Circle(2);
//     return pCir;
// }

// Triangle *getTriangle()
// {
//     Triangle *pTri = new Triangle(3, 4, 5);
//     return pTri;
// }

/* step 2 */
// class Factory
// {
// public:
//     static Rectangle *getRectangle()
//     {
//         Rectangle *pRec = new Rectangle(2, 10);
//         return pRec;
//     }

//     static Circle *getCircle()
//     {
//         Circle *pCir = new Circle(2);
//         return pCir;
//     }

//     static Triangle *getTriangle()
//     {
//         Triangle *pTri = new Triangle(3, 4, 5);
//         return pTri;
//     }
// };

/* step 3 */
// class Factory
// {
// public:
//     static Figure *getRectangle()
//     {
//         Rectangle *pRec = new Rectangle(2, 10);
//         return pRec;
//     }

//     static Figure *getCircle()
//     {
//         Circle *pCir = new Circle(2);
//         return pCir;
//     }

//     static Figure *getTriangle()
//     {
//         Triangle *pTri = new Triangle(3, 4, 5);
//         return pTri;
//     }
// };

/* step 4 */
class Factory
{
public:
    static Figure *getRectangle()
    {
        Rectangle *pRec = new Rectangle(2, 10);
        return pRec;
    }

    static Figure *getCircle()
    {
        Circle *pCir = new Circle(2);
        return pCir;
    }

    static Figure *getTriangle()
    {
        Triangle *pTri = new Triangle(3, 4, 5);
        return pTri;
    }
};

int main()
{
    // Rectangle rec(2, 10);
    // Circle cir(2);
    // Triangle tri(3, 4, 5);

    // rec.display();
    // cir.display();
    // tri.display();

    /* step 1 */
    // Rectangle *pRec = getRectangle();
    // Circle *pCir = getCircle();
    // Triangle *pTri = getTriangle();

    // pRec->display();
    // pCir->display();
    // pTri->display();

    // delete pRec;
    // delete pCir;
    // delete pTri;

    /* step 2 */
    // Rectangle *pRec = Factory::getRectangle();
    // Circle *pCir = Factory::getCircle();
    // Triangle *pTri = Factory::getTriangle();

    // pRec->display();
    // pCir->display();
    // pTri->display();

    // delete pRec;
    // delete pCir;
    // delete pTri;

    /* step 3 */
    // Figure *pRec = Factory::getRectangle();
    // Figure *pCir = Factory::getCircle();
    // Figure *pTri = Factory::getTriangle();

    // pRec->display();
    // pCir->display();
    // pTri->display();

    // delete pRec;
    // delete pCir;
    // delete pTri;

    /* step 4 */
    unique_ptr<Figure> pRec(Factory::getRectangle());
    unique_ptr<Figure> pCir(Factory::getCircle());
    unique_ptr<Figure> pTri(Factory::getTriangle());

    pRec->display();
    pCir->display();
    pTri->display();

    return 0;
}