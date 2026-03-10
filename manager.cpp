#include"manager.h"
manager::manager(int id1, string name1, double idd1) {
	this->id = id1;
	this->name = name1;
	this->idd = idd1;
}
void manager::show_id() {
	cout << "职工编号\t" << this->id
		<< "职工姓名\t" << this->name
		<< "职工岗位\t" << this->idd
		<< "岗位职责：完成老板交代任务，并给员工安排任务" << endl;
}
string manager::getname() {
	return string("manager");
}
void manager::showidd() {
	cout << "部门为" << this->idd;
}
