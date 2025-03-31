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
private:
    int m_width;
    int m_height;
public:
    // Constructor
    Button(int width=10, int height=5) : m_width(width), m_height(height) { }

    // Override the render method
    void render() const override {
        // Code to render the button
        cout << "Rendering a button of size " << m_width << "x" << m_height << endl;
    }

    // Override the resize method
    void resize(int width, int height) override {
        m_width = width;
        m_height = height;
        cout << "Resized button to " << m_width << "x" << m_height << endl;
    }

    // Override the onClick method
    void onClick() const override { cout << "Button clicked!" << endl; }
};

// This class represents a TextBox, derived from the IWindowObject interface.
class TextBox : public IWindowObject {
private:
    int m_width;
    int m_height;
    string m_text;
public:
    // Constructor
    TextBox(int width=10, int height=5, const string& text="TextBox")
        : m_width(width), m_height(height), m_text(text) {}

    // Override the render method
    void render() const override {
        // Code to render the text box
        cout << "Rendering a text box of size " << m_width << "x" << m_height
                  << " with text: \"" << m_text << "\"" << endl;
    }

    // Override the resize method
    void resize(int width, int height) override {
        m_width = width;
        m_height = height;
        cout << "Resized text box to " << m_width << "x" << m_height << endl;
    }

    // Override the onClick method
    void onClick() const override { cout << "TextBox clicked!" << endl; }

    // Method to set the text of the text box
    void setText(const string& text) {
        m_text = text;
        cout << "TextBox text set to: \"" << m_text << "\"" << endl;
    }

    // Method to get the text of the text box
    string getText() const { return m_text; }
};

// This class represents a ListBox, derived from the IWindowObject interface.
class ListBox : public IWindowObject {
private:
    int m_width;
    int m_height;
    vector<string> m_items;
public:
    // Constructor
    ListBox(int width=10, int height=5)
        : m_width(width), m_height(height) {}

    // Override the render method
    void render() const override {
        // Code to render the list box
        cout << "Rendering a list box of size " << m_width << "x" << m_height << " with no items:" << endl;
    }

    // Override the resize method
    void resize(int width, int height) override {
        m_width = width;
        m_height = height;
        cout << "Resized list box to " << m_width << "x" << m_height << endl;
    }

    // Override the onClick method
    void onClick() const override { cout << "ListBox clicked!" << endl; }

    // Method to add an item to the list box
    void addItem(const string& item) {
        m_items.push_back(item);
        cout << "Added item to ListBox: \"" << item << "\"" << endl;
    }

    // Method to remove an item from the list box
    void removeItem(const string& item) {
        auto it = find(m_items.begin(), m_items.end(), item);
        if (it != m_items.end()) {
            m_items.erase(it);
            cout << "Removed item from ListBox: \"" << item << "\"" << endl;
        } else {
            cout << "Item not found in ListBox: \"" << item << "\"" << endl;
        }
    }

    // Method to get all items in the list box
    vector<string> getItems() const {
        return m_items;
    }
};
#endif // WINDOWOBJECT_HPP