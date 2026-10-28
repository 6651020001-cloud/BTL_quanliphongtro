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
