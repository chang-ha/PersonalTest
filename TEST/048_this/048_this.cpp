// 048_this


#include <iostream>
class Player
{
public:
	Player()
	{
	}	    //아래 내용이 생략되어 있음
	void Damage(/*Player* const this*/ int _Att)
	{
		__int64 Address = (__int64)&Hp;
		// 눈에 보이지 않지만 멤버함수에는
		// 첫번째 인자로 무조건 자기자신의 클래스의 포인터가 들어가게 됩니다.(Player this가 생략)

		// * const이기 떄문에 this가 가리키는 대상은 바꿀 수 없다
		// this = nullptr; << 불가능

		/*this ->*/ Hp -= _Att;
	}
	inline int GetHp()
	{
		return Hp;
	}
	inline void SetHp(int _Value)
	{
		Hp = _Value;
	}
	inline int GetAtt()
	{
		return Att;
	}
	inline void SetAtt(int _Value)
	{
		Att = _Value;
	}
protected:

public:
	int Hp = 100;
	int Att = 10;
};

// NewPlayer가 300번지라면
void GlobalDamage(Player* _this, int _Att)
{
	// 클래스를 포인터로 사용할때는
	// 내부에 있는 멤버변수에 접근하는 방식이
	// .이 아니고 ->로 변경된다.
	// 300번지에 있는 Hp에 -Att
	_this->Hp -= _Att;
}

// 이렇게 인자를 받아오면 NewPlayer가 새로 생성되는 것임
// 250번지 NewPlayer가 만들어져서 값이 복사될 뿐
// 300번지에 있는 NewPlayer가 변하는 건 아님
// 포인터를 써야함
void GlobalValue(Player _NewPlayer, int _Att)
{
	_NewPlayer.Hp -= _Att;
}

int main()
{
	// 300번지
	Player NewPlayer0 = Player();
	// 350번지
	Player NewPlayer1 = Player();

	// 300번지, 350번지에 있는 값들이 수정되는 것
	// 컴퓨터는 어떻게 300번지, 350번지의 Hp를 알아낼 수 있었는가?
	// Player0와 Player1의 주소는 불러와 보면 다름을 알 수 있음
	// class의 모든 내용은 코드영역에 존재
	// 클래스의 멤버함수를 사용한다는 것은 클래스의 포인터를 사용하고 있음을 알 수 있다.
	NewPlayer0.Damage(/*&NewPlayer0,*/ 20);
	NewPlayer1.Damage(/*&NewPlayer1,*/50);

	// 위와 동일
	GlobalDamage(&NewPlayer0, NewPlayer1.Att);

	// 이 방식은 NewPlayer가 새로 200번지에 만들어져서 300번지의 값들이 복사될 뿐
	// 300번지에 있는 NewPlayer값들이 바뀌는 건 아님
	GlobalValue(NewPlayer0, NewPlayer1.Att);

	// 객체지향적으로 안정된 구조
	// 남에게 의존하면 안되고
	// 스스로 데미지를 입고
	// 스스로 점프를 뛰어야함
	// 외부기능을 의존하면 안됨 (내부에 내 기능으로 살아가야함)

	NewPlayer0.SetHp(200);
	NewPlayer0.SetAtt(100);
}

