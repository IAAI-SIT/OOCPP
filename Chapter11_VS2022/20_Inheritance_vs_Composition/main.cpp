#include <iostream>
using namespace std;

class Vehicle
{
public:
    void move() const { cout << "vehicle moves" << endl; }
};

class Engine
{
public:
    void start() const { cout << "engine starts" << endl; }
};

class Car : public Vehicle       // Car is-a Vehicle
{
private:
    Engine engine;               // Car has-an Engine

public:
    void start()
    {
        engine.start();
    }
};

int main()
{
    Car car;
    car.move();
    car.start();

#if 0
    // 不推荐的设计：Engine通常不是Vehicle
    class BadEngine : public Vehicle {};
#endif
    return 0;
}
