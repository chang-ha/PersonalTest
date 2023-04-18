#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineConsole/ConsoleGameScreen.h>


class ConsoleGameScreen;
class Bomb : public ConsoleGameObject
{
public:
	// constructer destructer
	Bomb();
	~Bomb();

	// delete function
	Bomb(const Bomb& _Ohter) = delete;
	Bomb(Bomb&& _Ohter) noexcept = delete;
	Bomb& operator=(const Bomb& _Other) = delete;
	Bomb& operator=(Bomb&& _Other) noexcept = delete;

	void Init(int _BombPower);
protected:
	void Update() override;
	void Render() override; 

private:
	int BombCount = 5;
	int MaxExpPower = 5;
	int CurExpPower = 0;
};

