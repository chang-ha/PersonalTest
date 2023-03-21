// HomeWokr0321

// 플레이어와 몬스터의 상태창이 실시간으로 바뀌도록 수정하기
// 무식하게 하자

#include <iostream>
#include <conio.h>
void Damage
(const char* const _AttName,    
    const char* const _DefName,     
    const int& _Att,                
    int& _HP)                       
{
    printf_s("%s공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다\n", _DefName, _Att);
    _HP -= _Att;
}


void StatusRender
(const char* const _Name,           
    const int& _Att,                
    const int& _HP)                 
{
    printf_s("%s의 스테이터스 -----------\n", _Name);

    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);
    printf_s("---------------------\n");


}

int main()
{   int PlayerHP = 100;
    int PlayerAtt = 10;

    int MonsterHP = 100;
    int MonsterAtt = 10;
    while (true)
    {
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
