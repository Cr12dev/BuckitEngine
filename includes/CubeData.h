#pragma once

#include <d3d11.h>
#include <DirectXMath.h>

#include "./ModelDatas.h"

// =====================
// CUBE DATA
// =====================


Vertex3D vertices[] =
{
    {-1,-1,-1, 1,0,0},
    {-1, 1,-1, 0,1,0},
    { 1, 1,-1, 0,0,1},
    { 1,-1,-1, 1,1,1},

    {-1,-1, 1, 1,0,1},
    {-1, 1, 1, 0,1,1},
    { 1, 1, 1, 1,1,0},
    { 1,-1, 1, 0.5,0.5,0.5}
};

UINT indices[] =
{
    0,1,2, 0,2,3,
    4,6,5, 4,7,6,
    4,5,1, 4,1,0,
    3,2,6, 3,6,7,
    1,5,6, 1,6,2,
    4,0,3, 4,3,7
};

ID3D11Buffer* vBuffer = nullptr;
ID3D11Buffer* iBuffer = nullptr;


float angle = 0.0f;

//h