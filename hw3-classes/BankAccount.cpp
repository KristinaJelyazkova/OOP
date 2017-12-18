#include<iostream>
using namespace std;

class BankAccount {
private:
	char name[50];
	char IBAN[20];
	long double sum;
public:
	void input();
	void print();
	void deposit(double);
	void withdraw(double);
	bool operator< (BankAccount&);
};

void BankAccount::input() {
	cin.getline(name, 50);
	cin.getline(IBAN, 20);
	cin >> sum;
}

void BankAccount::print() {
	cout << name << " "
		<< IBAN << " "
		<< sum << endl;
}

void BankAccount::deposit(double money) {
	sum += money;
}

void BankAccount::withdraw(double money) {
	if (money > sum) cout << "You don't have enough money!\n";
	else sum -= money;
}

bool BankAccount::operator<(BankAccount& bankAccount) {
	return sum < bankAccount.sum;
}

int main() {
	BankAccount ba1,ba2;

	ba1.input();
	cin.ignore();	// !!!
	ba2.input();

	ba1.print();
	ba2.print();

	if (ba1 < ba2) cout << "The first bank account has less money than the second.\n";
	else cout << "The first bank account has the same or more money than the second.\n";

	ba1.deposit(500.25);
	ba2.withdraw(234.12);

	ba1.print();
	ba2.print();

	system("pause");
	return 0;
}