#include<stdio.h>
#include<Windows.h>
#include<conio.h>
int x, y, i;
int a1, b1, a2, b2, a3, b3, a4, b4, a5, b5;
int bu[4] = { 0,0,0,0 };
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
}
void erase_bg(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}

void erase_bu(int a1, int b1)
{
	gotoxy(a1, b1);
	setcolor(0, 0);
	printf("       ");
}
void draw_B(int a1, int b1)
{
	gotoxy(a1, b1);
	setcolor(2, 4);
	printf("^");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	int a1 = x + 3, b1 = 19, b2 = 19, b3 = 19, b4 = 19, b5 = 19;
	setcursor(0);
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' && x > 0)
			{
				i = 1;
			}
			if (ch == 'd' && x < 80)
			{
				i = 2;
			}
			if (ch == 's')
			{
				i = 3;
			}
			if (ch == ' ')
			{
				if (b1 == 19)
				{
					bu[0] = 1;
					a1 = x + 3;
				}
				else if (bu[0] == 1 && b2 == 19)
				{
					bu[1] = 1;
					a2 = x + 3;
				}
				else if (bu[1] == 1 && b3 == 19)
				{
					bu[2] = 1;
					a3 = x + 3;
				}
				else if (bu[2] == 1 && b4 == 19)
				{
					bu[3] = 1;
					a4 = x + 3;
				}
				else if (bu[3] == 1 && b5 == 19)
				{
					bu[4] = 1;
					a5 = x + 3;
				}
			}
			fflush(stdin);
		}
		if (i != 0) {
			if (i == 1 && x > 0)
			{
				erase_ship(x, y);
				erase_bg(x, y);
				draw_ship(--x, y);
			}
			if (i == 2 && x < 80)
			{
				erase_ship(x, y);
				erase_bg(x, y);
				draw_ship(++x, y);
			}
			if (i == 3)
			{
				draw_ship(x, y);
			}
			if (bu[0] == 1) //1
			{

				erase_bu(a1, b1);
				if (b1 > 0)
				{
					erase_bu(a1, b1);
					draw_B(a1, --b1);
				}
				else
				{
					bu[0] = 0;
					b1 = 19;
				}
			}
			if (bu[1] == 1) //2
			{

				erase_bu(a2, b2);
				if (b2 > 0)
				{
					erase_bu(a2, b2);
					draw_B(a2, --b2);
				}
				else
				{
					bu[1] = 0;
					b2 = 19;
				}
			}
			if (bu[2] == 1) //3
			{

				erase_bu(a3, b3);
				if (b3 > 0)
				{
					erase_bu(a3, b3);
					draw_B(a3, --b3);
				}
				else
				{
					bu[2] = 0;
					b3 = 19;
				}
			}
			if (bu[3] == 1) //4
			{

				erase_bu(a4, b4);
				if (b4 > 0)
				{
					erase_bu(a4, b4);
					draw_B(a4, --b4);
				}
				else
				{
					bu[3] = 0;
					b4 = 19;
				}
			}
			if (bu[4] == 1) //5
			{

				erase_bu(a5, b5);
				if (b5 > 0)
				{
					erase_bu(a5, b5);
					draw_B(a5, --b5);
				}
				else
				{
					bu[4] = 0;
					b5 = 19;
				}
			}
		}
		Sleep(50);
	} while (ch != 'x');
	return 0;
}
