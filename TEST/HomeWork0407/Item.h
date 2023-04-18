#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

// ù��° ����
// ������ �÷��̾��� ��ź ������ �����ϵ��� �ٲټ���

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

