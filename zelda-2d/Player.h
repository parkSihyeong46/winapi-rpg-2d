﻿#pragma once
#include "Character.h"

class Player : public Character
{
private:
	int level;			// level
	int exp;

public:
	Player();
	Player(const DPOINT pos, const int hp, const int level, const int speed, const int damage);
	~Player();

public:
	const int GetLevel();

	void SetExp(const int exp);

	POINT GetPivotMapPoint();
public:
	void Input();
	void Update();
};

