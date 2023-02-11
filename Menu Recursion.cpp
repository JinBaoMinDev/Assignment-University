#include "windows.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

#ifdef WIN32
void gotoxy(int x, int y) {
    COORD cur = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}
#else
void gotoxy(int x, int y) {
    printf("\033[%dG\033[%dd", x+1, y+1);
}
#endif

int textcolor(int Color) {
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h, Color);
}

#define CYAN 10
#define YELLOW 14

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

void Baitap0() {
    system("cls");
    int a, b;
    cout << "Tim UCLN cua 2 so a,b";
    cout << "\nNhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Uoc Chung lon nhat cua " << a << " va " << b << " la: " << gcd(a, b);
    getch();
}

void reverse_string(string &s, int i, int j) {
    if(i >= j) return;
    swap(s[i], s[j]);
    reverse_string(s, i + 1, j - 1);
}

void Baitap1() {
    system("cls");
    string s;
    cout << "Tim xau dao nguoc cua xau";
    cout << "\nNhap xau: ";
    getline(cin, s);
    reverse_string(s, 0, s.size() - 1);
    cout << "Xau sau khi dao nguoc la: " << s;
    getch();
}

int sum(int a[], int n) {
    if(n==0) return 0;
    else return a[n] + sum(a, n - 1);
}
void Baitap2() {
    system("cls");
    cout << "Tinh tong cac phan tu cua mang";
    int n, a[1000];
    cout << "\nNhap so luong phan tu: "; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
    cout << "Tong cac phan tu cua mang la = " << sum(a, n);
    getch();
}

int maxelement(int a[], int n, int ans)
{
    if(n == 1) return ans;
    ans = max(ans, a[n]);
    maxelement(a, n - 1, ans);
}

void Baitap3() {
    system("cls");
    cout << "Phan tu lon nhat cua mang";
    int n, a[1000];
    cout << "\nNhap so luong phan tu cua mang: "; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
    int ans = a[1];
    cout << "Phan tu lon nhat cua mang la = " << maxelement(a, n, ans);
    getch();
}

bool check_increase(int a[], int n)
{
    if(n == 1) return true;
    if(a[n] < a[n - 1]) return false;
    check_increase(a, n - 1);
}

void Baitap4() {
    system("cls");
    cout << "Kiem tra mang co tang dan hay khong?";
    int n, a[1000];
    cout << "\nNhap so luong phan tu cua mang: "; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
    if(check_increase(a, n)) {
        cout << "Mang tang duoc sap tang";
    }
    else {
        cout << "Mang chua khong duoc sap tang";
    }
    getch();
}

bool check_symmetry(int a[], int i, int j)
{
    if(i >= j) return true;
    if(a[i] != a[j]) return false;
    check_symmetry(a, i + 1, j - 1);
}

void Baitap5() {
    system("cls");
    cout << "Kiem tra mang co doi xung hay khong?";
    int n, a[1000];
    cout << "\nNhap so luong phan tu cua mang: "; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << "a[" << i << "] = "; cin >> a[i];
    }
    if(check_symmetry(a, 1, n)) {
        cout << "Mang doi xung";
    }
    else {
        cout << "Mang khong doi xung";
    }
    getch();
}
//Viet xau s ra man hinh tai toa do (x,y) voi mau la color
void Write(char *s,int x,int y, int color) {
    textcolor(color);
    gotoxy(x,y);
    cout<<s;
    textcolor(15);
}

void Khung(int x1,int y1,int x2,int y2) {
    int x,y;
    gotoxy(x1,y1);
    cout<<"É";
    gotoxy(x2,y1);
    cout<<"»";
    gotoxy(x1,y2);
    cout<<"È";
    gotoxy(x2,y2);
    cout<<"¼";
    for(x=x1+1; x<x2; x++) {
        gotoxy(x,y1);
        cout<<"Í";
        gotoxy(x,y2);
        cout<<"Í";
    }
    for(y=y1+1; y<y2; y++) {
        gotoxy(x1,y);
        cout<<"º";
        gotoxy(x2,y);
        cout<<"º";
    }
}
/*Tao ra menu tai toa do (x0,y0) voi n dong luu trong bien s
chon: dong menu hien thoi (khac mau voi cac dong khac) */
void Ve_menu(int x0,int y0,int chon,int n,char *s[]) {
    system("cls");
    Khung(x0-2,y0-1,x0+30,y0+n);
    for(int i=0; i<n; i++)
        if(i==chon) Write(s[i],x0,y0+i,CYAN);
        else Write(s[i],x0,y0+i,YELLOW);
    Write("Copyright (c) 2023 by Pham Anh Phuong.",x0-4,y0+n+5,10);
}

int main() {
    char ch,*st[20]; //Ghi cac dong menu
    system("cls");
    st[0]="Tinh UCLN";
    st[1]="Tim xau dao nguoc";
    st[2]="Tinh tong cac phan tu";
    st[3]="Tim gia tri lon nhat";
    st[4]="Kiem tra mang sap tang?";
    st[5]="Kiem tra mang doi xung?";
    st[6]="<ESC> Ket thuc chuong trinh!";
    int x0=5,y0=5,chon=0,luuchon,sodong=7,ok=FALSE;
    Ve_menu(x0,y0,chon,sodong,st);
    do {
        ch=getch(); //Nhan mot phim
        switch (ch) {
        case 72: //phim len
            luuchon=chon;
            chon--;
            if(chon<0) chon=sodong-1;
            Write(st[luuchon],x0,y0+luuchon,YELLOW);
            Write(st[chon],x0,y0+chon,CYAN);
            break;
        case 80://phim xuong
            luuchon=chon;
            chon++;
            if(chon==sodong) chon=0;
            Write(st[luuchon],x0,y0+luuchon,YELLOW);
            Write(st[chon],x0,y0+chon,CYAN);
            break;
        case 13: //phim ENTER
            ok=TRUE;
            break;
        }
        if (ok==TRUE) { //Neu phim ENTER duoc nhan
            switch (chon) {
            case 0:
                Baitap0();
                Ve_menu(x0,y0,chon,sodong,st);
                break;
            case 1:
                Baitap1();
                Ve_menu(x0,y0,chon,sodong,st);
                break;
            case 2:
                Baitap2();
                Ve_menu(x0,y0,chon,sodong,st);
                break;
            case 3:
                Baitap3();
                Ve_menu(x0,y0,chon,sodong,st);
                break;
            case 4:
                Baitap4();
                Ve_menu(x0,y0,chon,sodong,st);
                break;
            case 5:
                Baitap5();
                Ve_menu(x0,y0,chon,sodong,st);
                break;
            case 6:
                exit(0);
            }
            ok=FALSE; //tra lai trang thai ENTER chua duoc nhan
        }
    } while (ch!=27); //Nhan phim ESC de thoat khoi chuong trinh
}
