﻿#pragma once

constexpr const POINT HWND_SPAWN_POS = { 500,200 };	// 메인 프레임 출력 위치

constexpr const int TILE_SIZE = 32;	// 맵 한 칸의 크기 ( 32 x 32)

constexpr const int MAP_MAX_X = 25;	// 행의 개수
constexpr const int MAP_MAX_Y = 19;	// 열의 개수

constexpr const POINT PLAYER_PIVOT_POS = { 16,47 };	// 캐릭터 콜라이더 기준 좌표 

constexpr const POINT STAGE2_SPAWN_POS = { 642, 115 };	// 오두막 집 문의 위치, 기준 위치로 부터 + alpah 값
constexpr const POINT WOOD_HOUSE_DOOR_POS = {2, 4};	// 오두막 집 문의 위치, 기준 위치로 부터 + alpah 값

constexpr const POINT START_BUTTON_POINT = { 370,430 };
constexpr const POINT MAPEDITTOR_BUTTON_POINT = { 370,480 };
constexpr const SIZE BUTTON_SIZE = { 100,30 };

constexpr const char BACKGROUND_BITMAP_PATH[] = { "data/bitmapinfo/BackgroundBitmapInfo.txt" };
constexpr const char OBJECT_BITMAP_PATH[] = { "data/bitmapinfo/ObjectBitmapInfo.txt" };
constexpr const char UI_BITMAP_PATH[] = { "data/bitmapinfo/UIBitmapInfo.txt" };

constexpr const char PLAYER_ANIMATION_PATH[] = { "data/bitmapinfo/CharacterAnimationBitmapInfo.txt" };
constexpr const char NPC_ANIMATION_PATH[] = { "data/bitmapinfo/NPCAnimationBitmapInfo.txt" };

constexpr const char HEART_ANIMATION_PATH[] = { "data/bitmapinfo/HeartAnimationBitmapInfo.txt" };
constexpr const char MONEY_ANIMATION_PATH[] = { "data/bitmapinfo/MoneyAnimationBitmapInfo.txt" };

namespace ClientSize
{
	enum
	{
		width = 800,
		height = 608
	};
}

enum class GameState
{
	MAIN,
	MAPEDITTOR,
	INGAME
};

typedef struct DOUBLEPOINT
{
	double x;
	double y;
}DPOINT;

namespace TextureName
{
	enum BackGround
	{
		grass = 1,
		grass_water1,
		grass_water2,
		grass_water3,
		grass_water4,
		grass_water5,
		grass_water6,
		grass_water7,
		grass_water8,
		grass_water9,
		castle_tile,
		black_tile,
		inside_tile,
	};

	enum Object
	{
		grassBlock1 = 1,
		grassBlock2,
		grassBlock3,
		grassBlock4,
		wood_house,
		wood_house_close,
		castle_door_close,
		castle_pillar,
		lever_off,
		lever_on,
		box_off,
		box_on,
		castle_wall_left,
		castle_wall_center,
		castle_wall_right,
		fireplace,
		table,
		chair_center,
		chair_left,
		chair_right,
		bed,
	};

	enum UI
	{
		Char_Info = 1,
		HP_Empty,
		HP_Half,
		HP_Full,
		Money_Info,
		ZERO,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
	};

	enum Animation
	{
		PLAYER_WALK,
		PLAYER_ATTACK,
		NPC_WALK,
		HEART_SPIN,
		MONEY_SPIN,
	};
}

enum class MapEdittorSelectState
{
	BACKGROUND,
	OBJECT,
	COLLIDER,
	EVENT,
};

constexpr const int STAGE_SIZE = 2;
constexpr const POINT STAGE2_SPAWN_POINT = {400,400};	// 추후에 수정

namespace MapInfo
{

	enum MapStage
	{
		NORMAL,
		WOOD_HOUSE,
	};
}

namespace Event
{
	enum eventKind
	{
		NONE,
		OPEN_WOOD_HOUSE_DOOR,
		CLOSE_WOOD_HOUSE_DOOR,
		OPEN_BOX,
		MOVE_STAGE_1,
		MOVE_STAGE_2,
	};
}

enum class BitmapKind
{
	BACKGROUND,
	OBJECT,
	UI
};

enum class ClickLR
{
	NONE,
	LEFT,
	RIGHT
};

namespace ButtonKind
{
	enum
	{
		START,
		MAPEDITTOR
	};
}

namespace CharacterInfo
{
	enum DIR
	{
		DOWN,
		RIGHT,
		UP,
		LEFT,
	};

	enum CharacterState
	{
		IDLE,
		WALK,
		ATTACK,
		INTERACTION,	// 상호작용
		HIT,
	};
}

namespace ItemInfo
{
	enum INDEX
	{
		HP,
		MONEY,
	};
}