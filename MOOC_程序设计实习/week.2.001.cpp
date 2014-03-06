//
//  week.2.001.cpp
//  程序设计实习
//
//  Created by 李喆 on 14-3-2.
//  Copyright (c) 2014年 李喆. All rights reserved.
//

/*
A:简单的学生信息处理程序实现
描述
在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。

（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

输入
姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。

其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。

各部分内容之间均用单个英文逗号","隔开，无多余空格。
输出
一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。

各部分内容之间均用单个英文逗号","隔开，无多余空格。
样例输入
Tom,18,7817,80,80,90,70
样例输出
Tom,18,7817,80
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Student {
private:
    char * name;
    int  age;
    char * id;
    int average_grade1;
    int average_grade2;
    int average_grade3;
    int average_grade4;
public:
    void setName(char *);
    void setAge(int);
    void setId(char *);
    void setAverage_grade1(int);
    void setAverage_grade2(int);
    void setAverage_grade3(int);
    void setAverage_grade4(int);
    
    char * getName();
    int getAge();
    char * getId();
    int getAverage_grade();
    
};

void Student::setName(char * sname) {
    name = sname;
}
void Student::setAge(int sage) {
    age = sage;
}
void Student::setId(char * sid) {
    id = sid;
}
void Student::setAverage_grade1(int grade1) {
    average_grade1 = grade1;
}
void Student::setAverage_grade2(int grade2) {
    average_grade2 = grade2;
}
void Student::setAverage_grade3(int grade3) {
    average_grade3 = grade3;
}
void Student::setAverage_grade4(int grade4) {
    average_grade4 = grade4;
}

char * Student::getName() {
    return name;
}
int Student::getAge() {
    return age;
}
char * Student::getId() {
    return id;
}
int Student::getAverage_grade() {
    return (average_grade1 + average_grade2 + average_grade3 + average_grade4) / 4;
}

int main() {
    char name[20];
    char age[20];
    char id[20];
    char average_grade1[20];
    char average_grade2[20];
    char average_grade3[20];
    char average_grade4[20];
    cin.getline(name, 20, ',');
    cin.getline(age, 20, ',');
    cin.getline(id, 20, ',');
    cin.getline(average_grade1, 20, ',');
    cin.getline(average_grade2, 20, ',');
    cin.getline(average_grade3, 20, ',');
    cin.getline(average_grade4, 20);
    Student stu ;
    stu.setName(name);
    stu.setAge(atoi(age));
    stu.setId(id);
    stu.setAverage_grade1(atoi(average_grade1));
    stu.setAverage_grade2(atoi(average_grade2));
    stu.setAverage_grade3(atoi(average_grade3));
    stu.setAverage_grade4(atoi(average_grade4));
    
    printf("%s,%d,%s,%d",stu.getName(),stu.getAge(),stu.getId(),stu.getAverage_grade());
    
}