
#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>
#include <string>
#include <stdexcept>
#include <map>
#include <functional>
#include "WindowObject.hpp" // Include the header file for IWindowObject and its derived classes

using namespace std;

// Enum for WindowObject types
enum class WindowObjectType { wot_BUTTON, wot_TEXTBOX, wot_LISTBOX, wot_UNDEFINED };

// Factory Class
class Factory {
    // Map to associate WindowObjectType with corresponding create methods
    map<WindowObjectType, function<unique_ptr<IWindowObject>()>> windowObjectCreators = {
    {WindowObjectType::wot_BUTTON, []() { return make_unique<Button>(); }},
    {WindowObjectType::wot_TEXTBOX, []() { return make_unique<TextBox>(); }},
    {WindowObjectType::wot_LISTBOX, []() { return make_unique<ListBox>(); }}
    };

public:
    std::unique_ptr<IWindowObject> createProduct(const WindowObjectType& o) {
        if(windowObjectCreators.find(o) != windowObjectCreators.end()) {
            return  windowObjectCreators[o]();
        }
        else {
            throw std::invalid_argument("Unknown product type");
        }
    }
};

#endif // FACTORY_HPP