#include <iostream>
#include <string>
using namespace std;
class SportCar
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    SportCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = 0;
        currentSpeed = 0;
        currentGear = 0;
    }
    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : engine starts with a roar!" << endl;
    }
    void shiftGear(int gear)
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " engine is off: cannot shift gear.." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : shifted to gear" << currentGear << endl;
    }
    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " engine is off: cannot shift gear.." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " :accelerating to" << currentSpeed << "km/h" << endl;
    }
    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << " : breaking ! speed is low" << currentSpeed << endl;
    }
    void stopEngine()
    {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << ": engine turned off..." << endl;
    }
    ~SportCar() {}
};

int main()
{
    SportCar *mysportcar = new SportCar("FORD", "MUSTANG");
    mysportcar->startEngine();
    mysportcar->shiftGear(1);
    mysportcar->accelerate();
    mysportcar->brake();
    mysportcar->stopEngine();
}