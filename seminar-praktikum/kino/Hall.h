#pragma once
#pragma once 
#ifndef _HALL__ 
#define _HALL_ 

class Hall {
private:
	int number;
	int rows;
	int columns;
	bool** seats;
public:
	Hall(int, int, int);
	Hall(const Hall&);
	void ReserveSeat(int, int);
	void printHall() const;
	int getNumber() const;
	~Hall();
};

#endif 

