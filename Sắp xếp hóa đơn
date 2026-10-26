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
        else if(kieu == 2)
        {
            while(j >= 0 && danhSachHoaDon[j].tongTien < x.tongTien)
            {
                danhSachHoaDon[j + 1] = danhSachHoaDon[j];
                j--;
            }
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
            return;
        }

        danhSachHoaDon[j + 1] = x;
    }

    luuDuLieu();
    cout << "\nDa sap xep hoa don thanh cong!\n";
    hienThiHoaDon();
}
