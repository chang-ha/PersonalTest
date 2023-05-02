#pragma once

class GameEngineTime
{
public:
	// �̱��� ����
	static GameEngineTime MainTimer;

	// constructer destructer
	GameEngineTime();
	~GameEngineTime();

	// delete function
	GameEngineTime(const GameEngineTime& _Ohter) = delete;
	GameEngineTime(GameEngineTime&& _Ohter) noexcept = delete;
	GameEngineTime& operator=(const GameEngineTime& _Other) = delete;
	GameEngineTime& operator=(GameEngineTime&& _Other) noexcept = delete;

protected:

private:
	LARGE_INTEGER Count; // 1�ʿ� �� �� �����־�?
	LARGE_INTEGER Cur; // ���ݱ��� �� �� ������?
	LARGE_INTEGER Prev; // �������� �� �� ������??
};

