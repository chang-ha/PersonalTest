// 금일 강의 내용 : Member, NameSpace

#include <iostream>

// 전역
// 이렇게 전역안에 선언된 함수를 전역함수라고 합니다.

// Value 전역변수
int Value = 0;

// Test 전역함수
void Test()
{

}

// 사용자 정의 자료형 내부의 공간을 멤버공간이라고 합니다.
class Player
{
private: // 명확하게 선언하는 것을 좋아한다
	int HP; // << 멤버변수라고 부릅니다.

public:
	// 멤버 함수라고 부름
	void Damage(int _Att)
	{
		// 여기는 다시 그냥 지역이라고 부름
		int Value = 20; // << 그냥 지역변수
	}

};
int main()
{
	// C++에서 영역에 대한 구분은
	// 전역, 지역, 멤버, 이름있는 NameSpace
}
