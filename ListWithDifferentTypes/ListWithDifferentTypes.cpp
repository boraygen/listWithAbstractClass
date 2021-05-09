#include <iostream>
#include <list>

using namespace std;

class Car   //abstract class
{
public:
    string Model;
    int Year;
    string Brand;

    Car(string model, int year)
    {
        Model = model;
        Year = year;
    }

    virtual void Run() = 0;
};


class Audi : public Car
{
public:
    Audi(string model, int year) : Car(model, year)
    {
        Brand = "Audi";
    }

    void Run()
    {
        cout << "Audi running.";
    }
};


class Honda : public Car
{
public:
    Honda(string model, int year) : Car(model, year)
    {
        Brand = "Honda";
    }

    void Run()
    {
        cout << "Honda running.";
    }
};


int main()
{
    list <Car*> carList;
    carList.push_back(new Audi("A3", 2005));
    carList.push_back(new Honda("City", 2009));

    for (Car*& car : carList)       //foreach loop
    {
        if (car->Year == 2009)
        {
            cout << car->Brand << " " << car->Model << " " << car->Year;
        }
    }
}