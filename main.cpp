
#include <iostream>
#include <limits.h>
#include <string>

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


int autoMath(const std::string& line)
{
	try
	{
		int a = std::stoi(line);
		int b = std::stoi(line.substr(line.find('+')));
		return a + b;
	}
	catch (std::numeric_limits<int>)
	{
		std::cout << "Error with size of integer";
	}
}

int main()
{
	autoMath("15+52");
	

	return 0;
}