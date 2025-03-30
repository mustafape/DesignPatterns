#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include "Observer.hpp"

class Subject
{
private: 
    vector<IObserver*> m_observers;

public:
    void Attach(IObserver* o)
    {
        m_observers.push_back(o);
    }

    void Detach(IObserver* o)
    {
        // Remove the observer from the list
        m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), o), m_observers.end());
    }

    void Notify(string message)
    {
        for(auto& observer : m_observers)
        {
            observer->update(message);
        }
    }
};

#endif // SUBJECT_HPP