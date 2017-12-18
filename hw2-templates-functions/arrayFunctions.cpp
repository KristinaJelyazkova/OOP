#include<iostream>
using namespace std;

typedef double (*function)(double);		// it has to be a pointer!!!

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

int main() {
	function functions[5];

	functions[0] = f0;
	functions[1] = f1;
	functions[2] = f2;
	functions[3] = f3;
	functions[4] = f4;

	double x;
	cin >> x;

	cout << functions[0](x) << " "
		<< functions[1](x) << " "
		<< functions[2](x) << " "
		<< functions[3](x) << " "
		<< functions[4](x) << endl;
		

	double max = functions[0](x);
	int maxIndex = 0;
	for (int i = 1; i < 5; i++) {
		if (max < functions[i](x)) {
			max = functions[i](x);
			maxIndex = i;
		}
	}
	cout << "max = " << max << endl
		<< "index = " << maxIndex << endl;

	system("pause");
	return 0;
}