#include <iostream>
#include <memory>
#include <string>

// Abstract Handler
class Handler {
protected:
    std::shared_ptr<Handler> nextHandler;

public:
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> handler) {
        nextHandler = handler;
    }

    virtual void handle(const std::string& request) = 0;
};

// Concrete Handlers
class AuthenticationHandler : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "auth") {
            std::cout << "AuthenticationHandler: Processing authentication\n";
            if (nextHandler) nextHandler->handle(request);
        } else if (nextHandler) {
            nextHandler->handle(request);
        }
    }
};

class LoggingHandler : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "log") {
            std::cout << "LoggingHandler: Processing logging\n";
            if (nextHandler) nextHandler->handle(request);
        } else if (nextHandler) {
            nextHandler->handle(request);
        }
    }
};

class ValidationHandler : public Handler {
public:
    void handle(const std::string& request) override {
        if (request == "validate") {
            std::cout << "ValidationHandler: Processing validation\n";
            if (nextHandler) nextHandler->handle(request);
        } else if (nextHandler) {
            nextHandler->handle(request);
        }
    }
};

// Main
int main() {
    auto auth = std::make_shared<AuthenticationHandler>();
    auto logging = std::make_shared<LoggingHandler>();
    auto validation = std::make_shared<ValidationHandler>();

    auth->setNext(logging);
    logging->setNext(validation);

    auth->handle("auth");
    auth->handle("log");
    auth->handle("validate");

    return 0;
}