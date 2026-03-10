#include <iostream>
#include "WorkerManager.h"
using namespace std;

int main() {
    // 创建管理对象
    workermanager wm;

    int choice = 0;

    while (true) {
        
        wm.show_menue();
        cin >> choice;

        switch (choice) {
        case 1:  // 添加
            wm.addworker();
            break;

        case 2:  // 显示
             wm.showworkers();
             break;

        case 3:  // 删除
            wm.deleteworker();
            break;

        case 4:  // 修改
           wm.modifyworker();
            break;

        //case 5:  // 查找
        //    wm.findworker();
        //    break;

        //case 6:  // 排序
        //    wm.sortworkers();
        //    break;

        //case 7:  // 清空
        //    wm.clearfile();
        //    break;

        case 0:  // 退出
            wm.exitsystem();

        default:
            cout << "输入有误，请重新输入！" << endl;
            break;
        }

        // 暂停，按任意键继续
        system("pause");    // Windows下用
        system("cls");      // 清屏
        // system("clear");  // Linux/Mac用
    }

    return 0;
}