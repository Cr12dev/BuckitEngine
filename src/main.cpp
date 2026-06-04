#include "../includes/InitWindow.h"

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int main()
{
    HINSTANCE instancia = GetModuleHandle(nullptr);

    WNDCLASSA wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = instancia;
    wc.lpszClassName = "MiClase";

    RegisterClassA(&wc);

    HWND ventana;

    if (!CrearVentana(
            ventana,
            "MiClase",
            "Mi Ventana",
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            1280,
            720,
            instancia))
    {
        return -1;
    }

    ShowWindow(ventana, SW_SHOW);

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }


    return 0;
}