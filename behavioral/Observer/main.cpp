
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include "Observer.hpp"
#include "Subject.hpp"

using namespace std;

int main(void)
{
    anObserver* observer1 = new anObserver();
    anotherObserver* observer2 = new anotherObserver();
    yetAnotherObserver* observer3 = new yetAnotherObserver();

    Subject* subject = new Subject();

    subject->Attach(observer1);
    subject->Attach(observer2);
    subject->Attach(observer3);
    subject->Notify("Hello, observers!");

    subject->Detach(observer1);
    subject->Notify("Hello again, observers!");  

    subject->Detach(observer2);
    subject->Detach(observer3);
    subject->Notify("Good bye, observers!");  
}