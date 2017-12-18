#include<iostream>
using namespace std;

typedef double (*function)(double);

double plus10(double x) {
	return x + 10;
}

double mult2(double x) {
	return x * 2;
}

double fmax(function f, function g, double x) {
	if (f(x) > g(x)) return f(x);
	else return g(x);
}

int main() {
	double x;
	cin >> x;

	cout << fmax(plus10, mult2, x) << endl;

	system("pause");
	return 0;
}