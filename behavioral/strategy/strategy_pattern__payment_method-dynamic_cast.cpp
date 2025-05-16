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
    void printCashPaymentAdvantages() {
        std::cout << "Advantages of Cash Payment: No transaction fees, immediate settlement." << std::endl;
    }
};

class CreditCardPayment : public PaymentStrategy {
public:
    void execute(double amount) override {
        std::cout << "Processing Credit Card payment of $" << amount << std::endl;
    }
    void printCreditCardPaymentAdvantages() {
        std::cout << "Advantages of Credit Card Payment: Rewards points, fraud protection." << std::endl;
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void execute(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
    void printPayPalPaymentAdvantages() {
        std::cout << "Advantages of PayPal Payment: Buyer protection, easy to use." << std::endl;
    }
};

class BitcoinPayment : public PaymentStrategy {
public:
    void execute(double amount) override {
        std::cout << "Processing Bitcoin payment of $" << amount << std::endl;
    }
    void printBitcoinPaymentAdvantages() {
        std::cout << "Advantages of Bitcoin Payment: Low transaction fees, decentralized." << std::endl;
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

        PaymentStrategy* getStrategy() const {
            return m_strategy.get();
        }
    
        void executeStrategy(double amount) const {
            if (m_strategy) {
                m_strategy->execute(amount);
            } else {
                std::cout << "No strategy set" << std::endl;
            }
        }
};

void printPaymentAdvantages(PaymentStrategy* strategy) {
    if (CashPayment* cp = dynamic_cast<CashPayment*>(strategy)) {
        cp->printCashPaymentAdvantages();
    } else if (CreditCardPayment* ccp = dynamic_cast<CreditCardPayment*>(strategy)) {
        ccp->printCreditCardPaymentAdvantages();
    } else if (PayPalPayment* pp = dynamic_cast<PayPalPayment*>(strategy)) {
        pp->printPayPalPaymentAdvantages();
    } else if (BitcoinPayment* bp = dynamic_cast<BitcoinPayment*>(strategy)) {
        bp->printBitcoinPaymentAdvantages();
    } else {
        std::cout << "Unknown payment strategy." << std::endl;
    }
}

int main() {

    PaymentContext paymentContext;
    PaymentStrategy* strategy = nullptr;

    paymentContext.setStrategy(std::make_unique<CashPayment>());
    paymentContext.executeStrategy(100.0);

    strategy = paymentContext.getStrategy();   // Demonstrate dynamic_cast
    printPaymentAdvantages(strategy);   


    paymentContext.setStrategy(std::make_unique<CreditCardPayment>());
    paymentContext.executeStrategy(200.0);

    strategy = paymentContext.getStrategy();   // Demonstrate dynamic_cast
    printPaymentAdvantages(strategy);   


    paymentContext.setStrategy(std::make_unique<PayPalPayment>());
    paymentContext.executeStrategy(300.0);

    strategy = paymentContext.getStrategy();   // Demonstrate dynamic_cast
    printPaymentAdvantages(strategy);   

    
    paymentContext.setStrategy(std::make_unique<BitcoinPayment>());
    paymentContext.executeStrategy(400.0);

    strategy = paymentContext.getStrategy();   // Demonstrate dynamic_cast
    printPaymentAdvantages(strategy);   

    return 0;
}