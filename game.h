#include"main.h"

int keyControl();
void titleDraw();
int menuSelect();
void GameInfo();
void InDraw();
void MapDraw();
void peaple_Draw(int p_x, int p_y);
void First_BallDraw();
void Ball_Peaple_Move(int roc_x, int roc_y, int *roc_px, int *roc_py);
void ballDraw(int *_x, int *_y, int *temp_x, int *temp_y);
void tagetDraw(int x, int y);
int tagetMove(int *x, int *y);
void tagetRemove(int x, int y);
void peapleDraw(int temp_px, int temp_py, int p_x, int p_y);
void New_score(int p[], int c[], int size);
int collision_desision(int px, int py, int bx, int by);
void gLoop();
void result(struct success s);