#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "Factory.hpp" // Include the factory header file

using namespace std;

string getWindowObjectTypeName(IWindowObject* obj) {
    if (dynamic_cast<Button*>(obj)) {
        return "Button";
    } else if (dynamic_cast<TextBox*>(obj)) {
        return "TextBox";
    } else if (dynamic_cast<ListBox*>(obj)) {
        return "ListBox";
    } else {
        return "Unknown";
    }
}

int main() {
    vector<unique_ptr<IWindowObject>> windowObjectCollection; 

    Factory factory; // Create a factory instance

    // Create different window objects using the factory
    windowObjectCollection.push_back(factory.createProduct(WindowObjectType::wot_BUTTON));
    windowObjectCollection.push_back(factory.createProduct(WindowObjectType::wot_TEXTBOX));
    windowObjectCollection.push_back(factory.createProduct(WindowObjectType::wot_LISTBOX));
    //windowObjectCollection.push_back(factory.createProduct(WindowObjectType::wot_UNDEFINED)); // This will throw an exception
    
    // Render all window objects
    for (const auto& woc : windowObjectCollection) {
        woc->render();
        woc->resize(30, 10);
        woc->render();
        woc->onClick();
        cout << "Object type: " << getWindowObjectTypeName(woc.get()) << endl;
    }

    return 0;
}