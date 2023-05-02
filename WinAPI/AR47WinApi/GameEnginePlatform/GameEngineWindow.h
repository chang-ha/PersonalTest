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

	// 윈도우창에 그림을 그리기위한 핸들을 리턴해주는 함수
	HDC GetHDC()
	{
		return Hdc;
	}

	// 윈도우창 업데이트를 off하는 기능
	static void WindowLoopOff()
	{
		IsWindowUpdate = false;
	}
protected:

private:
	// 해당 프로그램의 hInstance를 받기위한 static변수
	static HINSTANCE Instance;
	// 윈도우창의 Title을 받기위한 std::string변수
	std::string Title = "";
	// 윈도우 핸들을 받기위한 멤버변수
	HWND hWnd = nullptr;
	// 윈도우창에 그림을 그리기위한 윈도우 핸들
	HDC Hdc = nullptr;
	// 윈도우창을 업데이트 해야하는지 체크하는 bool값
	static bool IsWindowUpdate;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void MyRegisterClass();
	void InitInstance();

};

