#include <memory>
#include <iostream>
#include <stdexcept>

class MyClass {
public:
    static std::unique_ptr<MyClass> create(int param) {
        try {
            return std::unique_ptr<MyClass>(new MyClass(param));
        } catch (const std::exception& e) {
            std::cerr << "Failed to create MyClass: " << e.what() << std::endl;
            return nullptr;
        }
    }

    void display() const {
        std::cout << "MyClass object with param: " << m_param << std::endl;
    }

private:
    MyClass(int param) {
        if (param <= 0) {
            throw std::invalid_argument("param must be positive");
        }
        m_param = param;
    }

    int m_param;
};

int main() {
    auto obj = MyClass::create(10);
    if (obj) {
        obj->display();
    } else {
        std::cerr << "Object creation failed" << std::endl;
    }
    return 0;
}
