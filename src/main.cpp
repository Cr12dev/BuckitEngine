#include "../includes/InitWindow.h"
#include "../includes/CubeData.h"
#include <windows.h>
#include <d3d11.h>
#include <DirectXMath.h>

using namespace DirectX;

// =====================
// GLOBAL DX11
// =====================
ID3D11Device* device = nullptr;
ID3D11DeviceContext* context = nullptr;
IDXGISwapChain* swapChain = nullptr;
ID3D11RenderTargetView* rtv = nullptr;


// =====================
// WINDOW PROC
// =====================
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
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

// =====================
// DX INIT
// =====================
bool InitD3D(HWND hwnd)
{
    DXGI_SWAP_CHAIN_DESC scd = {};
    scd.BufferCount = 1;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = hwnd;
    scd.SampleDesc.Count = 1;
    scd.Windowed = TRUE;

    D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &scd,
        &swapChain,
        &device,
        nullptr,
        &context
    );

    ID3D11Texture2D* backBuffer;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, nullptr, &rtv);
    backBuffer->Release();

    context->OMSetRenderTargets(1, &rtv, nullptr);

    return true;
}

// =====================
// ENGINE UPDATE
// =====================
void Update()
{
    angle += 0.01f;
}

// =====================
// ENGINE RENDER
// =====================
void Render()
{
    float clearColor[4] = {0.1f, 0.1f, 0.2f, 1.0f};
    context->ClearRenderTargetView(rtv, clearColor);

    // Aquí iría:
    // - shaders
    // - buffers
    // - draw cube

    swapChain->Present(1, 0);
}

// =====================
// MAIN
// =====================
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
    UpdateWindow(ventana);

    InitD3D(ventana);

    MSG msg = {};

    while (running)
    {
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                running = false;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Update();
        Render();
    }

    return 0;
}