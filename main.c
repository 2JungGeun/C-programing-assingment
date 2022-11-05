#include"main.h"
#include"game.h"
#include"util.h"

int main(void)
{
	init();
	while (1) {
		titleDraw();
		int menucode = menuSelect();
		if (menucode == 0)
			gLoop();
		else if (menucode == 1)
			GameInfo();
		else if (menucode == 2)
			break;
	}
	return 0;
}
/*
SetColor(white, black);*/