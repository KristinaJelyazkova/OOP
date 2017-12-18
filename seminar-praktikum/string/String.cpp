#include<iostream>
using namespace std;

class String		// null - terminated
{
private:
	char *pointer;
public:
	String(const char *str = "") {
		int length = 0;
		while (*(str + length) != '\0') {
			length++;
		}
		pointer = new char[length + 1];	// +1 for the '\0'
		for (int i = 0; i < length; i++) {
			*(pointer + i) = *(str + i);
		}
		*(pointer + length) = '\0';
	}
	String(const String &other) {
		int length = other.length();
		pointer = new char[length + 1];	// +1 for the '\0'
		for (int i = 0; i < length; i++) {
			*(pointer + i) = *(other.pointer + i);
		}
		*(pointer + length) = '\0';
	}
	String& operator = (const String &other) {
		int length = other.length();
		char *tmp = new char[length + 1];
		for (int i = 0; i < length; i++) {
			*(tmp + i) = *(other.pointer + i);
		}
		*(tmp + length) = '\0';
		delete[] pointer;
		pointer = tmp;
		return *this;
	}
	String& operator = (const char *str) {
		int length = 0;
		while (*(str + length) != '\0') {
			length++;
		}
		char *tmp = new char[length + 1];
		for (int i = 0; i < length; i++) {
			*(tmp + i) = *(str + i);
		}
		*(tmp + length) = '\0';
		delete[] pointer;
		pointer = tmp;
		return *this;
	}
	~String() {
		delete[] pointer;
	}

	int length() const {
		int length = 0;
		while (*(pointer + length) != '\0') {
			length++;
		}
		return length;
	}

	char& operator [] (unsigned int index) {
		cout << "Calling char& operator[] \n";
		return *(pointer + index);
	}
	char operator [] (unsigned int index) const {
		cout << "Calling char operator[] \n";
		return *(pointer + index);
	}

	String operator + (const String &other) const {
		String result;
		int thisLength = this->length(), otherLength = other.length();
		int length = thisLength + otherLength;
		result.pointer = new char[length + 1];
		for (int i = 0; i < thisLength; i++) {
			*(result.pointer + i) = *(this->pointer + i);
		}
		for (int i = thisLength; i < length; i++) {
			*(result.pointer + i) = *(other.pointer + i - thisLength);
		}
		*(result.pointer + length) = '\0';
		return result;
	}
	String& operator += (const String &other) {
		*this = (*this + other);
		return *this;
	}

	void print() const {
		int length = this->length();
		for (int i = 0; i < length; i++) {
			cout << *(pointer + i);
		}
		cout << endl;
	}

	bool operator < (const String &other) const {
		int thisLength = this->length(), otherLength = other.length();
		int minLength = (thisLength < otherLength) ? thisLength : otherLength;
		for (int i = 0; i < minLength; i++) {
			if (*(pointer + i) < *(other.pointer + i)) return true;
			if (*(pointer + i) > *(other.pointer + i)) return false;
		}
		return (thisLength < otherLength);
	}
	bool operator == (const String &other) const {
		int thisLength = this->length(), otherLength = other.length();
		if (thisLength != otherLength) return false;
		for (int i = 0; i < thisLength; i++) {
			if (*(pointer + i) != *(other.pointer + i)) return false;
		}
		return true;
	}
	bool operator >= (const String &other) const {
		return !(*this < other);
	}
	bool operator > (const String &other) const {
		return !(*this < other) && !(*this == other);
	}
	bool operator <= (const String &other) const {
		return (*this < other) || (*this == other);
	}
	bool operator != (const String &other) const {
		return !(*this == other);
	}

};

std::ostream& operator << (std::ostream& out, const String& string) {
	int length = string.length();
	for (int i = 0; i < length; i++) {
		out << string[i];
	}
	out << endl;
	return out;
}

int main() {
	String s1("hey ya ");
	//s1.print();

	String s2(s1);
	//s2.print();

	s2 = "hello world";
	//s2.print();

	//s1.print();
	//s1 = s2;
	//s1.print();
	//cout << s1.length() << endl;
	//cout << s1[4] << endl;
	//s1[3] = s1[8];
	//s1.print();

	String s3;
	//s3.print();
	//cout << s3.length();
	s3 = s1 + s2;
	//s3.print();

	s1 += s2;
	//s1.print();

	String s4 = "baba", s5("babata");
	//cout << (s4 <= s5) << endl;

	//cout << s3;
	cout << s3[5] << endl;	// calling char& operator[] because s3 is not a const string

	const String s6("hello my name is");	
	cout << s6[9] << endl;	// calling char operator[] because s6 is a const string

	system("pause");
	return 0;
}