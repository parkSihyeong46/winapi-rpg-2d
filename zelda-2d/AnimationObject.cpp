﻿#include "pch.h"

#include "AnimationObject.h"

void AnimationObject::AddAnimationBitmap(HBITMAP hbitmap)
{
	animationBitmapData.emplace_back(hbitmap);
}

void AnimationObject::AddBitmapCount(const int count)
{
	bitmapCount.emplace_back(count);
}

void AnimationObject::AddNormalPos(const POINT pos)
{
	normalPos.emplace_back(pos);
}

void AnimationObject::AddDelay(const int delay)
{
	this->delay.emplace_back(delay);
}

const int AnimationObject::GetAnimationBitmapSize()
{
	return animationBitmapData.size();
}

const int AnimationObject::GetBitmapCount(const int index)
{
	if (0 >= index && index < static_cast<int>(animationBitmapData.size()))
		return bitmapCount[index];
	else
		return NULL;
}

const int AnimationObject::GetSelectAnimationBitmapIndex()
{
	return selectAnimationBitmapIndex;
}

void AnimationObject::SetSelectAnimationBitmapIndex(const int index)
{
	selectAnimationBitmapIndex = index;
}

const int AnimationObject::GetSelectBitmapIndex()
{
	return selectBitmapIndex;
}

void AnimationObject::SetSelectBitmapIndex(const int index)
{
	selectBitmapIndex = index;
}

const HBITMAP AnimationObject::GetAnimationBitmap(const int index)
{
	if (index < static_cast<int>(animationBitmapData.size()) && 0 >= index)
		return animationBitmapData[index];
	else
		return nullptr;

}

void AnimationObject::SetBitmap(const int index, const HBITMAP hbitmap)
{
	if (index < static_cast<int>(animationBitmapData.size()) && 0 >= index)
		animationBitmapData[index] = hbitmap;
}

const POINT AnimationObject::GetNormalPos(const int index)
{
	if (index > static_cast<int>(normalPos.size()) && 0 > index)
		return { NULL, NULL };

	return normalPos[index];
}

void AnimationObject::SetNormalPos(const int index, const POINT pos)
{
	if (index > static_cast<int>(normalPos.size()) && 0 > index)
		return;

	normalPos[index] = pos;
}

void AnimationObject::NextSelectBitmapIndex()
{
	if (GetTickCount64() > tick + delay[selectBitmapIndex])
	{
		tick = GetTickCount64();
		++selectBitmapIndex;
	}

	if(selectBitmapIndex >= static_cast<int>(bitmapCount.size()))
		selectBitmapIndex = 0;

	if (selectBitmapIndex >= bitmapCount[selectBitmapIndex])
		selectBitmapIndex = 0;
}
