// 063_vfptr


#include <iostream>
class FightUnit
{
public:
	virtual void Damage()
	{

	}

	virtual void StatusRender()
	{

	}

	FightUnit()
	{
		this;
		int a = 0;
	}

protected:

private:

};

// 함수를 아무리 많이 상속받아도 메모리크기에 영향을 주진 않음 (함수는 코드영역에)
class Player : public FightUnit
{
public:
	void Damage() override
	{

	}

	/*void StatusRender() override
	{

	}*/
	Player()
	{
		this;
		int a = 0;
	}
protected:

private:
};
int main()
{
	// 가상함수가 없을때는 1, 가상함수가 있으면 8이 되어버림 (가상함수가 2~3개 있어도 8바이트)
	// 왜 크기가 8이 되었을까?????
	// virtual의 동작원리
	// virtual이 붙어있는 클래스가 존재한다면
	// 이 클래스의 객체가 생성될 때
	// 함수포인터의 배열을 만들어내고 그걸 함수포인터의 포인터로 저장합니다
	// void(*__Vfptr[???])() <= 가상함수 테이블이라고 합니다.
	// void(**__VfPtr)(); << 해당 인자를 클래스가 저장하고 있음 (가상함수 테이블의 시작주소)
	int Value = sizeof(Player);

	Player NewPlayer;

	// override를 사용하지 않으면
	// Player의 vfptr배열안에는 FightUnit::StatudRender가 들어있음 (부모형으로 작동)
	// override한 함수는
	// Player의 vfptr배열안에 Player::Damage가 들어있음 (자식형으로 작동)
	// 그래서 override를 하지 않으면 부모 함수를 가지고 있음
}

