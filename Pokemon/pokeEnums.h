#pragma once


enum class eSceneType
{
	Intro,
	Title,
	Play,
	Ending,
	End,
};


enum class eLayerType
{
	BG,
	Player,
	Monster,
	Effect,
	UI,
	End = 16,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Audio,
	End,
};