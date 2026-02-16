#include <iostream>
#include <memory>

// Implementation Interface
class DrawingAPI {
public:
    virtual ~DrawingAPI() = default;
    virtual void drawCircle(double x, double y, double radius) = 0;
};

// Concrete Implementations
class DrawingAPI1 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API1.circle at " << x << ":" << y << " radius " << radius << std::endl;
    }
};

class DrawingAPI2 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) override {
        std::cout << "API2.circle at " << x << ":" << y << " radius " << radius << std::endl;
    }
};

// Abstraction
class Shape {
protected:
    std::unique_ptr<DrawingAPI> impl;
public:
    explicit Shape(std::unique_ptr<DrawingAPI> api) : impl(std::move(api)) {}
    virtual ~Shape() = default;
    virtual void draw() = 0;
};

// Refined Abstraction
class Circle : public Shape {
    double x, y, radius;
public:
    Circle(double x, double y, double radius, std::unique_ptr<DrawingAPI> api)
        : Shape(std::move(api)), x(x), y(y), radius(radius) {}
    
    void draw() override {
        impl->drawCircle(x, y, radius);
    }
};

// Usage
int main() {
    Circle c1(1, 2, 3, std::make_unique<DrawingAPI1>());
    Circle c2(4, 5, 6, std::make_unique<DrawingAPI2>());
    
    c1.draw();
    c2.draw();
    
    return 0;
}