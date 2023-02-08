#include <bits/stdc++.h>
using namespace std;

struct type {
    int first, second;
};

class giaiphuongtrinh {
public:
    void phuongtrinhbacnhat(int a, int b) {
        if(a == 0) {
            if(b == 0) {
                cout << "Phuong trinh co vo so nghiem";
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            cout << "Nghiem cua phuong trinh la: " << -(double)b / a;
        }
    }

    void phuongtrinhbachai(int a, int b, int c) {
        if(a == 0) {
            phuongtrinhbacnhat(b, c);
        } else {
            double delta = pow(b, 2) - 4 * a * c;
            if(delta > 0) {
                double x1 = (double)(- (double)b + sqrt(delta)) / (2 * a);
                double x2 = (double)(- (double)b - sqrt(delta)) / (2 * a);
                cout << "Phuong trinh co 2 nghiem: " << x1 << " " << x2 ;
            } else if(delta == 0) {
                cout << "Phuong trinh co nghiem kep: " << -(double)b / (2 * a);
            } else {
                cout << "Phuong trinh vo nghiem";
            }
        }
    }

    void phuongtrinhbacba(int a, int b, int c, int d) {
        if(a == 0) {
            phuongtrinhbachai(b, c, d);
        } else {
            double delta = (double)pow(b, 2) - (3 * a * c);
            double k = (double)(9 * a * b * c - 2 * pow(b, 3) - 27 * pow(a, 2) * d) / (2 * sqrt(abs(pow(delta, 3))));
            if(delta > 0) {
                if(abs(k) <= 1) {
                    double x1 = (2 * sqrt(delta) * cos((acos(k) / 3)) - b)/ (3 * a);
                    double x2 = (2 * sqrt(delta) * cos((acos(k) / 3 - (2 * M_PI / 3))) - b) / (3 * a);
                    double x3 = (2 * sqrt(delta) * cos((acos(k) / 3 + (2 * M_PI / 3))) - b)/(3 * a);
                    cout << "Phuong trinh co 3 nghiem la: " << x1 << " " << x2 << " " << x3;
                } else {
                    double x1 = ((sqrt(delta) * abs(k)) / (3 * a * k)) * (pow(abs(k) + sqrt(pow(k, 2) - 1),1.0 / 3) + pow(abs(k) - sqrt(pow(k, 2) - 1),1.0 / 3)) - (b / (3 * a));
                    cout << "Phuong trinh co nghiem duy nhat la: " << x1;
                }
            } else if(delta == 0) {
                double x1 = (-b + pow(pow(b, 3) - 27 * pow(a, 2) * d,1.0 / 3)) / (3 * a);
                cout << "Phuong trinh co nghiem boi la: " << x1;
            } else {
                double x1 = (sqrt(abs(delta)) / (3 * a)) * (pow(k + sqrt(pow(k, 2) + 1),1.0 / 3) + pow(k - sqrt(pow(k, 2) + 1),1.0 / 3)) - (b / (3 * a));
                cout << "Phuong trinh co nghiem duy nhat la: " << x1;
            }
        }
    }

    void phuongtrinhtrungphuong(int a, int b, int c) {
        if(a == 0) {
            phuongtrinhbachai(b, 0, c);
        } else {
            double delta = pow(b, 2) - 4 * a * c;
            if(delta > 0) {
                double x1 = (double)(-(double)b + sqrt(delta)) / 2 * a;
                double x2 = (double)(-(double)b + sqrt(delta)) / 2 * a;
                vector<double> v;
                if(x1 > 0) {
                    v.push_back(sqrt(x1));
                    v.push_back(-sqrt(x1));
                } else if(x1 == 0) {
                    v.push_back(0);
                }
                if(x2 > 0) {
                    v.push_back(sqrt(x2));
                    v.push_back(-sqrt(x2));
                } else if(x2 == 0) {
                    v.push_back(0);
                }
                cout << v.size();
                if(v.size()) {
                    cout << "Phuong trinh co " << v.size() << " nghiem la: ";
                    for(vector<double>::iterator it = v.begin(); it != v.end(); ++it) {
                        cout << *it << " ";
                    }
                } else {
                    cout << "Phuong trinh vo nghiem" << endl;
                }
            } else if(delta == 0) {
                double x1 = -(double)b / 2 * a;
                vector<int> v;
                if(x1 > 0) {
                    v.push_back(sqrt(x1));
                    v.push_back(-sqrt(x1));
                } else if(x1 == 0) {
                    v.push_back(0);
                }
                if(v.size()) {
                    cout << "Phuong trinh co " << v.size() << " nghiem la: ";
                    for(int i = 0; i < v.size(); ++i) {
                        cout << v[i] << " ";
                    }
                } else {
                    cout << "Phuong trinh vo nghiem";
                }
            } else {
                cout << "Phuong trinh vo nghiem";
            }
        }
    }
};

class tong {
private:
    int n, x;
public:
    long long s0() {
        cout << "\nNhap n: ";
        cin >> n;
        long long ans = 1;
        for(int i = 2; i <= n; ++i) {
            ans *= i;
        }
        return ans;
    }
    double s1() {
        cout << "\nNhap n: ";
        cin >> n;
        double ans = 1;
        for(int i = 2; i <= n; ++i) {
            ans += (double)1 / i;
        }
        return ans;
    }
    double s2() {
        cout << "\nNhap n: ";
        cin >> n;
        double ans = 1;
        double rem = 1;
        for(int i = 2; i <= n; ++i) {
            rem *= i;
            ans += (double)1 / rem;
        }
        return ans;
    }
    double s3() {
        cout << "\nNhap n: ";
        cin >> n;
        cout << "Nhap x: ";
        cin >> x;
        double ans = 1;
        long long res = 1;
        long tmp = 1;
        for(int i = 1; i <= n; ++i) {
            tmp *= i;
            res *= x;
            ans += (double)res / tmp;
        }
        return ans;
    }

    double s4() {
        cout << "\nNhap n: ";
        cin >> n;
        cout << "Nhap x: ";
        cin >> x;
        double ans = 1;
        long long res = 1;
        long tmp = 1;
        for(int i = 1; i <= n; ++i) {
            tmp *= i;
            res *= x;
            if(i % 2 == 0) {
                ans += (double)res / tmp;
            } else {
                ans -= (double)res / tmp;
            }
        }
        return ans;
    }

    double s5() {
        cout << "\nNhap n: ";
        cin >> n;
        cout << "Nhap x: ";
        cin >> x;
        double ans = 1;
        double tmp = 1;
        for(int i = 1; i <= n; ++i) {
            tmp *= sin(x);
            ans += tmp;
        }
        return ans;
    }
};

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

bool prime(int a) {
    if(a < 2) return false;
    for(int i = 2; i <= sqrt(a); ++i) {
        if(a % i == 0) return false;
    }
    return true;
}

class sohoc {
private:
    int n, a, b;
public:
    void uocchunglonnhat() {
        cout << "\nNhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;
        cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << gcd(a, b);
    }

    void boichungnhonhat() {
        cout << "\nnhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;
        cout << "Boi chung nho nhat cua " << a << " va " << b << " la: " << lcm(a, b);
    }
    void kiemtrasonguyento() {
        cout << "\nNhap so nguyen n: ";
        cin >> n;
        if(prime(n)) cout << n << " la so nguyen to";
        else cout << n << " khong phai la so nguyen to";
    }
    void lietkesonguyento() {
        cout << "\nNhap so n: ";
        cin >> n;
        cout << "Cac so nguyen to tu 1 den " << n << " la: ";
        for(int i = 2; i <= n; ++i) {
            if(prime(i)) cout << i << " ";
        }
    }
    void phantichthuasonguyento() {
        cout << "\nNhap so nguyen n: ";
        cin >> n;
        cout << "So nguyen " << n << " duoc phan tich thanh cac thua so nguyen to la: ";
        for(int i = 2; i <= sqrt(n); ++i) {
            if(n % i ==0) {
                cout << i << " ";
                n /= i;
            }
        }
        if(n != 1) cout << n;
    }
    void kiemtrasohoanthien() {
        cout << "\nNhap so nguyen n: ";
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n / 2; ++i) {
            if(n % i == 0) {
                ans += i;
            }
        }
        if(ans == n) {
            cout << n << " la so hoan thien";
        } else {
            cout << n << " khong phai la so hoan thien";
        }
    }
    void demsoluongso0() {
        cout << "\nNhap so nguyen n: ";
        cin >> n;
        int cnt = 0;
        for(int i = 5; i <= n; i *= 5) {
            cnt += n / i;
        }
        cout << "Co " << cnt << " so 0 o cuoi cua " << n << "!";
    }
};

class dequy {
public:
    void thaphanoi(int n, int a, int b, int c, vector<type>& v) {
        if(n == 1) {
            type va;
            va.first = a;
            va.second = c;
            v.push_back(va);
        } else {
            thaphanoi(n - 1, a, c, b,  v);
            thaphanoi(1, a, b, c, v);
            thaphanoi(n - 1, b, a, c, v);
        }
    }

    int fibonacci(int n) {
        if(n == 1 || n == 2) return 1;
        else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int tongcacchuso(int a) {
        if(a == 0) return 0;
        else {
            return (a % 10) + tongcacchuso(a / 10);
        }
    }
};

class menu {
public:
    void Menu() {
        cout << "\t\t\t\t\tChuong trinh lop va doi tuong";
        cout << "\n1.Lop Giai Phuong Trinh";
        cout << "\n2.Lop Tong";
        cout << "\n3.Lop So Hoc";
        cout << "\n4.Lop De Quy";
        cout << "\n5.Ket Thuc Chuong Trinh";
    }
    void Menu_giaiphuongtrinh() {
        cout << "\t\t\t\t\tLop Giai Phuong Trinh";
        cout << "\n1.Phuong trinh bac 1";
        cout << "\n2.Phuong trinh bac 2";
        cout << "\n3.Phuong trinh bac 3";
        cout << "\n4.Phuong trinh bac 4 trung phuong";
        cout << "\n5.Tro Ve Menu Chinh";
    }
    void Menu_tong() {
        cout << "\t\t\t\t\tLop Tong";
        cout << "\n1.Tinh s = 1 * 2 * ... * n = n!";
        cout << "\n2.Tinh s = 1 + 1/2 + ... + 1/n";
        cout << "\n3.Tinh s = 1 + 1/2! + 1/3! + ... + 1/n!";
        cout << "\n4.Tinh s = 1 + x + x^2/2! + ... + x^n/n!";
        cout << "\n5.Tinh s = 1 - x + x^2/2! - x^3/3! + ... + (-1)^n * x^n/n!";
        cout << "\n6.Tinh s = 1 + sin(x) + sin(x)^2 + ... + sin(x)^n";
        cout << "\n7.Tro ve Menu Chinh";
    }
    void Menu_sohoc() {
        cout << "\t\t\t\t\tLop So Hoc";
        cout << "\n1.Uoc Chung Lon Nhat";
        cout << "\n2.Boi Chung Nho Nhat";
        cout << "\n3.Kiem tra so nguyen to";
        cout << "\n4.Liet Ke So Nguyen To Be Hon N";
        cout << "\n5.Phan tich thua so nguyen to";
        cout << "\n6.Kiem tra so hoan thien";
        cout << "\n7.Dem so luong 0 cuoi cua N!";
        cout << "\n8.Tro Ve Menu Chinh";
    }
    void Menu_dequy() {
        cout << "\t\t\t\t\tLop De Quy";
        cout << "\n1.Bai Toan Thap Ha Noi";
        cout << "\n2.Tim so hang thu n cua day Fibonacci";
        cout << "\n3.Uoc Chung Lon Nhat";
        cout << "\n4.Tinh Tong Cac Chu So Cua 1 So Nguyen Duong";
        cout << "\n5.Tro Ve Menu Chinh";
    }
    void solve() {
Menu_main:
        system("cls");
        Menu();
        cout << "\nNhap so (chi nhap tu 1 den 5): ";
        int n;
        cin >> n;
        if(n < 1 || n > 5) {
            goto Menu_main;
        }
        if(n == 1) {
Menu_1:
            giaiphuongtrinh chosen;
            system("cls");
            Menu_giaiphuongtrinh();
            cout << "\nNhap so (chi nhap tu 1 den 5): ";
            int w;
            cin >> w;
            if(w < 1 || w > 5) {
                goto Menu_1;
            }
            if(w == 1) {
                system("cls");
                cout << "Giai phuong trinh bac 1 co dang ax + b = 0\n";
                cout << "Nhap a: ";
                int a;
                cin >> a;
                cout << "Nhap b: ";
                int b;
                cin >> b;
                chosen.phuongtrinhbacnhat(a, b);
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_1;
            } else if(w == 2) {
                system("cls");
                cout << "Giai phuong trinh bac 2 co dang ax^2 + bx + c = 0\n";
                cout << "Nhap a: ";
                int a;
                cin >> a;
                cout << "Nhap b: ";
                int b;
                cin >> b;
                cout << "Nhap c: ";
                int c;
                cin >> c;
                chosen.phuongtrinhbachai(a, b, c);
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_1;
            } else if(w == 3) {
                system("cls");
                cout << "Giai phuong trinh bac 3 co dang ax^3 + bx^2 + cx + d = 0\n";
                cout << "Nhap a: ";
                int a;
                cin >> a;
                cout << "Nhap b: ";
                int b;
                cin >> b;
                cout << "Nhap c: ";
                int c;
                cin >> c;
                cout << "Nhap d: ";
                int d;
                cin >> d;
                chosen.phuongtrinhbacba(a, b, c, d);
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_1;
            } else if(w == 4) {
                system("cls");
                cout << "Giai phuong trinh bac 4 trung phuong co dang ax^4 + bx^2 + c = 0\n";
                cout << "Nhap a: ";
                int a;
                cin >> a;
                cout << "Nhap b: ";
                int b;
                cin >> b;
                cout << "Nhap c: ";
                int c;
                cin >> c;
                chosen.phuongtrinhtrungphuong(a, b, c);
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_1;
            } else if(w == 5) {
                goto Menu_main;
            }
        } else if(n == 2) {
Menu_2:
            tong chosen;
            system("cls");
            Menu_tong();
            cout << "\nNhap so(tu 1 den 7): ";
            int w;
            cin >> w;
            if(w < 1 || w > 7) {
                goto Menu_2;
            }
            if(w == 1) {
                system("cls");
                cout << "Tinh s = 1 * 2 * ... * n = n!";
                long long ans = chosen.s0();
                cout << "s = " << ans;
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_2;
            } else if(w == 2) {
                system("cls");
                cout << "Tinh s = 1 + 1/2 + ... + 1/n";
                double ans = chosen.s1();
                cout << "s = " << ans;
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_2;
            } else if(w == 3) {
                system("cls");
                cout << "Tinh s = 1 + 1/2! + 1/3! + ... + 1/n!";
                double ans = chosen.s2();
                cout << "s = " << ans;
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_2;
            } else if(w == 4) {
                system("cls");
                cout << "Tinh s = 1 + x + x^2/2! + ... + x^n/n!";
                double ans = chosen.s3();
                cout << "s = " << ans;
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_2;
            } else if(w == 5) {
                system("cls");
                cout << "Tinh s = 1 - x + x^2/2! - x^3/3! + ... + (-1)^n * x^n/n!";
                cout << chosen.s4();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_2;
            } else if(w == 6) {
                system("cls");
                cout << "Tinh s = 1 + sin(x) + sin(x)^2 + ... + sin(x)^n";
                double ans = chosen.s5();
                cout << "s = " << ans;
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_2;
            } else {
                goto Menu_main;
            }
        } else if(n == 3) {
Menu_3:
            sohoc chosen;
            system("cls");
            Menu_sohoc();
            cout << "\nNhap so (chi nhap tu 1 den 8): ";
            int w;
            cin >> w;
            if(w < 1 || w > 8) {
                goto Menu_3;
            }
            if(w == 1) {
                system("cls");
                cout << "Tim Uoc Chung Lon Nhat";
                chosen.uocchunglonnhat();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_3;
            } else if(w == 2) {
                system("cls");
                cout << "Tim Boi Chung Nho Nhat";
                chosen.boichungnhonhat();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_3;
            } else if(w == 3) {
                system("cls");
                cout << "Kiem Tra So Nguyen To";
                chosen.kiemtrasonguyento();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_3;
            } else if(w == 4) {
                system("cls");
                cout << "Liet Ke So Nguyen To Nho Hon N";
                chosen.lietkesonguyento();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_3;
            } else if(w == 5) {
                system("cls");
                cout << "Phan Tich Thua So Thua So Nguyen To";
                chosen.phantichthuasonguyento();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_3;
            } else if(w == 6) {
                system("cls");
                cout << "Kiem Tra So Hoan Thien";
                chosen.kiemtrasohoanthien();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_3;
            } else if(w == 7) {
                system("cls");
                cout << "Dem So Luong Chu So 0 cuoi cua N!";
                chosen.demsoluongso0();
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_3;
            } else {
                goto Menu_main;
            }
        } else if(n == 4) {
Menu_4:
            dequy chosen;
            system("cls");
            Menu_dequy();
            cout << "\nNhap so (chi nhap tu 1 den 5): ";
            int w;
            cin >> w;
            if(w < 1 || w > 5) {
                goto Menu_4;
            }
            if(w == 1) {
                system("cls");
                cout << "Bai Toan Thap Ha Noi";
                cout << "\nNhap so luong n: ";
                int k;
                cin >> k;
                vector<type> v;
                chosen.thaphanoi(k, 1, 2, 3, v);
                cout << "\Co " << v.size() << " buoc de giai:";
                int cnt = 1;
                for(vector<type>::iterator it = v.begin(); it != v.end(); ++it) {
                    cout << "\nBuoc " << cnt++ << " chuyen tu cot " << (*it).first << " sang cot " << (*it).second;
                }
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_4;
            } else if(w == 2) {
                system("cls");
                cout << "Tim so hang thu n cua day Fibonacci";
                cout << "\nNhap so hang thu n: ";
                int k;
                cin >> k;
                cout << "So hang thu "<< n << " cua day Fibonacci la: " << chosen.fibonacci(n);
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_4;
            } else if(w == 3) {
                system("cls");
                cout << "Tim Uoc Chung Lon Nhat";
                cout << "\nNhap a: ";
                int x;
                cin >> x;
                cout << "Nhap b: ";
                int y;
                cin >> y;
                cout << "Uoc Chung Lon Nhat Cua " << x << " va " << y << " la: " << chosen.gcd(x, y);
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_4;
            } else if(w == 4) {
                system("cls");
                cout << "Tinh tong cac chu so cua 1 so nguyen";
                cout << "\nNhap so nguyen n: ";
                int k;
                cin >> k;
                cout << "Tong cac chu so cua " << k << " la: " << chosen.tongcacchuso(k);
                cout << "\nNhap Enter de quay ve!\n";
                system("pause");
                goto Menu_4;
            } else {
                goto Menu_main;
            }
        } else {
            cout << "Ket Thuc Chuong Trinh!";
            return;
        }
    }
};

int main() {
    menu a;
    a.solve();
    return 0;
}
