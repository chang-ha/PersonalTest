#include "GameEngineWindow.h"
#include <GameEngineBase/GameEngineDebug.h>

// 해당 프로그램의 hInstance값을 받기위한 static 변수
HINSTANCE GameEngineWindow::Instance = nullptr;
// 윈도우창은 한개만 만들기 위해 싱글톤 패턴 사용
GameEngineWindow GameEngineWindow::MainWindow;
// IsWindowUpdate의 실체를 구현(최초는 true값으로)
bool GameEngineWindow::IsWindowUpdate = true;


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
    // CreateDC 할필요 없음 << CreateDC는 완전히 새로운 HDC를 만드는함수임
    // hWnd = CreateWindowA할 때, HDC값도 안에 만들어져있음
    // 해당값을 받아오기만 하면 됨 (GetDC)

    // 윈도우창에 그림을 그리기위한 핸들을 저장
    Hdc = GetDC(hWnd); // == ::GetDC(hWnd);
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

    while (IsWindowUpdate)
    {
        // 프레임 : while로 묶여있는 내가 원하는 일을 한번 처리하는 단위 (내부에 움직이고 그린다는 작업이 들어가 있음)
        
        // 윈도우에 무슨일이 있는게 아니라 메세지가 있든 없든 
        // GetMessage << 동기함수 (함수내부에 모든일을 끝내야면 return을 해줌, 함수가 제대로 끝날때까지 기다리는 함수), ex) _getch()
        // 그래서 GetMessage에서 PeekMessage로 바꿔줌 (다른점은 마지막 인자 하나 추가 : PM_REMOVE, PM_NOREMOVE, PM_NOYIELD)
        // PeekMessage는 윈도우에 메세지가 없으면 0이 리턴됨
        // PeekMessage로 바꾸면서 프레임과 데드타임이 생겼다.
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            // 윈도우창이 떠있는 동안 계속 업데이트 해주는 부분

            // while문 한바퀴 도는것이 1프레임(FPS << 초당 화면이 그려지는 횟수)
            // 모니터 주사율 (모니터가 띄울수 있는 최대 프레임)
            // 윈도우창을 조작할 때도 게임이 움직이게 하기 위해서는 Message처리하는 부분에서도 Update를 해주면 된다.
            if (nullptr != _Update)
            {
                _Update();
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }

        // 윈도우 메세지가 없는 시간을 데드타임이라고 합니다.
        // 게임은 데드타임에 돌아가는게 보통이다.
        // 게임중에 2가지 종류가 있다. 
        // 1) 윈도우를 움직이거나 크기를 줄이면 화면이 정지하는 게임
        // 2) 내가 그런 윈도우 메세지를 발생시키는 와중에도 움직이는 게임
        if (nullptr != _Update)
        {
            _Update();
        }
    }

    if (nullptr != _End)
    {
        _End();
    }
    return;
}

// 윈도우창에 들어온 메세지를 어떻게 처리할 지 정하는 함수
// lpfnWndProc = GameEngineWindow::WndProc을 받는데
// lpfnWndProc를 타고 가보면 함수포인터를 받을 때 앞에 CALLBACK이라고 붙어있음
// CALLBACK = __stdcall (함수호출규약)으로 되어있는데
// 해당 함수를 받는 쪽이 __stdcall을 원하니 함수 선언 및 구현시 맞춰줘야함
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
        // WindowLoopOff();
        IsWindowUpdate = false;
        // PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

