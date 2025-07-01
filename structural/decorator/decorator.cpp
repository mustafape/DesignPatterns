#include <iostream>
#include <memory>
#include <string>
constexpr double SIMPLE_COFFEE_COST = 2.0;
constexpr double MILK_COST = 0.5;
constexpr double SUGAR_COST = 0.2;
constexpr double WHIP_COST = 0.7;

// Component
class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffee() = default;
};

// Concrete Component
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }
    double cost() const override {
        return SIMPLE_COFFEE_COST;
    }
};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::unique_ptr<Coffee> c) : coffee(std::move(c)) {}
};

// Concrete Decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}
    std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }
    double cost() const override {
        return coffee->cost() + MILK_COST;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}
    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }
    double cost() const override {
        return coffee->cost() + SUGAR_COST;
    }
};

class WhipDecorator : public CoffeeDecorator {
public:
    WhipDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}
    std::string getDescription() const override {
        return coffee->getDescription() + ", Whip";
    }
    double cost() const override {
        return coffee->cost() + WHIP_COST;
    }
};

// Demo
int main() {
    std::unique_ptr<Coffee> myCoffee = std::make_unique<SimpleCoffee>();
    std::cout << myCoffee->getDescription() << " : $" << myCoffee->cost() << "\n";

    myCoffee = std::make_unique<MilkDecorator>(std::move(myCoffee));
    myCoffee = std::make_unique<SugarDecorator>(std::move(myCoffee));
    myCoffee = std::make_unique<WhipDecorator>(std::move(myCoffee));

    std::cout << myCoffee->getDescription() << " : $" << myCoffee->cost() << "\n";

    // Another variation
    std::unique_ptr<Coffee> anotherCoffee = std::make_unique<WhipDecorator>(
        std::make_unique<MilkDecorator>(
            std::make_unique<SimpleCoffee>()));
    std::cout << anotherCoffee->getDescription() << " : $" << anotherCoffee->cost() << "\n";

    return 0;
}