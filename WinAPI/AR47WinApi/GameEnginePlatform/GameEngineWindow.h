#pragma once
#include <Windows.h>
#include <string>
#include "GameEngineWindowTexture.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineWindow
{
public:
	// 클래스 내부에 static변수로 선언(싱글톤 X)
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

	float4 GetScale()
	{
		return Scale;
	}

	GameEngineWindowTexture* GetWindowBuffer()
	{
		return WindowBuffer;
	}

	GameEngineWindowTexture* GetBackBuffer()
	{
		return BackBuffer;
	}

	void SetPosAndScale(const float4& _Pos, const float4& _Scale);

	void ClearBackBuffer();
	void DoubleBuffering();
protected:

private:
	// 해당 프로그램의 hInstance를 받기위한 static변수
	static HINSTANCE Instance;
	// 윈도우창의 Title을 받기위한 std::string변수
	std::string Title = "";
	// 윈도우 핸들을 받기위한 멤버변수
	HWND hWnd = nullptr;
	// 2차원 배열 형식의 색깔들의 집합이 존재하고
	// 거기에 그림을 그리거나 수정할수 있는 권한을 HDC
	// 요약 : 윈도우창에 그림을 그리기위한 윈도우 핸들
	HDC Hdc = nullptr;
	// 윈도우창을 업데이트 해야하는지 체크하는 bool값
	static bool IsWindowUpdate;
	// 윈도우창에 뜨는 것도 GameEngineTexture로 다루기 위한 멤버변수
	// 내 의견 : WindowBuffer를 캔버스로 생각하고, 나머지 DC들은 캔버스에 그려야하는 대상이라고 생각
	GameEngineWindowTexture* WindowBuffer = nullptr;

	// 한 윈도우 창에 그림이 여러개 그려지게 되면 서로 영역다툼을 하면서 깜빡이게 그려짐
	// 그래서 미리 BackBuffer에 다 그려놓고 BackBuffer를 WindowBuffer에 옮겨오는 형식으로 구성
	GameEngineWindowTexture* BackBuffer = nullptr;
	
	float4 Scale;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void MyRegisterClass();
	void InitInstance();

};

