#include <optional>
#include <iostream>
#include <string>

class MyClass {
public:
    static std::optional<MyClass> create(int param) {
        if (param <= 0) {
            std::cerr << "param must be positive" << std::endl;
            return std::nullopt;
        }
        return MyClass(param);
    }

    void display() const {
        std::cout << "MyClass object with param: " << m_param << std::endl;
    }

private:
    MyClass(int param) : m_param(param) {}

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
