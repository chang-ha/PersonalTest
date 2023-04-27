#pragma once
#include <Windows.h>
#include <string>

class GameEngineWindow
{
public:
	static GameEngineWindow MainWindow;
	// constructer destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete function
	GameEngineWindow(const GameEngineWindow& _Ohter) = delete;
	GameEngineWindow(GameEngineWindow&& _Ohter) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;

	void Open(const std::string& _Title, HINSTANCE _hInstance);

	static void MessageLoop(HINSTANCE _Inst, void(*_Start)(HINSTANCE), void(*_Update)(), void(*_End)());

protected:

private:
	// 해당 프로그램의 hInstance를 받기위한 static변수
	static HINSTANCE Instance;
	// 윈도우창의 Title을 받기위한 std::string변수
	std::string Title = "";
	// 윈도우 핸들을 받기위한 멤버변수
	HWND hWnd = nullptr;

	void MyRegisterClass();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void InitInstance();

};

