#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
    Computer(char *brand, double price)
        : _brand(new char[strlen(brand) + 1]()), _price(price)
    {
        strcpy(_brand, brand);
    }

    ~Computer()
    {
        if (_brand)
        {
            delete _brand;
            _brand = nullptr;
        }
    }

    void display()
    {
        cout << _brand << ": " << _price << endl;
    }

private:
    char *_brand;
    double _price;
};

int main()
{
    Computer pc("VAIO", 9999);
    pc.display();

    return 0;
}
