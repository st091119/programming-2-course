#include <iostream>

class B
{
private:
	int x, y;
	char w;
	int f1()
	{
		return x + y;
	}
	void f2() { std::cout << "haha is f2."; }
	char f3(char z)
	{
		return z + w; //складываются коды ну да пофиг
	}
public:
	B(int x = 0, int y = 0, char w = 'q')
		: x(x), y(y), w(w) {}

	B(const B& b)
		: x(b.x), y(b.y), w(b.w) {}

	~B() {};

	/* есть еще такой вариант, но его раскритиковали(
	friend std::ostream& operator<<(std::ostream& stream, B& b)
	{
		stream << b.f1()  << " is f1." << std::endl << b.f3('x') << " is f3.";
		return stream;
	}
	*/

	friend void publicf2(B b)
	{
		b.f2();
	}

	friend int publicf1(B b)
	{
		return b.f1();
	}

	friend char publicf3(B b, char z)
	{
		return b.f3(z);
	}

};

int main(int argc, char* argv[])
{
	B x1(1, 2, 'x');
	B x2;

	int x = publicf1(x1);
	char y = publicf3(x1, 'x');
	int z = publicf1(x2);
	char w = publicf3(x2, '1');

	publicf2(x1);

	std::cout << std::endl << x << " f1 " << std::endl << y << " f3 " << std::endl;

	publicf2(x2);

	std::cout << std::endl << z << " f1 " << std::endl << w << " f3 ";

	return EXIT_SUCCESS;
}