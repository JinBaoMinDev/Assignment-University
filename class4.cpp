#include <bits/stdc++.h>
using namespace std;

class tugiac
{
public:
    void output()
    {
        cout << endl << "La hinh co 4 canh";
    }
};

class hinhthang : public tugiac
{
public:
    void output()
    {
        tugiac::output();
        cout  << endl << "Co 1 cap canh doi dien song song";
    }
};

class hinhbinhhanh : public tugiac
{
public:
    void output()
    {
        tugiac::output();
        cout  << endl << "Co 2 cap canh doi dien song song";
    }
};

class hinhchunhat : public hinhbinhhanh
{
public:
    void output()
    {
        hinhbinhhanh::output();
        cout  << endl << "Co 1 goc vuong";
    }
};

class hinhthoi : public hinhbinhhanh
{
public:
    void output()
    {
        hinhbinhhanh::output();
        cout  << endl << "Co 2 duong cheo vuong goc";
    }
};

class hinhvuong : public hinhthoi, public hinhchunhat
{
public:
    void output()
    {
        hinhthoi::output();
        hinhchunhat::output();
        cout  << endl << "Co 4 canh bang nhau";
    }
};

int main()
{
    cout << "Tu giac co nhung tinh chat: ";
    tugiac a;
    a.output();
    cout << "\n\nHinh thang co nhung tinh chat: ";
    hinhthang b;
    b.output();
    cout << "\n\nHinh binh hanh co nhung tinh chat: ";
    hinhbinhhanh c;
    c.output();
    cout << "\n\nHinh chu nhat co nhung tinh chat: ";
    hinhchunhat d;
    d.output();
    cout << "\n\nHinh thoi co nhung tinh chat: ";
    hinhthoi e;
    e.output();
    cout << "\n\nHinh vuong co nhung tinh chat: ";
    hinhvuong f;
    f.output();
    return 0;
}
