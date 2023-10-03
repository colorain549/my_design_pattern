/* 记得考虑资源回收的问题 */
#include <iostream>

using std::cout;
using std::endl;
using std::string;

/* 抽象的汽车类 */
class Car
{
public:
    /* 驾驶汽车 */
    virtual void drive() = 0;
};

/* 具体的火车类 */
class Train : public Car
{
public:
    /* 驾驶火车 */
    void drive() override
    {
        cout << "Train drive" << endl;
    }
};

/* 具体的卡车类 */
class Truck : public Car
{
public:
    /* 驾驶卡车 */
    void drive() override
    {
        cout << "Truck drive" << endl;
    }
};

/* 汽车工厂类 */
class CarFactory
{
public:
    static Car *createCar(string type)
    {
        if ("train" == type)
        {
            Train *train = new Train();
            return train;
        }
        else if ("truck" == type)
        {
            Truck *truck = new Truck();
            return truck;
        }
        else
        {
            cout << " Unknown car type " << endl;
            return nullptr;
        }
    }
};

/* Demo类, 用于测试工厂类 */
class CarFactoryDemo
{
public:
    static void test()
    {
        CarFactory *carFactory = new CarFactory();
        Car *train = carFactory->createCar("train");
        train->drive();
        Car *truct = carFactory->createCar("truct");
        truct->drive();
    }
};

/* 函数入口 */
int main()
{
    CarFactoryDemo *carFactoryDemo = new CarFactoryDemo();
    carFactoryDemo->test();

    return 0;
}