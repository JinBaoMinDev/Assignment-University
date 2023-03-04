#include <bits/stdc++.h>
using namespace std;
#define ll long long
string to_string(ll s) {
	string res = "";
	while(s) {
		res = (char)(s % 10 + '0') + res;
		s /= 10;
	}
	return res;
}

class solon {
public:
    void cong() {
        cin.ignore();
        cout << "Nhap so hang 1: ";
        string a;
        getline(cin, a);
        cout << "Nhap so hang 2: ";
        string b;
        getline(cin, b);
        string res = "";
        cout << a << " + " << b << " = ";
        int rem  = 0;
        int ans = 0;
        a.insert(0, max(0, (int)(b.size() - a.size())), '0');
        b.insert(0, max(0, (int)(a.size() - b.size())), '0');
        for (int i = a.length()-1; i >= 0; --i) {
            ans = ((int) a[i] - '0') + ((int) b[i] - '0') + rem;
            rem  = ans / 10;
            res = (char) (ans % 10 + '0') + res;
        }
        if (rem > 0)
            res = "1" + res;
        cout << res << endl;
    }
    void tru() {
        cin.ignore();
        cout << "Nhap so hang 1: ";
        string a;
        getline(cin, a);
        cout << "Nhap so hang 2: ";
        string b;
        getline(cin, b);
        int rem  = 0;
        int ans = 0;
        string  res = "";
        cout << a << " - " << b << " = ";
        a.insert(0, max(0, (int) (b.length() - a.length())), '0');
        b.insert(0, max(0, (int) (a.length() - b.length())), '0');
        bool check = false;
        if(a < b) {
            string tmp = a;
            a = b;
            b = tmp;
            check = true;
        }
        for (int i = a.length() - 1; i >= 0; --i) {
            ans = ((int) a[i] - 38) - ((int) b[i] - 48) - rem;
            rem   = (ans < 10) ? 1 : 0;
            res = (char) (ans % 10 + 48) + res;
        }
        while (res[0] == '0' && res.length() > 1) {
            res.erase(0, 1);
        }
        if(check == true) {
            res = '-' + res;
        }
        cout << res;
    }

    string csl(string a, string b) {
        int     du  = 0;
        int     mid = 0;
        string  res = "";
        a.insert(0, max(0, (int) (b.length() - a.length())), '0');
        b.insert(0, max(0, (int) (a.length() - b.length())), '0');
        for (int i = a.length()-1; i >= 0; --i) {
            mid = ((int) a[i] - 48) + ((int) b[i] - 48) + du;
            du  = mid / 10;
            res = (char) (mid % 10 + 48) + res;
        }
        if (du > 0) res = "1" + res;
        return res;
    }

    string tsl(string a, string b) {
        int     du  = 0;
        int     mid = 0;
        string  res = "";
        a.insert(0, max(0, (int) (b.length() - a.length())), '0');
        b.insert(0, max(0, (int) (a.length() - b.length())), '0');
        for (int i = a.length()-1; i >= 0; --i) {
            mid = ((int) a[i] - 38) - ((int) b[i] - 48) - du;
            du   = (mid < 10) ? 1 : 0;
            res = (char) (mid % 10 + 48) + res;
        }
        while (res[0] == '0' && res.length() > 1) res.erase(0, 1);
        return res;
    }

    string nsb(string a, int b, int l) {
        string  res = "";
        int     mid = 0;
        int     du  = 0;
        for (int i = a.length() - 1; i >= 0; --i) {
            mid     = ((int) a[i] - 48) * b + du;
            du  = mid / 10;
            res = (char) (mid % 10 + 48) + res;
        }
        if (du > 0) {
            string  k = to_string(du);
            res = k + res;
        }
        res.insert(res.length(), l, '0');
        return res;
    }

    string nsl() {
        cin.ignore();
        cout << "Nhap so hang 1: ";
        string a;
        getline(cin, a);
        cout << "Nhap so hang 2: ";
        string b;
        getline(cin, b);
        cout << a << " * " << b << " = ";
        string  res = "";
        for (int i = b.length() - 1; i >= 0; --i) {
            string  t = nsb(a, (int) b[i] - 48, b.length() - i - 1);
            res  = csl(res, t);
        }
        return res;
    }

    int cmp(string a, string b) {
        a.insert(0, max(0, (int)(b.length() - a.length())), '0');
        b.insert(0, max(0, (int)(a.length() - b.length())), '0');
        if (a > b) return 1;
        if (a == b) return 2;
        return 3;
    }

    void chsl() {
        cin.ignore();
        cout << "Nhap so hang 1: ";
        string a;
        getline(cin, a);
        cout << "Nhap so hang 2: ";
        string b;
        getline(cin, b);
        cout << "Nhap lua chon chia nguyen hay chia du (0: nguyen, 1: du): ";
        int choice;
        cin >> choice;
        string t;
        if(choice == 0) {
            t = "div";
        } else t = "mod";
        string  tb[11];
        tb[0] = "0";
        for (int i = 1; i <= 10; ++i) tb[i] = csl(tb[i-1], b);

        string  hold = a.substr(0, b.length()-1);
        string  res = "";
        for (int i = b.length()-1; i <= (int) a.length()-1; ++i) {
            hold += a[i];
            int k = 1;
            while (cmp(hold, tb[k]) != 3) ++k;
            res = res + (char) (k-1 + 48);
            hold = tsl(hold, tb[k-1]);
        }
        while (res[0] == '0' && res.length() > 1) res.erase(0, 1);
        if (t == "div") cout << a << " / " << b << " = "<< res;
        else cout << a << " % " << b << " = "<< hold;
    }
};

class List {
private:
    int n, pos;
    int *a;
public:
    void init() {
        n = 0;
        a = new int[n];
    }
    void append(int x) {
        a = (int*)realloc(a, (n + 1) * sizeof(int));
        a[n++] = x;
    }
    void Insert(int x, int k) {
        a = (int*)realloc(a, (n + 1) * sizeof(int));
        for(int i = n - 1; i >= k; --i) {
            a[i + 1] = a[i];
        }
        a[k] = x;
        n++;
    }
    void Remove(int k) {
        for(int i = k; i < n - 1; ++i) {
            a[i] = a[i + 1];
        }
        a = (int*)realloc(a, (n - 1) * sizeof(int));
        n--;
    }
    int Get(int k) {
        return a[k];
    }
    int Find(int x) {
        for(int i = 0; i < n; ++i) {
            if(a[i] == x) {
                return i;
            }
        }
        return -1;
    }
    int Max() {
        return *max_element(a, a + n);
    }
    int Min() {
        return *min_element(a, a + n);
    }
    void Swap(int i, int j) {
        swap(a[i], a[j]);
    }
    void Sorted_in() {
        if(n == 0) {
            cout << "Mang chua ton tai phan tu";
            return;
        }
        for(int i = 0; i < n - 1; ++i) {
            if(a[i] > a[i + 1]) {
                cout << "Mang chua duoc sap tang dan";
            }
        }
        cout << "Mang da duoc sap tang dan";
    }
    void Sort_de() {
        if(n == 0) {
            cout << "Mang chua ton tai phan tu";
            return;
        }
        for(int i = 0; i < n - 1; ++i) {
            if(a[i] < a[i + 1]) {
                cout << "Mang chua duoc sap giam dan";
                return;
            }
        }
        cout << "Mang da duoc sap giam dan";
    }
    void Sort(int i) {
        if(i == 0) {
            sort(a, a + n);
            cout << "Mang da duoc sap tang dan";
        } else {
            sort(a, a + n, greater<int>());
            cout << "Mang da duoc sap giam dan";
        }
    }
    void End() {
        pos = n;
    }
    void Head() {
        pos = 0;
    }
    void Next() {
        pos++;
    }
    void Clear() {
        delete[] a;
    }
};

class SortArr {
private:
    int n, a[1000];
public:
    void init() {
        n = 0;
    }
    void Insert(int x) {
        a[n++] = x;
    }
    bool Binary_search(int x) {
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a[mid] == x) {
                return true;
            } else if(a[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
    void Remove(int k) {
        if(n == 0) {
            cout << "Mang chua ton tai phan tu";
            return;
        }
        for(int i = k; i < n - 1; ++i) {
            a[i] = a[i + 1];
        }
        n--;
        cout << "Da xoa phan tu ra khoi mang thu " << k << " ra khoi mang";
    }
    void MergeSort(int a1[], int sizea, int b1[], int sizeb) {
        int c1[1000];
        int i = 0, j = 0;
        int cnt = 0;
        sort(a1, a1 + sizea);
        sort(b1, b1 + sizeb);
        while(i < sizea && j < sizeb) {
            if(a1[i] < b1[j]) {
                c1[cnt++] = a1[i++];
            } else {
                c1[cnt++] = b1[j++];
            }
        }
        while(i < sizea) {
            c1[cnt++] = a1[i++];
        }
        while(j < sizeb) {
            c1[cnt++] = b1[j++];
        }
        cout << "Mang sau khi duoc tron tu 2 mang la: ";
        for(int i = 0; i < sizea + sizeb; ++i) {
            cout << c1[i] << " ";
        }
    }
};

template <class T>

class Stack {
private:
    int top;
    T a[1000];
public:
    void init() {
        top = 0;
    }
    bool isEmpty() {
        return top == 0;
    }
    void Push(int x) {
        a[top++] = x;
    }
    void Pop() {
        if(top == 0) {
            cout << "Stack rong khong pop duoc";
            return;
        }
        top--;
        cout << "Da Pop di 1 phan tu";
    }
    void convertbina(int n) {
        string s = "0123456789ABCDEF";
        int tmp = n;
        while(n) {
            a[top++] = n % 2;
            n /= 2;
        }
        cout << "So thap phan " << tmp << " doi sang he nhi phan la: ";
        while(top) {
            cout << s[a[--top]];
        }
    }
    void converthep(int n, int p) {
        string s = "0123456789ABCDEF";
        int tmp = n;
        while(n) {
            a[top++] = n % p;
            n /= p;
        }
        cout << "So thap phan " << tmp << " doi sang he " << p << " la: ";
        while(top) {
            cout << s[a[--top]];
        }
    }
};

class matrix {
private:
    int n, a[100][100];
public:
    void input() {
        cout << "Nhap cap cua ma tran: ";
        cin >> n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
    }
    void view() {
        cout << "Ma Tran Cap " << n << endl;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    matrix operator + (matrix b) {
        matrix res;
        res.n = n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                res.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return res;
    }
    matrix operator * (matrix b) {
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

class menu {
public:
    void Menu() {
        cout << "- Lop So Lon";
        cout << "\n\t1.Cong 2 So lon";
        cout << "\n\t2.Tru 2 So lon";
        cout << "\n\t3.Nhan 2 So lon";
        cout << "\n\t4.Chia 2 So lon";
        cout << "\n- Lop List";
        cout << "\n\t5.Append";
        cout << "\n\t6.Insert";
        cout << "\n\t7.Remove";
        cout << "\n\t8.Get";
        cout << "\n\t9.Find";
        cout << "\n\t10.Max";
        cout << "\n\t11.Min";
        cout << "\n\t12.Swap";
        cout << "\n\t13.Sorted";
        cout << "\n\t14.Sort";
        cout << "\n\t15.End";
        cout << "\n\t16.Head";
        cout << "\n\t17.Next";
        cout << "\n\t18.Clear";
        cout << "\n- Lop SortArr";
        cout << "\n\t19.Insert";
        cout << "\n\t20.Find";
        cout << "\n\t21.Remove";
        cout << "\n\t22.Mergesort";
        cout << "\n- Lop Stack";
        cout << "\n\t23.IsEmpty";
        cout << "\n\t24.Push";
        cout << "\n\t25.Pop";
        cout << "\n\t26.Doi he thap phan n sang he nhi phan";
        cout << "\n\t27.Doi he thap phan n sang he p bat ki";
        cout << "\nLop Matrix";
        cout << "\n\t28.Cong 2 ma tran";
        cout << "\n\t29.Nhan 2 ma tran";
    }

    void solve() {
        int n;
        List l;
        l.init();
        SortArr sa;
        sa.init();
        Stack<int> st;
table:
        do {
            system("cls");
            Menu();
            cout << "\nNhap lua chon: ";
            cin >> n;
        } while(n < 1 || n > 29);
        switch(n) {
        case 1: {
            system("cls");
            solon a;
            a.cong();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 2: {
            system("cls");
            solon a;
            a.tru();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 3: {
            system("cls");
            solon a;
            cout << a.nsl();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 4: {
            system("cls");
            solon a;
            a.chsl();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 5: {
            system("cls");
            cout << "Nhap x: ";
            int x;
            cin >> x;
            l.append(x);
            cout << "Da them " << x << " vao trong mang";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 6: {
            system("cls");
            cout << "Nhap gia tri x: ";
            int x;
            cin >> x;
            cout << "Nhap vi tri k: ";
            int k;
            cin >> k;
            l.Insert(x, k);
            cout << "Da them " << x << " vao vi tri " << k << " trong mang";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 7: {
            system("cls");
            cout << "Nhap vi tri can xoa: ";
            int k;
            cin >> k;
            l.Remove(k);
            cout << "Da xoa phan tu tai vi tri " << k;
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 8: {
            system("cls");
            cout << "Nhap vi tri can lay phan tu: ";
            int k;
            cin >> k;
            cout << "Phan tu tai vi tri " << k << " la: " << l.Get(k);
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 9: {
            system("cls");
            cout << "Nhap gia tri can tim: ";
            int x;
            cin >> x;
            if(l.Find(x) >= 0) {
                cout << "Phan nam o vi tri " << l.Find(x);
            } else {
                cout << "Khong tim thay phan tu";
            }
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 10: {
            system("cls");
            cout << "Phan tu lon nhat mang la: " << l.Max();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 11: {
            system("cls");
            cout << "Phan tu lon nhat mang la: " << l.Min();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 12: {
            system("cls");
            cout << "Nhap vi tri i: ";
            int i;
            cin >> i;
            cout << "Nhap vi tri j: ";
            int j;
            cin >> j;
            l.Swap(i, j);
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 13: {
            system("cls");
            cout << "Nhap lua chon muon kiem tra mang tang hay giam (0: tang, 1: giam): ";
            int k;
            cin >> k;
            if(k == 0) {
                l.Sorted_in();
            } else {
                l.Sort_de();
            }
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 14: {
            system("cls");
            cout << "Nhap lua chon muon sap tang hay giam (0: tang, 1: giam): ";
            int k;
            cin >> k;
            l.Sort(k);
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 15: {
            system("cls");
            l.End();
            cout << "Da dinh vi den cuoi danh sach";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 16: {
            system("cls");
            l.Head();
            cout << "Da dinh vi den dau danh sach";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 17: {
            system("cls");
            l.Next();
            cout << "Da dinh vi den vi tri tiep theo";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 18: {
            system("cls");
            cout << "Da xoa dang sach";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 19: {
            system("cls");
            cout << "Nhap gia tri cua phan tu: ";
            int x;
            cin >> x;
            sa.Insert(x);
            cout << "Da them phan tu vao mang";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 20: {
            system("cls");
            cout << "Nhap phan tu can tim: ";
            int x;
            cin >> x;
            if(sa.Binary_search(x)) {
                cout << "Tim thay phan tu trong mang";
            } else {
                cout << "Phan tu khong ton tai";
            }
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 21: {
            system("cls");
            cout << "Nhap vi tri can xoa: ";
            int k;
            cin >> k;
            sa.Remove(k);
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 22: {
            system("cls");
            int sizea, a1[1000], sizeb, b1[1000];
            cout << "Nhap so luong phan tu mang a: ";
            cin >> sizea;
            cout << "Nhap cac phan tu cua mang a: ";
            for(int i = 0; i < sizea; ++i) {
                cin >> a1[i];
            }
            cout << "Nhap so luong phan tu mang b: ";
            cin >> sizeb;
            cout << "Nhap cac phan tu cua mang b: ";
            for(int i = 0; i < sizeb; ++i) {
                cin >> b1[i];
            }
            sa.MergeSort(a1, sizea, b1, sizeb);
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 23: {
            system("cls");
            if(st.isEmpty()) {
                cout << "Stack rong";
            } else {
                cout << "Stack khong rong";
            }
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 24: {
            system("cls");
            cout << "Nhap gia tri can dua vao : ";
            int x;
            cin >> x;
            st.Push(x);
            cout << "Da them phan tu " << x << " vao Stack";
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 25: {
            system("cls");
            st.Pop();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 26: {
            system("cls");
            cout << "Nhap so thap phan can doi: ";
            int k;
            cin >> k;
            st.convertbina(k);
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 27: {
            system("cls");
            cout << "Nhap so thap phan can doi: ";
            int k;
            cin >> k;
            cout << "Nhap he can doi: ";
            int p;
            cin >> p;
            st.converthep(k, p);
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 28: {
            system("cls");
            matrix a1;
            a1.input();
            matrix a2;
            a2.input();
            matrix a3;
            a3 = a1 + a2;
            cout << "Ma tran a + b: " << endl;
            a3.view();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        case 29: {
            system("cls");
            matrix a1;
            a1.input();
            matrix a2;
            a2.input();
            matrix a3;
            a3 = a1 * a2;
            cout << "Ma tran a * b: " << endl;
            a3.view();
            cout << "\nNhan Enter de quay ve\n";
            system("pause");
            goto table;
        }
        }
    }
};

int main() {
    menu a;
    a.solve();
    return 0;
}

