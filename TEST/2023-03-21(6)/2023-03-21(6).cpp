// 금일 강의 내용 : class 사용법

#include <iostream>

class Player
{
    // 클래스문법에서는 속성이나 행동을
    // 내가 외부에 공개할지 안할지 결정할 수 있습니다.
    
    // 3가지 코드영역이 존재함
    // 내부코드 : 
    // 자식코드 :
    // 외부코드 : 스코프 내부가 아니면 다 외부

public: // 모두에게 공개한다.
    int Att = 10;
    int Def = 2;
protected: // 외부에 공개하지 않는다.
    int Hp = 100;
private:  // 모두에게 공개하지 않는다.
    int Speed = 3;

// 아래를 접근제한 지정자라고 부릅니다.
// public 접근제한 지정자를 썻다.
// 접근제한 지정자는 만들어진 위치부터 아래까지 새로운 접근제한 지정자가 없으면
// 전부다 자신의 접근제한 지정자로 판단한다.
//              내부코드     자식코드    외부코드
//public         공개         공개        공개
//protected      공개         공개       비공개
//private        공개        비공개      비공개
};
class Monseter
{
    // 디폴트값은 private로 설정되어있음
    // public를 사용하지 않으면 외부에서 사용하지 못함
    int Att = 10;
    int def = 2;
    int Hp = 100;
    int Speed = 3;

public:
    // Get, Set함수는 만들어 주는게 좋음 << 이 함수들을 통해서만 값을 조절할 수 있게 하기 위해
    int GetAtt()
    {
        return Att;
    }
    void SetAtt(int _Att)
    {
        // 통로가 하나로 만들면 어디서 버그가 발생했는지 알 수 있음
        Att = _Att;
        if (_Att == 0)
        {
        }
    }
};
int main()
{
    // 외부코드
    Player NewPlayer = Player();
    // 레벨업해서 스텟이 오르면 좋겠다
    //NewPlayer.
    
    // 속성은 Private로 만드는게 좋음
    // 보통 행동을 만들면 public으로 만듭니다.
    // 그럼 공격력을 고치고 싶으면 어떻게 하느냐??
    // class안에 get, set함수를 만들어서 사용하는게 좋음
    // 그래야 버그를 찾기 좋음 (실력이 늘어남)
    // 습관을 들여놓는게 중요함
}
