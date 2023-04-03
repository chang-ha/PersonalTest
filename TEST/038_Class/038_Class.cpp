// 038_Class


#include <iostream>
#include <conio.h>
// C는 절차지향으로는 객체(플레이어)를 만들 수가 없음
// 행동 하나하나가 다 데이터


// C++는 객체지향언어
// 나는 그저 플레이어를 만들고 싶은 것
// 여러 데이터를 묶어서 하나의 객체로 보고 싶음
// 캡슐화, 추상화
// 객체 스스로일은 스스로가 해야함


// C++ << C를 기반문법으로 해서 객체지향을 추가한 언어
// + 다른언어에서 좋다고 칭찬받은 문법들을 마구잡이로 흡수

// 특정대상이 다른 대상을 때린다
void Damage
(const char* const _AttName,    // 때리는 쪽의 이름
    const char* const _DefName,     // 맞는 쪽의 이름
    const int& _Att,                // 떄리는 쪽의 공격력
    int& _HP)                       // 맞는 쪽의 체력
{
    printf_s("%s공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다\n", _DefName, _Att);
    _HP -= _Att;
}

// 특정대상의 상태창
void StatusRender
(const char* const _Name,           // 때리는 쪽의 이름
    const int& _Att,                // 떄리는 쪽의 공격력
    const int& _HP)                 // 맞는 쪽의 체력
{
    printf_s("%s의 스테이터스 -----------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);
    printf_s("---------------------\n");
}

int main()
{
    // 글자로 몬스터와 플레이어가 싸우는 게임을 만들고 싶다
    // 플레이어를 만들어야 한다

    // c는 데이터를 기반으로 시작한다.
    // 행동을 정의하기 시작합니다.
    int PlayerHP = 100;
    int PlayerAtt = 10;

    int MonsterHP = 100;
    int MonsterAtt = 10;

    while (true)
    {
        // 추후설명
        // 콘솔창의 모든 글자를 지웁니다.
        system("cls");

        StatusRender("Player", PlayerAtt, PlayerHP);
        _getch();
        StatusRender("Monster", MonsterAtt, MonsterHP);
        _getch();


        Damage("Player", "Monster", PlayerAtt, MonsterHP);
        _getch();
        Damage("Player", "Monster", MonsterAtt, PlayerHP);
        _getch();
        if (0 >= MonsterHP)
        {
            printf_s("몬스터가 죽었습니다");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }
        else if (0 >= PlayerHP)
        {
            printf_s("플레이어가 죽었습니다");
            printf_s("몬스터의 승리입니다.");
            _getch();
            break;
        }
    }
}
