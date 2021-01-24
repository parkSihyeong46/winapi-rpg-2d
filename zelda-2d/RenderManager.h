﻿#pragma once

#include "DataStruct.h"
#include "ImageManager.h"
#include "MapEdittor.h"
#include "Item.h"
#include "Player.h"
#include "NPC.h"
#include <vector>

using namespace std;

#pragma comment (lib, "Msimg32.lib")

constexpr POINT INVENTORY_SPAWN_POS = { 650,170 };
constexpr SIZE INVENTORY_interval_SIZE = { 8,8 };
constexpr int HP_UI_COUNT = 3;

class RenderManager
{
private:
	HDC hdc{ nullptr };
	HDC memDC{ nullptr };
	HDC backMemDC{ nullptr };
	HBITMAP oldCreateBitmap{ nullptr };

private:
	static RenderManager* instance;

	RenderManager();
	~RenderManager();
public:
	static RenderManager* GetInstance();
	static void ReleaseInstance();

public:
	void Init();

	void RenderInitSetting();

public:
	void SaveMemDcData(const HWND itemHwnd, POINT pos);
	void SaveMemDcData(const HBITMAP hbitmap, POINT pos);
	void Render();
	
public:
	void MainFrameDataRender();
	void MapEdittorDataRender();
	void InGameDataRender(Player* character, NPC* npc);

public:
	void DrawWorldMapData(const GameState gameState);
	void DrawFieldItem();		// 필드 아이템 그리기
	void DrawInventoryItem();	// 인벤토리 아이템 그리기

	void DrawPlayer(Player* character);
	void DrawNPC(NPC* npc);
	void DrawCharUIData(const int uiName, const POINT pos);

	void DrawCheckPattern(HDC hdc, const SIZE size);
	void DrawCursorFollowBitmap();

public:
	void DrawAnimation(const int uiName, const DPOINT pos);

	void InitPlayerAnimation(const int state, Player* player);

};

