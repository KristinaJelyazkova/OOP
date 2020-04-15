// LOOK AT THE MAP TEMPLATE METHOD!!!
#include <iostream>
#include <assert.h>
using namespace std;

//template<typename T> // a typedef template is illegal
//typedef int(*function) (int);

/* // обсъждахме го в почивката...
void strcpy(char* dest, const char* src)
{
while (*dest++ = *src++); // красота
}*/

template<typename T>
class LinkedList
{
private:
	// box е вложен клас и тъй като е private, извън класа НЕ МОЖЕМ да създаваме и работим с кутийки
	// => това е капсулация + абстракция. Само списъкът знае как е организиран, ние получаваме
	// различни непрозрачни методи за работи с него - push, pop, insert, front и т.н.
	struct box
	{
		T data;
		box* next;

		box(T _d, box* _p = nullptr) : data(_d), next(_p) {}
	};

	// достатъчен е само указател към първата кутийка - другото е за улеснение и скорост
	box* first;
	// box* last; // добавете и указател към последната кутийка и променете които методи трябва
	int _size;

	void copyFrom(const LinkedList& other)
	{
		// ВНИМАНИЕ: много бавна операция (т.к. push_back) всеки път търси края на списъка!!!
		// никога не е било казано, че във for можем да ползваме само int-ове...
		for (box* ptr = other.first; ptr != nullptr; ptr = ptr->next)
			push_back(ptr->data);
	}
	void clearEverything()
	{
		while (!empty())
			pop();
		// след това first == nullptr, и няма нужда да се грижим за това
	}
public:
	// стандартни
	LinkedList() : first(nullptr), _size(0) {}
	// Делегиране на конструктори: първо ще се изпълни дефолтния, т.е. списъкът
	// ще се инициализира по валиден начин, след което ще се изпълни тялото.
	LinkedList(const LinkedList& other) : LinkedList() { copyFrom(other); }
	LinkedList& operator=(const LinkedList& other)
	{
		if (this != &other)
		{
			clearEverything();
			copyFrom(other);
		}
		return *this;
	}
	~LinkedList()
	{
		clearEverything();
	}

	// Стандартни за списъците, вмъкване и премахване от началото.
	void push(T x)
	{
		box* newbox = new box(x, first);
		first = newbox;
		++_size;
	}
	// Не работи за празен списък (undefined behaviour) - или трябва
	// изрично да го споменем, или да се справим по друг начин (exception, return...)
	void pop()
	{
		box* tmp = first;
		first = first->next;
		delete tmp;
		--_size;
	}

	// Ако списъкът е празен, pos може да е произволна и ще работи
	// Ако списъкът е непразен, трябва pos <= size() - иначе undefined behaviour :(
	void insertAt(T x, int pos)
	{

		if (empty() || pos == 0)
		{
			push(x);
			return;
		}
		box* tmp = first;
		while (pos > 1)
		{
			--pos;
			tmp = tmp->next;
		}
		tmp->next = new box(x, tmp->next);
		++_size;
	}
	// Трябва pos да е валиден индекс, т.е. pos < size()
	void removeAt(int pos)
	{
		if (pos == 0)
		{
			pop();
			return;
		}
		box* tmp = first;
		while (pos > 1)
		{
			--pos;
			tmp = tmp->next;
		}
		box* toRemove = tmp->next;
		tmp->next = toRemove->next; // tmp->next->next
		delete toRemove;
		--_size;
	}
	// Важно - т.к. имаме само указател къ,м първата кутийка, това е супер бавно!
	// Ще става много по-бързо и лесно, ако пазихме и указател към последната кутийка.
	void push_back(T x)
	{
		insertAt(x, size());
	}

	// по-добре да се казва get или at, а не operator[], понеже е бавна операция!
	// Позициите се броят от нула.
	int& operator[](int idx)
	{
		box* tmp = first;
		while (idx)
		{
			--idx;
			tmp = tmp->next;
		}
		return tmp->data;
	}

	// Стандартни
	bool empty() const
	{
		return (first == nullptr);
		// return !first;
	}
	int size() const { return _size; }
	// Достъп до първия елемент (главата) на списъка
	int front() const { return first->data; }
	// Обхождане на целия списък
	void print() const
	{
		box* curr = first;
		while (curr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << "\n";
	}

	// Функцията е външна и е friend, за да достъпва член-данните на списъците (first)
	// ИЗИСКВА СЕ СПИСЪЦИТЕ ДА БЪДАТ СОРТИРАНИ ПРЕДВАРИТЕЛНО!
	// Заради постоянното използване на push_back() е също много бавно!
	friend LinkedList merge(const LinkedList& lst1, const LinkedList& lst2)
	{
		LinkedList result;
		box* p1 = lst1.first;
		box* p2 = lst2.first;
		// първо копираме елементите от двата списъка едновременно, докато не изчерпаме единия от тях.
		while (p1&&p2)
		{
			if (p1->data < p2->data)
			{
				result.push_back(p1->data);
				p1 = p1->next;
			}
			else
			{
				result.push_back(p2->data);
				p2 = p2->next;
			}
		}
		// ако p1 е валиден <=> изчерпали сме l2 и трябва да добавим остатъка от l1
		while (p1)
		{
			result.push_back(p1->data);
			p1 = p1->next;
		}
		// аналогично, ако p2 е валиден
		while (p2)
		{
			result.push_back(p2->data);
			p2 = p2->next;
		}
		// накрая връщаме насъбраното
		return result;
	}

	int count(T x) const{
		int count = 0;
		box *tmp = first;
		while (tmp) {
			if (tmp->data == x) count++;
			tmp = tmp->next;
		}
		return count;
	}

	LinkedList(T x, T y) : LinkedList() {
		assert(x <= y);
		box *cur = nullptr;
		while (y >= x) {
			box *newbox = new box(y--, cur);
			cur = newbox;
		}
		first = cur;
		_size = y - x + 1;
	}

	void removeAll(T x) {
		if (empty()) return;
		box *tmp = first, *parent = first;
		while (tmp) {
			if (tmp->data == x) {
				if (tmp == first) first = first->next;
				box *toBeDeleted = tmp;
				tmp = tmp->next;
				parent->next = tmp;
				delete toBeDeleted;
				_size--;
			}
			else {
				parent = tmp;
				tmp = tmp->next;
			}
		}
	}

	void append(const LinkedList &other) {
		//LinkedList newOther(other); NO!!! taka se zatriva sled kraq na append i greshka!
		box *tmp = first;
		while (tmp->next != nullptr) tmp = tmp->next;
		box *ptr = other.first;
		while (ptr) {
			box *newbox = new box(ptr->data);
			tmp->next = newbox;
			tmp = tmp->next;
			ptr = ptr->next;
		}
		_size = _size + other._size;
	}

	LinkedList concat(const LinkedList &other) const{
		LinkedList result(*this);
		result.append(other);
		return result;
	}

	LinkedList& operator += (const LinkedList &other) {
		(*this).append(other);
		return (*this);
	}

	LinkedList operator + (const LinkedList &other) const {
		return (*this).concat(other);
	}

	void map(T (*function)(T)){			//	!!!!!!!!!!
		box *tmp = first;
		while (tmp) {
			tmp->data = function(tmp->data);
			tmp = tmp->next;
		}
	}

	void reverse() {
		LinkedList copy(*this);
		clearEverything();
		box *tmp = copy.first;
		while (tmp) {
			push(tmp->data);
			tmp = tmp->next;
		}
	}
};

template<typename T>
T add42(T x) {
	return x + 42;
}

template<typename T>
T inc(T x) {
	return x + 1;
}

int main()
{
	LinkedList<int> lst;
	lst.push_back(3);     // {3}
	lst.push(2);          // {2,3}
	lst.push_back(10);    // {2,3,10}
	lst.insertAt(20, 0);  // {20,2,3,10}, аналогично на push(20)
	//lst.print();
	//lst.pop();

	LinkedList<int> lst2;
	lst2.push(12);
	lst2.push(10);
	lst2.push(5);
	lst2.push(1);	// {1,5,10,12}

	LinkedList<int> lst3 = merge(lst, lst2);
	//lst3.print();
	//cout << lst3.count(10) << endl;

	LinkedList<int> lst4(1, 10);
	//lst4.print();

	LinkedList<int> lst5;
	lst5.push_back(5);
	lst5.push_back(9);
	lst5.push_back(10);
	lst5.push_back(5);
	lst5.push_back(5);
	lst5.push_back(7);
	lst5.push_back(8);
	lst5.push_back(5);
	//lst5.print();
	lst5.removeAll(5);
	//lst5.print();
	//cout << lst5.size() << endl;

	lst3.append(lst5);
	lst3 += lst5;	//  <=> lst3.append(lst5);
	//lst3.print();

	LinkedList<int> lst6;
	lst6 = lst3.concat(lst5);
	lst6 = lst3 + lst5;	//  <=> lst6 = lst3.concat(lst5);
	//lst3.print();
	//lst5.print();
	//lst6.print();

	lst6.map(add42<int>);
	//lst6.print();

	lst6.reverse();
	//lst6.print();

	LinkedList<double> listDouble;
	listDouble.push(1.14);
	listDouble.push(7.88);
	listDouble.push(5.1);
	listDouble.push(4.875);
	listDouble.push(2.34);
	listDouble.push(6.00);
	listDouble.push(5.72);
	//listDouble.print();
	//listDouble.pop();
	//listDouble.print();

	LinkedList<double> listDouble2;
	listDouble2.push_back(7.88);
	listDouble2.push_back(4.875);
	listDouble2.push_back(2.34);
	listDouble2.push_back(5.72);

	listDouble += listDouble2;
	//listDouble.print();

	listDouble.map(add42<double>);
	//listDouble.print();

	LinkedList<char> listChar;
	listChar.push_back('A');
	listChar.push_back('z');
	listChar.push_back(' ');
	listChar.push_back('s');
	listChar.push_back('u');
	listChar.push_back('m');
	//listChar.print();

	LinkedList<char> listChar2;
	listChar2.push_back(' ');
	listChar2.push_back('P');
	listChar2.push_back('u');
	listChar2.push_back('h');
	listChar2.push_back('i');
	listChar2.push_back('!');

	listChar += listChar2;
	listChar.print();

	listChar.map(inc<char>);
	listChar.print();

	system("pause");
	return 0;
}
