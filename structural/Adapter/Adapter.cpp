#include <string>
#include <iostream>
#include <string>

using namespace std;

typedef struct coordinate {
    int x;
    int y;
} Coordinate;

typedef struct dimensions {
    int width;
    int height;
} Dimensions;

class Rectangle {
public:
    virtual ~Rectangle() = default;
    virtual void render() = 0;
};

class LegacyReactangle {
private:
    int m_top;
    int m_left;  
    int m_bottom;
    int m_right;
public:
    LegacyReactangle(int x1, int y1, int x2, int y2) : m_top(x1), m_left(y1), m_bottom(x2), m_right(y2) {}
    void legacyRender() {
        // Render logic for legacy rectangle
        cout << "Rendering legacy rectangle from (" << m_top << ", " << m_left << ") to (" << m_bottom << ", " << m_right << ")" << endl;
    }
};

class RectangleAdapter : public Rectangle, private LegacyReactangle {    
    public:
    RectangleAdapter(Coordinate topleft, Dimensions sizes) 
                    : LegacyReactangle(topleft.x, topleft.y, topleft.x + sizes.width, topleft.y + sizes.height) {
                        cout << "Rectangle Adapter -> Create Rectangle with TopLeft (" << topleft.x << ", " << topleft.y << ") and Sizes (" << sizes.width << ", " << sizes.height << ")" << endl;
                    }
    void render() override {
        legacyRender();
        cout << "Rectangle Adapter -> Render" << endl;
    }
};

int main() {
    Coordinate topLeft = {1, 1};
    Dimensions size = {10, 5};

    RectangleAdapter* r = new RectangleAdapter(topLeft, size);
    r->render();

    delete r;

    return 0;
}

