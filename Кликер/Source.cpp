#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int on = 1;
	const int size = 20;
	int arrx[size];
	int arry[size];
	int step = 0;
	int counter = 0;
	int num = 0;
	int time = 0;
	int starttime = 0;
	POINT mouse;

	cout << "Идёт запись координат.Что бы записать точку нажмите LEFT ALT.\nЧто бы закончить запись нажмите SPACE." << endl;

	while (counter != 19)
	{
		if (GetAsyncKeyState(VK_LMENU))
		{
			Sleep(200);
			GetCursorPos(&mouse);
			arrx[step] = mouse.x;
			arry[step] = mouse.y;
			cout << arrx[step] << ' ' << arry[step] << endl;
			step++;
			counter++;
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			counter = 19;
		}
	}

	cout << "Введите кол-во повторений имитаций кликов : ";
	cin >> num;
	cout << "Введите время задержки между повторениями (в секундах) : ";
	cin >> time;
	cout << "Введите время,спустя которое кликер должен начать работу :";
	cin >> starttime;
	cout << "Что бы запустить бота нажмите ENTER." << endl;
	
	while (num < 9999999999)
	{
		if (GetAsyncKeyState(VK_RETURN))
		{
			Sleep(starttime * 1000);
			for (int j = 0; j < num; j++)
			{
				for (int i = 0; i < step; i++)
				{
					Sleep(500);
					SetCursorPos(arrx[i], arry[i]);
					Sleep(1500);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				}
				Sleep(time * 1000);
			}
		}
	}
}
