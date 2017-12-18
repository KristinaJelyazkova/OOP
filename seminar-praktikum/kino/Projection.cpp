
#include"Projection.h" 
#include<iostream>

Projection::Projection(int _hour, int _minutes, Hall _hall) : hour(_hour), minutes(_minutes), hall(_hall) {
}

Show::Show(std::string _movie, int _runtime) : movie(_movie), runtime(_runtime) {}

void Show::AddProjection(int hour, int minutes, Hall hall) {
	projections.push_back(Projection(hour, minutes, hall));
}

void Show::print() const {
	std::cout << "Movie: " << movie << std::endl;
	std::cout << "Runtime: " << runtime << std::endl;
	std::cout << "Projections: " << std::endl;
	int size = projections.size();
	for (int i = 0; i < size; i++) {
		std::cout << projections[i].hour << ':'
			<< projections[i].minutes
			<< "Hall number " << projections[i].hall.getNumber() << " ;";
	}
	std::cout << std::endl;
}

void Show::printByHall(int numberOfHall) const {
	int size = projections.size();
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (projections[i].hall.getNumber() == numberOfHall) {
			std::cout << projections[i].hour << ':'
				<< projections[i].minutes << " ";
			flag = true;
		}
	}
	std::cout << std::endl;
	if (flag) {
		std::cout << "These are the projections of the movie: " << movie << std::endl;
		std::cout << "This movie runtime is " << runtime << std::endl;
	}
	std::cout << std::endl;
}


/*bool Show::printHours(std::string movieName) const {
	if (movie != movieName) {
		return false;
	}
	else {
		int size = projections.size();
		for (int i = 0; i < size; i++) {
				std::cout << projections[i].hour << ':'
					<< projections[i].minutes << " ";
			}
		}
		std::cout << std::endl;
		return true;
	}
}*/

void Show::printNameByHour(int hour, int minutes) const{
	int size = projections.size();
	for (int i = 0; i < size; i++) {
		if (projections[i].hour == hour && projections[i].minutes == minutes) {
			std::cout << movie << std::endl;
		}
	}
}