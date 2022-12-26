#include <iostream>
using namespace std;

class Complex
{
public:

	// Default Constructor
	Complex()
	{
		whole = 0;
		imaginary = 0;
	}

	// Constructor with Parametres
	Complex(double UserWhole, double UserImaginary)
	{
		whole = UserWhole;
		imaginary = UserImaginary;
	};

	// Copy Constructor 
	Complex(Complex& UserComplex)
	{
		whole = UserComplex.whole;
		imaginary = UserComplex.imaginary;
	}

	// Module from Complex Number 
	double Module() const
	{
		return My_Sqrt((whole * whole) - (imaginary * imaginary));
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
		whole = UserValue.whole;
		imaginary = UserValue.imaginary;
		return *this;
	}

	// Overload operator +
	Complex& operator + (Complex& UserValue) const
	{
		Complex temp;
		temp.whole += UserValue.whole;
		temp.imaginary += UserValue.imaginary;
		return temp;
	}

	// Overload operator -
	Complex& operator - (Complex& UserValue) const
	{
		Complex temp;
		temp.whole -= UserValue.whole;
		temp.imaginary -= UserValue.imaginary;
		return temp;
	}

	// Overload operator *
	Complex& operator * (Complex& UserValue) const
	{
		Complex temp;
		temp.whole *= UserValue.whole;
		temp.imaginary *= UserValue.imaginary;
		return temp;
	}

	// Overload operator / 
	Complex& operator / (Complex& UserValue) const
	{
		Complex temp;

		double r = UserValue.whole * UserValue.whole + UserValue.imaginary * UserValue.imaginary;
		temp.whole = (whole * UserValue.whole + imaginary * UserValue.imaginary) / r;
		temp.imaginary = (imaginary * UserValue.whole - whole * UserValue.imaginary) / r;

		return temp;
	}

	// Display
	void Output() const
	{
		cout << "Whole: " << whole << " " << "Imaginary: " << imaginary;
	}

	// Destructor
	~Complex()
	{

	};

	// Friend Method Cout 
	friend ostream& operator<<(ostream& out, const Complex& Num);

private:
	double whole;
	double imaginary;
};

// Overload cout 
ostream& operator<<(ostream& out, const Complex& Num)
{
	out << "Whole: " << Num.whole << " Imaginary: " << Num.imaginary << "\n";
	return out;
}

int main()
{
	Complex a(1, 4);
	Complex b(2, 1);
	Complex c;
	c = a / b;
	cout << c;
}