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

    if(kieu == 0)
        return;

    // insertion sort
    for(int i = 1; i < (int)danhSachPhong.size(); i++)
    {
        Phong x = danhSachPhong[i];
        int j = i - 1;

        if(kieu == 1)
        {
            while(j >= 0 && danhSachPhong[j].giaPhong > x.giaPhong)
            {
                danhSachPhong[j + 1] = danhSachPhong[j];
                j--;
            }
        }
        else if(kieu == 2)
        {
            while(j >= 0 && danhSachPhong[j].giaPhong < x.giaPhong)
            {
                danhSachPhong[j + 1] = danhSachPhong[j];
                j--;
            }
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
            return;
        }

        danhSachPhong[j + 1] = x;
    }

    luuDuLieu();
    cout << "\nDa sap xep phong thanh cong!\n";
    hienThiPhong();
}
