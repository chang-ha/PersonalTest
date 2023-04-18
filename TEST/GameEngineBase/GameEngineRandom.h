#pragma once

class GameEngineRandom
{
public:
	static GameEngineRandom MainRandom;
	// constructer destructer
	GameEngineRandom();
	GameEngineRandom(int _Seed);
	~GameEngineRandom();

	// delete function
	GameEngineRandom(const GameEngineRandom& _Ohter) = delete;
	GameEngineRandom(GameEngineRandom&& _Ohter) noexcept = delete;
	GameEngineRandom& operator=(const GameEngineRandom& _Other) = delete;
	GameEngineRandom& operator=(GameEngineRandom&& _Other) noexcept = delete;

	int RandomInt(int _Min, int _Max);
protected:

private:
	int Seed = 0;
};

