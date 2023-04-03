// 050_ClassOperator


#include <iostream>
class Number
{
private:
	int Value;
public:
	Number(int _Value)
		: Value(_Value)
	{

	}
	// operator는 클래스가 연산자를 쓸 수 있게 만들어주는 것.
	int operator+(int _Value)
	{
		return Value + _Value;
	}

	bool operator==(bool _Value)
	{
		return Value == _Value;
	}

	/*int operator[]*/
};
int main()
{
	{
		int Value = 10;
		Value + 10;
	}
	{
		// 자신이 논리적으로 이 연산자는 이렇게 만들면 되겠다 할 수 있는 모든 연산자를 만들어 오기
		// 이 연산자들은 제약이 있다.
		// 안되는 것들이 있을것임
		// 모든 연산자는 다 할 수 있을것 (형식만 맞추면)
		// 어떤 애들은 return값에 따라 에러가 날 수 도 있음
		Number Value = 10;
		Value + 10; // << 더하기가 안되는 이유는? 내가 기능을 안만들었기 떄문에
		if (Value == 10)
		{
			int a = 0;
		}

	}
	Number NewNumber = 10;

	// 연산자 겹지정함수라고 부른다.
	NewNumber + 10; // ==
	NewNumber.operator+(10);

	// 리턴값 생각하지 말고, 정확히 해당 함수랑 동작방법이 같지 않아도 됨
	// 어디까지 되는지만 해오기
}

