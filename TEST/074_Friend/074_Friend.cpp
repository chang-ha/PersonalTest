// 074_Friend


#include <iostream>
// 클래스 A의 Value를
// 클래스 B에만 공개하고 싶음
// 클래스 C는 모르게 하고 싶음
class B;
class A
{
public:
protected:
	// 특정 클래스에게 자신의 접근제한 지정자를
	// 취소시키는 문법
	// 그치만 해당 문법을 싫어하는 사람들이 있음
	// 객체지향을 정면에서 부숴버리는 문법이니까
	// 이런 문법을 사용하면 객체지향을 왜 함?? (private가 왜 있어??)
	// 선생님의견 : 애초에 c++는 객체지향 언어가 아니야.... (짬뽕언어야)
	friend B;
	// 내 의견
	// A가 B한테 접근권한을 주는 것
	// B는 A한테 접근권한을 주는 것은 아님
	// friend는 일방향임 A->B
private:
	int Value = 0;
};
class B
{
public:
	void Function(A& _Other)
	{
		_Other.Value = 20;
	}
protected:
private:
};
class C
{
public:
protected:
private:
};
int main()
{

}