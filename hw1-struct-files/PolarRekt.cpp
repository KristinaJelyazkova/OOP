#include<iostream>
#include<stdio.h>
#include<fstream>
#include<math.h>

#define PI 3.14159265 

using namespace std;

struct polar {
	double distance;
	double angle; // in degrees
};

struct rekt {
	double x;
	double y;
};

rekt polarToRekt(polar vector) {
	rekt sameVector;
	sameVector.x = vector.distance * cos(vector.angle * PI / 180);
	sameVector.y = vector.distance * sin(vector.angle * PI / 180);
	double eps = 0.00001;
	if (abs(vector.angle - 90) < eps
		|| abs(vector.angle - 270) < eps)
		sameVector.x = 0;
	if (abs(vector.angle) < eps
		|| abs(vector.angle - 180) < eps
		|| abs(vector.angle - 360) < eps)
		sameVector.y = 0;
	return sameVector;
}

polar rektToPolar(rekt vector) {
	polar sameVector;
	sameVector.distance = sqrt(vector.x * vector.x + vector.y * vector.y);
	sameVector.angle = asin((double)vector.y / sameVector.distance);
	if (vector.x < 0) sameVector.angle += PI;
	else if (vector.y < 0) sameVector.angle += 2 * PI;
	sameVector.angle = sameVector.angle * 180 / PI;
	return sameVector;
}

void printPolar(polar vector) {
	cout << vector.distance << " " 
		<< vector.angle << endl;
}

void printRekt(rekt vector) {
	cout << vector.x << " "
		<< vector.y << endl;
}

int main() {
	cout << "Enter 'r' if you write Cartesian coordinates or 'p' if polar.\n";
	char mode;
	cin >> mode;

	cout << "Enter number of vectors: ";
	int n;
	cin >> n;

	switch (mode) {
	case 'r': {
		rekt *vector = new rekt[n];
		polar *sameVector = new polar[n];
		for (int i = 0; i < n; i++) {
			cin >> vector[i].x >> vector[i].y;
			sameVector[i] = rektToPolar(vector[i]);
		}
		for (int i = 0; i < n; i++) {
			cout << "Polar coordinates of the vectors: ";
			printPolar(sameVector[i]);
		}
		break;
	}
	case 'p': {
		polar *vector = new polar[n];
		rekt *sameVector = new rekt[n];
		for (int i = 0; i < n; i++) {
			cin >> vector[i].distance >> vector[i].angle;
			sameVector[i] = polarToRekt(vector[i]);
		}
		for (int i = 0; i < n; i++) {
			cout << "Cartesian coordinates of the vectors: ";
			printRekt(sameVector[i]);
		}
		break;
	}
	}
	system("pause");
	return 0;
}