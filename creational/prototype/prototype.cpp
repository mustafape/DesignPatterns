#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

// Prototype interface
class Shape {
public:
    virtual ~Shape() = default;
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

// Concrete Prototype: Circle
class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }
    void draw() const override {
        std::cout << "Drawing Circle with radius: " << radius << std::endl;
    }
};

// Concrete Prototype: Rectangle
class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }
    void draw() const override {
        std::cout << "Drawing Rectangle with width: " << width << ", height: " << height << std::endl;
    }
};

// Prototype Factory
class ShapeFactory {
    std::unordered_map<std::string, std::unique_ptr<Shape>> prototypes;
public:
    ShapeFactory() {
        prototypes["Circle"] = std::make_unique<Circle>(10);
        prototypes["Rectangle"] = std::make_unique<Rectangle>(20, 30);
    }
    std::unique_ptr<Shape> create(const std::string& type) {
        if (prototypes.find(type) != prototypes.end()) {
            return prototypes[type]->clone();
        }
        return nullptr;
    }
};

int main() {
    ShapeFactory factory;

    auto shape1 = factory.create("Circle");
    auto shape2 = factory.create("Rectangle");

    if (shape1) shape1->draw();
    if (shape2) shape2->draw();

    // Clone and demo
    auto shape3 = shape1->clone();
    if (shape3) shape3->draw();

    return 0;
}