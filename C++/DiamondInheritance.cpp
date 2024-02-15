#include <iostream>
using namespace std;
class Person {
public:
	Person(int x) { cout << "Person::Person(int ) called" << endl; }
	Person() { cout << "Person::Person() called" << endl; }

	virtual void Call()
	{
		cout << "Person Call" << endl;
	}
};

class Faculty : virtual public Person {
public:
	Faculty(int x) :Person(x) {
		cout << "Faculty::Faculty(int ) called" << endl;
	}

	void Call() override
	{
		cout << "Faculty Call" << endl;
	}
};

class Student : virtual public Person {
public:
	Student(int x) :Person(x) {
		cout << "Student::Student(int ) called" << endl;
	}

	void Call() override
	{
		cout << "Student Call" << endl;
	}
};

class TA : public Faculty, public Student {
public:
	TA(int x) : Student(x), Faculty(x), Person(x) {
		cout << "TA::TA(int ) called" << endl;
	}

	void Call() override
	{

	}
};

int main() {
	TA ta1(30);
}
