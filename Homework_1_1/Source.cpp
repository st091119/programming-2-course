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
    // ������: ���������� ����� �������
public:
    void newFunction() {
        std::cout << "New function in class B" << std::endl;
    }
};

int main() {
    B b;
    int result1 = b.f1(5); // ������������� ������� f1 �� ������ A
    char result2 = b.f2('a'); // ������������� ������� f2 �� ������ A
    b.f3(); // ������������� ������� f3 �� ������ A
    b.newFunction(); // ������� �� ������ B

    return 0;
}
