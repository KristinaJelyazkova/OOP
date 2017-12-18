#include"Team.h"


Team::Team(int _IDnumber, std::string _leaderName, std::string _project)
	: IDnumber(_IDnumber), leaderName(_leaderName), project(_project) {}

int Team::getIDnumber() const {
	return IDnumber;
}

std::string Team::getLeaderName() const {
	return leaderName;
}

void Team::setLeaderName(std::string newName) {
	leaderName = newName;
}

void Team::setTeamNumber(int newTeamNumber) {
	IDnumber = newTeamNumber;
}

void Team::print(std::ostream& out) const{
	out << IDnumber << '\n'
		<< leaderName << '\n'
		<< project << '\n';
}

void Team::input(std::istream& in) {
	in >> IDnumber;
	if (in.peek() == '\n') in.ignore();
	std::getline(in, leaderName);
	std::getline(in, project);
}