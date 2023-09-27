#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer
{
    // step 1: public => private
    // public:
private:
    Computer(char *brand, double price)
        : _brand(new char[strlen(brand) + 1]()), _price(price)
    {
        strcpy(_brand, brand);
    }

public:
    // step 5 显化默认构造函数
    Computer() = default;

    // step 2: *getInstance
    static Computer *getInstance()
    {
        // goto step 3
        if (_pInstance == nullptr)
        {
            // goto step 5 显化默认构造函数
            _pInstance = new Computer();
        }
        return _pInstance;
    }

    void display()
    {
        cout << _brand << ": " << _price << endl;
    }

    // step 6 init
    void init(char *brand, double price)
    {
        if (_brand)
        {
            delete _brand;
            _brand = nullptr;
        }
        _brand = new char[strlen(brand) + 1]();
        strcpy(_brand, brand);
        _price = price;
    }

    // step 7 destroy
    void destroy()
    {
        // !!! notice: delete _pInstance
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    ~Computer()
    {
        // !!! notice: delete[] _brand
        if (_brand)
        {
            delete[] _brand;
            _brand = nullptr;
        }
    }

private:
    char *_brand;
    double _price;

    // step 3 declare
    static Computer *_pInstance;
};

// step 4 define
Computer *Computer::_pInstance = nullptr;

int main()
{
    // Computer pc("Apple", 9299);
    // pc.display();

    Computer::getInstance()->init("VAIO", 9999);
    Computer::getInstance()->display();
    Computer::getInstance()->init("Apple", 9299);
    Computer::getInstance()->display();
    Computer::getInstance()->destroy();

    return 0;
}
