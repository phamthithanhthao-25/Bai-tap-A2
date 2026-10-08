#include <iostream>
#include <string>
using namespace std;

class DuAn
{
private:
    string maDuAn;
    string tenDuAn;
    string tenKhachHang;
    string ngayBatDau;
    string ngayKetThuc;
    long long nganSach;
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

    // Xuat thong tin du an
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

    long long getnganSach()
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


void boSungDuAn(DuAn ds[], int &n)
{
    int viTri;

    if (n >= 200)
    {
        cout << "\nLoi khong hop le! Danh sach da day.\n";
        return;
    }

    cout << "\nNhap vi tri muon bo sung (1 den "
         << n + 1 << "): ";
    cin >> viTri;
    cin.ignore();

    if (viTri < 1 || viTri > n + 1)
    {
        cout << "\nLoi khong hop le! Vi tri phai tu 1 den "
             << n + 1 << ".\n";
        return;
    }

    for (int i = n; i >= viTri; i--)
    {
        ds[i] = ds[i - 1];
    }

    cout << "\nNHAP DU AN MOI\n";
    ds[viTri - 1].nhap();

    n++;

    cout << "\nDa bo sung du an thanh cong!\n";
}


void xoaDuAn(DuAn ds[], int &n)
{
    int vt;

    if (n <= 0)
    {
        cout << "Danh sach rong!" << endl;
        return;
    }

    cout << "Nhap vi tri du an muon xoa (1 den " << n << "): "; cin >> vt;
    cin.ignore();

    if (vt < 1 || vt > n)
    {
        cout << "\nVi tri khong hop le! Vui long nhap lai!\n";
        return;
    }

    cout << "\nDU AN BI XOA:\n";
    ds[vt - 1].xuat();

    for (int i = vt - 1; i < n - 1; i++)
    {
        ds[i] = ds[i + 1];
    }

    n--;

    cout << "\nDA XOA DU AN THANH CONG\n";
}


int main()
{
    int n;

    do{
        cout << "Nhap so luong du an: ";
        cin >> n;

        if (n <= 0 || n >= 200)
        {
            cout << "So luong du an khong hop le! "
                 << "Vui long nhap lai.\n";
        }

    } while (n <= 0 || n >= 200);

    cin.ignore();

    DuAn ds[200];

    for (int i = 0; i < n; i++)
    {
        cout << "\nNHAP DU AN " << i + 1 << "\n";
        ds[i].nhap();
    }

    sapXep(ds, n);

    cout << "\n\n====================================";
    cout << "\nDANH SACH DU AN SAU SAP XEP";
    cout << "\nTHEO NGAN SACH GIAM DAN";
    cout << "\n====================================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nDU AN " << i + 1 << "\n";
        ds[i].xuat();
    }

    timKiem(ds, n);

    boSungDuAn(ds, n);

    cout << "\n\n====================================";
    cout << "\nDANH SACH SAU KHI BO SUNG";
    cout << "\n====================================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nDU AN " << i + 1 << "\n";
        ds[i].xuat();
    }

    xoaDuAn(ds, n);

    cout << "\n\n====================================";
    cout << "\nDANH SACH SAU KHI XOA";
    cout << "\n====================================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nDU AN " << i + 1 << "\n";
        ds[i].xuat();
    }

    return 0;
}
