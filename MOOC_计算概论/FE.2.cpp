//
//  FE.2.cpp
//  计算概论
//
//  Created by 李喆 on 13-12-25.
//  Copyright (c) 2013年 李喆. All rights reserved.
//
//=====
//2 : 统计词长度
//=====
//总时间限制:
//1000ms
//内存限制:
//65536kB
//描述
//假定一篇文章由若干词组成，单词之间通过英语的逗号、句点或空格间隔。想统计不同长度的单词数量，按由短到长的顺序输出不同长度的单词数量，并输出所有单词的平均长度（按除式表示）。
//
//(注意：忽略标点符号和空格)。
//
//例如，一串单词：
//
//I am a student.
//
//这里，长度为1的单词有2个，长度为2的有1个，长度为7的有1个，所有单词的长度之和为11，于是，输出为：
//(1,2)
//(2,1)
//(7,1)
//11/4
//
//前面若干行以小括号表示，左边的数值表示单词长度，右边的数值表示该长度的单词个数。
//
//输入
//单词序列，其间由空格、逗号或句点间隔。
//输出
//按长度由短到长输出不同长度单词的个数，并输出平均长度
//样例输入
//I am a student.
//样例输出
//(1,2)
//(2,1)
//(7,1)
//11/4

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char article[100000];
    int num[100000]={0};
    int word_length=0,total_length=0,word_count=0;
    cin.getline(article,100000);
    for (int i=0; i<strlen(article); i++) {
        if (article[i]!=' ' && article[i]!=',' && article[i]!='.') {
            word_length++;
            total_length++;
        } else {
            if (word_length>0) {
                num[word_length]++;
                word_count++;
            }
            word_length=0;
        }
    }
    if (word_length!=0) {
        num[word_length]++;
        word_count++;
    }

    for (int i=1; i<100000; i++) {
        if (num[i]!=0) {
            cout << "(" << i << "," << num[i] << ")" << endl;
        }
    }
    cout << total_length << "/" << word_count << endl;
    return 0;
}