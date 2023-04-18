#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>

class ConsoleGameScreen;
class Body : public ConsoleGameObject
{
public:
	// constructer destructer
	Body();
	~Body();

	// delete function
	Body(const Body& _Ohter) = delete;
	Body(Body&& _Ohter) noexcept = delete;
	Body& operator=(const Body& _Other) = delete;
	Body& operator=(Body&& _Other) noexcept = delete;

protected:

private:

};

