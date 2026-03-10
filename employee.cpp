#include"employee.h"
employee::employee(int id1,string name1,double idd1) {
	this->id = id1;
	this->name = name1;
	this->idd = idd1;
}
void employee::show_id() {
	cout << "职工编号" << this->id
		<< "\t职工姓名" << this->name
		<< "\t职工岗位" << this->idd
		<< "\t岗位职责：完成经理交代任务" << endl;
}
string employee::getname() {
	return string("员工");
}
void employee::showidd() {
	cout << "部门为" << this->idd;
}
