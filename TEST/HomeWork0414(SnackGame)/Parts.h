#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

class Parts : public ConsoleGameObject
{
public:
	// constructer destructer
	Parts();
	~Parts();

	// delete function
	Parts(const Parts& _Ohter) = delete;
	Parts(Parts&& _Ohter) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

protected:
	void Update() override;
private:
	Parts* Prev;
	Parts* Next;
};

