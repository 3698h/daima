#include <iostream>
#include <string>
using namespace std;
#define MAX 1000   //最大人数
//联系人结构体
struct Person
{
    string Name;
    string sex;
    int age;
    string phone;
    string address;
};
//通讯录结构体
struct txl
{
    Person personArray[MAX]; //通讯录中保存的联系人数组
    int m_Size;             //通讯录中当前人数
};
void add(txl *t);
void show(txl *t);
void del(txl *t);
void findperson(txl *t);
void modify(txl *t);
void clean(txl*t);
void showMenu()
{
    cout << "**************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "**************************" << endl;
}
void add(txl*t){
    if(t->m_Size==MAX){
        cout << "通讯录已满，无法添加" << endl;
        return;
    }else{
       //姓名
       string name;
       cout << "请输入姓名：" << endl;
       cin >> name;
       t->personArray[t->m_Size].Name = name;
       //性别
       string sex;
       cout << "请输入性别：" << endl;
       while (true)
       {
           cin >> sex;
           if (sex == "男" || sex == "女")
           {
               t->personArray[t->m_Size].sex = sex;
               break;
           }
           else
           {
               cout << "输入有误，请重新输入" << endl;
           }
       } // 这里添加了缺失的右花括号
       // 年龄
       int age;
       cout << "请输入年龄：" << endl;
       cin >> age;
       t->personArray[t->m_Size].age = age;
       // 电话
       string phone;
       cout << "请输入电话：" << endl;
       cin >> phone;
       t->personArray[t->m_Size].phone = phone;
       // 地址
       string address;
       cout << "请输入地址：" << endl;
       cin >> address;
       t->personArray[t->m_Size].address = address;
       t->m_Size++;
       cout << "添加成功" << endl;
       system("pause");
       system("cls");
     }
}
void show(txl*t){
    if (t->m_Size==0)
    {
        cout << "当前通讯录为空" << endl;
    }else
        for (int i = 0; i < t->m_Size; i++)
        {
            cout << "姓名：" << t->personArray[i].Name << "\t";
            cout << "性别：" << t->personArray[i].sex<< "\t";
            cout << "年龄：" << t->personArray[i].age<< "\t";
            cout << "电话：" << t->personArray[i].phone<< "\t";
            cout << "地址：" << t->personArray[i].address<< endl;
        }
    system("pause");
    system("cls");
    }
    // 判断是否存在查询的人员，存在返回在数组中索引位置，不存在返回-1
    int isExist(txl* abs, string name)
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            if (abs->personArray[i].Name == name)
            {
                return i;
            }
        }
        return -1;
    }
    // 3、删除指定联系人信息
    void del(txl*t)
    {
        cout << "请输入您要删除的联系人" << endl;
        string name;
        cin >> name;

        int ret = isExist(t, name);
        if (ret != -1)
        {
            for (int i = ret; i < t->m_Size; i++)
            {
                t->personArray[i] = t->personArray[i + 1];
            }
            t->m_Size--;
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "查无此人" << endl;
        }

        system("pause");
        system("cls");
    }
    // 4、查找指定联系人信息
    void findperson(txl *t)
    {
        cout << "请输入您要查找的联系人" << endl;
        string name;
        cin >> name;

        int ret = isExist(t, name);
        if (ret != -1)
        {
            cout << "姓名：" << t->personArray[ret].Name << "\t";
            cout << "性别：" << t->personArray[ret].sex << "\t";
            cout << "年龄：" << t->personArray[ret].age<< "\t";
            cout << "电话：" << t->personArray[ret].phone << "\t";
            cout << "住址：" << t->personArray[ret].address << endl;
        }
        else
        {
            cout << "查无此人" << endl;
        }

        system("pause");
        system("cls");
    }
    // 5、修改指定联系人信息
    void modify(txl *t)
    {
        cout << "请输入您要修改的联系人" << endl;
        string name;
        cin >> name;

        int ret = isExist(t, name);
        if (ret != -1)
        {
            // 姓名
            string name;
            cout << "请输入姓名：" << endl;
            cin >> name;
            t->personArray[ret].Name = name;

            cout << "请输入性别：" << endl;
            cout << "男/女" << endl;

            // 性别
            string  sex;
            while (true)
            {
                cin >> sex;
                if (sex == "男" || sex == "女")
                {
                    t->personArray[ret].sex = sex;
                    break;
                }
                cout << "输入有误，请重新输入";
            }

            // 年龄
            cout << "请输入年龄：" << endl;
            int age = 0;
            cin >> age;
            t->personArray[ret].age = age;

            // 联系电话
            cout << "请输入联系电话：" << endl;
            string phone = "";
            cin >> phone;
            t->personArray[ret].phone = phone;

            // 家庭住址
            cout << "请输入家庭住址：" << endl;
            string address;
            cin >> address;
            t->personArray[ret].address = address;

            cout << "修改成功" << endl;
        }
        else
        {
            cout << "查无此人" << endl;
        }

        system("pause");
        system("cls");
    }
    // 6、清空所有联系人
    void clean(txl *t)
    {
        t->m_Size = 0;
        cout << "通讯录已清空" << endl;
        system("pause");
        system("cls");
    }

int main()
{
    txl t;
    t.m_Size = 0; //初始化通讯录人数
    int choice = 0;
    while(true){
    showMenu();
    cin >> choice;
    switch (choice)
    {
    case 1:
        add(&t);
        break;
    case 2:
        show(&t);
        break;
    case 3:
        del(&t);
        break;      
    case 4:
        findperson(&t);
        break;
    case 5:
        modify(&t);
         break;
    case 6:
        clean(&t);
        break;
    case 0:
        cout << "欢迎下次使用" << endl;
        system("pause");
        return 0;
        break;
    }
}
    system("pause");
    return 0;

}