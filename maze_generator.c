#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void walk(int w1,int h1,int x, int y, int (*vis1)[w1], char (*ver1)[w1][4], char (*hor1)[w1][4]);
void shuffle(int (*array)[2], size_t n);
int main()
{
    int w=16, h=8;
    srand(time(0));
    int vis[h+1][w+1];
    char ver[h+1][w+1][4];
    char hor[h+1][w+1][4];

    for (int i=0;i<h+1;i++)
    {
      if (i<h)
        {
            for (int j=0;j<w;j++)
            {
                vis[i][j]=0;
            
            }
            vis[i][w+1]=1;
        }
        else
        {
            for (int j=0;j<w+1;j++)
            {
                vis[i][j]=1;
            }
        }   
    }   
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w+1;j++)
        {
            ver[i][j][0]='|';
            ver[i][j][1]=' ';
            ver[i][j][2]=' ';
            ver[i][j][3]='\0';



        }
    }
    for (int i=0;i<h+1;i++)
    {
        for (int j=0;j<w+1;j++)
        {
            hor[i][j][0]='+';
            hor[i][j][1]='-';
            hor[i][j][2]='-';
            hor[i][j][3]='\0';

        }
    }
    walk(16,8,rand()%(w+1),rand()%(h+1), vis,ver,hor);
    for (int i=0; i<h+1; i++)
    {
        for (int j=0; j<w+1; j++)
        {
            printf("%s",hor[i][j]);
        }
        printf("\n");
        for (int j=0; j<w+1; j++)
        {
            printf("%s",ver[i][j]);
        }
        printf("\n");
    }
}
void walk(int w1,int h1,int x, int y, int (*vis1)[w1], char (*ver1)[w1][4], char (*hor1)[w1][4])
{
    vis1[y][x]=1;
    int d[][2]={{x-1,y},{x,y+1},{x+1,y},{x,y-1}};
    shuffle(d,4);
    for (int i=0; i<4; i++)
    {
        if (vis1[d[i][1]][d[i][0]])
        {
            continue;
        }
        if (d[i][0]==x)
        {   
            int yy=y>d[i][1]?y:d[i][1];
            hor1[yy][x][0]='+';
            hor1[yy][x][1]=' ';
            hor1[yy][x][2]=' ';
            hor1[yy][x][3]='\0';



        }
        if (d[i][1]==y)
        {
            int xx=x>d[i][0]?x:d[i][0];
            ver1[y][xx][0]=' ';
            ver1[y][xx][1]=' ';
            ver1[y][xx][2]=' ';
            ver1[y][xx][3]='\0';



        }
        walk(w1,h1,d[i][0],d[i][1],vis1,ver1,hor1);
    }

}
void shuffle(int (*array)[2], size_t n)
{
    if (n > 1) 
    {
        int i;
        for (i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          for (int k=0; k<2;k++)
          {
              int t=array[j][k];
              array[j][k]=array[i][k];
              array[i][k]=t;
          }
        }
    }
}