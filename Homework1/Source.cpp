#include <iostream>
//выравнивание памяти
class A {
	int a, b;
	double c, d;
	char e[42];
	int f[2];
	bool h, g;
};

class B
{
	char e[42];
	bool h, g;
	int a;
	double c, d;
	int f[2];
	int b;
};

int main(int argc, char* argv[])
{
	std::cout << sizeof(A) << std::endl;

	std::cout << sizeof(B);

	return EXIT_SUCCESS;
}