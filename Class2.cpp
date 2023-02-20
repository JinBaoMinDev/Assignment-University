#include <bits/stdc++.h>
using namespace std;

class tohop
{
private:
    int n, k;
public:
    tohop(int n, int k)
    {
        this->n = n;
        this->k = k;
    }
    void factorial()
    {
        int f[n + 1];
        f[0] = 1;
        for(int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }
        cout << "Hoan vi " << n << " = " << f[n];
    }
    void chinhhopkhonglapchapkcuan()
    {
        int f[n + 1];
        f[0] = 1;
        for(int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }
        cout << "Chinh hop khong lap chap " << k << " cua "<< n << " = " << f[n] / f[n - k];
    }
    void chinhhopchapkcuan()
    {
        long long res = 1;
        int tmpn = n;
        int tmpk = k;
        while(tmpk) {
            if(tmpk % 2 != 0) {
                res *= tmpn;
            }
            tmpn *= tmpn;
            tmpk /= 2;
        }
        cout << "Chinh hop lap chap " << k << " cua " <<  n << " = " << res;
    }
    void tohopchapkcuan()
    {
        int f[n + 1];
        f[0] = 1;
        for(int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }
        cout << "To hop " << k << " cua " << n << " = " << (f[n] / (f[k] * f[n- k]));
    }
};

class Vector
{
private:
    int x, y;
public:
    Vector(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void tichvohuong(Vector a)
    {
        long long ans = this->x * a.x + this->y * a.y;
        cout << "Tich vo huong 2 vector la = " << ans;
    }
    void kiemtra2vectorsongsong(Vector a)
    {
        if(fabs((double)this->x / a.x) == fabs((double)this->y / a.y)) {
            cout << "Hai Vector Song Song";
        }
        else {
            cout << "Hai Vector Khong Song Song";
        }
    }
    void kiemtra2vectorvuonggoc(Vector a)
    {
        double ans = this->x * a.x + this->y * a.y;
        if(ans == 0) {
            cout << "Hai Vector Vuong Goc";
        }
        else {
            cout << "Hai Vector Khong Vuong Goc";
        }
    }
};

class dathuc
{
private:
    int n, a[10000];
public:
    void convert(dathuc b)
    {
        this->n = b.n;
        for(int i = 0; i < n; ++i) {
            a[i] = b.a[i];
        }
    }
    void nhapdathuc()
    {
        cout << "Nhap bac cua da thuc = "; cin >> n;
        cout << "Nhap he so cua moi bac: ";
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    }
    void giatri()
    {
        cout << "Nhap gia tri x: ";
        int x; cin >> x;
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            cnt += pow(x, i) * a[i - 1];
        }
        cout << "Gia tri cua da thuc la: " << cnt;
    }
    dathuc operator + (dathuc b)
    {
        dathuc ans;
        int max_level = max(n, b.n);
        ans.n = max_level;
        for(int i = 0; i < max_level; ++i) {
            ans.a[i] = a[i] + b.a[i];
        }
        return ans;
    }
    void cong2dathuc()
    {
        dathuc k, l;
        k.nhapdathuc();
        l.nhapdathuc();
        dathuc ans = k + l;
        cout << "Bieu thuc sau khi cong da thuc la: ";
        for(int i = 1; i <= ans.n; ++i) {
            if(i != ans.n) {
                cout << ans.a[i - 1] << "x^" << i << " + ";
            }
            else {
                cout << ans.a[i - 1] << "x^" << i;
            }
        }
    }
};

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

class phanso
{
private:
    int tu, mau;
public:
    phanso()
    {
        this->tu = 0;
        this->mau = 0;
    }
    phanso(int tu, int mau)
    {
        this->tu = tu;
        this->mau = mau;
    }
    friend phanso operator + (phanso a, phanso b)
    {
        phanso ans;
        ans.tu = a.tu * b.mau + b.tu * a.mau;
        ans.mau = a.mau * b.mau;
        int gcdans = gcd(ans.tu, ans.mau);
        ans.tu /= gcdans;
        ans.mau /= gcdans;
        if(ans.mau < 0) {
            ans.mau *= -1;
            ans.tu *= -1;
        }
        return ans;
    }
    friend phanso operator - (phanso a, phanso b)
    {
        phanso ans;
        ans.tu = a.tu * b.mau - b.tu * a.mau;
        ans.mau = a.mau * b.mau;
        int gcdans = gcd(ans.tu, ans.mau);
        ans.tu /= gcdans;
        ans.mau /= gcdans;
        if(ans.mau < 0) {
            ans.mau *= -1;
            ans.tu *= -1;
        }
        return ans;
    }
    friend phanso operator * (phanso a,phanso b)
    {
        phanso ans;
        ans.tu = a.tu * b.tu;
        ans.mau = a.mau * b.mau;
        int gcdans = gcd(ans.tu, ans.mau);
        ans.tu /= gcdans;
        ans.mau /= gcdans;
        if(ans.mau < 0) {
            ans.mau *= -1;
            ans.tu *= -1;
        }
        return ans;
    }
    friend phanso operator / (phanso a, phanso b)
    {
        phanso ans;
        ans.tu = b.mau;
        ans.mau = b.tu;
        int gcdans = gcd(ans.tu, ans.mau);
        ans.tu /= gcdans;
        ans.mau /= gcdans;
        if(ans.mau < 0) {
            ans.mau *= -1;
            ans.tu *= -1;
        }
        return a * ans;
    }
    void toigian()
    {
        int gcda = gcd(tu, mau);
        tu /= gcda;
        mau /= gcda;
        if(mau < 0) {
            mau *= -1;
            tu *= -1;
        }
    }
    int getter_tu()
    {
        return tu;
    }
    int getter_mau()
    {
        return mau;
    }
};

class matrix
{
private:
    int n, a[100][100];
public:
    void convert(matrix b)
    {
        this->n = b.n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                a[i][j] = b.a[i][j];
            }
        }
    }
    void input()
    {
        cout << "Nhap cap cua ma tran: "; cin >> n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
    }
    void view()
    {
        cout << "Ma Tran Cap " << n << endl;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    matrix operator + (matrix b)
    {
        matrix res;
        res.n = n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                res.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return res;
    }
    matrix operator * (matrix b)
    {
        matrix res;
        res.n = n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                res.a[i][j] = 0;
                for(int k = 0; k < n; ++k) {
                    res.a[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }
        return res;
    }
};

class menu
{
public:
    void Menu()
    {
        cout << "- Lop To Hop";
        cout << "\n\t1.Hoan vi N";
        cout << "\n\t2.Chinh Hop Khong Lap Chap K Cua N";
        cout << "\n\t3.Chinh Hop Chap K Cua N";
        cout << "\n\t4.To Hop Chap K Cua N";
        cout << "\n- Lop Vector";
        cout << "\n\t5.Tich Vo Huong 2 Vector";
        cout << "\n\t6.Kiem Tra 2 Vector Song Song";
        cout << "\n\t7.Kiem Tra 2 Vector Vuong Goc";
        cout << "\n- Lop Da Thuc";
        cout << "\n\t8.Nhap Da Thuc";
        cout << "\n\t9.Tinh Gia Tri Da Thuc";
        cout << "\n\t10.Cong 2 Da Thuc";
        cout << "\n- Lop Phan So";
        cout << "\n\t11.Cong 2 Phan So";
        cout << "\n\t12.Tru 2 Phan So";
        cout << "\n\t13.Nhan 2 Phan So";
        cout << "\n\t14.Chia 2 Phan So";
        cout << "\n\t15.Toi Gian Phan So";
        cout << "\n- Lop MaTrix";
        cout << "\n\t16.Nhap Ma Tran";
        cout << "\n\t17.In Ma Tran";
        cout << "\n\t18.Cong 2 Ma Tran A B";
        cout << "\n\t19.Nhan 2 Ma Tran A B";
    }

    void solve()
    {
        int n;
        matrix matran;
        dathuc bieuthuc;
table:
        do {
            system("cls");
            Menu();
            cout << "\nNhap lua chon: "; cin >> n;
        } while(n < 1 || n > 19);
        switch(n)
        {
            case 1: {
                system("cls");
                int t;
                cout << "Nhap n: "; cin >> t;
                tohop a(t, 0);
                a.factorial();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 2: {
                system("cls");
                int t, k;
                cout << "Nhap k: "; cin >> k;
                cout << "Nhap n: "; cin >> t;
                tohop a(t, k);
                a.chinhhopkhonglapchapkcuan();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 3: {
                system("cls");
                int t, k;
                cout << "Nhap k: "; cin >> k;
                cout << "Nhap n: "; cin >> t;
                tohop a(t, k);
                a.chinhhopchapkcuan();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 4: {
                system("cls");
                int t, k;
                cout << "Nhap k: "; cin >> k;
                cout << "Nhap n: "; cin >> t;
                tohop a(t, k);
                a.tohopchapkcuan();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 5: {
                system("cls");
                int xa, xb, ya, yb;
                cout << "Nhap x cua vector A: "; cin >> xa;
                cout << "Nhap y cua vector A: "; cin >> ya;
                cout << "Nhap x cua vector B: "; cin >> xb;
                cout << "Nhap y cua vector B: "; cin >> yb;
                Vector a(xa, ya), b(xb, yb);
                a.tichvohuong(b);
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 6: {
                system("cls");
                int xa, xb, ya, yb;
                cout << "Nhap x cua vector A: "; cin >> xa;
                cout << "Nhap y cua vector A: "; cin >> ya;
                cout << "Nhap x cua vector B: "; cin >> xb;
                cout << "Nhap y cua vector B: "; cin >> yb;
                Vector a(xa, ya), b(xb, yb);
                a.kiemtra2vectorsongsong(b);
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 7: {
                system("cls");
                int xa, xb, ya, yb;
                cout << "Nhap x cua vector A: "; cin >> xa;
                cout << "Nhap y cua vector A: "; cin >> ya;
                cout << "Nhap x cua vector B: "; cin >> xb;
                cout << "Nhap y cua vector B: "; cin >> yb;
                Vector a(xa, ya), b(xb, yb);
                a.kiemtra2vectorvuonggoc(b);
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 8: {
                system("cls");
                dathuc a;
                a.nhapdathuc();
                bieuthuc.convert(a);
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 9: {
                system("cls");
                bieuthuc.giatri();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 10: {
                system("cls");
                dathuc a;
                a.cong2dathuc();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 11: {
                system("cls");
                int xa, ya, xb, yb;
                cout << "Nhap tu so cua phan so A: "; cin >> xa;
                cout << "Nhap mau so cua phan so A: "; cin >> ya;
                cout << "Nhap tu so cua phan so B: "; cin >> xb;
                cout << "Nhap mau so cua phan so B: "; cin >> yb;
                phanso a(xa, ya), b(xb, yb);
                phanso ans = a + b;
                cout << "Phan so A + B = " << ans.getter_tu() << "/" << ans.getter_mau();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 12: {
                system("cls");
                int xa, ya, xb, yb;
                cout << "Nhap tu so cua phan so A: "; cin >> xa;
                cout << "Nhap mau so cua phan so A: "; cin >> ya;
                cout << "Nhap tu so cua phan so B: "; cin >> xb;
                cout << "Nhap mau so cua phan so B: "; cin >> yb;
                phanso a(xa, ya), b(xb, yb);
                phanso ans = a - b;
                cout << "Phan so A - B = " << ans.getter_tu() << "/" << ans.getter_mau();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 13: {
                system("cls");
                int xa, ya, xb, yb;
                cout << "Nhap tu so cua phan so A: "; cin >> xa;
                cout << "Nhap mau so cua phan so A: "; cin >> ya;
                cout << "Nhap tu so cua phan so B: "; cin >> xb;
                cout << "Nhap mau so cua phan so B: "; cin >> yb;
                phanso a(xa, ya), b(xb, yb);
                phanso ans = a * b;
                cout << "Phan so A * B = " << ans.getter_tu() << "/" << ans.getter_mau();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 14: {
                system("cls");
                int xa, ya, xb, yb;
                cout << "Nhap tu so cua phan so A: "; cin >> xa;
                cout << "Nhap mau so cua phan so A: "; cin >> ya;
                cout << "Nhap tu so cua phan so B: "; cin >> xb;
                cout << "Nhap mau so cua phan so B: "; cin >> yb;
                phanso a(xa, ya), b(xb, yb);
                phanso ans = a / b;
                cout << "Phan so A / B = " << ans.getter_tu() << "/" << ans.getter_mau();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 15: {
                system("cls");
                int xa, ya;
                cout << "Nhap tu so cua phan so: "; cin >> xa;
                cout << "Nhap mau so cua phan so: "; cin >> ya;
                phanso a(xa, ya);
                a.toigian();
                cout << "Phan so sau khi toi gian la: " << a.getter_tu() << "/" << a.getter_mau();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 16: {
                system("cls");
                matrix a;
                a.input();
                matran.convert(a);
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 17: {
                system("cls");
                matran.view();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 18: {
                system("cls");
                matrix a1, a2;
                cout << "Nhap ma tran 1: \n";
                a1.input();
                cout << "Nhap ma tran 2: \n";
                a2.input();
                matrix ans = a1 + a2;
                cout << "Ket Qua Cong 2 Ma Tran: \n";
                ans.view();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
            case 19: {
                system("cls");
                matrix a1, a2;
                cout << "Nhap ma tran 1: \n";
                a1.input();
                cout << "Nhap ma tran 2: \n";
                a2.input();
                matrix ans = a1 * a2;
                cout << "Ket Qua Nhan 2 Ma Tran: \n";
                ans.view();
                cout << "\nNhan Enter de quay ve\n";
                system("pause");
                goto table;
            }
        }
    }
};

int main()
{
    menu a;
    a.solve();
    return 0;
}
