#pragma once
#ifndef _TEAM_
#define _TEAM_

#include<string>

class Team {
private:
	int IDnumber;
	std::string leaderName;
	std::string project;
public:
	Team(int = 0, std::string = "", std::string = "");

	int getIDnumber() const;
	std::string getLeaderName() const;

	void setLeaderName(std::string);
	void setTeamNumber(int);

	void print(std::ostream&) const;
	void input(std::istream&);
};

#endif