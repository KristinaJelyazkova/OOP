#include<iostream>
#include<fstream>

using namespace std;

struct Point {
	double x;
	double y;
};

void Swap(Point &p1, Point &p2) {
	Point buf = p2;
	p2 = p1;
	p1 = buf;
}

void sort(Point *point, int n) {
	double eps = 0.001;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ((point[j].x > point[j+1].x)
				|| ((abs(point[j].x - point[j+1].x) < eps) && (point[j].y > point[j+1].y))) Swap(point[j], point[j+1]);
		}
	}
}

int main() {
	Point point[5];
	point[0].x = 7;
	point[0].y = 19;

	point[1].x = 2;
	point[1].y = 10;

	point[2].x = 2;
	point[2].y = 15;

	point[3].x = 7;
	point[3].y = 21;

	point[4].x = 2;
	point[4].y = 15;

	sort(point, 5);
	for (int i = 0; i < 5; i++) {
		cout << point[i].x << " " << point[i].y << endl;
	}
	system("pause");
	return 0;
}