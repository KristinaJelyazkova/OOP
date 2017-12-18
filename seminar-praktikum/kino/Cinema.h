
#pragma once 
#ifndef _CINEMA_ 
#define _CINEMA_ 

#include"Projection.h" 
#include<vector> 

class Cinema {
private:
	std::vector<Show> shows;
public:
	void AddShow(const Show&);
	void printProgram() const;
	void printProgramByHall(int) const;
	void printHoursOfTheMovie(std::string) const;
	void printMoviesByHour(int, int) const;
};

#endif 
