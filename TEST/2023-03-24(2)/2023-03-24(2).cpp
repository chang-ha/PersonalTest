// 금일 강의 내용 : parameter

#include <iostream>

class Player
{
public:
    int Value0;
    int Value1;
    int Value2;
    int Value3;
    int Value4;
    int Value5;
    int Value6;
    int Value7;
};


void StatusRenderPtr(const Player* _Player)
{
    // *랑 &를 붙이는 차이??
    // 방어코드가 필요할 때
    // 포인터에 비어있는 값이 들어올 떄가 있으면 포인터로 인자를 받음
    // 포인터로 하면 무조건 null체크해서 return
    if (nullptr == _Player)
    {
        return;
    }
}

void StatusRenRef(const Player& _Player) // << 선생님이 선호하는 방법 (무조건 플레이어를 넣어주고 방어코드를 안 만들기)
{
    // 왜 const를 붙이나?? << 능력치 보여주는데 값이 바뀌면 안됨
    // 인자값을 *, &를 붙이냐?? 
    // Player를 붙이면 32바이트
    // Player*, Player&는 8바이트로 인자를 받음
    // 그래서 int는 *, &를 붙일 필요가 없음 (int는 4바이트기 때문에 오히려 바이트크기가 커짐)
    // 이런게 정말 최적화임
}

void StatusRender(const Player _Player)
{
    // 이렇게 인자를 받아서 함수를 작성하면
    // Player 자료형 전체를 받는 것이기 때문에
    // 32바이트짜리 자료형을 인자로 받는것과 동일함
    // 그러면 실행효율이 엄청나게 안좋아짐
}

Player NewPlayer; // 전역변수 << 메모리영역 << 프로그램이 종료될 떄 사라짐
// 위와 같은 이유 때문에 주로 플레이어가 없는 경우(nullptr인 경우)가 잘 없음 
// 그래도 잠깐이라도 없어지는 경우에는 *를 인자로 하는것이 좋음(nullptr체크는 필수)

int main()
{
    int Value = sizeof(Player); // 32바이트
}