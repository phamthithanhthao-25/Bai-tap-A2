#include <iostream>
#include <string>
using namespace std;

class DuAn{
private:
    string maDuAn;
    string tenDuAn;
    string tenKhachHang;
    string ngayBatDau;
    string ngayKetThuc;
    double nganSach;
    double tyLeHoanThanh;

public:
    void nhap()
    {
        cout << "Ma du an: ";
        getline(cin, maDuAn);

        cout << "Ten du an: ";
        getline(cin, tenDuAn);

        cout << "Ten khach hang: ";
        getline(cin, tenKhachHang);

        cout << "Ngay bat dau: ";
        getline(cin, ngayBatDau);

        cout << "Ngay ket thuc du kien: ";
        getline(cin, ngayKetThuc);

        cout << "Ngan sach: ";
        cin >> nganSach;

        cout << "Ty le hoan thanh (%): ";
        cin >> tyLeHoanThanh;

        cin.ignore();
    }

    void xuat()
    {
        cout << "Ma du an: " << maDuAn << endl;
        cout << "Ten du an: " << tenDuAn << endl;
        cout << "Ten khach hang: " << tenKhachHang << endl;
        cout << "Ngay bat dau: " << ngayBatDau << endl;
        cout << "Ngay ket thuc du kien: " << ngayKetThuc << endl;
        cout << "Ngan sach: " << nganSach << endl;
        cout << "Ty le hoan thanh: " << tyLeHoanThanh << "%" << endl;
    }

    double getnganSach()
    {
        return nganSach;
    }

    string getmaDuAn()
    {
        return maDuAn;
    }

    string gettenDuAn()
    {
        return tenDuAn;
    }
};

void sapXep(DuAn ds[], int n)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ds[i].getnganSach() < ds[j].getnganSach())
            {
                DuAn temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void timKiem(DuAn ds[], int n)
{
    string tuKhoa;
    bool timThay = false;

    cout << "\nNhap ma du an hoac ten du an can tim: ";
    getline(cin, tuKhoa);

    for (int i = 0; i < n; i++)
    {
        if (ds[i].getmaDuAn() == tuKhoa ||
            ds[i].gettenDuAn() == tuKhoa)
        {
            cout << "\nDU AN TIM THAY\n";
            ds[i].xuat();
            timThay = true;
        }
    }

    if (timThay == false)
    {
        cout << "\nKhong tim thay du an!\n";
    }
}

int main()
{
    int n;

    cout << "Nhap so luong du an: ";
    cin >> n;
    cin.ignore();

    DuAn ds[200];

    for (int i = 0; i < n; i++)
    {
        cout << "\nNHAP DU AN " << i + 1 << "\n";
        ds[i].nhap();
    }

    sapXep(ds, n);

    cout << "\n\nDANH SACH DU AN SAU SAP XEP THEO NGAN SACH\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nDU AN " << i + 1 << "\n";
        ds[i].xuat();
    }

    timKiem(ds, n);

    return 0;
}
