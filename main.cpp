
#include <iostream>

class Fraction
{
private:
	int numerator, denominator;
	void resize();
public:
	Fraction(int pNum, int pDenom) : numerator(pNum) { setDenominator(pDenom); resize(); };

	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }

	void setNumerator(int value) { numerator = value; resize(); }
	void setDenominator(int value) { if (value == 0) throw *this; denominator = value; resize();}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& frac) { return out << frac.getNumerator() << "/" << frac.getDenominator(); }
};

void Fraction::resize()
{
	int a = numerator;
	int b = denominator;
	while (a % b != 0)
	{
		int tmp = a - b * (a / b);
		a = b;
		b = tmp;
	}
	numerator = numerator / b;
	denominator = denominator / b;
}

int main()
{
	try
	{
		Fraction a(9, 0);
		std::cout << a;
	}
	catch (Fraction)
	{
		std::cout << "Fraction error";
	}
	

	return 0;
}