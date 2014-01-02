//
//  FE.1.cpp
//  计算概论
//
//  Created by 李喆 on 13-12-25.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//1 : 含k个3的数
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//输入二个正整数m 和 k，其中1 < m < 100000，1 < k <5 ，判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。
//
//例如，输入：
//43833 3
//满足条件，输出YES
//
//如果输入
//39331 3
//尽管有3个3，但不能被19整除，也不满足条件，应输出NO
//
//输入
//m 和 k 的值，空格间隔
//输出
//满足条件时输出 YES，不满足时输出 NO
//样例输入
//43833 3
//样例输出
//YES


#include <iostream>
using namespace std;

int main() {
    int m,k,m2;
    cin >> m >> k;
    int q=0;
    m2 = m ;
    if (m>1 && m<100000 && k>1 && k<5 && m%19==0) {
        
        while (m > 1) {

            if (m%10 == 3){
                q++ ;
            }
            
            m/= 10 ;
        }
        
        if (q==k) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
    } else
        cout << "NO" << endl;
    
    return 0;
}