#pragma once

#include <Windows.h>
#include <assert.h>
#define MsgBoxAssert(Text) 	MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);

//class GameEngineDebug
//{
//public:
//	// constructer destructer
//	GameEngineDebug();
//	~GameEngineDebug();
//
//	// delete function
//	GameEngineDebug(const GameEngineDebug& _Ohter) = delete;
//	GameEngineDebug(GameEngineDebug&& _Ohter) noexcept = delete;
//	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
//	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;
//
//protected:
//
//private:
//
//};
//
