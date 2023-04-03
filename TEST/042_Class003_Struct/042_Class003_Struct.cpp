// 041_Class003_Struct


#include <iostream>
// struct는 class와 완전히 동일한데 단 하나 다르다
// 디폴트 접근제한자가 다름
class Player
{
    int Att = 10;
    int def = 2;
    int Hp = 100;
    int Speed = 3;
};

struct Monster
{
    int Att = 10;
    int def = 2;
    int Hp = 100;
    int Speed = 3;
};

int main()
{
    Player NewPlayer; // 디폴트 접근제한자가 private
    Monster NewMonster; // 디폴트 접근제한자가 public
    //NewPlayer.
    //NewMonster.
}