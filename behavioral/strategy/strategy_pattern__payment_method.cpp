#include <iostream>
#include <memory>
#include <string>

// Strategy Interface
class PaymentStrategy {
public:
    virtual void execute(double amount) = 0; // Pure virtual function
    virtual ~PaymentStrategy() {} // Virtual destructor
};

class CashPayment : public PaymentStrategy {
public:
    void execute(double amount) override {
        std::cout << "Processing Cash payment of $" << amount << std::endl;
    }
};

class CreditCardPayment : public PaymentStrategy {
public:
    void execute(double amount) override {
        std::cout << "Processing Credit Card payment of $" << amount << std::endl;
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void execute(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
};

class BitcoinPayment : public PaymentStrategy {
public:
    void execute(double amount) override {
        std::cout << "Processing Bitcoin payment of $" << amount << std::endl;
    }
};

// Context Class
class PaymentContext {
    private:
        std::unique_ptr<PaymentStrategy> m_strategy;
    
    public:
        void setStrategy(std::unique_ptr<PaymentStrategy> newStrategy) {
            m_strategy = std::move(newStrategy);
        }
    
        void executeStrategy(double amount) const {
            if (m_strategy) {
                m_strategy->execute(amount);
            } else {
                std::cout << "No strategy set" << std::endl;
            }
        }
};
    
int main() {

    PaymentContext paymentContext;

    paymentContext.setStrategy(std::make_unique<CashPayment>());
    paymentContext.executeStrategy(100.0);

    paymentContext.setStrategy(std::make_unique<CreditCardPayment>());
    paymentContext.executeStrategy(200.0);

    paymentContext.setStrategy(std::make_unique<PayPalPayment>());
    paymentContext.executeStrategy(300.0);

    paymentContext.setStrategy(std::make_unique<BitcoinPayment>());
    paymentContext.executeStrategy(400.0);

    return 0;
}