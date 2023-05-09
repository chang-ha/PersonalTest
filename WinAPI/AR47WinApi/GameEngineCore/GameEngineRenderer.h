#pragma once
#include "GameEngineObject.h"

class GameEngineRenderer : public GameEngineObject
{
public:
	// constructer destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete function
	GameEngineRenderer(const GameEngineRenderer& _Ohter) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Ohter) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

protected:

private:

};

