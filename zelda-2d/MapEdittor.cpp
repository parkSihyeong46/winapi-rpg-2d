﻿#include "pch.h"
#include "MapEdittor.h"

extern HWND g_hWnd;
extern SIZE g_clientSize;
extern HINSTANCE hInst;

MapEdittor* MapEdittor::instance = nullptr;

MapEdittor::MapEdittor()
{
    Init();
}

MapEdittor::~MapEdittor()
{
    delete instance;
    instance = nullptr;

    delete mapData;
    mapData = nullptr;
}

MapEdittor* MapEdittor::GetInstance()
{
    if (nullptr == instance)
    {
        instance = new MapEdittor();
    }

    return instance;
}

void MapEdittor::ReleaseInstance()
{
    delete instance;
    instance = nullptr;
}

void MapEdittor::Init()
{
    if (mapData != nullptr)
        delete mapData;

    mapData = new WorldMap();

    selectBitmap = BackGroundTextureName::grass;
    selectState = MapEdittorSelectState::BACKGROUND;
}

void MapEdittor::SetMapData(const POINT pos, const bool isLbutton)
{
    if (!(0 <= pos.x && ClientSize::width > pos.x))
        return;
    if (!(0 <= pos.y && ClientSize::height > pos.y))
        return;

    POINT mapPos;
    mapPos.x = pos.x / TILE_SIZE;
    mapPos.y = pos.y / TILE_SIZE;

    if (isLbutton)
    {
        switch (selectState)
        {
        case MapEdittorSelectState::BACKGROUND:
            mapData->backgroundData[mapPos.y][mapPos.x] = selectBitmap;
            break;
        case MapEdittorSelectState::OBJECT:
            mapData->objectData[mapPos.y][mapPos.x] = selectBitmap;
            break;
        case MapEdittorSelectState::COLLIDER:
            mapData->coliderData[mapPos.y][mapPos.x] = true;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (selectState)
        {
        case MapEdittorSelectState::BACKGROUND:
            mapData->backgroundData[mapPos.y][mapPos.x] = 0;
            break;
        case MapEdittorSelectState::OBJECT:
            mapData->objectData[mapPos.y][mapPos.x] = 0;
            break;
        case MapEdittorSelectState::COLLIDER:
            mapData->coliderData[mapPos.y][mapPos.x] = false;
            break;
        default:
            break;
        }
    }
}

const MapEdittorSelectState MapEdittor::GetSelectState()
{
    return selectState;
}

const WorldMap MapEdittor::GetWorldMapData()
{
    return *mapData;
}

const int MapEdittor::GetSelectBitmapNumber()
{
    return selectBitmap;
}
