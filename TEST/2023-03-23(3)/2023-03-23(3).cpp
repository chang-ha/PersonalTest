 // 금일 강의 내용 : class object pointer

#include <iostream>
class Player
{
public: 
	void Damage(/*Player* const this*/)
	{
		// this 가 0번지인 것임
		printf_s("맞았습니다");
	}
public:
	int Hp = 100;
	int Att = 10;
};

int main()
{
	int Value = int();
	Player NewPlayer = Player();

	int* ValuePtr = &Value;
	Player* NewPlayerPtr = &NewPlayer;

	// ValuePtr = nullptr;
	// *ValuePtr = 20; << nullptr 익셉션이 납니다
	// 절대 하면 안되는 것 (nullptr의 값을 수정하려고 함)

	// NewPlayerPtr = nullptr;
	// 위와 동일한 내용으로 하면 안되는 짓
	// NewPlayerPtr->Hp = 20;

	// 위에것들은 0번지의 값들을 바꾸려고 했지만
	// 아래는 값은 건드리지 않음 그냥 출력한 함수라서 정상작동함
	NewPlayerPtr = nullptr;
	NewPlayerPtr->Damage();

	// 그래서 null을 부여하는 곳이 어딘지 잘 확인하고 위에처럼 쓰지 말기!!!!!!
}

