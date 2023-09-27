#include <iostream>

using std::cout;
using std::endl;

class Point
{
    // step 1: public => private
private:
    Point(int ix, int iy)
        : _ix(ix), _iy(iy) {}

public:
    // step 7 显化默认构造函数
    Point() = default;

    // step 2: &getInstance
    // static Point &getInstance()
    // {
    //     // 思考: 实例化对象为什么需要static
    //     // 思考: 全局访问???
    //     static Point pt(2, 3);
    //     return pt;
    // }

    // step 3 *getInstance
    static Point *getInstance()
    {
        if (_pInstance == nullptr)
        {
            // step 6 若不希望传实参,显化默认构造函数
            // _pInstance = new Point(3, 4);
            _pInstance = new Point();
        }
        return _pInstance;
    }

    void display()
    {
        cout << "(" << _ix << ", " << _iy << ")" << endl;
    }

    // step 8 init
    void init(int ix, int iy)
    {
        _ix = ix;
        _iy = iy;
    }

    // step 9 delete
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

    // step 4 declare
    static Point *_pInstance;
};

// step 5 define
Point *Point::_pInstance = nullptr;

int main()
{
    // Point pt(1, 2);
    // pt.display();

    // Point::getInstance().display();

    // Point::getInstance()->display();

    Point::getInstance()->init(5, 6);
    Point::getInstance()->display();
    Point::getInstance()->init(6, 8);
    Point::getInstance()->display();
    Point::getInstance()->destroy();

    return 0;
}