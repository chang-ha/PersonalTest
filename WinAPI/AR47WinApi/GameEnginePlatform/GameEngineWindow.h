#pragma once
#include <Windows.h>
#include <string>
#include "GameEngineWindowTexture.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineWindow
{
public:
	// Ŭ���� ���ο� static������ ����(�̱��� X)
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

	// ������â�� �׸��� �׸������� �ڵ��� �������ִ� �Լ�
	HDC GetHDC()
	{
		return Hdc;
	}

	// ������â ������Ʈ�� off�ϴ� ���
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
	// �ش� ���α׷��� hInstance�� �ޱ����� static����
	static HINSTANCE Instance;
	// ������â�� Title�� �ޱ����� std::string����
	std::string Title = "";
	// ������ �ڵ��� �ޱ����� �������
	HWND hWnd = nullptr;
	// 2���� �迭 ������ ������� ������ �����ϰ�
	// �ű⿡ �׸��� �׸��ų� �����Ҽ� �ִ� ������ HDC
	// ��� : ������â�� �׸��� �׸������� ������ �ڵ�
	HDC Hdc = nullptr;
	// ������â�� ������Ʈ �ؾ��ϴ��� üũ�ϴ� bool��
	static bool IsWindowUpdate;
	// ������â�� �ߴ� �͵� GameEngineTexture�� �ٷ�� ���� �������
	// �� �ǰ� : WindowBuffer�� ĵ������ �����ϰ�, ������ DC���� ĵ������ �׷����ϴ� ����̶�� ����
	GameEngineWindowTexture* WindowBuffer = nullptr;

	// �� ������ â�� �׸��� ������ �׷����� �Ǹ� ���� ���������� �ϸ鼭 �����̰� �׷���
	// �׷��� �̸� BackBuffer�� �� �׷����� BackBuffer�� WindowBuffer�� �Űܿ��� �������� ����
	GameEngineWindowTexture* BackBuffer = nullptr;
	
	float4 Scale;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void MyRegisterClass();
	void InitInstance();

};

