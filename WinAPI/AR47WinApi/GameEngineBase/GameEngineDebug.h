#pragma once
#include <Windows.h>
#include <assert.h>

//// 설명 :
class GameEngineDebug
{
public:
	// constrcuter destructer
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;

	static void LeckCheck();

protected:

private:

};

// c_str (std::string을 const char*로 바꿔주는 함수)
// const char* Ptr = Value.c_str(); 
#define MsgBoxAssert(Text) \
std::string Value = Text; \
MessageBoxA(nullptr, Value.c_str(), "Error", MB_OK); assert(false);
