#include <iostream>

using namespace std;

//item 4 : make sure that all constructors initialize everything in object
class Engine{
    public:
        string brand;
    //item 5
        Engine (string brand, string id): //default constructor
        brand(brand),
        id(id) {}

    void toString()
    {
        cout<<"Engine brand => "<<this->brand<<endl;
        cout<<"Id => "<<this->id<<endl;
    }
     Engine(const Engine& e)//copy constructor
     {
        this -> brand = e.brand;
        this -> id = e.id;
     }
    Engine& operator=(const Engine& e)////assigment operator
    {
        if (this != &e)
            {
            this -> brand = e.brand;
            this ->id = e.id;
            }
        return *this;
    }
    ~Engine()
    {
        cout<<"Destructor for engine"<<endl;
    }
    string getId()
    {
        return this->id;
    }
    private :
    string id;
};

class Car
{
private:
    string producer;
    string id;
    Engine* engine;
public:
    string brand;
    string colour;
    int numberOfSeats;
    Car(string producer, string id, string brand, string colour, int numberOfSeats, Engine *engine):
        producer(producer),
        id(id),
        brand(brand),
        colour(colour),
        numberOfSeats(numberOfSeats),
        engine(engine)
        {}
     Car(const Car& e)
     {
        this->colour = e.colour;
        this->brand = e.brand;
        this->producer = e.producer;
        this->numberOfSeats = e.numberOfSeats;
        this->engine = e.engine;
     }

    Car& operator=(const Car& e)
    {
        if (this != &e)
            {
            this->colour = e.colour;
            this->brand = e.brand;
            this->producer = e.producer;
            this->numberOfSeats = e.numberOfSeats;
            this->engine = e.engine;
            }
        return *this;
    }

    void showAttributes()
    {
        cout<<"Brand: "<<brand<<", number of seats: "<<numberOfSeats<<", colour "<<colour<<" ";
        this->engine->toString();
    }

    void toString()
    {
        cout<<brand<<" " << numberOfSeats<<" "<<colour<<endl;
    }

};

class DollarBill
{
    public:
        string id;
        int  value;
        DollarBill(string id, int value):
            id(id),
            value(value)
        {}

         void toString()
    {
        cout<<id<<" "<<value<<endl;
    }

    //item 6
    private:
    DollarBill(const DollarBill&);// DollarBill d1(d2);
    DollarBill operator=(const DollarBill&);//DollarBill d1 = d2;

};

int main()
{
    Engine w1("Mercedes","SH77BSJBJS");
    Car b1("GLE Coupe","BS7SFB","Mercedes","blue",5,&w1);
    b1.showAttributes();
    Car b2 = b1;
    Car b5(b1);
    b5.showAttributes();
    b2.showAttributes();
    DollarBill d1("123412",20);
    d1.toString();
    return 0;
}
