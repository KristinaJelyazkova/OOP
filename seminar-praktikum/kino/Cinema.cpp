#include"Cinema.h" 
#include<iostream>

void Cinema::AddShow(const Show& show) {
	shows.push_back(show);
}


void Cinema::printProgram() const{
	int size = shows.size();
	for (int i = 0; i < size; i++) {
		shows[i].print();
	}
}


void Cinema::printProgramByHall(int numberOfHall) const {
	std::cout << "The program of hall " << numberOfHall << " is:\n";
	int size = shows.size();
	for (int i = 0; i < size; i++) {
		shows[i].printByHall(numberOfHall);
	}
}

void Cinema::printHoursOfTheMovie(std::string movieName) const {
	int size = shows.size();
	for (int i = 0; i < size; i++) {
		if (shows[i].printHours(movieName)) return;
	}
}


void Cinema::printMoviesByHour(int hour, int minutes) const {
	int size = shows.size();
	for (int i = 0; i < size; i++) {
		shows[i].printNameByHour(hour, minutes);
	}
}