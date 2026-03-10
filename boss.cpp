#include"boss.h"
boss::boss(int id1, string name1, double idd1) {
	this->id = id1;
	this->name = name1;
	this->idd = idd1;
}
void boss::show_id() {
	cout << "职工编号\t" << this->id
		<< "职工姓名\t" << this->name
		<< "职工岗位\t" << this->idd
		<< "岗位职责：管理公司" << endl;
}
string boss::getname() {
	return string("boss");
}
void boss::showidd() {
	cout << "部门为" << this->idd;
}
