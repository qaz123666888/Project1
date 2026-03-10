#include"WorkerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
workermanager::workermanager() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    //1.文件不存在
    if (!ifs.is_open() ){
        cout << "文件不存在" << endl;
        this->fileisempty = true;
        this->array = nullptr;
        this->endcount = 0;
        ifs.close();
        return;
    }
    //2.文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空" << endl;
        this->fileisempty = true;
        this->array = nullptr;
        this->endcount = 0;
        ifs.close();
        return;
    }
    //3.文件存在且有数据，统计人数
    int total = gettotal();
    cout << "员工人数为" << total << endl;
    this->endcount = total;
    this->array = new worker*[this->endcount];
    this->fileisempty= false;
    this->init_emp();
}


void workermanager::show_menue() { // 显示菜单
    cout << "*************************" << endl;
    cout << "**** 职工管理系统 ****" << endl;
    cout << "*** 1. 添加职工 ****" << endl;
    cout << "*** 2. 显示职工 ****" << endl;
    cout << "*** 3. 删除职工 ****" << endl;
    cout << "*** 4. 修改职工 ****" << endl;
    cout << "*** 5. 查找职工 ****" << endl;
    cout << "*** 6. 排序职工 ****" << endl;
    cout << "*** 7. 清空文件 ****" << endl;
    cout << "*** 0. 退出系统 ****" << endl;
    cout << "*************************" << endl;
    cout << "请输入选择：";
}

void  workermanager::exitsystem() {
    cout << "欢迎下次使用" << endl;
    exit(0);
}


void  workermanager::addworker() {
    cout << "请输入添加员工数量" << endl;
    int count = 0;
    cin >> count;
    if (count > 0)
    {
        //拷贝数据到新空间
        int newsize = count + this->endcount;
        if (newsize <= 0) {
            cout << "大小无效" << endl;
            return;
        }

        worker** newspace = new worker * [newsize];
        for (int i = 0; i < newsize; ++i) newspace[i] = nullptr;
        if (this->array != nullptr) {
            for (int i = 0; i < endcount; ++i) newspace[i] = this->array[i];
        }

        for (int i = 0; i < count; i++)
        {
            int id;
            string name;
            int idd;
            cout << "请输入第" << i + 1 << "个新员工的编号" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个新员工的姓名" << endl;
            cin >> name;
            cout << "请输入第" << i + 1 << "个新员工的部门" << endl;
            cout << "1.empolyee" << endl;
            cout << "2.manager" << endl;
            cout << "3.boss" << endl;
            cin >> idd;
            worker* pWorker = nullptr;              // 重命名，避免与类型名冲突
            switch (idd)
            {
            case 1:
                pWorker = new employee(id, name, idd);
                break;
            case 2:
                pWorker = new manager(id, name, idd);
                break;
            case 3:
                pWorker = new boss(id, name, idd);
                break;
            default:
                continue;
            }
            newspace[this->endcount + i] = pWorker; // 原来的第77行
        }

        // 用临时保存旧指针，先指向新空间再释放旧空间，避免工具误报或在释放后使用指针
        worker** oldArray = this->array;
        this->array = newspace;   // 将新空间赋给成员（必须）
        if (oldArray != nullptr) {
            delete[] oldArray;    // 原来的第80行
        }

        //更新人数
        this->endcount = newsize;
        //添加成功
        cout << "添加成功了" << count << "名新员工" << endl;
        this->save();
    }


    else
    {
        cout << "输入错误" << endl;
    }
    system("pause");
    system("cls");
}
void workermanager::save() {
    // 打开文件
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    if (!ofs.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }

    // 保存数据
    for (int i = 0; i < this->endcount; i++) {
        if (this->array[i] != NULL) {  // 只处理非空指针
            ofs << this->array[i]->id << " "
                << this->array[i]->name << " "
                << this->array[i]->idd<< endl;
        }
        // 空指针不保存
    }

    ofs.close();
}

//统计人数
int workermanager::gettotal() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int idd;
    int total = 0;
    while (ifs >> id && ifs >> name && ifs >> idd)
    {
        total++;
    }
    return total;
}


//初始化员工
void workermanager::init_emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int idd;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> idd)
    {
        worker* workera = nullptr;
        if (idd == 1)
        {
            workera = new employee(id, name, idd);
        }
        if (idd == 2)
        {
            workera = new manager(id, name, idd);
        }
        if (idd == 3)
        {
            workera = new boss(id, name, idd);
        }
        this->array[index] = workera;
        index++;   
    }

    ifs.close();
}


//显示员工
void workermanager::showworkers() {
    if (this->fileisempty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        for (int i = 0; i < this->endcount; i++)
        {
            this->array[i]->show_id();
        }
        system("pause");
        system("cls");
    }
}


//判断员工是否存在
int workermanager::isexit(int id, string name) {
    for (int i = 0; i < this->endcount; i++)
    {
        if (this->array[i]->id == id && this->array[i]->name == name)
        {
            return i;
        }
    }
    return -1;
}

//删除员工
void workermanager::deleteworker() {
    int id;
    string name;
    cout << "输入删除员工的编号" << endl;
    cin >> id;
    cout << "输入删除员工的姓名" << endl;
    cin >> name;
    int index = isexit(id, name);
    if (index!=-1)
    {
        for (int i = index; i < this->endcount-1; i++)
        {
            this->array[i] = this->array[i + 1];
        }
        this->endcount--;
        this->save();
        cout << "delete is ok" << endl;
    }
    else
    {
        cout<<"error" << endl;
    }
    system("pause");
    system("cls");
}


//修改员工信息
void workermanager::modifyworker() {
    if (this->fileisempty) {
        cout<<"error" << endl;
    }
    else {
        int id;
        string name;
        cout << "输入更改员工的编号" << endl;
        cin >> id;
        cout << "输入更改员工的姓名" << endl;
        cin >> name;
        int index = isexit(id, name);
        if (index != -1)
        {
            int select;
            delete this->array[index];
            int newid = 0;
            string newname = "";
            cout << "输入新员工的编号" << endl;
            cin >> newid;
            cout << "输入新员工的姓名" << endl;
            cin >> newname;
            cout << "新职位" << endl;
            cout << "1.empolyee" << endl;
            cout << "2.manager" << endl;
            cout << "3.boss" << endl;
            cin >> select;
            worker* workerc = nullptr;
            switch (select)
            {
            case 1:
                workerc = new employee(newid, newname, select);
                break;
            case 2:
                workerc = new manager(newid, newname, select);
                break;
            case 3:
                workerc = new boss(newid, newname, select);
                break;
            default:
                cout << "error" << endl;
                return;
            }
            this->array[index] = workerc;
            this->save();
            cout << "modify is ok" << endl;
        }
        else
        {
            cout << "error" << endl;
        }
        system("pause");
        system("cls");
    }

}


workermanager::~workermanager() {
    if (this->array != NULL) {
        // 1. 先释放每个员工对象
        for (int i = 0; i < this->endcount; i++) {
            if (this->array[i] != NULL) {
                delete this->array[i];  // ✅ 释放对象
            }
        }
        // 2. 再释放指针数组
        delete[] this->array;
        this->array =nullptr;
    }
    this->endcount = 0;
}




