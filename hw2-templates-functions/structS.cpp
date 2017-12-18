#include<iostream>
#include<fstream>

using namespace std;

struct S {
	int a;
	int b;
	int c;
};

void swap(S &s1, S &s2) {
	S buf = s2;
	s2 = s1;
	s1 = buf;
}

int compareByA(S s1, S s2) {
	if (s1.a > s2.a) return 1;
	if (s1.a == s2.a) return 0;
	return -1;
}

int compareByB(S s1, S s2) {
	if (s1.b > s2.b) return 1;
	if (s1.b == s2.b) return 0;
	return -1;
}

int compareLeks(S s1, S s2) {
	if (s1.a > s2.a) return 1;
	if (s1.a < s2.a) return -1;
	if (s1.b > s2.b) return 1;
	if (s1.b < s2.b) return -1;
	if (s1.c > s2.c) return 1;
	if (s1.c < s2.c) return -1;
	return 0;
}

void sort(S *array, int n, int(*compare)(S, S)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (compare(array[j], array[j + 1]) == 1) swap(array[j], array[j + 1]);
		}
	}
}

int main() {
	S s[5];
	for (int i = 0; i < 5; i++) {
		cin >> s[i].a >> s[i].b >> s[i].c;
	}
	sort(s, 5, compareLeks);
	for (int i = 0; i < 5; i++) {
		cout << s[i].a << " "
			<< s[i].b << " "
			<< s[i].c << endl;
	}
	system("pause");
	return 0;
}