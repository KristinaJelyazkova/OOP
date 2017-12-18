#include<iostream>
using namespace std;

struct Definition {
	char word[101];
	char definition[501];
};

class Dictionary {
private:
	int size;
	Definition definition[50];	// NOT ENOUGH MEMORY FOR 500
public:
	Dictionary();
	bool isFull();
	void print();
	void addDefiniton(Definition&);
	void removeDefinition(char[]);
	// returns the position of the definition in the dictionary or -1 if there is no definition for this word
	int searchForDefinition(char[]);	
	void sortAlphabeticallyAndPrint();
	Dictionary operator+(Dictionary);
	char* getDefinition(char word[]) {
		int index = searchForDefinition(word);
		if (index == -1) return "";
		else return definition[index].definition;
	};
};

Dictionary::Dictionary() {
	size = 0;
}

void Dictionary::print() {
	for (int i = 0; i < size; i++) {
		cout << definition[i].word << ": "
			<< definition[i].definition << endl;
	}
}

bool Dictionary::isFull() {
	return (size == 500);
}

void Dictionary::addDefiniton(Definition& definition) {
	if (searchForDefinition(definition.word) != -1) {
		cout << "This word is already in the dictionary.\n";
		return;
	}
	if (isFull()) {
		cout << "The dictionary is full.\n";
		return;
	}
	if(strlen(definition.word) >= 100) {
		cout << "The word is too long.\n";
		return;
	}
	if (strlen(definition.definition) >= 500) {
		cout << "The definiton is too long.\n";
		return;
	}
	strcpy_s(this->definition[size].word, definition.word);
	strcpy_s(this->definition[size].definition, definition.definition);
	size++;
}

void Dictionary::removeDefinition(char word[]) {
	int index;
	bool flag = true;
	for (int i = 0; i < size && flag; i++) {
		if (strcmp(this->definition[i].word, word) == 0) {
			index = i;
			flag = false;
		}
	}
	for (int i = index; i < size - 1; i++) {
		strcpy_s(this->definition[i].word, this->definition[i + 1].word);
		strcpy_s(this->definition[i].definition, this->definition[i + 1].definition);
	}
	size--;
}

int Dictionary::searchForDefinition(char word[]) {
	int index;
	bool found = false;
	for (int i = 0; i < size && !found; i++) {
		if (strcmp(this->definition[i].word, word) == 0) {
			index = i;
			found = true;
		}
	}
	if (!found) {
		// No such word in the dictionary.
		return -1;
	}
	return index;
}

void Dictionary::sortAlphabeticallyAndPrint() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(definition[j].word, definition[j + 1].word) == 1)
				swap(definition[j], definition[j + 1]);
		}
	}
	print();
}

Dictionary Dictionary::operator+(Dictionary dictionary) {
	//cout << endl << size << endl;
	Dictionary newDictionary;
	//newDictionary.size = 0;
	bool stop = false;
	for (int i = 0; (i < this->size) /*&& (!stop)*/; i++) {
		Definition newDefinition;
		strcpy_s(newDefinition.word, this->definition[i].word);
		int index = dictionary.searchForDefinition(this->definition[i].word);
		if (index == -1)
			strcpy_s(newDefinition.definition, this->definition[i].definition);
		else {
			if ((strlen(this->definition[i].definition) + strlen(dictionary.getDefinition(this->definition[i].word)) <= 500)){
				strcpy_s(newDefinition.definition, "1.");
				strcat_s(newDefinition.definition, this->definition[i].definition);
				strcat_s(newDefinition.definition, " 2.");
				strcat_s(newDefinition.definition, dictionary.getDefinition(this->definition[i].word));
				dictionary.removeDefinition(this->definition[i].word);
			}
			else strcpy_s(newDefinition.definition, this->definition[i].definition);
		}
		if (!newDictionary.isFull()) newDictionary.addDefiniton(newDefinition);
		else {
			stop = true;
			cout << "The dictionary is full.\n";
		}
	}
	for (int i = 0; i < dictionary.size && !stop; i++) {
		if (!newDictionary.isFull()) newDictionary.addDefiniton(dictionary.definition[i]);
		else {
			stop = true;
			cout << "The dictionary is full.\n";
		}
	}
	return newDictionary;
}

int main() {
	Dictionary dictionary1, dictionary2;

	Definition definition[8];
	strcpy_s(definition[0].word,"transparent");
	strcpy_s(definition[0].definition, "easy to perceive or detect");
	strcpy_s(definition[1].word, "heal");
	strcpy_s(definition[1].definition, "cause (a wound, injury, or person) to become sound or healthy again");
	strcpy_s(definition[2].word, "break");
	strcpy_s(definition[2].definition, "separate into pieces as a result of a blow, shock, or strain");
	strcpy_s(definition[3].word, "window");
	strcpy_s(definition[3].definition, "an opening in the wall or roof of a building or vehicle, fitted with glass in a frame to admit light or air and allow people to see out");
	strcpy_s(definition[4].word, "transparent");
	strcpy_s(definition[4].definition, "(of a material or article) allowing light to pass through so that objects behind can be distinctly seen");
	strcpy_s(definition[5].word, "beautiful");
	strcpy_s(definition[5].definition, "pleasing the senses or mind aesthetically");
	strcpy_s(definition[6].word, "forever");
	strcpy_s(definition[6].definition, "for all future time; for always");
	strcpy_s(definition[7].word, "break");
	strcpy_s(definition[7].definition, "a pause in work or during an activity or event");

	for (int i = 0; i < 4; i++) {
		dictionary1.addDefiniton(definition[i]);
	}
	for (int i = 4; i < 7; i++) {
		dictionary2.addDefiniton(definition[i]);
	}

	cout << "\nPrint dictionary 1: ------------------------------\n";
	dictionary1.print();
	cout << "Print dictionary 2: ------------------------------\n";
	dictionary2.print();

	dictionary2.addDefiniton(definition[7]);
	dictionary1.removeDefinition("heal");
	cout << "\nPrint dictionary 1: ------------------------------\n";
	dictionary1.print();
	cout << "Print dictionary 2: ------------------------------\n";
	dictionary2.print();

	cout << "\nSearching for the definition of the word 'break' -------------------\n";
	if (dictionary2.searchForDefinition("break") == -1) cout << "No such word in the dictionary.\n";
	else cout << "The definition of 'break' is " << dictionary2.getDefinition("break") << endl;

	cout << "\nPrint dictionary 1: ------------------------------\n";
	dictionary1.sortAlphabeticallyAndPrint();
	cout << "Print dictionary 2: ------------------------------\n";
	dictionary2.sortAlphabeticallyAndPrint();

	Dictionary newDictionary = (dictionary1 + dictionary2);
	cout << "\nPrint new dictionary: ------------------------------\n";
	newDictionary.print();

	cout << "\nPrint new dictionary: ------------------------------\n";
	newDictionary.sortAlphabeticallyAndPrint();

	system("pause");
	return 0;
}