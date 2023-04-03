// 051_ClassConst


#include <iostream>
class Player
{
public:
	// GetHp << Hp를 그저 확인하는 함수인데 값이 바뀌면 안되니까 const를 붙인다
	// 보통 Get함수 및 필요한 함수들은 (값이 바뀌면 안되는 것들)에는 const를 붙인다.
	// 뒤에 const를 붙이면 값이 안바뀐 다는걸 다들 알고있음
	int GetHp() const
	{
		return Hp;
	}

	// Set함수는 값이 바뀌는 함수이기 때문에 const를 붙이면 안됨
	void SetHp(int _Value)
	{
		Hp = _Value;
	}

	// 멤버함수뒤에는 const를 붙일 수 있다.

	// 함수뒤에 const를 붙이면
	// 이 함수를 호출한다고 해도
	// 이 클래스를 통해서 만들어진 객체는 변화하지 않을거야.
	void PrintStatus() const
	{
		// 멤버함수 뒤에 const를 붙이면 멤버변수를 고칠 수 없다. => X
		// this->Att += 100;
		// Att += 100;
		this; // << const를 붙이면 Player* const this가 const가 되어버리는 것 
		// => const Player* const this가 되어 버리는 것
		printf_s("플레이어의 능력치 -----------\n");
		printf_s("공격력 : %d\n", Hp);
		printf_s("체력 : %d\n", Att);
		printf_s("----------------------------\n");

		printf_s("플레이어의 능력치를 출력합니다.");
	}

protected:

private:
	int Hp = 100;
	int Att = 10;
};
int main()
{
	Player NewPlayer = Player();
	NewPlayer.PrintStatus();
}