#include "QuanLyPhongTro.h"

// ================= SAP XEP =================

void sapxepMenu()
{
    int luaChon;

    do
    {
        cout << "\n============= SAP XEP =============\n";
        cout << "1. Sap xep phong theo gia\n";
        cout << "2. Sap xep hoa don theo tong tien\n";
        cout << "3. Sap xep hoa don theo thang/nam\n";
        cout << "4. Sap xep nguoi thue theo ma phong\n";
        cout << "0. Quay lai\n";
        cout << "===================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                sapXepPhong();
                break;
            case 2:
                sapXepHoaDon();
                break;
            case 3:
                sapXepHoaDonTheoThang();
                break;
            case 4:
                sapXepNguoiThue();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}

// a dung truoc b ma sai thu tu thi tra ve true
bool saiThuTu(double a, double b, bool tangDan)
{
    if(tangDan)
        return a > b;
    return a < b;
}

// insertion sort: lay tung phong chen vao dung vi tri trong doan da sap xep
// soSoSanh, soDiChuyen de dem so buoc, dung de so sanh 2 thuat toan
void insertionSortPhong(bool tangDan, int &soSoSanh, int &soDiChuyen)
{
    for(int i = 1; i < (int)danhSachPhong.size(); i++)
    {
        Phong x = danhSachPhong[i];
        int j = i - 1;

        while(j >= 0)
        {
            soSoSanh++;
            if(!saiThuTu(danhSachPhong[j].giaPhong, x.giaPhong, tangDan))
                break;

            danhSachPhong[j + 1] = danhSachPhong[j];
            soDiChuyen++;
            j--;
        }

        danhSachPhong[j + 1] = x;
    }
}

// selection sort: moi luot tim phong re nhat (hoac dat nhat) dua len dau
void selectionSortPhong(bool tangDan, int &soSoSanh, int &soDiChuyen)
{
    int n = danhSachPhong.size();

    for(int i = 0; i < n - 1; i++)
    {
        int viTri = i;

        for(int j = i + 1; j < n; j++)
        {
            soSoSanh++;
            if(saiThuTu(danhSachPhong[viTri].giaPhong, danhSachPhong[j].giaPhong, tangDan))
                viTri = j;
        }

        if(viTri != i)
        {
            Phong tam = danhSachPhong[i];
            danhSachPhong[i] = danhSachPhong[viTri];
            danhSachPhong[viTri] = tam;
            soDiChuyen++;
        }
    }
}

void sapXepPhong()
{
    if(danhSachPhong.empty())
    {
        cout << "Danh sach phong dang rong!\n";
        return;
    }

    int kieu;
    cout << "\n1. Gia tang dan\n";
    cout << "2. Gia giam dan\n";
    cout << "0. Huy\n";
    cout << "Nhap lua chon: ";
    kieu = nhapSoNguyen();
    while(kieu < 0 || kieu > 2)
    {
        cout << "Lua chon khong hop le, nhap lai: ";
        kieu = nhapSoNguyen();
    }

    if(kieu == 0)
        return;

    int thuatToan;
    cout << "\nChon thuat toan:\n";
    cout << "1. Insertion sort\n";
    cout << "2. Selection sort\n";
    cout << "Nhap lua chon: ";
    thuatToan = nhapSoNguyen();
    while(thuatToan != 1 && thuatToan != 2)
    {
        cout << "Chi nhap 1 hoac 2: ";
        thuatToan = nhapSoNguyen();
    }

    int soSoSanh = 0;
    int soDiChuyen = 0;

    if(thuatToan == 1)
        insertionSortPhong(kieu == 1, soSoSanh, soDiChuyen);
    else
        selectionSortPhong(kieu == 1, soSoSanh, soDiChuyen);

    luuDuLieu();
    cout << "\nDa sap xep phong thanh cong!\n";
    cout << "So lan so sanh: " << soSoSanh << endl;
    cout << "So lan di chuyen/doi cho: " << soDiChuyen << endl;
    hienThiPhong();
}

void sapXepHoaDon()
{
    if(danhSachHoaDon.empty())
    {
        cout << "Danh sach hoa don dang rong!\n";
        return;
    }

    int kieu;
    cout << "\n1. Tong tien tang dan\n";
    cout << "2. Tong tien giam dan\n";
    cout << "0. Huy\n";
    cout << "Nhap lua chon: ";
    kieu = nhapSoNguyen();
    while(kieu < 0 || kieu > 2)
    {
        cout << "Lua chon khong hop le, nhap lai: ";
        kieu = nhapSoNguyen();
    }

    if(kieu == 0)
        return;

    // insertion sort
    for(int i = 1; i < (int)danhSachHoaDon.size(); i++)
    {
        HoaDon x = danhSachHoaDon[i];
        int j = i - 1;

        if(kieu == 1)
        {
            while(j >= 0 && danhSachHoaDon[j].tongTien > x.tongTien)
            {
                danhSachHoaDon[j + 1] = danhSachHoaDon[j];
                j--;
            }
        }
        else
        {
            while(j >= 0 && danhSachHoaDon[j].tongTien < x.tongTien)
            {
                danhSachHoaDon[j + 1] = danhSachHoaDon[j];
                j--;
            }
        }

        danhSachHoaDon[j + 1] = x;
    }

    luuDuLieu();
    cout << "\nDa sap xep hoa don thanh cong!\n";
    hienThiHoaDon();
}

// sap xep hoa don tu cu den moi de xem lich su thu tien
void sapXepHoaDonTheoThang()
{
    if(danhSachHoaDon.empty())
    {
        cout << "Danh sach hoa don dang rong!\n";
        return;
    }

    // insertion sort, doi thang/nam thanh 1 so cho de so sanh
    // vi du 10/2026 -> 202610
    for(int i = 1; i < (int)danhSachHoaDon.size(); i++)
    {
        HoaDon x = danhSachHoaDon[i];
        int giaTriX = x.nam * 100 + x.thang;
        int j = i - 1;

        while(j >= 0 && danhSachHoaDon[j].nam * 100 + danhSachHoaDon[j].thang > giaTriX)
        {
            danhSachHoaDon[j + 1] = danhSachHoaDon[j];
            j--;
        }

        danhSachHoaDon[j + 1] = x;
    }

    luuDuLieu();
    cout << "\nDa sap xep hoa don theo thang/nam!\n";
    hienThiHoaDon();
}

// sap xep nguoi thue theo ma phong de nhung nguoi cung phong dung canh nhau
void sapXepNguoiThue()
{
    if(danhSachNguoiThue.empty())
    {
        cout << "Danh sach nguoi thue dang rong!\n";
        return;
    }

    // insertion sort, so sanh chuoi theo thu tu tu dien
    for(int i = 1; i < (int)danhSachNguoiThue.size(); i++)
    {
        NguoiThue x = danhSachNguoiThue[i];
        int j = i - 1;

        while(j >= 0 && danhSachNguoiThue[j].maPhong > x.maPhong)
        {
            danhSachNguoiThue[j + 1] = danhSachNguoiThue[j];
            j--;
        }

        danhSachNguoiThue[j + 1] = x;
    }

    luuDuLieu();
    cout << "\nDa sap xep nguoi thue theo ma phong!\n";
    hienThiNguoiThue();
}
