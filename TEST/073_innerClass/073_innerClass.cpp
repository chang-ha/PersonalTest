// 073_innerClass


#include <iostream>
template <typename DataType>
class Test
{
public:
	// 클래스안의 클래스
	// 이걸 이너클래스 문법이라고 합니다.
	// 이너클래스라고 해당 클래스(Test)와 연관이 있는것은 아님
	// Test클래스의 Value는 publicInner가 사용하지 못함
	// template는 사용 가능함
	// "이너클래스 사용 이유"
	// 1. 외부에 있는 클래스(Test)가 네임스페이스가 되어줄 뿐임
	// 2. 이 클래스를 Test클래스만 사용하게 하고 싶을 떄
	// 전혀 상속과 다름
	class publicInner
	{
	public:
		publicInner()
		{
			// Value = 100;
			// Test에 있는 Value를 사용할 수 없음
			// "그냥 해당 클래스가 Test클래스 외부에 있다고 보는게 좋음"
		}
		DataType InnerValue = 0;
	};
protected:

private:
	class privateInner
	{

	};
	DataType Value = 0;
};
int main()
{
	Test<int>::publicInner Inner;
	// Test::privateInner(); << private에 있으면 사용 불가능

}