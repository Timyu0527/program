#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define width 10
#define height 5

char maze[2 * height + 1][2 * width + 1];

void initMaze()
{
    for(int i = 0; i < 2 * height + 1; i++)
    {
        for(int j = 0; j < 2 * width + 1; j++)
        {
            if(i != 2 * height && j != 2 * width && i != 0 && j != 0) maze[i][j] = 1;
            else maze[i][j] = 2;
        }
    }
}

void creatMaze(int x, int y)
{
    if(x >= 1 && x < 2 * height + 1 && y >= 1 && y < 2 * width + 1)
    {
        while(1)
        {
            int count = 0;
            int offset[4][2] ={{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
            if(maze[x][y] == 1) maze[x][y] = 0;
            for(int i = 0; i < 4; i++)
            {
                if(maze[x+offset[i][0]][y+offset[i][1]] == 1) count++;
            }
            if(count)
            {
                int dir;
                do
                {
                    dir = rand() % 4;
                }
                while(maze[x+offset[dir][0]][y+offset[dir][1]] == 0);
                if(maze[x+offset[dir][0]][y+offset[dir][1]] == 1) maze[x+offset[dir][0]/2][y+offset[dir][1]/2] = 0;
                creatMaze(x+offset[dir][0], y+offset[dir][1]);
            }
            else return;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    initMaze();
    creatMaze(1, 1);
    maze[1][0] = 0;
    maze[2 * height - 1][2 * width] = 0;
    for(int i = 0; i < 2 * height + 1; i++)
    {
        for(int j = 0; j < 2 * width + 1; j++)
        {
            if(maze[i][j]) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}
