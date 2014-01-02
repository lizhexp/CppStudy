//
//  B11.1.2.cpp
//  计算概论
//
//  Created by 李喆 on 13-12-13.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//第2题：2:二维数组右上左下遍历
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//给定一个row行col列的整数数组array，要求从array[0][0]元素开始，按从左上到右下的对角线顺序遍历整个数组。
//
//输入
//输入的第一行上有两个整数，依次为row和col。
//余下有row行，每行包含col个整数，构成一个二维整数数组。
//（注：输入的row和col保证0 < row < 100, 0 < col < 100）
//输出
//按遍历顺序输出每个整数。每个整数占一行。
//样例输入
//3 4
//1 2  4  7
//3 5  8 10
//6 9 11 12
//样例输出
//1
//2
//3
//4
//5
//6
//7
//8
//9
//10
//11
//12


#include <iostream>
using namespace std;

int main() {
    int m,n;
    cin >> m >> n;
    int array[100][100];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> array[i][j];
        }
    }
    for (int i=0; i<n+m-1; i++) {
        for (int j=i,k=0; j>=0&&k<m; j--,k++) {
            if (j<n) {
                cout << *(*(array+k)+j)<<endl;;
            }
        }
    }
}