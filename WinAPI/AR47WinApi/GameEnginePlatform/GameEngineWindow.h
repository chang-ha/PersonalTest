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
protected:

private:
	// �ش� ���α׷��� hInstance�� �ޱ����� static����
	static HINSTANCE Instance;
	// ������â�� Title�� �ޱ����� std::string����
	std::string Title = "";
	// ������ �ڵ��� �ޱ����� �������
	HWND hWnd = nullptr;
	// ������â�� �׸��� �׸������� ������ �ڵ�
	HDC Hdc = nullptr;
	// ������â�� ������Ʈ �ؾ��ϴ��� üũ�ϴ� bool��
	static bool IsWindowUpdate;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void MyRegisterClass();
	void InitInstance();

};

