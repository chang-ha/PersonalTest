// 072_Enum


#include <iostream>

// enum은 컴파일되면 무조건 int로 바뀜
// 아무것도 안넣어주면 차례대로 0 1 2 3 ...
//enum GameJobType
//{
//	Fighter, // 0
//	Mage, // 1
//	Archer, // 2
//	Paladin, // 3
//};

// enum class는 좀 더 형을 따진다
// 암시적 형변환이 다 막혔다.
// 이녀석은 그냥 int가 될 수 없다.
enum class GameJobType
{
	Fighter, // 0
	Mage, // 1
	Archer, // 2
	Paladin, // 3
};

class FightUnit
{
	// 직업이 이 클래스 안에 있다고 치면
	// 직업이 뭔지 알기위한 값
	//int JobType;

	GameJobType JobType;
	// ex)
	// 0 == 전사
	// 1 == 마법사
	// 2 == 궁수
	// 3 == 성기사
	// 이렇게 표현하면 숫자만 보고 직업을 알 수가 없음 
	// 그때 사용하는게 enum
public:
	// 
	void SetJobType(GameJobType _Type)
	{
		JobType = _Type;
	}
};
int main()
{
	// 직업이라는게 있다고 쳤을 떄
	FightUnit NewUnit;

	// NewUnit.SetJobType(0) << 이렇게 되어있으면 직업이 뭔지 알 수가 없음
	NewUnit.SetJobType(GameJobType::Archer);
	// NewUnit.SetJobType(0) << enum을 쓰고 int를 넣으면 에러가 발생함

	// 그런데 enum으로 선언한 변수들은 암시적 형변환이 지원됨
	// int Value = Archer;

	// 그래서 enum class로 하게 되면
	int Value = (int)GameJobType::Archer;

}

