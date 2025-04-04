#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <memory>
#include <map>
#include <functional>
#include <stdexcept>
#include "WindowObject.hpp" // Include the header file for IWindowObject and its derived classes

using namespace std;

// Enum for WindowObject types
enum class WindowObjectType { wot_BUTTON, wot_TEXTBOX, wot_LISTBOX, wot_UNDEFINED };

// Factory Class
class Factory {
private:
    // Map to associate WindowObjectType with corresponding create methods
    map<WindowObjectType, function<unique_ptr<IWindowObject>()>> m_windowObjectCreators = {
    {WindowObjectType::wot_BUTTON,  []() { return make_unique<Button>(); }},
    {WindowObjectType::wot_TEXTBOX, []() { return make_unique<TextBox>(); }},
    {WindowObjectType::wot_LISTBOX, []() { return make_unique<ListBox>(); }}
    };

    bool isValidType(const WindowObjectType& o) {
        return m_windowObjectCreators.find(o) != m_windowObjectCreators.end();
    }
public:
    unique_ptr<IWindowObject> createProduct(const WindowObjectType& o) {
        if(isValidType(o)) {
            return  m_windowObjectCreators[o]();
        }
        else {
            throw invalid_argument("Unknown product type");
        }
    }
};

#endif // FACTORY_HPP