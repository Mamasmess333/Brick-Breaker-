#include <stdlib.h>
#include "stdio.h"
#include "myLib.h"
#include "text.h"

#define MAXROW 149

int main()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	MOVOBJ objs[NUMOBJS];
	MOVOBJ oldobjs[NUMOBJS];
	MOVOBJ *cur;
	int dels[] = {-3, -2, -1, 1, 2, 3};
	int numdels = sizeof(dels)/sizeof(dels[0]);
	u16 colors[] = {RED, GREEN};
	int numcolors = sizeof(colors)/sizeof(colors[0]);
	for(int i=0; i<NUMOBJS; i++)
	{
		objs[i].row = rand()%20 + 70;
		objs[i].col = rand()%20 + 110;
		objs[i].rd =  dels[rand()%numdels];
		objs[i].cd =  dels[rand()%numdels];
		objs[i].color = colors[i%numcolors];
		oldobjs[i] = objs[i];

	}


	int size = 5;
	int oldsize = size;
	u16 bgcolor = BLACK;
	REG_DMA3SAD = (u32)&bgcolor;
	REG_DMA3DAD = (u32)videoBuffer;
	REG_DMA3CNT = 38400 | DMA_ON | DMA_SOURCE_FIXED;
	

	char buffer[41];
	int age = 67;
	drawString(150, 5, buffer, YELLOW);
	while(1);
	while(1)
	{
		if(KEY_DOWN_NOW(BUTTON_UP))
		{
			size++;
			if(size>150) size = 150;
		}
		if(KEY_DOWN_NOW(BUTTON_DOWN))
		{
			size--;
			if(size<3) size = 3;
		}
		for(int i=0; i<NUMOBJS; i++)
		{
			//cur = &objs[i];
			cur = objs + i;   
			//(*cur).row += (*cur).rd;
			cur->row += cur->rd;

			cur->col += cur->cd;
			if(cur->row < 0)
			{
				cur->row = 0;
				cur->rd = -cur->rd;
			}
			if(cur->row > MAXROW-size)
			{
				cur->row = MAXROW-size;
				cur->rd = -cur->rd;
			}
			if(cur->col < 0)
			{
				cur->col = 0;
				cur->cd = -cur->cd;
			}
			if(cur->col > 239-size)
			{
				cur->col = 239-size;
				cur->cd = -cur->cd;
			}
		}
		waitForVblank();
		for(int i=0; i<NUMOBJS; i++)
		{
			
			drawRect(oldobjs[i].row, oldobjs[i].col, oldsize, oldsize, bgcolor);
		}
		for(int i=0; i<NUMOBJS; i++)
		{
			cur = objs + i;
			drawRect(cur->row, cur->col, size, size, cur->color);
			oldobjs[i] = objs[i];
		} 
		oldsize = size;

	}

}


