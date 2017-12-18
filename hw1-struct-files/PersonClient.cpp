#include<iostream>
#include<fstream>
using namespace std;

const int MAXSIZE = 30;

struct Person {
	char firstName[MAXSIZE];
	char lastName[MAXSIZE];
};

struct Client {
	Person person;
	double bankAccount;
};

Client* inputFromFile(ifstream &in, int &numberOfClients) {		// input an array from clients
	in >> numberOfClients;		// 	their number is read from the file
	Client *client = new Client[numberOfClients];
	for (int i = 0; i < numberOfClients; i++) {
		in.ignore();
		in.getline(client[i].person.firstName, MAXSIZE);
		in.getline(client[i].person.lastName, MAXSIZE);
		in >> client[i].bankAccount;
	}
	return client;
}

void print(Client *client, int numberOfClients) {
	for (int i = 0; i < numberOfClients; i++) {
		cout << "Client " << i + 1 << ": "
			<< client[i].person.firstName << " "
			<< client[i].person.lastName << " "
			<< client[i].bankAccount << endl;
	}
}

double findSum(Client *client, int numberOfClients) {
	double sum = 0;
	for (int i = 0; i < numberOfClients; i++) {
		sum += client[i].bankAccount;
	}
	return sum;
}

int main() {
	const char *myFile = "bankAccounts.txt";
	ifstream gin(myFile);
	int numberOfClients = 0;

	Client *client = inputFromFile(gin, numberOfClients);

	print(client, numberOfClients);
	
	double sum = findSum(client, numberOfClients);
	cout << "The sum is " << sum << endl;

	delete[] client;
	system("pause");
	return 0;
}