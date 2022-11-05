#include"game.h"
#include"main.h"
#include"util.h"
struct success {
	int player_success;
	int computer_success;
};
struct Pos {
	int x;
	int y;
};
int keyControl()
{
	char temp = getch();
	// 키보드 값 : up = 1 left = 2 down = 3 right = 4 submit = 5
	if (temp == 'w' || temp == 'W')
		return 1;
	else if (temp == 'a' || temp == 'A')
		return 2;
	else if (temp == 's' || temp == 'S')
		return 3;
	else if (temp == 'd' || temp == 'D')
		return 4;
	else if (temp == ' ')
		return 5;
	else if (temp == 'f' || temp == 'F')
		return 6;
}
void titleDraw()
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("      #######     ####        ####   ###########      #######     ####    ##        ##   \n");
	printf("      ##        ##    ##    ##   ##      ##           ##    ##   ##  ##   ##        ##   \n");
	printf("      ##       ##     ##   ##     ##     ##           ##    ##  ##    ##  ##        ##   \n");
	printf("      #######  ##     ##   ##     ##     ##           ######    ########  ##        ##   \n");
	printf("      ##       ##     ##   ##     ##     ##           ##    ##  ##    ##  ##        ##   \n");
	printf("      ##        ##   ##     ##   ##      ##           ##    ##  ##    ##  ##        ##   \n");
	printf("      ##         ####        ####        ##           #######   ##    ##  ########  ######## \n\n\n");
	printf("       ######  ######  ##    ##   ####  ##   ###### ##    ##     ##  ## ####  ####   ##  ##\n");
	printf("       ##   ## ##      ####  ##  ##  ## ##     ##    ##  ##      ## ##   ##  ##  ##  ## ## \n");
	printf("       ######  ######  ## ## ##  ###### ##     ##     ####       ###     ##  ##      ###   \n");
	printf("       ##      ##      ##  ####  ##  ## ##     ##      ##        ## ##   ##  ##  ##  ## ## \n");
	printf("       ##      ######  ##    ##  ##  ## ###### ##      ##        ##  ## ####  ####   ##  ##\n");
	struct Pos cursorPos = { 43, 27 };
	gotoxy(cursorPos.x - 2, cursorPos.y);
	printf("> 게 임 시 작 ");
	gotoxy(cursorPos.x, cursorPos.y + 1);
	printf("게 임 정 보 ");
	gotoxy(cursorPos.x, cursorPos.y + 2);
	printf("   종 료   ");
}
int menuSelect()
{
	struct Pos cursorPos = { 43, 27 };
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case 1: {
			if (cursorPos.y > 27)
			{
				gotoxy(cursorPos.x - 2, cursorPos.y);
				printf(" ");
				gotoxy(cursorPos.x - 2, --cursorPos.y);
				printf(">");
			}
			break;
		}
		case 3: {
			if (cursorPos.y < 29)
			{
				gotoxy(cursorPos.x - 2, cursorPos.y);
				printf(" ");
				gotoxy(cursorPos.x - 2, ++cursorPos.y);
				printf(">");
			}
			break;
		}
		case 5: {
			return cursorPos.y - 27;
			break;
		}
		}
	}
}
void GameInfo()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("   1. 이 게임은 승부차기 게임입니다.\n");
	printf("   2. 기본적으로 5번씩 컴퓨터와 유저가 번갈아 페널티킥을 찹니다.\n");
	printf("   3. 공격 상황에서는 w, a, s, d로 방향을 조정할 수 있고 f를 누르면 슈팅을 합니다.\n");
	printf("   4. 슈팅에는 오차범위가 존재합니다.\n");
	printf("   5. 규칙은 축구의 승부차기 규칙을 따릅니다.\n");
	printf("\n\n\n\n                            -스페이스바를 누르면 메뉴화면으로 돌아갑니다.-");
	while (1) {
		if (keyControl() == 5)
		{
			system("cls");
			break;
		}
	}
}
char Map[40][101] =
{
	{"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},//0
	{"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"},//1
	{"0000001111111111111111111111111111111111111111111111111111111111111111111111111111111111111111000000"},//2
	{"0000001010000000000000000000000000000000000000000000000000000000000000000000000000000000000101000000"},//3
	{"0000001001111111111111111111111111111111111111111111111111111111111111111111111111111111111001000000"},//4
	{"0000001001000000000000000000000000000000000000000000000000000000000000000000000000000000001001000000"},//5
	{"0000001001000000000000000000000000000000000000000000000000000000000000000000000000000000001001000000"},//6
	{"0000001000100000000000000000000000000000000000000000000000000000000000000000000000000000010001000000"},//7
	{"0000001000100000000000000000000000000000000000000000000000000000000000000000000000000000010001000000"},//8
	{"0000001000100000000000000000000000000000000000000000000000000000000000000000000000000000010001000000"},//9
	{"0000001000010000000000000000000000000000000000000000000000000000000000000000000000000000100001000000"},//10
	{"0000001000010000000000000000000000000000000000000000000000000000000000000000000000000000100001000000"},//11
	{"0000001000001000000000000000000000000000000000000000000000000000000000000000000000000001000001000000"},//12
	{"0000001000001000000000000000000000000000000000000000000000000000000000000000000000000001000001000000"},//13
	{"0000001000001000000000000000000000000000000000000000000000000000000000000000000000000001000001000000"},//14
	{"0000001000000100000000000000000000000000000000000000000000000000000000000000000000000010000001000000"},//15
	{"0000001000000100000000000000000000000000000000000000000000000000000000000000000000000010000001000000"},//16
	{"0000001000000010000000000000000000000000000000000000000000000000000000000000000000000100000001000000"},//17
	{"0000001000000010000000000000000000000000000000000000000000000000000000000000000000000100000001000000"},//18
	{"0000001000000011111111111111111111111111111111111111111111111111111111111111111111111100000001000000"},//19
	{"0000001000000100000000000000000000000000000000000000000000000000000000000000000000000010000001000000"},//20
	{"0000001000010000000000000000000000000000000000000000000000000000000000000000000000000000100001000000"},//21
	{"0000001001000000000000000000000000000000000000000000000000000000000000000000000000000000001001000000"},//22
	{"0000001100000000000000000000000000000000000000000000000000000000000000000000000000000000000011000000"},//23
	{"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"},//24
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//25
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//26
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//27
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//28
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//29
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//30
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//31
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//32
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//33
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//34
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//35
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//36
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//37
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"},//38
	{"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"}//39
};
void gLoop()
{

	int Playing = 1;
	int desision_player[5] = { 0,0,0,0,0 };
	int desision_computer[5] = { 0,0,0,0,0 };
	struct success s = { 0, 0 };
	int i = -1;
	while (Playing)
	{
		int n = 0;
		int t_x = 50;
		int t_y = 10;
		int p_x = 48;
		int p_y = 18;
		MapDraw();
		New_score(desision_player, desision_computer, i);
		peaple_Draw(p_x, p_y);
		tagetDraw(t_x, t_y);
		First_BallDraw();
		do
		{
			n = tagetMove(&t_x, &t_y);

		} while (n != 5);
		Ball_Peaple_Move(t_x, t_y, &p_x, &p_y);
		i++;
		desision_player[i] = collision_desision(p_x, p_y, t_x, t_y);
		desision_computer[i] = computer_desision();
		New_score(desision_player, desision_computer, i);
		Sleep(1000);
		if (i == 4)
		{
			for (int x = 0; x <= i; x++)
			{
				if (desision_player[x] == 2)
					s.player_success++;
				if (desision_computer[x] == 2)
					s.computer_success++;
			}
			break;
		}
	}
	SetColor(white, black);
	system("cls");
	result(s);
	Sleep(2000);
	system("cls");
}
void MapDraw()
{
	system("cls");
	for (int x = 0; x < 40; x++)
	{
		for (int y = 0; y < 101; y++)
		{
			char temp = Map[x][y];
			if (temp == '0')
			{
				SetColor(lightblue, lightblue);
				printf(" ");
			}
			else if (temp == '1')
			{
				SetColor(white, white);
				printf(" ");
			}
			else if (temp == 'g')
			{
				SetColor(lightgreen, lightgreen);
				printf(" ");
			}
		}
		if (x < 39)
			printf("\n");
	}
	SetColor(white, black);
}
void New_score(int p[], int c[], int size)
{
	SetColor(black, lightgreen);
	gotoxy(5, 35);
	printf("플레이어의 성공 :");
	gotoxy(5, 36);
	printf("컴퓨터의 성공 :");
	if (size != -1)
	{
		for (int i = 0; i <= size; i++)
		{
			if (p[i] == 1)
			{
				gotoxy(23 + 3 * i, 35);
				printf("x");
			}
			else
			{
				gotoxy(23 + 3 * i, 35);
				printf("0");
			}

			if (c[i] == 1)
			{
				gotoxy(23 + 3 * i, 36);
				printf("x");
			}
			else
			{
				gotoxy(23 + 3 * i, 36);
				printf("0");
			}
		}
	}
}
void InDraw()
{
	gotoxy(8, 3);
	for (int x = 2; x < 34; x++)
	{
		for (int y = 7; y < 92; y++)
		{
			char temp = Map[x][y];
			if (temp == '0')
			{
				SetColor(lightblue, lightblue);
				printf(" ");
			}
			else if (temp == '1')
			{
				SetColor(white, white);
				printf(" ");
			}
			else if (temp == 'p')
			{
				SetColor(black, black);
				printf(" ");
			}
			else if (temp == 'g')
			{
				SetColor(lightgreen, lightgreen);
				printf(" ");
			}
		}
		gotoxy(7, x + 1);
		SetColor(white, black);
	}
}

char ball[3][6] =
{
{"011110"},
{"111111"},
{"011110"},
};
void First_BallDraw()
{
	int ballx = 50;
	int bally = 30;
	gotoxy(ballx, bally);
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			char temp = ball[x][y];
			if (temp == '1')
			{
				SetColor(red, yellow);
				printf("*");
			}
		}
		if (x == 0)
			gotoxy(ballx - 1, bally + 1);
		else if (x == 1)
			gotoxy(ballx, bally + 2);
	}
}
void ballDraw(int *_x, int *_y, int *temp_x, int *temp_y)
{
	gotoxy(*_x, *_y);
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			char temp = ball[x][y];
			if (temp == '1')
			{
				SetColor(red, yellow);
				printf("*");
			}
		}
		if (x == 0)
		{
			gotoxy(*_x - 1, *_y + 1);
		}
		else if (x == 1)
		{
			gotoxy(*_x, *_y + 2);
		}
	}
}
void Ball_Peaple_Move(int roc_x, int roc_y, int *roc_px, int *roc_py)
{
	int i_x = 50;
	int i_y = 30;
	double _x = 50.0;
	double _y = 30.0;
	srand(time(NULL));
	int p_xi = 48;
	int p_yi = 18;
	double p_x = 48.0;
	double p_y = 18.0;
	int random_roc = rand() % 100;
	if (random_roc < 28)
	{
		*roc_px = roc_x;
		*roc_py = roc_y;
	}
	else
	{
		*roc_px = 7 + rand() % 75;
		*roc_py = 3 + rand() % 16;
	}
	int n = 0;
	double delta_px;
	double delta_py;
	if (*roc_px < 48)
	{
		delta_px = ((double)p_xi - (double)*roc_px) / 10.0;
	}
	else
	{
		delta_px = ((double)*roc_px - (double)p_xi) / 10.0;
	}
	if (*roc_py < 18)
	{
		delta_py = ((double)p_yi - (double)*roc_py) / 10.0;
	}
	else
	{
		delta_py = ((double)*roc_py - (double)p_yi) / 10.0;
	}
	double delta_x;
	double delta_y;
	delta_y = (double)(_y - roc_y) / 10.0;
	if (roc_x >= 50)
	{
		delta_x = ((double)roc_x - (double)i_x) / 10.0;
	}
	else
	{
		delta_x = ((double)i_x - (double)roc_x) / 10.0;
	}
	while (n != 6)
	{
		n = keyControl();
		if (n == 6)
		{
			for (int k = 0; k < 10; k++)
			{
				InDraw();
				int temp_px = p_xi;
				int temp_py = p_yi;
				if (*roc_px < 48)
				{
					p_x = p_x - delta_px;
				}
				else
				{
					p_x = p_x + delta_px;
				}
				p_xi = (int)p_x;
				p_y = p_y - delta_py;
				p_yi = (int)p_y;
				peapleDraw(temp_px, temp_py, p_xi, p_yi);
				int temp_x = i_x;
				int temp_y = i_y;
				if (roc_x <= 50)
					_x = _x - delta_x;
				else
					_x = _x + delta_x;
				i_x = (int)_x;
				_y = _y - delta_y;
				i_y = (int)_y;
				ballDraw(&i_x, &i_y, &temp_x, &temp_y);
			}
		}
	}
}
char peaple[6][9] =
{
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"},
	{"pppppppp"}
};
void peaple_Draw(int p_x, int p_y)
{
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			char temp = peaple[y][x];
			if (temp == 'p')
			{
				SetColor(black, black);
				gotoxy(p_x + x, p_y + y);
				printf(" ");
			}
		}
	}
}
void peapleDraw(int temp_px, int temp_py, int p_x, int p_y)
{
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			char temp = peaple[y][x];
			if (temp == 'p')
			{
				SetColor(black, black);
				gotoxy(p_x + x, p_y + y);
				printf(" ");
			}
		}
	}
}
void tagetDraw(int x, int y)
{
	if ((x >= 48) && (x < 56))
	{
		if ((y <= 24) && (y >= 18))
		{
			SetColor(white, black);
			gotoxy(x, y);
			printf("#");
		}
		else
		{
			char temp = Map[y][x];
			if (temp == '0')
			{
				SetColor(yellow, lightblue);
				gotoxy(x, y);
				printf("#");
			}
			else if (temp == '1')
			{
				SetColor(black, white);
				gotoxy(x, y);
				printf("#");
			}
		}
	}
	else
	{
		char temp = Map[y][x];
		if (temp == '0')
		{
			SetColor(yellow, lightblue);
			gotoxy(x, y);
			printf("#");
		}
		else if (temp == '1')
		{
			SetColor(black, white);
			gotoxy(x, y);
			printf("#");
		}
	}
}

void tagetRemove(int x, int y)
{
	if ((x >= 48) && (x < 56))
	{
		if ((y <= 24) && (y >= 18))
		{
			SetColor(black, black);
			gotoxy(x, y);
			printf(" ");
		}
		else
		{
			char temp = Map[y][x];
			if (temp == '0')
			{
				SetColor(yellow, lightblue);
				gotoxy(x, y);
				printf(" ");
			}
			else if (temp == 'p')
			{
				SetColor(yellow, black);
				gotoxy(x, y);
				printf(" ");
			}
			else if (temp == '1')
			{
				SetColor(yellow, white);
				gotoxy(x, y);
				printf(" ");
			}
		}
	}
	else
	{
		char temp = Map[y][x];
		if (temp == '0')
		{
			SetColor(yellow, lightblue);
			gotoxy(x, y);
			printf(" ");
		}
		else if (temp == 'p')
		{
			SetColor(yellow, black);
			gotoxy(x, y);
			printf(" ");
		}
		else if (temp == '1')
		{
			SetColor(yellow, white);
			gotoxy(x, y);
			printf(" ");
		}
	}
}

int tagetMove(int *x, int *y)
{
	int n = keyControl();
	if (n == 1 && (*y != 3))
	{
		tagetRemove(*x, *y);
		*y -= 1;
		tagetDraw(*x, *y);
	}
	else if (n == 2 && (*x != 7))
	{
		tagetRemove(*x, *y);
		*x -= 1;
		tagetDraw(*x, *y);
	}
	else if (n == 3 && (*y != 23))
	{
		tagetRemove(*x, *y);
		*y += 1;
		tagetDraw(*x, *y);
	}
	else if (n == 4 && (*x != 92))
	{
		tagetRemove(*x, *y);
		*x += 1;
		tagetDraw(*x, *y);
	}
	else if (n == 5)
	{
		tagetRemove(*x, *y);
	}
	return n;
}
int collision_desision(int px, int py, int bx, int by)
{
	if ((px - 6 <= bx) && (bx <= px + 8))
	{
		if ((py - 3 <= by) && (by <= py + 6))
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 2;
	}
}
int computer_desision()
{
	srand(time(NULL));
	int computer_desision = 0;
	int random = rand() % 100;
	if (random < 70)
		computer_desision = 2;
	else
		computer_desision = 1;
	return computer_desision;
}

void result(struct success s)
{
	if (s.player_success > s.computer_success)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                   ###        #####        ###     #######     ######        ###         \n");
		printf("                   ###       ### ###       ###       ###       ### ###       ###         \n");
		printf("                    ###     ###   ###     ###        ###       ###  ###      ###         \n");
		printf("                    ###     ###   ###     ###        ###       ###   ###     ###         \n");
		printf("                     ###   ###     ###   ###         ###       ###    ###    ###         \n");
		printf("                     ###   ###     ###   ###         ###       ###     ###   ###         \n");
		printf("                      ### ###       ### ###          ###       ###      ###  ###         \n");
		printf("                      ### ###       ### ###          ###       ###       ### ###         \n");
		printf("                       #####         #####         #######     ###        ######         \n");
		printf("\n\n\n\n\n\n\n\n");
	}
	else if (s.player_success == s.computer_success)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("       ###########         ###########              ########     ###        #####        ###       \n");
		printf("       ###       ###       ###       ###           ###    ###    ###       ### ###       ###       \n");
		printf("       ###        ###      ###        ###         ###     ###     ###     ###   ###     ###        \n");
		printf("       ###         ###     ###       ###         ###      ###     ###     ###   ###     ###        \n");
		printf("       ###         ###     ###########          #############      ###   ###     ###   ###         \n");
		printf("       ###         ###     ###      ###        ###        ###      ###   ###     ###   ###         \n");
		printf("       ###        ###      ###       ###      ###         ###       ### ###       ### ###          \n");
		printf("       ###       ###       ###        ###    ###          ###       ### ###       ### ###          \n");
		printf("       ###########         ###         ###  ###           ###        #####         #####           \n");
		printf("\n\n\n\n\n\n\n\n");
	}
	else
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("             ###                 #########           ###########        #############              \n");
		printf("             ###               ###       ###        ###       ###       ###                        \n");
		printf("             ###              ###         ###      ###                  ###                        \n");
		printf("             ###              ###         ###       ###                 ###                        \n");
		printf("             ###              ###         ###        ###########        #############              \n");
		printf("             ###              ###         ###                 ###       ###                        \n");
		printf("             ###              ###         ###                  ###      ###                        \n");
		printf("             ###               ###       ###       ###        ###       ###                        \n");
		printf("             #############       #########           ###########        #############              \n");
		printf("\n\n\n\n\n\n\n\n");
	}
}