//

#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix, int iy)
        : _ix(ix), _iy(iy) {}

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
    Point pt(1, 2);
    pt.display();

    return 0;
}