#include<iostream>

const int C = 239;
int mod(int d)
{
	d = d % 239;
	if (d < 0)
	{
		d += 239;
	}
	return d;
}

class C239 {
private:
	int x;

public:

	C239(int x = 0)
		: x(mod(x)) {}

	C239(const C239& c)
		: x(c.x) {}

	~C239() {};

	int inverse(int x)
	{
		if (x == 0)
		{
			throw std::string{ "error" };
		}
		for (int i = 1; i < 239; ++i)
		{
			if (((x * i) % C) == 1)
			{
				x = i;
				return i;
				break;
			}
		}
	}

	C239 operator+(int d)
	{
		return C239((x + d) % C);
	}
	C239 operator-(int d)
	{
		return C239((x - d) % C);
	}
	C239 operator*(int d)
	{
		return C239((x * d) % C);
	}
	C239 operator/(int d)
	{
		d = mod(d);
		return C239(x * inverse(d));
	}

	friend C239 operator+(int d, const C239& c)
	{
		return C239((c.x + d) % C);
	}
	friend C239 operator-(int d, const C239& c)
	{
		return C239((c.x - d) % C);
	}
	friend C239 operator*(int d, const C239& c)
	{
		return C239((c.x * d) % C);
	}
	friend C239 operator/(int d, C239& c)
	{
		return C239(d * c.inverse(c.x));
	}

	C239 operator+(const C239& c)
	{
		return C239((x + c.x) % C);
	}
	C239 operator-(const C239& c)
	{
		return C239((x - c.x) % C);
	}
	C239 operator*(const C239& c)
	{
		return ((x * c.x) % C);
	}
	C239 operator/(C239& c)
	{
		return C239(x * c.inverse(c.x));
	}

	C239 operator+=(int d)
	{
		x = (x + d) % C;
		return *this;
	}
	C239 operator-=(int d)
	{
		x = (x - d) % C;
		return *this;
	}
	C239 operator*=(int d)
	{
		x = (x * d) % C;
		return *this;
	}

	C239 operator+=(const C239& c)
	{
		x = (c.x + x) % C;
		return c;
	}
	C239 operator-=(const C239& c)
	{
		x = (c.x - x) % C;
		return c;
	}
	C239 operator*=(const C239& c)
	{
		x = (c.x * x) % C;
		return c;
	}

	bool operator>(int d)
	{
		d = mod(d);
		if (x > d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator<(int d)
	{
		d = mod(d);
		if (x < d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator>=(int d)
	{
		d = mod(d);
		if (x >= d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator<=(int d)
	{
		d = mod(d);
		if (x > d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator!=(int d)
	{
		d = mod(d);
		if (x != d)
		{
			std::cout << "True." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	friend bool operator>(int d, const C239& c)
	{
		d = mod(d);
		if (c.x < d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	friend bool operator<(int d, const C239& c)
	{
		d = mod(d);
		if (c.x > d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	friend bool operator>=(int d, const C239& c)
	{
		d = mod(d);
		if (c.x <= d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	friend bool operator<=(int d, const C239& c)
	{
		d = mod(d);
		if (c.x >= d)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	friend bool operator!=(int d, const C239& c)
	{
		d = mod(d);
		if (c.x != d)
		{
			std::cout << "True." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator>(const C239& c)
	{
		if (x > c.x)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator<(const C239& c)
	{
		if (x < c.x)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator>=(const C239& c)
	{
		if (x >= c.x)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator<=(const C239& c)
	{
		if (x <= c.x)
		{
			std::cout << "Inequality is true." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}
	bool operator!=(const C239& c)
	{
		if (x != c.x)
		{
			std::cout << " True." << std::endl;
			return 1;
		}
		else
		{
			std::cout << "Inequality is false." << std::endl;
			return 0;
		}
	}

	C239 operator^(int deg)
	{
		int result = 1;
		while (deg) {
			if (deg % 2 == 0) {
				deg /= 2;
				x *= x;
			}
			else {
				deg -= 1;
				result *= x;
			}
		}

		return C239(result);
	}

	friend std::ostream& operator<<(std::ostream& stream, const C239& c)
	{
		stream << c.x << " mod 239" << std::endl;
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, C239& c)
	{
		int input;
		stream >> input;
		c = C239(input);
		return stream;
	}
};

int main(int argc, char* argv[])
{
	C239 x1(239);
	C239 x2(-100);
	C239 x4(535);
	int a1 = 10;
	
	std::cout << " addition " << x2 + a1 << a1 + x2 << x2 + x4 << std::endl;
	std::cout << " subtraction " << x2 - a1 << a1 - x2 << x2 - x4 << std::endl;
	std::cout << " multiplication " << x2 * a1 << a1 * x2 << x2 * x4 << std::endl;
	std::cout << " division " << x2 / a1 << a1 / x2  << x2 / x4 << std::endl;
	std::cout << " BinPow " << (x2 ^ 3) << std::endl;
	std::cout << " += " << (x2 += a1) << " " << (x2 += x4) << std::endl;
	std::cout << " -= " << (x2 -= a1) << " " << (x2 -= x4) << std::endl;
	std::cout << " *= " << (x2 *= a1) << " " << (x2 *= x4) << std::endl;
	std::cout << " > and < " << (x2 > x4) << " " << (x2 < x4) << std::endl;

	try
	{
		C239 x3 = a1 / x1;
		std::cout << " Division by zero " << x3;
	}
	catch (std::string& error_message)
	{
		std::cout << error_message << std::endl;
	}
	
	return EXIT_SUCCESS;
}