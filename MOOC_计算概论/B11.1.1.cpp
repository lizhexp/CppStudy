//
//  B11.1.1.cpp
//  计算概论
//
//  Created by 李喆 on 13-12-13.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//第1题：1:计算矩阵边缘元素之和
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。
//
//输入
//第一行为整数k，表示有k组数据。
//每组数据有多行组成，表示一个矩阵：
//第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。
//接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。
//输出
//输出对应矩阵的边缘元素和，一个一行。
//样例输入
//2
//4 4
//1 1 1 1
//0 0 0 0
//1 0 1 0
//0 0 0 0
//3 3
//3 4 1
//3 7 1
//2 0 1
//样例输出
//5
//15


#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    int m,n;
    int count[100]={0};
    for (int i=0; i<a; i++) {
        cin >> m >> n;
        int x[100][100];
        for (int j=0; j<m; j++) {
            for (int k=0; k<n; k++) {
                cin >> x[j][k];
            }
        }
        for (int j=0; j<m; j++) {
            count[i]=count[i] + **(x+j);
            if (n>1) {
                count[i]=count[i] + *(*(x+j)+n-1);
            }
            
        }
        for (int j=1; j<n-1; j++) {
            count[i]=count[i] + *(*x+j);
            if (m>1) {
                count[i]=count[i] + *(*(x+m-1)+j);
            }
        }
    }
    for (int i=0; i<a; i++) {
        cout << count[i] <<endl;
    }
}