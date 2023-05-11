#pragma once
#include <Windows.h>
#include <map>
#include <string>
// �����쿡 ������ Input���� �ش� Ŭ������ ���� ������ ���� ó���� ����
class GameEngineInput
{
private:
	// Ű �ϳ��� üũ�ϰ� ��( AŰ, BŰ ���...)
	class GameEngineKey
	{
		// ���¸� üũ�ϱ� ���� ���������

		// Down�� ������ ���� �ѹ��� üũ��
		bool Down = false;
		// Ű�� ��� ������ �ִ��� üũ��
		bool Press = false;
		// Ű�� ���� ���� �ѹ��� üũ��
		bool Up = false;
		// �ȴ����� �ִ�.
		bool Free = true;
		// �ش� Ű�� �� �ʰ� ��������?
		float PressTime = 0.0f;

		int Key = -1;
		bool KeyCheck()
		{
			return 0 != GetAsyncKeyState(Key);
		}

		void Update(float _DeltaTime);
	};
public:
	// constructer destructer
	GameEngineInput();
	~GameEngineInput();

	// delete function
	GameEngineInput(const GameEngineInput& _Ohter) = delete;
	GameEngineInput(GameEngineInput&& _Ohter) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;

protected:

private:
	static std::map <std::string, GameEngineKey> AllKeys;
};

