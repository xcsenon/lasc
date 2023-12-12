#include <iostream>

// Handler
class Handler {
protected:
    Handler* successor;

public:
    Handler() : successor(nullptr) {}

    void setSuccessor(Handler* successor) {
        this->successor = successor;
    }

    virtual void handleRequest(int request) const = 0;
};

// ConcreteHandlerA
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(int request) const override {
        if (request >= 0 && request < 10) {
            std::cout << "ConcreteHandlerA handles the request: " << request << std::endl;
        }
        else if (successor) {
            successor->handleRequest(request);
        }
    }
};

// ConcreteHandlerB
class ConcreteHandlerB : public Handler {
public:
    void handleRequest(int request) const override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandlerB handles the request: " << request << std::endl;
        }
        else if (successor) {
            successor->handleRequest(request);
        }
    }
};

// Client
class Client {
private:
    Handler* chain;

public:
    Client() {
        chain = new ConcreteHandlerA();
        chain->setSuccessor(new ConcreteHandlerB());
        // Додайте інші обробники за потребою
    }

    void makeRequest(int request) const {
        chain->handleRequest(request);
    }
};

int main() {
    Client client;
    client.makeRequest(5);
    client.makeRequest(15);

    return 0;
}
