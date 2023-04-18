// 076_MyCout


#include <iostream>
class MyEndl
{

};
class MyCout
{
public:
	void operator<<(const MyEndl& _Text)
	{
		printf_s("\n");
	}

	MyCout& operator<<(const char* _Text)
	{
		printf_s(_Text);
		return *this;
	}
protected:

private:
};
namespace std
{
	MyCout MCout;
	MyEndl MEndl;
}

int main()
{
	std::MCout << "Hello World!" << std::MEndl;
	std::MCout.operator<<("Hello World!").operator<<(std::MEndl);
	std::cout << "Hello World" << std::endl;
}
