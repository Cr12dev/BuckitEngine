#include <windows.h>

bool CrearVentana(
    HWND& ventana,
    LPCSTR clase,
    LPCSTR titulo,
    int x,
    int y,
    int ancho,
    int alto,
    HINSTANCE instancia)
{
    ventana = CreateWindowExA(
        0,
        clase,
        titulo,
        WS_OVERLAPPEDWINDOW,
        x,
        y,
        ancho,
        alto,
        nullptr,
        nullptr,
        instancia,
        nullptr
    );

    return ventana != nullptr;
}