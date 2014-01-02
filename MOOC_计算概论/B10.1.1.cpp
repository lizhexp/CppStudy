//
//  B10.1.1.cpp
//  计算概论
//
//  Created by 李喆 on 13-11-28.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//第1题：1:单词翻转
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//输入一个句子（一行），将句子中的每一个单词翻转后输出
//
//输入
//只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。
//输出
//翻转每一个单词后的字符串
//样例输入
//hello world
//样例输出
//olleh dlrow

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[500]={};
    char a[500][2];
    int sp=0,len=0;
    cin.get(str,500).get();
	for (int i=0; i<=strlen(str); i++) {
        if (str[i]!=' ' && i != strlen(str)) {
            a[sp][0]=str[i];
            a[sp++][1]=i;
            len=sp;
        } else if (i == strlen(str)) {
            for (int j=0; j<len; j++) {
                cout << a[--sp][0];
            }
        } else {
            for (int j=0; j<len; j++) {
                cout << a[--sp][0];
            }
            cout << " ";
            len = 0;
        }
        
    }
	return 0;
}