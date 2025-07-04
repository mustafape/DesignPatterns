#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// Forward declarations
class Circle;
class Rectangle;

// Visitor Interface
class Visitor {
public:
    virtual void Visit(Circle& circle) = 0;
    virtual void Visit(Rectangle& rectangle) = 0;
    virtual ~Visitor() = default;
};

// Element Interface
class Shape {
public:
    virtual void Accept(Visitor& visitor) = 0;
    virtual ~Shape() = default;
};

// Concrete Elements
class Circle : public Shape {
private:
    double m_radius;
public:
    Circle(double r) : m_radius(r) {}
    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
    double GetRadius() const { return m_radius; }
};

class Rectangle : public Shape {
private:
    double m_width, m_height;
public:
    Rectangle(double w, double h) : m_width(w), m_height(h) {}
    void Accept(Visitor& visitor) override {
        visitor.Visit(*this);
    }
    double GetWidth() const { return m_width; }
    double GetHeight() const { return m_height; }
};

// Concrete Visitor
class AreaVisitor : public Visitor {
public:
    void Visit(Circle& circle) override {
        double area = M_PI * circle.GetRadius() * circle.GetRadius();
        std::cout << "Circle area: " << area << std::endl;
    }
    void Visit(Rectangle& rectangle) override {
        double area = rectangle.GetWidth() * rectangle.GetHeight();
        std::cout << "Rectangle area: " << area << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));

    AreaVisitor areaVisitor;
    for (auto& shape : shapes) {
        shape->Accept(areaVisitor);
    }
    return 0;
}
