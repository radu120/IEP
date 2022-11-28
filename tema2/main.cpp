#include <iostream>

using namespace std;
class Car{
    private:
        string brand;
        string id;
        int numberOfDoors;
        string colour;
    public:
      int price;

    Car (string brand, string id, int numberOfDoors, string colour, int price):
        brand(brand),
        id(id),
        price(price),
        numberOfDoors(numberOfDoors),
        colour(colour)
        {}

    Car(const Car& rhs)  {
        this -> brand = rhs.brand;
        this -> id = rhs.id;
        this -> numberOfDoors = rhs.numberOfDoors;
        this->  colour = rhs.colour;
        this-> price =rhs.price;
    }

    Car& operator=(const Car& rhs) {
        if (this != &rhs){
            this -> brand = rhs.brand;
            this ->id = rhs.id;
            this ->numberOfDoors = rhs.numberOfDoors;
            this-> colour = rhs.colour;
            this-> price =rhs.price;
            }
        return *this;
    }
      Car& operator*=(const Car& rhs) {
        if (this != &rhs){
            this-> price =rhs.price*99.99; // custom price for *=
            this -> brand = rhs.brand;
            this ->id = rhs.id;
            this ->numberOfDoors = rhs.numberOfDoors;
            this-> colour = rhs.colour;
            }
        return *this;
    }
     void showBaseDetails(){
        cout<<" Car -> "<< "brand: "<<this->brand<<", id: "<< this->id <<", price: "<<this->price<<endl;
    }


};

class ElectricCar : public Car{
    private:
    string typeEnginee;
    int power;
    int maxSpeed;

    public:

ElectricCar(string typeEnginee, int power,int maxSpeed,string brand, string id, int numberOfDoors, string colour, int price)
    : Car(brand, id, numberOfDoors, colour, price)
    ,
        typeEnginee(typeEnginee),
        power(power),
        maxSpeed(maxSpeed)
        {}

    public:
     ElectricCar(const ElectricCar& rhs): Car(rhs) {
      this->maxSpeed = rhs.maxSpeed;
      this->power = rhs.power;
      this->typeEnginee = rhs.typeEnginee;
    }

    ElectricCar& operator=(const ElectricCar& rhs) {
        if (this != &rhs){
            Car::operator=(rhs);
            this->typeEnginee = rhs.typeEnginee;
            this->maxSpeed = rhs.maxSpeed;
            this->power = rhs.power;

        }
        else
        cout<<"Same object assignments"<<endl;
        return *this;
    }
    void show(){
        cout<<"Electric car -> "<<"engine: "<<this->typeEnginee<<", power: "<< this->power <<", max speed "<<this->maxSpeed<<endl;
    }
};

int main(){
    Car c1("Peugeot","12fds213adsfA1",5,"black",15000);
    Car c11( "Mazda","IE23adsf",5,"red",35000);
    c1.showBaseDetails();
    Car c2 = c1;
    c2.showBaseDetails();
    Car c3 = c1;
    c3.showBaseDetails();
    c3*=c1;
    ElectricCar ec1("Electric",500, 250, "Tesla","IE23adsf",5,"red",55000);
    ec1.show();
    ec1.Car::showBaseDetails();
    c3.showBaseDetails();
    c1 = c1;
    c1.showBaseDetails();
    ec1= ec1;
    ec1.show();
}
