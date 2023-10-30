#include <stdio.h>

using namespace std;

int ROW,COL;
int row,col;

int main(void)
{
	scanf("%d %d %d %d",&ROW, &COL, &row, &col);
	int x = (COL/(col+1));
	int y = (ROW/(row+1));

	if(COL % (col+1))
		x++;
	if(ROW % (row+1))
		y++;
	
	printf("%d\n", x*y);
    return 0;
}