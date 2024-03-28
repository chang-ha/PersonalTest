#include<memory>
#include <iostream>

class Parent : public std::enable_shared_from_this<Parent>
{
public:
	Parent()
	{
		std::cout << "Parent" << std::endl;
	}

	~Parent()
	{
		std::cout << "~Parent" << std::endl;
	}

	std::shared_ptr<class Child> mChild;
};

class Child : public std::enable_shared_from_this<Child>
{
public:
	Child()
	{
		std::cout << "Child" << std::endl;
	}

	~Child()
	{
		std::cout << "~Child" << std::endl;
	}

	std::weak_ptr<Parent> mParent;
};


int main()
{
	std::shared_ptr<Parent> p = std::make_shared<Parent>();
	std::shared_ptr<Child> c = std::make_shared<Child>();

	p->mChild = c;
	c->mParent = p;

	long long address = reinterpret_cast<long long>(c->mParent);

	int a = 0;
}
