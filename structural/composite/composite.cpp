#include <iostream>
#include <vector>
#include <memory>

// Component
class Graphic {
public:
    virtual void draw() const = 0;
    virtual ~Graphic() = default;
};

// Leaf
class Circle : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing Square\n";
    }
};

// Composite
class Picture : public Graphic {
    std::vector<std::shared_ptr<Graphic>> children;
public:
    void add(const std::shared_ptr<Graphic>& graphic) {
        children.push_back(graphic);
    }
    void draw() const override {
        std::cout << "Drawing Picture containing:\n";
        for (const auto& child : children)
            child->draw();
    }
};

int main() {
    auto circle1 = std::make_shared<Circle>();
    auto square1 = std::make_shared<Square>();
    auto picture1 = std::make_shared<Picture>();
    picture1->add(circle1);
    picture1->add(square1);

    auto circle2 = std::make_shared<Circle>();
    auto picture2 = std::make_shared<Picture>();
    picture2->add(circle2);
    picture2->add(picture1); // Nested composite

    picture2->draw();
    return 0;
}