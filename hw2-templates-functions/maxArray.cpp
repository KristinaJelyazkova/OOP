#include<iostream>
using namespace std;

typedef double(*function)(double);

double plus10(double x) {
	return x + 10;
}

double mult2(double x) {
	return x * 2;
}

double f0(double x) {
	return x + 1;
}

double f1(double x) {
	return x * 4;
}

double f2(double x) {
	return x / 2;
}

double f3(double x) {
	return x + 100;
}

double f4(double x) {
	return x * 10;
}

double fmax(function f, function g, double x) {
	if (f(x) > g(x)) return f(x);
	else return g(x);
}


// maxarray without using fmax
/*double maxarray(function *array, int n, double x) {
	double max = array[0](x);
	for (int i = 1; i < n; i++) {
		if (max < array[i](x)) max = array[i](x);
	}
	return max;
}*/

// maxarray with using fmax
double maxarray(function *array, int n, double x) {
	double max = array[0](x);
	double max2;
	for (int i = 1; i < n - 1; i = i + 2) {
		max2 = fmax(array[i], array[i + 1], x);
		if (max < max2) max = max2;
	}
	if (n % 2 == 0) {
		if (max < array[n - 1](x)) max = array[n - 1](x);
	}
	return max;
}

int main() {
	double x;
	cin >> x;

	//cout << fmax(plus10, mult2, x) << endl;

	int size = 7;
	function *array = new function[size];
	array[0] = plus10;
	array[1] = mult2;
	array[2] = f0;
	array[3] = f1;
	array[4] = f2;
	array[5] = f3;
	array[6] = f4;

	cout << maxarray(array, size, x) << endl;

	system("pause");
	return 0;
}