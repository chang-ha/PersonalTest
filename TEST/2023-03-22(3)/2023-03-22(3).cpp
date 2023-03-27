// 금일 강의 내용 : NameSpace

#include <iostream>

// 코드영역에 들어감!!!!
// 실제적으로 플레이어의 스펙이나 만들어질때의 내용들은 코드영역에 들어가 있음
// 플레이어가 만들어지면 내부에 int Att를 하나 가지고 있어야 해...
class Player
{
	int Att;
};

// 같은 번지(Player)를 또 쓰려고 하면 컴파일러 에러가 발생함
// 여러명이 작업하면 이름이 겹칠 수 밖에없음
//class Player
//{
//
//};

// 그래서 나온게 namespace
namespace AProgramger
{
	// AProgramger의 Player
	class Player
	{

	};
}

namespace BProgramger
{
	// BProgramger의 Player
	class Player
	{

	};
}

namespace BProgramger
{
	// namespace는 얼마든지 열었다 닫았다 할 수 있음
	// BProgramger의 Item
	class Item
	{

	};
	// namespace안에 또 namespace를 만들 수 있다.
	namespace BValue
	{

	}
}

// 선생님은 절대절대 안쓰는 것
// 사용하지 마라
// 앞으로 이 밑에서는 AProgramger 쓰는것을 생략하겠다는 뜻
// 이렇게 코딩 문법을 사용하지 말자 하자 정하는 것 (팀장 등이 정함) << 코딩 스텐다드라고 부른다
using namespace AProgramger;


int main()
{
	// 범위 확인 연산자 (::), 스코프 확인(A::B , A안에 있는 B)
	// 범위 == 지역
	// 같은 클래스명이 있으면 컴파일러 에러가 발생하기 때문에
	// 결국은 Player이름을 길게 한 것 뿐
	// 사용하자는 주의와 사용하지 말자는 주의가 있음
	// 선생님은 사용하지 말자는 주의
	AProgramger::Player NewPlayer;
	BProgramger::Player NewPlayer;

	// std는 cout의 namespace
	// std는 c++공인 namespace == standard
	// c++가 품질 보증한 객체 혹은 클래스 혹은 모든것들을 std에 모아놓은 것
	// 그래서 std namespace에 다른 함수나 변수 만드는 것은 금기(가능은 함)
	std::cout << "Hello World!\n";
}

