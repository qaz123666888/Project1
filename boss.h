#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
class boss :public worker {
public:
	boss(int id1, string name1, double idd1);
	virtual void show_id();
	virtual string getname();
	virtual void showidd();
};