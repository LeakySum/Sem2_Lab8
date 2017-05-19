

#include <iostream>

using namespace std;

template <class T>
class Complex {
	public:
	double x;
	double y;
	Complex& sum(T number)
	{
		Complex buf(x + number, y);
		return buf;
	}

	Complex& sum(const Complex& number)
	{
		Complex buf(x + number.x, y + number.y);
		return buf;
	}

	Complex& sub(const Complex& number)
	{
		Complex buf(x - number.x, y - number.y);
		return buf;
	}
	Complex& sub(T number)
	{
		Complex buf(x - number, y);
		return buf;
	}

	Complex& mul(int number)
	{
		Complex buf(x *number, y * number);
		return buf;
	}

	Complex& div(int number)
	{
		if (number) {
			Complex buf(T(x /number), T(y /number));
			return buf;
		}
		else
		{
			Complex buf;
			cout << "You can't divide by zero !" << endl;
			return buf;
		}
	}

	
	Complex()
	{
		x = 0.0;
		y = 0.0;
	}
	Complex(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
	

	Complex& mul_complex(const Complex& number)
	{
		Complex buf(x*number.x - y*number.y, x*number.y + y*number.y);
		return buf;
	}
	
	Complex operator+(const Complex& comp)
	{
		return sum(comp);
	}
	Complex operator+(T num)
	{
		return sum(num);
	}
	Complex operator-(const Complex& comp)
	{
		return sub(comp);
	}
	Complex operator-(T num)
	{
		return sub(num);
	}
	Complex operator*(const Complex& comp)
	{
		return mul_complex(comp);
	}
	Complex operator*(T num)
	{
		return mul(num);
	}
	Complex operator/(T num)
	{
		return div(num);
	}
	Complex operator=(const Complex& comp)
	{
		x = comp.x;
		y = comp.y;
		return *this;
	}
		Complex operator+=(T num)
	{
		*this = *this + num;
		return *this;
	}
	Complex operator+=(const Complex& comp)
	{
		*this = *this + comp;
		return *this;
	}
	Complex operator-=(const Complex& comp)
	{
		*this = *this - comp;
		return *this;
	}
	Complex operator-=(T num)
	{
		*this = *this - num;
		return *this;
	}
	Complex operator*=(const Complex& comp)
	{
		*this = *this * comp;
		return *this;
	}
	Complex operator*=(T num)
	{
		*this = *this * num;
		return *this;
	}
	Complex operator/=(T num)
	{
		*this = *this / num;
		return *this;
	}
	bool operator==(const Complex& comp)
	{
		if ((x == comp.x) && (y == comp.y))
			return 1;
		else
			return 0;
	}
	template <typename U>
	friend ostream& operator<<(ostream&, const Complex<U>&);
	template <typename U>
	friend istream& operator >> (istream&, Complex<U>&);
};

template <class T>
ostream& operator<<(ostream& out, const Complex<T>& num)
{
	if (num.x && num.y)
		out << num.x << " + " << num.y << 'i' << endl;
	else if (num.x && !num.y)
		out << num.x << endl;
	else if (!num.x && num.y)
		out << num.y << 'i' << endl;
	else
		out << 0 << endl;
	return out;
}
template <class T>
istream& operator >> (istream &in, Complex<T>& number)
{
	T x;
	T y;
	in >> x;
	in >> y;
	Complex<T> buf(x, y);
	number = buf;
	return in;
}

