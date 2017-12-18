#include<iostream>
#include<fstream>

using namespace std;

const int MAXSIZE = 30;
const double speedOfLight = 299792; // in km per sec

struct Planet {
	char name[MAXSIZE];
	double distance; // from planet to Sun in km
	double diameter;
	double weight;
};

void inputFromKeyboard(Planet planet) {
	cin.getline(planet.name, MAXSIZE);
	cin >> planet.distance 
		>> planet.diameter 
		>> planet.weight;
}

void print(Planet planet) {
	cout << planet.name << " "
		<< planet.distance << " "
		<< planet.diameter << " "
		<< planet.weight << endl;
}

double seconds(Planet planet) {
	return (double)planet.distance / speedOfLight;
}

Planet* inputFromFile(ifstream &in, int &numberOfPlanets) {
	in >> numberOfPlanets;
	Planet *planet = new Planet[numberOfPlanets];
	for (int i = 0; i < numberOfPlanets; i++) {
		in.ignore();
		in.getline(planet[i].name, MAXSIZE);
		in >> planet[i].distance
			>> planet[i].diameter
			>> planet[i].weight;
	}
	return planet;
}

void printArray(Planet *planet, int numberOfPlanets) {
	for (int i = 0; i < numberOfPlanets; i++) {
		print(planet[i]);
	}
}

void planetWithMaxDiameter(Planet *planet, int numberOfPlanets) {
	Planet maxPlanet = planet[0];
	double maxDiameter = planet[0].diameter;
	for (int i = 1; i < numberOfPlanets; i++) {
		if (planet[i].diameter > maxDiameter) {
			maxPlanet = planet[i];
			maxDiameter = planet[i].diameter;
		}
	}
	cout << "\nThe planet with the biggest diameter: ";
	print(maxPlanet);
}

int main() {
	const char *myFile = "planets.txt";
	ifstream in(myFile);

	int numberOfPlanets = 0;
	Planet *planet = inputFromFile(in, numberOfPlanets);

	cout << "Seconds: " << seconds(planet[2]) << endl << endl;

	printArray(planet, numberOfPlanets);

	planetWithMaxDiameter(planet, numberOfPlanets);

	delete[] planet;
	system("pause");
	return 0;
}