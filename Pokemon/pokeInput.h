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
			// 키
			// 상태
			eKeyCode key;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static __forceinline eKeyState GetKeyState(eKeyCode keyCode)
		{
			return mKeys[(UINT)keyCode].state;
		}

		//GetKey()		키를 누르는 시간만큼 true를 반환
		//GetKeyDown()	키를 눌렀을 때, 딱 한번 true를 반환
		//GetKeyUp()	키를 누르다 땠을 때, 딱 한번 true를 반환

		static __forceinline bool GetKeyHold(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::Hold;
		}

		static __forceinline bool GetKeyDown(eKeyCode keyCode)
		{
			return mKeys[(UINT)keyCode].state == eKeyState::Down;
		}

		static __forceinline bool GetKeyUp(eKeyCode keyCode)
		{
			return mKeys[(UINT)keyCode].state == eKeyState::Up;
		}

	private:
		static std::vector<Key> mKeys;

	};
}

