#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	POINT mouse;
	const int size = 20;
	int arrx[size],arry[size];

	cout << "Нажмите левый АЛЬТ что бы записать точку." << endl;
	for (int i = 0; i < size; i++)
	{
		if (GetAsyncKeyState(VK_LMENU))
		{
			GetCursorPos(&mouse);
			arrx[i] = mouse.x;
			arry[i] = mouse.y;
			cout << arrx[i] << " " << arry[i] << endl;
		}
	}
}
