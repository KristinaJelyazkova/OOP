#include"Hall.h"
#include"Projection.h"
#include"Cinema.h"

#include<iostream>


void menu(Cinema &cinema) {
	std::cout << "Enter a number from 1 to 6 for the one of the following options.\n";
	int number;
	std::cin >> number;
	switch (number) {
	case 1: {
		cinema.printProgram();
		menu(cinema);
		break;
	}
	case 2: {
		int numberOfHall;
		std::cout << "Enter the number of the hall you want to see the program of: ";
		std::cin >> numberOfHall;
		cinema.printProgramByHall(numberOfHall);
		menu(cinema);
		break;
	}
	case 3: {
		std::string movieName;
		std::cout << "Enter the name of the movie: ";
		std::cin >> movieName;
		cinema.printHoursOfTheMovie(movieName);
		menu(cinema);
		break;
	}
	case 4: {
		menu(cinema);
		break;
	}
	case 5: {
		menu(cinema);
		break;
	}
	case 6: {
		return;
	}
	}
}

int main() {
	Cinema cinema;
	menu(cinema);
	system("pause");
	return 0;
}