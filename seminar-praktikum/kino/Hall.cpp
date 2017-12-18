#include"Hall.h" 
#include<iostream> 

Hall::Hall(int _number, int _rows, int _columns) : number(_number), rows(_rows), columns(_columns) {
	seats = new bool*[_rows];
	for (int i = 0; i < _rows; i++) {
		seats[i] = new bool[_columns];
	}
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			seats[i][j] = false;    // all seats are free 
		}
	}
}

Hall::Hall(const Hall& other) {
	number = other.number;
	rows = other.rows;
	columns = other.columns;
	seats = new bool*[rows];
	for (int i = 0; i < rows; i++) {
		seats[i] = new bool[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (other.seats[i][j] == false) seats[i][j] = false;
			else seats[i][j] = false;
		}
	}
}

void Hall::ReserveSeat(int row, int column) {
	seats[row][column] = true;
}

void Hall::printHall() const{
	std::cout << "Hall number " << number << ":\n";
	for (int i = 0; i < rows; i++) {
		std::cout << i << "   ";
		for (int j = 0; j < columns; j++) {
			if (seats[i][j] == false) std::cout << "O ";
			else std::cout << "X ";
		}
		std::cout << std::endl;
	}
}

int Hall::getNumber() const{
	return number;
}

Hall::~Hall() {
	for (int i = 0; i < rows; i++) {
		delete[] seats[i];
	}
	delete[] seats;
}