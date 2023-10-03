/* 记得考虑资源回收的问题 */
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

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
    virtual Car *createCar() = 0;
};
class TrainFactory : public CarFactory
{
public:
    Car *createCar() override
    {
        Train *train = new Train();
        return train;
    }
};
class TruckFactory : public CarFactory
{
    Car *createCar() override
    {
        Truck *truck = new Truck();
        return truck;
    }
};

/* Demo类, 用于测试工厂类 */
class CarFactoryDemo
{
public:
    void test()
    {
        unique_ptr<CarFactory> pTrainFactory(new TrainFactory());
        unique_ptr<Car> pTrain(pTrainFactory->createCar());

        unique_ptr<CarFactory> pTruckFactory(new TruckFactory());
        unique_ptr<Car> pTruck(pTruckFactory->createCar());

        pTrain->drive();
        pTruck->drive();
    }
};

/* 函数入口 */
int main()
{
    CarFactoryDemo *carFactory = new CarFactoryDemo();
    carFactory->test();

    return 0;
}