#include <iostream>
using namespace std;

class Complex
{
public:

	// Default Constructor
	Complex()
	{
		real = 0;
		imag = 0;
	}

	// Constructor with Parametres
	Complex(double UserWhole, double UserImaginary)
	{
		real = UserWhole;
		imag = UserImaginary;
	};

	// Copy Constructor 
	Complex(Complex& UserComplex)
	{
		real = UserComplex.real;
		imag = UserComplex.imag;
	}

	// Module from Complex Number 
	// |x| = sqrt(a^2 + b^2) 
	double Module() const
	{
		return My_Sqrt((real * real) - (imag * imag));
	}

	// Implementation of Sqrt using bitwise search
	// Algorithmic complexity is linear rather than exponential
	int My_Sqrt(int value) const
	{
		int temp, x = 0;
		if (value < 0)
			value = -value;
		for (temp = 0, x = 1u << (sizeof(int) * 4 - 1); x; x >>= 1)
		{
			if ((temp | x) * (temp | x) <= value)
				temp |= x;
		}
		return temp;
	}

	// Overload operator = 
	Complex& operator = (Complex& UserValue)
	{
		real = UserValue.real;
		imag = UserValue.imag;
		return *this;
	}


	// Overload operator +
	Complex& operator + (Complex& UserValue) const
	{
		Complex temp;
		temp.real = real + UserValue.real;
		temp.imag = real + UserValue.imag;
		return temp;
	}

	// Overload operator -
	Complex& operator - (Complex& UserValue) const
	{
		Complex temp;
		temp.real = real - UserValue.real;
		temp.imag = imag - UserValue.imag;
		return temp;
	}

	// Overload operator *
	Complex& operator * (Complex& UserValue) const
	{
		Complex temp;
		temp.real = (real * UserValue.real) - (imag * UserValue.imag);
		temp.imag = (imag * UserValue.real) + (real * UserValue.imag);
		return temp;
	}

	// Overload operator / 
	Complex& operator / (Complex& UserValue) const
	{
		Complex temp;

		double r = UserValue.real * UserValue.real + UserValue.imag * UserValue.imag;
		temp.real = (real * UserValue.real + imag * UserValue.imag) / r;
		temp.imag = (imag * UserValue.real - real * UserValue.imag) / r;

		return temp;
	}

	// Display
	void Output() const
	{
		cout << "Whole: " << real << " " << "Imaginary: " << imag;
	}

	// Destructor
	~Complex()
	{

	};

	// Friend Method Cout 
	friend ostream& operator<<(ostream& out, const Complex& Num);

private:
	float real;
	float imag;
};

// Overload cout 
ostream& operator<<(ostream& out, const Complex& Num)
{
	out << "Whole: " << Num.real << " Imaginary: " << Num.imag << "\n";
	return out;
}

int main()
{
	Complex a(2, 5);
	Complex b(1, 3);
	Complex c;
	cout << " / " << endl;
	c = a / b;
	cout << c;
	cout << " * " << endl;
	c = a * b;
	cout << c;
	cout << " + " << endl;
	c = a + b;
	cout << c;
	cout << " - " << endl;
	c = a - b;
	cout << c;
}
