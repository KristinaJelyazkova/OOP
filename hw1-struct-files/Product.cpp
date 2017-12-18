#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

struct Product {
	char description[32];
	int partNum;
	double cost;
};

/*Product input() {
	Product p;
	cin.getline(p.description, 32);
	cin >> p.partNum
		>> p.cost;
	return p;
}*/

int main() {
	Product p1, p2;

	strcpy_s(p1.description, "screw driver");
	p1.partNum = 456;
	p1.cost = 5.50;

	strcpy_s(p2.description, "hammer");
	p2.partNum = 324;
	p2.cost = 8.20;

	cout << "Product 1: " << p1.description << " " << p1.partNum << " " << p1.cost << endl;
	cout << "Product 2: " << p2.description << " " << p2.partNum << " " << p2.cost << endl;

	Product product[5];
	for (int i = 0; i < 5; i++) {
		strcpy_s(product[i].description, "0");
		product[i].partNum = 0;
		product[i].cost = 0;
	}

	strcpy_s(product[0].description, "screw driver");
	product[0].partNum = 456;
	product[0].cost = 5.50;

	strcpy_s(product[1].description, "hammer");
	product[1].partNum = 324;
	product[1].cost = 8.20;

	strcpy_s(product[2].description, "socket");
	product[2].partNum = 777;
	product[2].cost = 6.80;

	strcpy_s(product[3].description, "plier");
	product[3].partNum = 123;
	product[3].cost = 10.80;

	strcpy_s(product[4].description, "hand-saw");
	product[4].partNum = 555;
	product[4].cost = 12.80;

	cout << endl;
	cout << "Products 1: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Product " << i + 1 << ": "
			<< product[i].description << " "
			<< product[i].partNum << " "
			<< product[i].cost << endl;
	}

	char *myFile = "Products.txt";
	ofstream out(myFile);
	for (int i = 0; i < 5; i++) {
		out << product[i].description << endl
			<< product[i].partNum << " "
			<< product[i].cost << endl;
	}

	Product products2[5];
	ifstream in(myFile);
	for (int i = 0; i < 5; i++) {
		if(i != 0) in.ignore();
		in.getline(products2[i].description, 32);
		in >> products2[i].partNum;
		in >> products2[i].cost;
	}

	bool areEqual = true;
	double eps = 0.0000001;
	cout << endl << "Products 2: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Product " << i + 1 << ": "
			<< products2[i].description << " "
			<< products2[i].partNum << " "
			<< products2[i].cost << endl;
		if (strcmp(product[i].description, products2[i].description) != 0
			|| product[i].partNum != products2[i].partNum
			|| abs(product[i].cost - products2[i].cost) > eps ) areEqual = false;
	}

	if (areEqual) cout << "The products are the same.\n";
	else cout << "The products are not the same.\n";

	system("pause");
	return 0;
}