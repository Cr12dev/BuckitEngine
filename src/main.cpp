#include "../includes/InitWindow.h"
#include <windows.h>

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

static bool running = true;

// Engine Systems // 

/**
 * Function for update all frames 
 */
void Update()
{
    
}

/**
 * Function for render 
 */
void Render()
{
    
}

int main()
{
    HINSTANCE instancia = GetModuleHandle(nullptr);

    WNDCLASSA wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = instancia;
    wc.lpszClassName = "MiClase";

    if (!RegisterClassA(&wc))
    {
        return -1;
    }

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
    UpdateWindow(ventana);

    MSG msg = {};

    // GAME LOOP REAL
    while (running)
    {
        // Procesar mensajes sin bloquear
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                running = false;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // ===== UPDATE =====
        Update();

        // ===== RENDER =====
        Render();
    }

    return 0;
}