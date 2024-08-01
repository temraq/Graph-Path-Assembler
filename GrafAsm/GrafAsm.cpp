// GrafAsm.cpp : Определяет точку входа для приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define UNICODE
#include "framework.h"
#include "GrafAsm.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>
#include <commdlg.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

int n = 0;
int matr[100];
int v01, v02, v1, v2, v3, v4;
int path[10];
int np = 0;
int nsm = 0;
int k;

TCHAR buf1[5];
TCHAR buf2[5];
TCHAR buf3[5];
TCHAR buf4[5];

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

INT_PTR CALLBACK    N(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Put(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Rebra(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    KSm(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Sm(HWND, UINT, WPARAM, LPARAM);

void Preobr(std::vector<std::string> v, int& n, int& v01, int& v02, int& v1, int& v2, int& v3, int& v4) {
    std::string buf = v[0];
    std::stringstream ss(buf);
    std::vector<int> bufv;
    std::copy(std::istream_iterator<int>(ss), {}, back_inserter(bufv));
    n = bufv[0];
    v01 = bufv[1];
    v02 = bufv[2];
    v1 = bufv[3];
    v2 = bufv[4];
    v3 = bufv[5];
    v4 = bufv[6];
    return;
}

void FindPathAsm(int* matr, int n, int v01, int v02, int v1, int v2, int v3, int v4, int path[10], int& npp) {
    int St[100], M[100];
    int* p = M;
    int* way = St;
    int* rez = path;
    int v, i, j, L, Pr, Prt, ks;
    int c = sizeof(int);
    /*for (j = 0; j < n; j++) {
        M[j] = 0;
    }*/

    int np;
    int buf;

    __asm {
        mov np, 0
        mov buf, 0
        mov L, 0
        mov j, 0
    M0:     
        mov edx, j
        cmp edx, n
        jz after_M0
        mov eax, j
        mov ecx, c
        mul ecx
        mov ebx, p
        add ebx, eax
        mov [ebx], 0
        inc j
        jmp M0
    after_M0:   
        mov ks, 0
        mov ebx, way
        mov eax, ks
        mov ecx, c
        mul ecx
        add ebx, eax
        mov ecx, v01
        mov [ebx], ecx
        mov ebx, p
        mov eax, ks
        mov ecx, c
        mul ecx
        add ebx, eax
        mov [ebx], 1
        mov ks, 0
    MKS:    
        mov edx, ks
        cmp edx, 0
        js after_MKS
        mov Pr, 0
        mov eax, ks
        mov ecx, c
        mul ecx
        mov ebx, way
        add ebx, eax
        mov edx, [ebx]
        mov v, edx
        mov edx, L
        mov j, edx
    ML:     
        mov edx, j
        cmp edx, n
        jz after_ML
        mov ebx, matr
        mov eax, v
        mov ecx, n
        mul ecx
        add eax, j
        mov ecx, c
        mul ecx
        add ebx, eax
        mov edx, [ebx]
        cmp edx, 1
        jnz M_next_j
        mov edx, j
        cmp edx, v02
        jnz j_else
        mov Prt, 0
        mov i, 0
    M_i:    
        mov edx, i
        cmp edx, ks
        jz after_M_i
        mov eax, i
        mov ecx, c
        mul ecx
        mov ebx, way
        add ebx, eax
        mov edx, [ebx]
        cmp edx, v1
        jnz Dal1
        mov eax, i
        inc eax
        mov ecx, c
        mul ecx
        mov ebx, way
        add ebx, eax
        mov edx, [ebx]
        cmp edx, v2
        jnz Dal1
        mov edx, i
        inc edx
        cmp edx, ks
        ja Dal1
        mov Prt, 1
    Dal1:   
        mov eax, i
        mov ecx, c
        mul ecx
        mov ebx, way
        add ebx, eax
        mov edx, [ebx]
        cmp edx, v3
        jnz after_M_i
        mov eax, i
        inc eax
        mov ecx, c
        mul ecx
        mov ebx, way
        add ebx, eax
        mov edx, [ebx]
        cmp edx, v4
        jnz after_M_i
        mov edx, i
        inc edx
        cmp edx, ks
        ja after_M_i
        mov Prt, 1
    after_M_i:  
            mov eax, ks
            mov ecx, c
            mul ecx
            mov ebx, way
            add ebx, eax
            mov edx, [ebx]
            cmp edx, v1
            jnz after_Prov1
            mov edx, j
            cmp edx, v2
            jnz after_Prov1
            mov Prt, 1
     after_Prov1:    
            mov eax, ks
            mov ecx, c
            mul ecx
            mov ebx, way
            add ebx, eax
            mov edx, [ebx]
            cmp edx, v3
            jnz after_Prov2
            mov edx, j
            cmp edx, v4
            jnz after_Prov2
            mov Prt, 1
    after_Prov2:    
            mov edx, Prt
            cmp edx, 0
            jnz M_next_j
            mov edx, ks
            cmp edx, np
            ja M_next_j
            mov i, 0
    Zap_i: 
            mov edx, i
            cmp edx, ks
            ja after_Zap_i
            mov eax, i
            mov ecx, c
            mul ecx
            mov ebx, way
            add ebx, eax
            mov edx, [ebx]
            mov buf, edx
            mov ebx, rez
            mov eax, i
            mov ecx, c
            mul ecx
            add ebx, eax
            mov edx, buf
            mov [ebx], edx
            inc i
            jmp Zap_i
    after_Zap_i:    
            mov eax, ks
            inc eax
            mov ecx, c
            mul ecx
            mov ebx, rez
            add ebx, eax
            mov ecx, v02
            mov[ebx], ecx
            mov eax, ks
            inc eax
            inc eax
            mov np, eax
            jmp M_next_j
    j_else:     
            mov eax, j
            mov ecx, c
            mul ecx
            mov ebx, p
            add ebx, eax
            mov edx, [ebx]
            cmp edx, 0
            jnz M_next_j
            mov Pr, 1
            jmp after_ML
    M_next_j: 
            inc j
            jmp ML
    after_ML: 
            mov edx, Pr
            cmp edx, 1
            jnz else_Pr
            inc ks
            mov eax, ks
            mov ecx, c
            mul ecx
            mov ebx, way
            add ebx, eax
            mov ecx, j
            mov [ebx], ecx
            mov L, 0
            mov eax, j
            mov ecx, c
            mul ecx
            mov ebx, p
            add ebx, eax
            mov[ebx], 1
            jmp MKS
    else_Pr:    
            mov eax, v
            inc eax
            mov L, eax
            mov eax, v
            mov ecx, c
            mul ecx
            mov ebx, p
            add ebx, eax
            mov[ebx], 0
            dec ks
            jmp MKS
    after_MKS:

    }
    for (i = 0; i < np; i++) {
        path[i] = rez[i];
    }
    npp = np;
    return;
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GRAFASM, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAFASM));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GRAFASM));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GRAFASM);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int wmEvent = HIWORD(wParam);
            TCHAR  FileName[200];
            OPENFILENAME ofn;
            TCHAR szFilter[100] = L"Текстовые файлы\0*.txt;*.doc\0Двоичные файлы\0 * .exe\0";
            std::ifstream in;
            std::vector<std::string> v;
            std::string st;
            std::string buf;
            int ppp[10];
            HDC hdc;
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case IDM_OPEN:
                FileName[0] = '\0';
                memset(&ofn, 0, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.lpstrFilter = szFilter;
                ofn.nFilterIndex = 1;
                ofn.lpstrFile = FileName;
                ofn.nMaxFile = sizeof(FileName);
                if (!GetOpenFileName(&ofn)) return 1;
                in.open(FileName);
                while (getline(in, st)) v.push_back(st);
                in.close();
                Preobr(v, n, v01, v02, v1, v2, v3, v4);
                for (int i = 0; i < n; i++) {
                    buf = v[i + 1];
                    std::stringstream ss1(buf);
                    std::vector<int> bufv1;
                    std::copy(std::istream_iterator<int>(ss1), {}, back_inserter(bufv1));
                    for (int j = 0; j < n; j++) {
                        int index = i * n + j;
                        matr[index] = bufv1[j];
                    }
                }
                FindPathAsm(matr, n, v01, v02, v1, v2, v3, v4, ppp, np);
                for (int i = 0; i < np; i++) {
                    path[i] = ppp[i];
                }
                break;
            case IDM_VVOD:
                if (DialogBox(hInst, MAKEINTRESOURCE(IDD_N), hWnd, N)) {
                    n = _wtoi(buf1);
                }
                if (DialogBox(hInst, MAKEINTRESOURCE(IDD_PUT), hWnd, Put)) {
                    v01 = _wtoi(buf1);
                    v02 = _wtoi(buf2);
                }
                if (DialogBox(hInst, MAKEINTRESOURCE(IDD_REBRA), hWnd, Rebra)) {
                    v1 = _wtoi(buf1);
                    v2 = _wtoi(buf2);
                    v3 = _wtoi(buf3);
                    v4 = _wtoi(buf4);
                }
                for (int i = 0; i < n; i++) {
                    if (DialogBox(hInst, MAKEINTRESOURCE(IDD_KSM), hWnd, KSm)) {
                        nsm = _wtoi(buf1);
                        for (int j = 0; j < nsm; j++) {
                            if (DialogBox(hInst, MAKEINTRESOURCE(IDD_SM), hWnd, Sm)) {
                                k = _wtoi(buf1);
                                int index = i * n + k;
                                matr[index] = 1;
                            }
                        }
                    }
                }
                FindPathAsm(matr, n, v01, v02, v1, v2, v3, v4, ppp, np);
                for (int i = 0; i < np; i++) {
                    path[i] = ppp[i];
                }
                break;
            case IDM_SHOW:
                hdc = GetDC(hWnd);

                HPEN hPen, hOldPen;
                hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
                hOldPen = (HPEN)SelectObject(hdc, hPen);

                for (int i = 0; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                    {
                        if (matr[i * n + j] == 1)
                        {
                            MoveToEx(hdc, 300 + 200 * sin(2 * M_PI * i / n), 300 + 200 * cos(2 * M_PI * i / n), NULL);
                            LineTo(hdc, 300 + 200 * sin(2 * M_PI * j / n), 300 + 200 * cos(2 * M_PI * j / n));
                        }
                    }
                DeleteObject(hPen);

                hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
                hOldPen = (HPEN)SelectObject(hdc, hPen);

                if (np == 0)
                {
                    LPCWSTR Str = L"Нет путей, удовлетворяющих условию";
                    std::wstring df = std::wstring(Str);
                    LPCWSTR res = df.c_str();
                    TextOut(hdc, 185, 30, res, wcslen(res));
                }
                else
                {
                    for (int i = 0; i < np-1; i++)
                    {

                        MoveToEx(hdc, 300 + 200 * sin(2 * M_PI * path[i] / n), 300 + 200 * cos(2 * M_PI * path[i] / n), NULL);
                        LineTo(hdc, 300 + 200 * sin(2 * M_PI * path[i + 1] / n), 300 + 200 * cos(2 * M_PI * path[i + 1] / n));
                    }
                }
                DeleteObject(hPen);

                hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                hOldPen = (HPEN)SelectObject(hdc, hPen);

                MoveToEx(hdc, 300 + 200 * sin(2 * M_PI * v1 / n), 300 + 200 * cos(2 * M_PI * v1 / n), NULL);
                LineTo(hdc, 300 + 200 * sin(2 * M_PI * v2 / n), 300 + 200 * cos(2 * M_PI * v2 / n));
                MoveToEx(hdc, 300 + 200 * sin(2 * M_PI * v3 / n), 300 + 200 * cos(2 * M_PI * v3 / n), NULL);
                LineTo(hdc, 300 + 200 * sin(2 * M_PI * v4 / n), 300 + 200 * cos(2 * M_PI * v4 / n));
                  
                hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
                hOldPen = (HPEN)SelectObject(hdc, hPen);
                for (int i = 0; i < n; i++)
                {
                    std::wstring S = std::to_wstring(i);
                    LPCWSTR res = S.c_str();
                    TextOut(hdc, 300 + 210 * sin(2 * M_PI * i / n), 300 + 210 * cos(2 * M_PI * i / n), res, wcslen(res));
                }

                ReleaseDC(hWnd, hdc);

                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
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

// Обработчик сообщений для окна "О программе".
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

INT_PTR CALLBACK N(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hDlg, IDC_EDIT1, buf1, 4);
            EndDialog(hDlg, 1);
            break;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            break;
        }
        return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;

}

INT_PTR CALLBACK Put(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hDlg, IDC_EDIT1, buf1, 4);
            GetDlgItemText(hDlg, IDC_EDIT2, buf2, 4);
            EndDialog(hDlg, 1);
            break;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            break;
        }
        return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;

}

INT_PTR CALLBACK Rebra(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hDlg, IDC_EDIT1, buf1, 4);
            GetDlgItemText(hDlg, IDC_EDIT2, buf2, 4);
            GetDlgItemText(hDlg, IDC_EDIT3, buf3, 4);
            GetDlgItemText(hDlg, IDC_EDIT4, buf4, 4);
            EndDialog(hDlg, 1);
            break;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            break;
        }
        return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK KSm(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hDlg, IDC_EDIT1, buf1, 4);
            EndDialog(hDlg, 1);
            break;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            break;
        }
        return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;

}

INT_PTR CALLBACK Sm(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            GetDlgItemText(hDlg, IDC_EDIT1, buf1, 4);
            EndDialog(hDlg, 1);
            break;
        case IDCANCEL:
            EndDialog(hDlg, 0);
            break;
        }
        return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;

}