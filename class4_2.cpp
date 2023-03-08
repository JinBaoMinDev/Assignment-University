#include <bits/stdc++.h>
using namespace std;

class person
{
private:
    string name, date, gender, idnumber;
public:
    void in()
    {
        cout << "Nhap ten: "; getline(cin, name);
        cout << "Nhap ngay sinh: "; getline(cin, date);
        cout << "Nhap gioi tinh: "; getline(cin, gender);
        cout << "Nhap CMND: "; getline(cin, idnumber);
    }
    void out()
    {
        cout << "Nhap ten: " << name << endl;
        cout << "Nhap ngay sinh: " << date << endl;
        cout << "Nhap gioi tinh: " << gender << endl;
        cout << "Nhap CMND: " << idnumber << endl;
    }
};

class employee : public person
{
private:
    string Code_Id, datein, position;
    int Basic_Salary, Coefficient_Salary;
public:
    void in()
    {
        person::in();
        cout << "Nhap ma nhan vien: "; getline(cin, Code_Id);
        cout << "Nhap ngay vao co quan: "; getline(cin, datein);
        cout << "Nhap chuc vu: "; getline(cin, position);
        cout << "Nhap luong co ban: "; cin >> Basic_Salary;
        cout << "Nhap he so luong: "; cin >> Coefficient_Salary;
    }
    int subsidize()
    {
        if(position == "giam doc") return 2000000;
        else if(position == "truong phong") return 1000000;
        return 500000;
    }
    int income()
    {
        return Basic_Salary * Coefficient_Salary + subsidize();
    }
    void out()
    {
        person::out();
        cout << "Ma nhan vien: " << Code_Id << endl;
        cout << "Ngay vao co quan: " << datein << endl;
        cout << "Chuc vu: " << position << endl;
        cout << "Luong co ban: " << Basic_Salary << endl;
        cout << "He so luong: " << Coefficient_Salary << endl;
        cout << "Tro Cap: " << subsidize() << endl;
        cout << "Thu Nhap: " << income() << endl;
    }
};

int main()
{
    employee e;
    e.in();
    cout << endl;
    e.out();
    return 0;
}
