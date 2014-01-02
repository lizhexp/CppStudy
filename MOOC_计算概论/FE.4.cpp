//
//  FE.4.cpp
//  计算概论
//
//  Created by 李喆 on 13-12-25.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//4 : 矩阵归零消减序列和
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//给定一个n*n的矩阵（3 <= n <= 100，元素的值都是非负整数）。通过n-1次实施下述过程，可把这个矩阵转换成一个1*1的矩阵。每次的过程如下：
//首先对矩阵进行行归零：即对每一行上的所有元素，都在其原来值的基础上减去该行上的最小值，保证相减后的值仍然是非负整数，且这一行上至少有一个元素的值为0。
//接着对矩阵进行列归零：即对每一列上的所有元素，都在其原来值的基础上减去该列上的最小值，保证相减后的值仍然是非负整数，且这一列上至少有一个元素的值为0。
//然后对矩阵进行消减：即把n*n矩阵的第二行和第二列删除（如果二维数组为a[][]，则删除的是a[1][1]所在的行和列），使之转换为一个(n-1)*(n-1)的矩阵。
//下一次过程，对生成的(n-1)*(n-1)矩阵实施上述过程。显然，经过n-1次上述过程， n*n的矩阵会被转换为一个1*1的矩阵。
//请求出每次消减前a[1][1]值之和。
//
//输入
//第一行是一个整数n。
//其后是n个n*n的矩阵。
//每个矩阵占n行，每行有n个正整数，每个整数间用空格分隔。
//输出
//输出为n行，每行上的整数为对应矩阵归零消减过程中，每次消减前a[1][1]值之和。
//样例输入
//3
//1 2 3
//2 3 4
//3 4 5
//1 2 3
//5 4 2
//9 4 5
//1 2 3
//5 4 2
//9 5 4
//样例输出
//0
//2
//1

#include <iostream>
using namespace std;

int main() {
    int n;
    int array[101][101]={0};
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                cin >> array[j][k];
            }
        }
        int count=0;
        for (int m=n; m>1; m--) {
            for (int j=0; j<m; j++) {
                int min=*array[j];
                for (int k=0; k<m; k++) {
                    if (array[j][k]<min) {
                        min=array[j][k];
                    }
                }
                for (int k=0; k<m; k++) {
                    array[j][k]=array[j][k]-min;
                }
            }
            
            for (int j=0; j<m; j++) {
                int min=array[0][j];
                for (int k=0; k<m; k++) {
                    if (array[k][j]<min) {
                        min=array[k][j];
                    }
                }
                for (int k=0; k<m; k++) {
                    array[k][j]=array[k][j]-min;
                }
            }
            
            count=count+array[1][1];
            
            for (int j=1; j<m; j++) {
                for (int k=0; k<m; k++) {
                    array[j][k]=array[j+1][k];
                }
            }
            for (int j=0; j<m; j++) {
                for (int k=1; k<m; k++) {
                    array[j][k]=array[j][k+1];
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}