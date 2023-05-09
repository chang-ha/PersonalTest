#pragma once
#include <Windows.h>

class GameEngineTime
{
public:
	static GameEngineTime MainTimer;

	// constructer destructer
	GameEngineTime();
	~GameEngineTime();

	// delete function
	GameEngineTime(const GameEngineTime& _Ohter) = delete;
	GameEngineTime(GameEngineTime&& _Ohter) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;

	// �帥 �ð�(float)�� return���ִ� ����Լ�
	float GetDeltaTime()
	{
		return FloatDelta;
	}

	// ���ݱ��� ������ �ð��� �ʱ�ȭ�ϴ� ����Լ� 
	void Reset();

	// �� �������� ������ ���� �帥 �ð��� DoubleDelta, FloatDelta�� �����ϴ� �Լ�
	void Update();
protected:

private:
	LARGE_INTEGER Count = { 0 }; // 1�ʿ� �� �� �����ִ��� �����ϴ� �������
	LARGE_INTEGER Cur = { 0 }; // ���ݱ��� �� �� �������� �����ϴ� �������
	LARGE_INTEGER Prev = { 0 }; // �������� �� �� �������� �����ϴ� �������
	__int64 Tick; // Tick(�� �� ��������) ���̰��� �����ϱ� ���� �������
	double DoubleDelta; // �帥 �ð��� double�� �����ϴ� �������
	float FloatDelta; // �帥 �ð��� float�� �����ϴ� �������
};

