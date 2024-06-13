#include <iostream>
#include <string>

class MyClass {
public:
    MyClass() : m_initialized(false) {}

    bool init(int param) {
        if (param <= 0) {
            m_errorMessage = "param must be positive";
            return false;
        }
        m_param = param;
        m_initialized = true;
        return true;
    }

    void display() const {
        if (m_initialized) {
            std::cout << "MyClass object with param: " << m_param << std::endl;
        } else {
            std::cerr << "Object not initialized: " << m_errorMessage << std::endl;
        }
    }

private:
    int m_param;
    bool m_initialized;
    std::string m_errorMessage;
};

int main() {
    MyClass obj;
    if (obj.init(10)) {
        obj.display();
    } else {
        std::cerr << "Object initialization failed" << std::endl;
    }
    return 0;
}
