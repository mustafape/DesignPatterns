#ifndef WINDOWOBJECT_HPP
#define WINDOWOBJECT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// This header file defines the IWindowObject interface for window objects in a GUI application.
class IWindowObject {
public:
    virtual ~IWindowObject() = default;

    // Pure virtual method to render the window
    virtual void render() const = 0;

    // Pure virtual method to resize the window
    virtual void resize(int width, int height) = 0;

    // Pure virtual method to handle click events
    virtual void onClick() const = 0;
};

// This class represents a Button, derived from the IWindowObject interface.
class Button : public IWindowObject {
public:
    // Constructor
    Button(int width=10, int height=5) : width_(width), height_(height) { }

    // Override the render method
    void render() const override {
        // Code to render the button
        cout << "Rendering a button of size " << width_ << "x" << height_ << endl;
    }

    // Override the resize method
    void resize(int width, int height) override {
        width_ = width;
        height_ = height;
        cout << "Resized button to " << width_ << "x" << height_ << endl;
    }

    // Override the onClick method
    void onClick() const override { cout << "Button clicked!" << endl; }

private:
    int width_;
    int height_;
};

// This class represents a TextBox, derived from the IWindowObject interface.
class TextBox : public IWindowObject {
public:
    // Constructor
    TextBox(int width=10, int height=5, const string& text="TextBox")
        : width_(width), height_(height), text_(text) {}

    // Override the render method
    void render() const override {
        // Code to render the text box
        cout << "Rendering a text box of size " << width_ << "x" << height_
                  << " with text: \"" << text_ << "\"" << endl;
    }

    // Override the resize method
    void resize(int width, int height) override {
        width_ = width;
        height_ = height;
        cout << "Resized text box to " << width_ << "x" << height_ << endl;
    }

    // Override the onClick method
    void onClick() const override { cout << "TextBox clicked!" << endl; }

    // Method to set the text of the text box
    void setText(const string& text) {
        text_ = text;
        cout << "TextBox text set to: \"" << text_ << "\"" << endl;
    }

    // Method to get the text of the text box
    string getText() const { return text_; }

private:
    int width_;
    int height_;
    string text_;
};

// This class represents a ListBox, derived from the IWindowObject interface.
class ListBox : public IWindowObject {
public:
    // Constructor
    ListBox(int width=10, int height=5)
        : width_(width), height_(height) {}

    // Override the render method
    void render() const override {
        // Code to render the list box
        cout << "Rendering a list box of size " << width_ << "x" << height_ << " with no items:" << endl;
    }

    // Override the resize method
    void resize(int width, int height) override {
        width_ = width;
        height_ = height;
        cout << "Resized list box to " << width_ << "x" << height_ << endl;
    }

    // Override the onClick method
    void onClick() const override { cout << "ListBox clicked!" << endl; }

    // Method to add an item to the list box
    void addItem(const string& item) {
        items_.push_back(item);
        cout << "Added item to ListBox: \"" << item << "\"" << endl;
    }

    // Method to remove an item from the list box
    void removeItem(const string& item) {
        auto it = find(items_.begin(), items_.end(), item);
        if (it != items_.end()) {
            items_.erase(it);
            cout << "Removed item from ListBox: \"" << item << "\"" << endl;
        } else {
            cout << "Item not found in ListBox: \"" << item << "\"" << endl;
        }
    }

    // Method to get all items in the list box
    vector<string> getItems() const {
        return items_;
    }

private:
    int width_;
    int height_;
    vector<string> items_;
};
#endif // WINDOWOBJECT_HPP