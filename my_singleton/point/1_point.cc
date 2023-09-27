#include <iostream>

using std::cout;
using std::endl;

class Point
{
    // step 1: public => private
    // public:
private:
    Point(int ix, int iy)
        : _ix(ix), _iy(iy) {}

public:
    // step 2: &getInstance
    static Point &getInstance()
    {
        static Point pt(2, 3);
        return pt;
    }

    void display()
    {
        cout << "(" << _ix << ", " << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

int main()
{
    // Point pt(1, 2);
    // pt.display();

    Point::getInstance().display();

    return 0;
}