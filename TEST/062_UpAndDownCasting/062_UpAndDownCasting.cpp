// 062_UpAndDownCasting


#include <iostream>

class FightUnit
{
public:
    int Hp = 100;
    int Att = 10;

    void Damage(int _Damage)
    {
        Hp -= _Damage;
    }

    // 이 GetArr가 각자 자식형일때는 자식들의 방식으로 동작하게 도와주는 문법이 있다.
    // 그걸 Virtual이라고 한다 ("가상함수 문법")
    // 이렇게 가상함수라는것이 만들어지게 되면
    // 자식이 이걸 새롭게 정의하지 않는다면 부모형으로 동작하고
    // 자식이 이걸 새롭게 정의하면 자식형으로 동작한다
    // 이때 정의하는 방식은 부모와 완전히 동일한 함수로 정의해야 한다.
    // 함수이름, 받는인자가 같아야함 << 내 의견 : 인자가 다르면 함수의 오버로딩때문에 인식을 못하더라;;
    virtual int GetAtt()
    {
        return Att;
    }
};

class Player : public FightUnit
{
public:
    int Lv = 3;
    void PlayerDamage(int _Damage, int _Lv)
    {
        Hp -= _Damage + _Lv;
    }


    // FightUnit의 GetAtt가 Player에서는 다르게 동작하도록 하는 문법
    // 이를 "오버라이드 문법"이라고 한다.
    // 명시적으로 overraid했다는 것을 표현해주는것이 좋은데
    // 내용은 함수뒤에 붙여주는게 좋음
    // 붙이면 명시적임 (선생님은 명시적이지 않은걸 싫어하심)
    int GetAtt() override
    {
        return FightUnit::GetAtt() + Lv;
    }

    // override는 부모쪽에 virtual함수가 없으면 에러가 발생
    /*void Test() override
    {

    }*/
};

class Monster : public FightUnit
{

};

// 싸우기 위한 기능은 FightUnit을 다 갖기로했음
// Upcasting때문에 이 함수가 가능함
void Fight(FightUnit* _Left, FightUnit* _Right)
{
    // _Right->Damage(_Left->Att);
    // _Left->Damage(_Right->Att);

    // 그런데 객체마다 공격력에 영향을 미치는게 다를 수가 있음 (플레이어의 데미지는 레벨에 비례)
    // 최악의 방법은 다운캐스팅을 이용하는 것이다!!!!!!!!!!!!!
    // FightUnit을 다시 Player로 만드는 것
    // Player* PlayerPtr = (Player*)_Left; << FightUnit* _Left를 Player(자식클래스)로 다운캐스팅
    
    // _Right->PlayerDamage(_Left->Att);
    // _Left->Damage(_Right->Att);

    // 만약 왼쪽에 몬스터가 들어오면 몬스터가 플레이어로 바뀜 
    //        << Moster정보를 가지고 있던 FightUnit*이 Player*로 바뀌는 이상한 현상이 되어버림
    // 그러면 무슨일이 벌어질 지 알수가 없고
    // 이 방법은 사용하지 않는다!!!!!!!!!!!!!!!!

    // 부모클래스는 자식클래스를 절대로 알면안됨
    // 언제나 문제가 생김

    // 그래서 문법을 더 익혀야함
    // 플레이어일때는 다르게 작동하고
    // 몬스터일때는 다르게 작동하고...
    // 다형성을 가져야함
    // 겉으로보기엔 FightUnit이지만 실제로보면 Player, Monster, Npc, Boss가 다다름

    int LeftAtt = _Left->GetAtt();
    int RightAtt = _Right->GetAtt();

    _Right->Damage(LeftAtt);
    _Left->Damage(RightAtt);
}
int main()
{
    Player NewPlayer;
    Monster NewMonster;
    FightUnit* Ptr;

    // 아래는 자료형이 다른데 암시적 형변환이 일어났음
    // Player는 FightUnit을 온전히(모든 내용을) 들고 있음 << 상속받았기 떄문
    // 그래서 FightUnit부분(앞부분)의 주소값만 받아오면 되기 떄문
    // 참조형일떄 이 현상을 UpCasting이라고 부른다.
    Player* PlayerPtr = &NewPlayer;
    Monster* MonsterPtr = &NewMonster;

    FightUnit* Ptr = PlayerPtr;
    // FightUnit* Ptr2 = MonstePtr; << Monster가 상속받지 않으면 형변환 불가능

    // Monster도 상속받으면 아래처럼 사용 가능
    Fight(&NewPlayer, &NewMonster);

    {
        // 다운캐스팅
        // 부모형을 자식형으로 "강제로" 자료형을 바꿔준다 << 위험성이 있다
        // 내가 직접 쳐줘야함
        FightUnit* Ptr1;
        Player* Ptr2 = (Player*)Ptr1;

        // 다운캐스팅을 꼭 해야하는 경우를 본 적이 없다.
        // 그래서 위험하다 << 만약 내가 해야한다고 생각이 든다면 내가 잘못생각한 것
        // 그냥 하면 절대로안됨 (안전하게 하는방법은 추후에 배움)
    }
}
