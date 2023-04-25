// WindowTestProject


#include "framework.h"
#include "WindowTestProject.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING] = L"AAAAAA"; // 기본 윈도우의 클래스 이름

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 윈도우의 핸들 방식에 대해서 이해해야 합니다. << 윈도우에게 우리가 원하는걸 요청하는 형식(제 hInstance는 00000인데 창 하나를 띄워주세요!!)
// 윈도우는 진입점을 지들이 바꿔놨다.
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 윈도우가 응용프로그래머에게 주는 우리 프로그램의 등록번호 << 윈도우가 인식하는 내 코드번호 << 개념적으론 포인터랑 다를게 없음
                                                // 너는 앞으로 301211번이야 나한테 뭔가를 부탁할때 저 숫자를 내놔.
                     _In_opt_ HINSTANCE hPrevInstance, // 별로 중요하지 않음
                     _In_ LPWSTR    lpCmdLine, // 커맨드라인
                     _In_ int       nCmdShow) // 별로 중요하지 않음
{
    // 아래는 경고를 없애려고 사용한 코드임
    // 만약 변수를 선언하고 사용하지 않으면 경고뜸
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // hInstance : 윈도우가 내 프로그램에 부여한 번호
    // 내 프로그램에 몇 가지 니 프로그램의 이름은 뭐고 미리 넣어놓습니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWTESTPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWTESTPROJECT));

    MSG msg;

    // while문으로 
    // 윈도우가 켜져있는 동안 계속 프로그램이 켜져있게 만들려고 while로 막아놓는다
    // GetMessage는 윈도우에 Message가 발생한 경우에만 리턴되는 함수 << _getch와 유사한 기능(키가 들어오기 전까지 대기)
    // GetMessagen << 윈도우에 무슨일이 생겼는지 체크
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


// 윈도우 창을 띄우기 전에 해야할 일(옵션)
// 그걸 미리 등록시켜야함 (WINDOWCLASS)
// 이 윈도우 창은 크기를 조절할 수 있고 아이콘은 뭐고 등등...
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    // 크기(구조체)
    wcex.cbSize = sizeof(WNDCLASSEX);

    // 크기바꾸면 다시 그려라 (RE DRAW)
    wcex.style          = CS_HREDRAW | CS_VREDRAW;

    // 중요!!!
    // 윈도우에 무슨일이 생기면 어떻게 처리할까??
    // 이때 사용하는게 "함수포인터" (UI에서 사용한다고 했음) << 내가 어떻게 해야할지 알려줘
    // 내가 너 대신 행동(함수)를 해줄게
    wcex.lpfnWndProc    = WndProc;

    // 모른다 (0이면 보통 기본설정)
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    // 중요!!!
    // 이 윈도우 클래스를 등록하려는 프로그램이 나야.
    wcex.hInstance      = hInstance;

    // 하단의 윈도우 아이콘을 정해주는 함수
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWTESTPROJECT));

    // 커서를 정하는 함수
    // 내가 원하는 커서로 바꾸는건 보통 게임 내부에서 구현함
    // 기본커서는 지우고 자기가 원하는 이미지로 커서를 대체함
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);

    // 윈도우 배경색 (의미없음)
    // 어차피 게임배경으로 덮힐것이니
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    
    // 메뉴이름(상단의 메뉴바)
    //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWTESTPROJECT);
    wcex.lpszMenuName   = nullptr; // 메뉴창을 사용하지 않는다고 등록
    
    // 이 형식의 이름은 "AAAAAA" 입니다.
    // 앞으로 제가 윈도우를 만들 때 선택할 수 있는 형식 중 1가지로 "AAAAAA"를 등록해 주세요
    wcex.lpszClassName  = szWindowClass;

    // 좌상단의 작은 아이콘을 정하는 함수
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    // 위에서 설정한 윈도우의 형식을
    // 윈도우 형식을 등록하는 함수
    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; 

   // 윈도우를 만드는 함수
   // 윈도우 != 프로그램 (프로그램 하나가 윈도우 여러 개를 띄울 수 있음) << 윈도우는 그저 내 프로그램에 귀속된 인터페이스일 뿐임 (윈도우가 프로그램이 아님)
   // HWND 등 DECLARE_HANDLE == struct HWND__{int unused;}; typedef struct HWND__ *HWND << 구조체의 포인터임
   // 왜 이렇게 핸들 종류가 많을까??
   // 1. 하나의 핸들로 윈도우의 수많은 기능을 관리할수가 없음 << 그래서 해당 기능에 관련된 관리번호를 따로 부여해 주는 것 
   // 2. 만약 윈도우가 여러 개 존재한다면 어떻게 구분하여 함수를 처리할 것인가?? << 윈도우창 마다 관리번호를 따로 부여해줌으로 해결
   HWND hWnd = CreateWindowW(szWindowClass          // "AAAAAA"형식 (위에서 내가 등록한 형식) 윈도우창 만들어 주세요
                            , szTitle               // 타이틀(윈도우창 이름)은 이걸로 해주세요
                            , WS_OVERLAPPEDWINDOW   // 윈도우 스타일은 이걸로 해주세요
                            , CW_USEDEFAULT         // 좌상단 끝점의 X
                            , 0                     // 좌상단 끝점의 Y
                            , CW_USEDEFAULT         // 우하단 끝점의 X
                            , 0                     // 우하단 끝점의 Y
                            , nullptr               // 몰라요
                            , nullptr               // 몰라요
                            , hInstance             // 윈도우의 주인은 ??? hInstance(윈도우가 나에게 부여해준 ID값)
                            , nullptr);             // 

   if (!hWnd)
   {
      return FALSE;
   }

   // 만든 윈도우창을 시각적으로 보여주는(실제로 창을 띄워주는) 함수
   ShowWindow(hWnd, nCmdShow);

   // 윈도우를 한번 갱신하라(새로 그리기)
   UpdateWindow(hWnd);

   return TRUE;
}

int Value = 0;
// message << 윈도우에서 벌어진 일의 종류 (ex. 윈도우가 선택되었다, 윈도우가 크기가 바뀌었다)
// wParam, lParam << message에 붙어오는 부가적인 설명 (unsigned __int64)
// 내가 어떤 윈도우창에 함수를 실행할 것인가? << hWnd인자로 결정
// HWND hWnd << 어떤 윈도우에 메세지가 왔는지 알려주는 용도
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        int a = 0;
        break;
    }
    case WM_SETFOCUS:
        break;
    case WM_KILLFOCUS:
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            // hdc << 내가 어떤 윈도우의 화면에 무언가를 그리기 위한 권한 << 그래서 hWnd가 인자로 필요함(어떤 윈도우창에 그릴거야?)
            HDC hdc = BeginPaint(hWnd, &ps);

            // 윈도우창의 크기가 바뀌면 REDRAW가 호출되면서 WM_PAINT안에 들어옴
            // 이런 형식으로는 게임을 만들 수 없음 << 가만히 있어도 몬스터가 움직이고 배경이 움직이고 해야함(갱신되야함)
            Rectangle(hdc, 100 + Value, 100, 200 + Value, 200);

            ++Value;
            EndPaint(hWnd, &ps);
        }
        break;
        // 우상단의 X키를 눌렀을 때 처리내용
    case WM_DESTROY:
        // GetMessage의 return값을 0으로 해줌
        PostQuitMessage(0);
        break;
    default:
        // 내가 처리한 메세지 종류가 아닐 경우에는
        // 윈도우 자체적으로 처리해준다(Default로 처리해준다)
        // WM 종류가 엄청나게 많기 때문에 모든 case를 사용자가 처리할 수 없기 떄문
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
