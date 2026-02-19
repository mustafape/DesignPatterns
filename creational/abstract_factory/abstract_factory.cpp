#include <iostream>
#include <memory>
#include <string>

// Abstract Product
class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual void display() const = 0;
};

// Concrete Products
class Car : public Vehicle {
public:
    void display() const override {
        std::cout << "This is a Car\n";
    }
};

class Motorcycle : public Vehicle {
public:
    void display() const override {
        std::cout << "This is a Motorcycle\n";
    }
};

class Truck : public Vehicle {
public:
    void display() const override {
        std::cout << "This is a Truck\n";
    }
};

// Abstract Factory
class VehicleFactory {
public:
    virtual ~VehicleFactory() = default;
    virtual std::unique_ptr<Vehicle> createVehicle() = 0;
};

// Concrete Factories
class CarFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> createVehicle() override {
        return std::make_unique<Car>();
    }
};

class MotorcycleFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> createVehicle() override {
        return std::make_unique<Motorcycle>();
    }
};

class TruckFactory : public VehicleFactory {
public:
    std::unique_ptr<Vehicle> createVehicle() override {
        return std::make_unique<Truck>();
    }
};

// Main
int main() {
    std::unique_ptr<VehicleFactory> factory;
    
    factory = std::make_unique<CarFactory>();
    auto vehicle1 = factory->createVehicle();
    vehicle1->display();
    
    factory = std::make_unique<MotorcycleFactory>();
    auto vehicle2 = factory->createVehicle();
    vehicle2->display();
    
    factory = std::make_unique<TruckFactory>();
    auto vehicle3 = factory->createVehicle();
    vehicle3->display();
    
    return 0;
}