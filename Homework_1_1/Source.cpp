#include <iostream>

class A {
private:
    int f1(int x) {
        return x * 2;
    }

    char f2(char c) {
        return c;
    }

    void f3() {
        std::cout << "Function f3 in class A" << std::endl;
    }
};

class B : public A {
    // Пример: добавление новой функции
public:
    void newFunction() {
        std::cout << "New function in class B" << std::endl;
    }
};

int main() {
    B b;
    int result1 = b.f1(5); // Наследованная функция f1 из класса A
    char result2 = b.f2('a'); // Наследованная функция f2 из класса A
    b.f3(); // Наследованная функция f3 из класса A
    b.newFunction(); // Функция из класса B

    return 0;
}
