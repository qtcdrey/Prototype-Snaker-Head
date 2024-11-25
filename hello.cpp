#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void gotoxy(int x,int y);

int main() 
{
	int x = 10,y = 10;
	char ch;
	
	gotoxy(x,y);
	printf("O");
	
	while(true) {
		if(kbhit()) {
			ch = getch();
			
			gotoxy(x,y);
			printf(" ");
			
			switch(ch) {
				case 72:
					y--;
					break;
				case 80:
					y++;
					break;
				case 75:
					x--;
					break;
				case 77:
					x++;
					break;
				case 27:
					return 0;
			}
			gotoxy(x,y);
			printf("O");
		}
	}

	return 0;
}

void gotoxy(int x, int y)
{
	HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD row;
	row.X = x;
	row.Y = y;
	SetConsoleCursorPosition(col,row);
}