#pragma once
#pragma once 
#ifndef _PROJECTION_ 
#define _PROJECTION_ 

#include"Hall.h" 
#include<string> 
#include<vector> 

struct Projection {
	int hour;
	int minutes;
	Hall hall;
	Projection(int, int, Hall);
};

class Show {
private:
	std::string movie;
	int runtime;
	std::vector<Projection> projections;
public:
	Show(std::string, int);
	void AddProjection(int, int, Hall);
	void print() const;
	void printByHall(int) const;
	bool printHours(std::string) const;
	void printNameByHour(int, int) const;
};

#endif 
