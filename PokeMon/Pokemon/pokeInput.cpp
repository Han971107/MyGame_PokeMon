#include "pokeInput.h"


namespace poke
{
	int ASCII[(UINT)eKeyCode::END] =
	{
		VK_LEFT,
		VK_RIGHT,
		VK_UP,
		VK_DOWN,
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_MENU,
		VK_CONTROL,
		VK_LSHIFT,
		VK_SPACE,
		VK_RETURN,
		VK_ESCAPE,
	};

	std::vector<Input::Key> Input::mKeys;

	void Input::Initialize()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; ++i)
		{
			Key keyInfo;
			keyInfo.key = (eKeyCode)i;
			keyInfo.state = eKeyState::None;
			keyInfo.bPressed = false;

			mKeys.push_back(keyInfo);
		}
	}

	void Input::Update()
	{
		HWND hwnd = GetFocus();

		// ������ ��Ŀ�� ���� �� Ű �̺�Ʈ ����
		if (hwnd != nullptr)
		{
			for (int i = 0; i < (UINT)eKeyCode::END; ++i)
			{
				if (GetAsyncKeyState(ASCII[i]) & 0x8000)
				{
					// ���� �����ӿ��� �����־���.
					if (mKeys[i].bPressed)
						mKeys[i].state = eKeyState::Pressed;
					else
						mKeys[i].state = eKeyState::Down;

					mKeys[i].bPressed = true;
				}
				else // ���� �����ӿ� Ű�� �������� �ʴ�.
				{
					// ���� �����ӿ� ��Ű�� �����־���.
					if (mKeys[i].bPressed)
						mKeys[i].state = eKeyState::Up;
					else
						mKeys[i].state = eKeyState::None;

					mKeys[i].bPressed = false;
				}
			}
		}
		else // ������ ��Ŀ�� ���� ����
		{
			for (int i = 0; i < (int)eKeyCode::END; ++i) {
				mKeys[i].bPressed = false;

				if (eKeyState::Down == mKeys[i].state || eKeyState::Pressed == mKeys[i].state) {
					mKeys[i].state == eKeyState::None;
				}
				else if (eKeyState::Up == mKeys[i].state) {
					mKeys[i].state == eKeyState::None;
				}
			}
		}
	}

	void Input::Render(HDC hdc)
	{

	}
}