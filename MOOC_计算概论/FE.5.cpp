//
//  FE.5.cpp
//  计算概论
//
//  Created by 李喆 on 13-12-25.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//5 : 走出迷宫
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。
//假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。
//
//输入
//第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。
//接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。
//输出
//输出从起点到出口最少需要走的步数。(你不能起出迷宫外)
//样例输入
//3 3
//S#T
//.#.
//...
//样例输出
//6

#include <iostream>
#include <cstring>
using namespace std;

int m,n;
char map[101][101];
int already[101][101];
int min_count=0;

void cross(int u, int v, int i, int j)
{
    int t = already[u][v];
	if (u == i && v == j)
    {
        min_count = t;
    }
    t++;
    
    if (v < m - 1 && map[u][v+1] != '#'  && already[u][v+1]>t)
	{
        already[u][v+1] = t;
        cross(u, v+1, i, j);
	}
	if (u > 0 && map[u-1][v] != '#'  && already[u-1][v]>t)
	{
        already[u-1][v] = t;
        cross(u-1, v, i, j);
	}
    if (v > 0 && map[u][v-1] != '#'  && already[u][v-1]>t)
	{
        already[u][v-1] = t;
		cross(u, v-1, i, j);
	}
    if (u < n - 1 && map[u+1][v] != '#' && already[u+1][v]>t)
	{
        already[u+1][v] = t;
		cross(u+1, v, i, j);
	}
}

int main() {
    int startx,starty,endx,endy;
    cin >> n >> m ;
    for (int i=0; i<n ; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j]=='S') {
                startx=i;
                starty=j;
            }
            if (map[i][j]=='T') {
                endx=i;
                endy=j;
            }
        }
    }
    memset(already,1,sizeof(already));
    already[startx][starty]=0;
    cross(startx,starty,endx,endy);
    cout <<min_count<<endl;
    return 0;
}