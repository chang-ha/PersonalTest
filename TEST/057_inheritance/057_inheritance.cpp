// 057_inheritance(상속)


#include <iostream>
// 캡슐화
// 클래스가 특정 기능들을 내부에 품고있는 특성 그 자체를 캡슐화라고 부른다.
// 캡슐화를 지원하는 문법은 접근제한 지정자
//						  클래스 그 자체

// 상속은 객체지향의 특성중 하나로서
// 상속은 특정 개념의 특성들을 하위 개념들이 물려 받는것을 말한다
// Is a 관계 (Has a는 플레이어는 총알을 "가지고"있다)
// ex) Weapon Is a Item << 무기는 아이템이다

class Player
{

};

// 1. 기본 클래스를 만든다.
class Item
{
public:
	Player* Master;

protected:

	int Gold = 0;
private:

};

// : public Item 상속을 의미하는 문법
// 상속 관계가 된다
// 부모코드를 모두 복사해서 private는 지움
class Weapon : public Item
{
// 양쪽을 비교해 좁은 범위를 가진것을 남긴다 
//public: 비교 public
//    int Gold = 0;
//
//protected: 비교 public
//    void Buy() {
//
//    }
//
//private: 비교 public
//    void Sell()
//    {
//    }
public:
	Weapon()
	{
		Gold = 20;
	}
};

// 부모코드가 내려와서 protected로 바꿔버림
class Potion : private Item
{
public:
	Potion()
	{
		Gold = 10;
	}
};

class Armor : public Potion
{
	//Gold = 20;
};

int main()
{




}
