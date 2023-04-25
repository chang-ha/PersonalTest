// etc_StaticMember


#include <iostream>
// C++는 객체지향 언어가 아니라는걸 확실히 설명할 수 있다
//    << 이유는 전역변수의 존재

// C++는 절차 + 객체이기 때문에 섞이면 안되는 존재들이 섞임

// 오직 클래스와 객체로만 코딩해야하는것이 객체지향이다.
// 객체를 지향하지 않으면 객체지향이 아니다.
// 다른건 인정하지 않아 (전역)

class Player
{
    // 클래스 내부에 존재하는 값들조차 public은 접근 가능, private는 접근 불가능...
private:
};

// 전역변수
// 어디에도 속하지 않음 (클래스, 함수에 속하지 않음)
//      << 이는 객체지향을 깨는 뜻임
// 객체지향은 오직 객체로만 코딩해야함
// 다른 객체지향 언어를 보면 main()함수조차 class내부에 있음
int Test = 10;

class Monster
{
public:
    static int Count;
    int Hp;
    Monster()
    {
        // 4를 원하지만 1이 나옴
        // 저 값(privateCount)들은 객체마다 각자 가지고 있기 때문에 (a객체의 privateCount, b객체의 preivateCount... = 모두 1)
        // 전역변수로하면 4가 나옴 << 그치만 객체가 깨져버림
        // 그래서 class의 전역변수를 문법생성
        // 그게 "static 멤버변수"
        // ++MonsterCount;
        ++privateCount;
    }

    // 함수의 선언
    // 이렇게 하면 "확인할 수 없는 외부 기호" 에러가 남
    // 선언만해놓고 실체가 없음(구현을 안했음) << 어떤식으로든 안한것임
    void Print();

    int GetAllMonsterCount()
    {
        return privateCount;
    }

private:
    // 현재까지 만들어진 모든 몬스터수를 알고싶다.
    // 생성함수(Monster())내부에 ++Count를 해도 안됨
    // 그 이유는?? MonsterCount라는 변수는 객체마다 다 가지고 있는 변수이기 때문
    // 모든 객체가 MonsterCount = 1의 값을 가짐
    int MonsterCount = 0;
    // static int MonsterCount;
    // 전역변수라 메모리영역에 들어가야하는데
    // 막상해보면 에러가 나옴 ("확인할 수 없는 외부 기호")
    // 왜 나올까???
    //      >> void Print()로 이동

    // 몬스터만 사용할 수 있는 전역변수
    // 실체는 없고 구상(설계)만 있음
    static int privateCount;
};

// 전역에서 초기화해줘야함(클래스 외부에서 실제 메모리를 할당받는 것)
// 실체를 둔다는 것
int Monster::privateCount = 0;


int main()
{
    // 객체의 전역변수는 아래처럼 사용할 수 있다
    // 몬스터가 관리하는 전역변수다 == 몬스터라는 속성에 속한 전역변수
    // 전역변수라서 모두가 접근가능
    // 객체 자기만 쓸 수 있는 변수가 아니니까 믿을만하지 않음
    Monster::Count = 10;
    // 아래는 Monster만 쓸 수 있는 전역변수이기 때문에 main에서 접근 X
    // Monster::privateCount = 10;

    Monster NewMonetsr0 = Monster();
    Monster NewMonetsr1 = Monster();
    Monster NewMonetsr2 = Monster();
    Monster NewMonetsr3 = Monster();
    NewMonetsr0.Print();

    // 함수는 그럼 객체있어야만 사용할 수 있나???
    // 클래스에 속한 전역함수 또한 존재
    // static int GetSet()...
    // 함수명 앞에 static 붙여줘야함
    // 사용시에는 Monster::GetSet()
}
