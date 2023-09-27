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
    // static Point &getInstance()
    // {
    //     static Point pt(2, 3);
    //     return pt;
    // }

    // step 3: *getInstance
    static Point *getInstance()
    {
        if (_pInstance)
        {
            // goto step 4
            if (_pInstance)
            {
                _pInstance = new Point(3, 4);
            }
            return _pInstance;
        }
    }

    void display()
    {
        cout << "(" << _ix << ", " << _iy << ")" << endl;
    }

    // step 6 delete
    void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

private:
    int _ix;
    int _iy;

    // step 4
    static Point *_pInstance;
};

// step 5
Point *Point::_pInstance = nullptr;

int main()
{
    // Point pt(1, 2);
    // pt.display();

    // Point::getInstance().display();

    Point::getInstance()->display();
    Point::getInstance()->destroy();

    return 0;
}