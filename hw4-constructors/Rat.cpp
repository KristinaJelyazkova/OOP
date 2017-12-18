#include<iostream>
#include<assert.h>
using namespace std;

unsigned int NOD(unsigned int a, unsigned int b) {
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	NOD(a % b, b);
}

unsigned int NOK(unsigned int a, unsigned int b) {
	return (a * b) / NOD(a, b);
}

class Rat {
private:
	int num;
	unsigned int denom;
public:
	//Rat();
	Rat(int, unsigned int);
	void simplify();
	Rat& operator+(Rat&);
	Rat& operator*(Rat&);
	void print();
};

/*Rat::Rat() {
	num = 0;
	denom = 1;
}*/

Rat::Rat(int num = 0, unsigned int denom = 1) {
	assert(denom != 0);
	this->num = num;
	this->denom = denom;
}

void Rat::simplify() {
	unsigned int nod = NOD(abs(num), denom);
	num /= nod;
	denom /= nod;
}

Rat& Rat::operator+(Rat& other) {
	Rat res;
	unsigned int nok = NOK(denom, other.denom);
	res.denom = nok;
	res.num = num * (nok / denom) + other.num * (nok / other.denom);
	res.simplify();
	return res;
}

Rat& Rat::operator*(Rat& other) {
	Rat res(num * other.num, denom * other.denom);
	res.simplify();
	return res;
}

void Rat::print() {
	if (denom == 1) cout << num << endl;
	else  cout << num << "/" << denom << endl;
}

Rat poly(Rat coef[], int n, Rat x) {
	Rat res(0, 1);
	Rat mid;
	Rat powerOfX(1, 1);
	for (int i = n; i >= 0; i--) {
		mid = coef[i] * powerOfX;
		res = res + mid;
		powerOfX = powerOfX * x;
	}
	res.simplify();
	return res;
}

int main() {
	Rat r1(5, 12), r2(3, 20);

	/*Rat r3 = r1 + r2;
	r3.print();
	r3 = r1 * r2;
	r3.print();*/

	Rat a0(1, 81), a1(1, 27), a2(1, 9), a3(1, 3), a4(1, 1);
	Rat coef[5];
	coef[0] = a0;
	coef[1] = a1;
	coef[2] = a2;
	coef[3] = a3;
	coef[4] = a4;
	Rat x(9, 1);
	Rat polynom = poly(coef, 4, x);
	polynom.print();
	system("pause");
	return 0;
}