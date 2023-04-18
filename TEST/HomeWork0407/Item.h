#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// 첫번째 숙제
// 먹으면 플레이어의 폭탄 위력이 증가하도록 바꾸세요

class ConsoleGameScreen;
class Item : public ConsoleGameObject
{
public:
	// constructer destructer
	Item();
	~Item();

	// delete function
	Item(const Item& _Ohter) = delete;
	Item(Item&& _Ohter) noexcept = delete;
	Item& operator=(const Item& _Other) = delete;
	Item& operator=(Item&& _Other) noexcept = delete;

	void Update() override;
protected:

private:

};

