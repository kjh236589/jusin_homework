// DefaultWindow.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "DefaultWindow.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,     // 메모리에 할당된 실체
                     _In_opt_ HINSTANCE hPrevInstance, // 전에 실행되었던 인스턴스 핸들(없을 경우 NULL)
                     _In_ LPWSTR    lpCmdLine,          
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DEFAULTWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEFAULTWINDOW));

    MSG msg;

    // 기본 메시지 루프입니다:
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



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    // 윈도우 창 만들기 위해 데이터 값을 저장하기 위한 구조체


    wcex.cbSize = sizeof(WNDCLASSEX);       // 자기 자신의 사이즈를 저장해 놓음

    wcex.style = CS_HREDRAW | CS_VREDRAW;

    // HREDRAW: horizontal redraw;
    // VREDRAW: vertical redraw;

    // 메세지 처리기 함수 이름 지정
    wcex.lpfnWndProc    = WndProc;

    // 윈도우 특수한 목적으로 사용하는 여분의 공간, 일종의 예약 영역
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    wcex.hInstance      = hInstance;

    // 윈도우 창에 출력할 아이콘 모양
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEFAULTWINDOW));

    // 마우스 커서 모양
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);

    // 뷰창의 배경 화면 색상
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);

    // 메뉴 설정 
    wcex.lpszMenuName = NULL;

    // 실행파일 이름
    wcex.lpszClassName  = szWindowClass;

    // 윈도우 상단 아이콘
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, // 윈도우 클래스 이름
       L"바꾸지마",     // 상단의 출력할 문자열
       WS_OVERLAPPEDWINDOW,     // 창 스타일(기본적으로 제공하는 창 형식으로 생성)
       CW_USEDEFAULT, 0,        // 창의 생성 위치(LEFT, TOP)
       800, 600,        // 창의 가로, 세로 사이즈
       nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

// 1. kernel : 메모리를 관리하고 프로그램 실행 명령어 수록
// 2. user : 유저 인터페이스와 윈도우 창을 관리하는 명령어 수록
// 3. gdi : 화면 처리와 그래픽을 담당하는 명령어 수록

RECT            rc{ 100, 100, 200, 200 };
list<RECT>      BulletList;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:

        SetTimer(hWnd, 0, 0, 0);
        // 타이머를 설치하는 함수
        // 2 : 타이머의 ID
        // 3 : 타이머 주기, 0을 지정할 경우 1 / 1000초의 주기를 생성
        // 4 : 3에서 설정한 주기대로 WM_TIMER 메세지를 발생시킴   
        break;

    case WM_TIMER:

        InvalidateRect(hWnd, 0, true);

        // InvalidateRect : 윈도우(창) 갱신 함수, 호출 시, WM_PAINT 메시지 발생

        // 2 : 윈도우 안에서 갱신할 범위(NULL), RECT 구조체의 주소, null인 경우 윈도우 전체 영역 갱신
        // 3 : true - 그리지 않는 화면의 모든 부분도 갱신
           //  false - 그리는 부분만 갱신
        break;


    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);


        // 커서의 위치를 이동시키는 함수
        // MoveToEx(hdc, 100, 100, NULL);
        // LineTo(hdc, 200, 100);
        // LineTo(hdc, 200, 200);
        // LineTo(hdc, 100, 200);
        // LineTo(hdc, 100, 100);
        //
        // LineTo(hdc, 200, 200);
        //
        // MoveToEx(hdc, 200, 100, NULL);
        // LineTo(hdc, 100, 200);

         // 커서의 위치로 부터 매개 변수의 위치까지 선 그리기 함수
         // LineTo(hdc, 200, 200);
         // LineTo(hdc, 200, 300);


         // Ellipse(hdc, 300, 300, 400, 400);

         // for (auto& Bullet : BulletList)
         // {
         //     Ellipse(hdc, Bullet.left, Bullet.top, Bullet.right, Bullet.bottom);
         // 
         //     Bullet.top -= 10;
         //     Bullet.bottom -= 10;
         // }

        Ellipse(hdc, 75, 190, 225, 340);
        Ellipse(hdc, 100, 100, 200, 200);
        MoveToEx(hdc, 115, 145, NULL);
        LineTo(hdc, 125, 135);
        LineTo(hdc, 135, 145);
        MoveToEx(hdc, 185, 145, NULL);
        LineTo(hdc, 175, 135);
        LineTo(hdc, 165, 145);
        MoveToEx(hdc, 170, 175, NULL);
        LineTo(hdc, 150, 185);
        LineTo(hdc, 130, 175);
        LineTo(hdc, 170, 175);
        Rectangle(hdc, 110, 50, 190, 115);
        Rectangle(hdc, 90, 110, 210, 120);
        MoveToEx(hdc, 90, 240, NULL);
        LineTo(hdc, 45, 175);
        LineTo(hdc, 35, 173);
        MoveToEx(hdc, 45, 175, NULL);
        LineTo(hdc, 43, 165);

        MoveToEx(hdc, 210, 240, NULL);
        LineTo(hdc, 255, 175);
        LineTo(hdc, 265, 173);
        MoveToEx(hdc, 255, 175, NULL);
        LineTo(hdc, 257, 165);

        EndPaint(hWnd, &ps);


    }
    break;


    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
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
    
    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;

        case VK_RIGHT:
            rc.left  += 10;
            rc.right += 10;
            break;

        case VK_LEFT:
            rc.left  -= 10;
            rc.right -= 10;
            break;

        case VK_UP:
            rc.top    -= 10;
            rc.bottom -= 10;
            break;

        case VK_DOWN:
            rc.top    += 10;
            rc.bottom += 10;
            break;

        case VK_SPACE:
            BulletList.push_back(rc);
            break;
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

// 정보 대화 상자의 메시지 처리기입니다.
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

// 호출자, 호출원(caller) : 궁극적으로 함수들을 호출하는 위치, 1개월차의 trpg중 main 함수가 해당 
// 피호출자(callee) : 그외의 기능별 함수들이 피호출자에 해당

// __cdecl : c /c++ 기본 호출 규약,  "호출자가 stack을 정리", 가변 인자 함수(매개 변수가 얼마나 들어올지 알 수가 없음)
//              본인이 스스로 stack을 정리하지는 못함

// __stdcall : winapi 기본 호출 규약, 피호출자가 stack을 정리, 고정 인자 함수, 본인 스스로 stack을 정리 할 수 있음
// 
// __fastcall : 함수 호출을 빠르게 하기 위한 규약, ecx, edx라 불리는 레지스터 메모리에 함수 코드를 저장
// 
// __thiscall : this 포인터를 매개 변수로 설정할 경우 자동으로 연결되는 규약
