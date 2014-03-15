//
//  week.3.001.cpp
//  程序设计实习
//
//  Created by 李喆 on 14-3-15.
//  Copyright (c) 2014年 李喆. All rights reserved.
//
/*
A:魔兽世界之一：备战
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
武士在刚降生的时候有一个生命值。
在每个整点，双方的司令部中各有一个武士降生。
红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
制造武士需要生命元。
制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：
1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士
输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。
输入
第一行是一个整数，代表测试数据组数。
每组测试数据共两行。
第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 1000)。
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于100。
输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
样例输入
1
20
3 4 5 6 7
样例输出
Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
000 blue lion 1 born with strength 6,1 lion in blue headquarter
001 red lion 2 born with strength 6,1 lion in red headquarter
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
004 blue headquarter stops making warriors
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Warrior {
private:
    int no;
    int str;
    string type;
public:
    Warrior(int wno,int wstr,string wtype) {
        no = wno;
        str = wstr;
        type = wtype;
    }
    int getNo() {return no;}
    int getStr() {return str;}
    string getType() {return type;}
    void setStr(int newStr) {str = newStr;}
};

class Headquarter {
private:
    string color;
    int totalStr;
    string createorder[5];
    int strorder[5];
    int warsum[5];
    int curpos;
    int create_order;
    bool flag;

public:
    Headquarter(string hcolor,int htotal,string horder[5],int hstr[5]) {
        color = hcolor;
        totalStr = htotal;
        for (int i=0; i<5; i++) {
            createorder[i] = horder[i];
            strorder[i] = hstr[i];
            warsum[i] = 0;
        }
        curpos = 0;
        flag = true;
        create_order = 0;
    }
    string getColor() {return color;}
    int getTotalstr() {return totalStr;}
    int nextPos() { return (curpos + 1) % 5; }
    int minStr();
    
    bool createWarrior();
    
};

int Headquarter::minStr() {
    int minStr = strorder[0];
    for (int i=0; i<5; i++) {
        if (minStr > strorder[i]) {
            minStr = strorder[i];
        }
    }
    return minStr;
}

bool Headquarter::createWarrior() {
    if (!flag) {
        return flag;
    }
    
    if (totalStr < minStr())
	{
        flag = false;
		printf("%03d %s headquarter stops making warriors\n",create_order,getColor().c_str());
		return flag;
	}
    
    while (strorder[curpos] > totalStr) {
        curpos = nextPos();
    }
    Warrior war(create_order, strorder[curpos], createorder[curpos]);
    warsum[curpos]++;
    
    printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",create_order,getColor().c_str(),createorder[curpos].c_str(),create_order + 1,strorder[curpos],warsum[curpos],createorder[curpos].c_str(),getColor().c_str());
    
    totalStr -= strorder[curpos];
    curpos = nextPos();
    create_order++;
    return flag;
}

int main() {
    int num = 0;
    cin >> num;
    
    string normalWar[5] = {"dragon","ninja","iceman","lion","wolf"};
    string redWar[5] = {normalWar[2],normalWar[3],normalWar[4],normalWar[1],normalWar[0]};
    string blueWar[5] = {normalWar[3],normalWar[0],normalWar[1],normalWar[2],normalWar[4]};

    for (int i=0; i<num; i++) {
        printf("Case:%d\n",i+1);
        
        int initStr = 0;
        cin >> initStr;
        
        int normStr[5];
        for (int i=0; i<5; i++) {
            cin >>normStr[i];
        }
        int redStr[5] = {normStr[2],normStr[3],normStr[4],normStr[1],normStr[0]};
        int blueStr[5] = {normStr[3],normStr[0],normStr[1],normStr[2],normStr[4]};
        
        Headquarter redCamp("red", initStr, redWar, redStr);
        Headquarter blueCamp("blue", initStr, blueWar, blueStr);

        
        bool blueFlag = true,redFlag = true;
        while (blueFlag || redFlag) {
            
            redFlag = redCamp.createWarrior();
            blueFlag = blueCamp.createWarrior();

        }
        
        
    }
}

