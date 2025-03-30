#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>

using namespace std;

class IObserver {
public:
    virtual ~IObserver() = default; // Virtual destructor for proper cleanup of derived classes
    virtual void update(string message) = 0;
};

class anObserver : public IObserver {
public:    
    void update(string message) override {
        cout << "Observer received message: " << message << endl;
    }
};

class anotherObserver : public IObserver {
    public:    
        void update(string message) override {
            cout << "Another Observer received message: " << message << endl;
        }
    };

class yetAnotherObserver : public IObserver {
public:    
    void update(string message) override {
        cout << "Yet Another Observer received message: " << message << endl;
    }
};

#endif // OBSERVER_H