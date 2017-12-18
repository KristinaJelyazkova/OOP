#include<iostream>
using namespace std;

template<typename T>
void input(T *array, int n) {
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
}

template<typename T>
void output(T *array, int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<typename T>
bool ordered(T *array, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (array[i] >= array[i + 1]) return false;
	}
	return true;
}

template<typename T>
bool member(T *array, int n, T x) {
	for (int i = 0; i < n; i++) {
		if (array[i] == x) return true;
	}
	return false;
}

int main() {
	const int size = 5;

	int arrI[size];
	double arrD[size];
	char arrC[size];
	char *arrCP = new char[size];

	//input<int>(arrI, size);
	//output<int>(arrI, size);

	//input<double>(arrD, size);
	//output<double>(arrD, size);

	input<char>(arrC, size);
	output<char>(arrC, size);

	//if (ordered<char>(arrC, size)) cout << "Yes.\n";
	//else cout << "No.\n";

	if(member<char>(arrC,size,'c')) cout << "Yes.\n";
	else cout << "No.\n";

	system("pause");
	return 0;
}