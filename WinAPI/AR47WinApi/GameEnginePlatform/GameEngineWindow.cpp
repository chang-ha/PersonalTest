#include "GameEngineWindow.h"
#include <GameEngineBase/GameEngineDebug.h>

// 해당 프로그램의 hInstance값을 받기위한 static 변수
HINSTANCE GameEngineWindow::Instance = nullptr;
// 윈도우창은 한개만 만들기 위해 싱글톤 패턴 사용
GameEngineWindow GameEngineWindow::MainWindow;

GameEngineWindow::GameEngineWindow()
{

}

GameEngineWindow::~GameEngineWindow()
{

}

// 윈도우창을 만들기 위한 전체적인 함수
void GameEngineWindow::Open(const std::string& _Title, HINSTANCE _hInstance)
{
    Title = _Title;
    Instance = _hInstance;

    if (nullptr == Instance)
    {
        MsgBoxAssert("HInstance없이 윈도우를 만들수는 없습니다.");
        return;
    }

    MyRegisterClass(); // 윈도우 형식을 등록하는 함수
    InitInstance(); // 윈도우를 생성하는 함수
}

// 윈도우형식을 등록하는 함수
void GameEngineWindow::MyRegisterClass()
{
    // 지역 static변수 선언
    // 초기화는 최초 한번만 됨
    // 해당 함수내부에서만 접근 가능
    // 윈도우형식을 단 한번만 등록하기 위해 선언한 변수
    static bool Check = false;

    if (true == Check)
    {
        return;
    }

    WNDCLASSEXA wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    // lpfnWndProc == WNDPROC ==  LRESULT(CALLBACK* WNDPROC)(HWND, unsigned int, unsigned int, unsigned int);
    wcex.lpfnWndProc = GameEngineWindow::WndProc; // 메세지 처리 방식
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = Instance; // hInstance값
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "DefaultWindow"; // 윈도우형식 이름
    wcex.hIconSm = nullptr;

    // RegisterClassExA는 ATOM(unsigned short)를 반환하는데 클래스 등록에 실패하면 0을 리턴
    if (false == RegisterClassExA(&wcex))
    {
        MsgBoxAssert("윈도우 클래스 동록에 실패했습니다.");
        return;
    }
    Check = true;
}

// 윈도우를 만드는 함수
void GameEngineWindow::InitInstance()
{
    // DefaultWindow : 윈도우창을 만들 윈도우 형식
    // Title.c_str() : 윈도우창의 Title이름 (기존에는 const char* 형식이 필요하나, std::string변수로 관리하고 있기 때문에 내부 함수인 c_str을 사용함)
    // Instance : 해당 프로그램의 hInstance
    hWnd = CreateWindowA("DefaultWindow", Title.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, Instance, nullptr);
    if (nullptr == hWnd)
    {
        MsgBoxAssert("윈도우 생성에 실패했습니다.");
        return;
    }
    // 윈도우창을 시각적으로 보여주는 함수
    ShowWindow(hWnd, SW_SHOW);
    // 윈도우창을 다시 그려주는 함수(업데이트)
    UpdateWindow(hWnd);
}

// 윈도우창이 꺼지지 않고 계속 유지되기 위한 함수
// 윈도우창 입장에서는 내가 내부에서 무엇을 할 지는 알아하지만, 내부에 컨텐츠 요소들을 알아서는 안됨
// 그래서 함수포인터 형식으로 알려주면 해당 일처리는 대신 해줌
void GameEngineWindow::MessageLoop(HINSTANCE _Inst, void(*_Start)(HINSTANCE), void(*_Update)(), void(*_End)())
{
    // 윈도우창이 뜨기전에 로딩해야할 이미지나 사운드 등등을 처리하는 단계
    if (nullptr != _Start)
    {
        _Start(_Inst);
    }

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // 윈도우창이 떠있는 동안 계속 업데이트 해주는 부분
        if (nullptr != _Update)
        {
            _Update();
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if (nullptr != _End)
    {
        _End();
    }
    return;
}

// 윈도우창에 들어온 메세지를 어떻게 처리할 지 정하는 함수
LRESULT CALLBACK GameEngineWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

