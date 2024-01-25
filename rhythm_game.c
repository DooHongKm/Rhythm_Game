#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#pragma comment(lib,"winmm") 

struct music {
	char up;
	char down;
	char left;
	char right;
};

int main()
{
	PlaySoundA("music.wav", NULL, SND_ASYNC);
	int B1 = 0;
	int B2 = 0;
	int B3 = 0;
	int B4 = 0;

	Sleep(1500);
	FILE* f = fopen("input.dat", "r");
	char temp[9];
	char buf[1000][4];
	int i = 0;
	int score = 0;
	struct music m;

	while (!feof(f)) {

		fgets(temp, 9, f);
		if (temp[0] == '1')
			printf("*\t");
		else
			printf("\t");
		if (temp[2] == '1')
			printf("*\t");
		else
			printf("\t");
		if (temp[4] == '1')
			printf("*\t");
		else
			printf("\t");
		if (temp[6] == '1')
			printf("*\t");
		else
			printf("\t");

		buf[i][0] = temp[0];
		buf[i][1] = temp[2];
		buf[i][2] = temp[4];
		buf[i][3] = temp[6];

		if (i > 29) {
			if (GetAsyncKeyState(VK_UP)) {
				m.up = '1';
				B1 = 1;
			}
			else {
				m.up = '0';
				B1 = 0;
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				m.down = '1';
				B2 = 1;
			}
			else {
				m.down = '0';
				B2 = 0;
			}

			if (GetAsyncKeyState(VK_LEFT)) {
				m.left = '1';
				B3 = 1;
			}
			else {
				m.left = '0';
				B3 = 0;
			}

			if (GetAsyncKeyState(VK_RIGHT)) {
				m.right = '1';
				B4 = 1;
			}
			else {
				m.right = '0';
				B4 = 0;
			}


			if ((B1 == 1 || B2 == 1 || B3 == 1 || B4 == 1) && buf[i - 30][0] == m.up && buf[i - 30][1] == m.down && buf[i - 30][2] == m.left && buf[i - 30][3] == m.right) {
				score += 1;
				printf("\tYou - HIT");
			}
			else {
				printf("\tYou - MISS");
			}
		}

		printf("\n");

		i++;

		Sleep(50);
	}

	printf("\nscore : %d\n", score);

	fclose(f);

}