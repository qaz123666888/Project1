#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker {
public:
	virtual void show_id()=0;
	virtual string getname() = 0;
	virtual void showidd()=0;


	int id;
	string name;
	double idd;
	

};