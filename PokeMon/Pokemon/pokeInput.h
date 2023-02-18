#pragma once
#include "MergeEngine.h"


namespace poke
{
	enum class eKeyCode
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,

		ALT,
		CTRL,
		LSHIFT,
		SPACE,
		ENTER,
		ESC,

		END,
	};

	enum class eKeyState
	{
		Down,
		Hold,
		Up,
		None,
	};


	class Input
	{
	public:

		struct Key
		{
			// Å°
			// »óÅÂ
			eKeyCode key;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static eKeyState GetKeyState(eKeyCode keyCode)
		{
			return mKeys[(UINT)keyCode].state;
		}

	private:
		static std::vector<Key> mKeys;

	};
}

