#include <iostream>
#include <string>
#include <memory>

// Subject interface
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// RealSubject: Heavy object that loads image from disk
class RealImage : public Image {
private:
    std::string filename;
    void loadFromDisk() {
        std::cout << "Loading image: " << filename << std::endl;
    }
public:
    RealImage(const std::string& filename) : filename(filename) {
        loadFromDisk();
    }
    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }
};

// Proxy: Controls access to RealImage, implements lazy loading
class ProxyImage : public Image {
private:
    std::string filename;
    std::unique_ptr<RealImage> realImage;  // Lazy initialization
public:
    ProxyImage(const std::string& filename) : filename(filename), realImage(nullptr) {}
    void display() override {
        if (!realImage) {
            realImage = std::make_unique<RealImage>(filename);
        }
        realImage->display();
    }
};

// Demo usage
int main() {
    // Create proxy images
    std::unique_ptr<Image> image1 = std::make_unique<ProxyImage>("photo1.jpg");
    std::unique_ptr<Image> image2 = std::make_unique<ProxyImage>("photo2.jpg");

    // Display images - loading happens only here
    image1->display();  // Loads and displays
    std::cout << "---" << std::endl;
    image1->display();  // Already loaded, just displays
    std::cout << "---" << std::endl;
    image2->display();  // Loads and displays

    return 0;
}