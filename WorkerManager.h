#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME  "tryfile.txt"
class workermanager {
public:
	workermanager();
    bool fileisempty;
    //退出
    void exitsystem();//0
    //添加员工
    int endcount=0;
    worker** array=nullptr;
	void addworker();
    
    //保存文件
    void save();

    //统计员工数量
    int gettotal();

    //初始化员工
    void init_emp();


    //显示员工
    void showworkers();



    //判断员工是否存在
    int isexit(int id, string name);

    //删除员工
    void deleteworker();



    //更改员工
    void modifyworker();



    //查询员工
    void  findworker();
    //排序
    void   sortworkers();
    //清空
    void  clearfile();


    void show_menue();




	~workermanager();


};