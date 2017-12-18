#include<iostream>
using namespace std;

typedef double(*function)(double);

double inc(double x) {
	return x + 1;
}

void map(double array[], int n, function f) {
	for (int i = 0; i < n; i++) {
		array[i] = f(array[i]);
	}
}

void print(double array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}

int main() {
	double array[] = { 1.5, 6.2, 0.54 };
	map(array, 3, inc);
	print(array, 3);
	system("pause");
	return 0;
}