void xoaPhong()
{
    string ma;

    cout << "\n===== XOA PHONG =====\n";
    cout << "Nhap ma phong can xoa: ";
    cin >> ma;

    // khong cho xoa phong dang co nguoi thue
    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maPhong == ma)
        {
            cout << "Phong dang co nguoi thue!\n";
            return;
        }
    }

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == ma)
        {
            danhSachPhong.erase(danhSachPhong.begin() + i);
            luuDuLieu();
            cout << "Xoa phong thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay phong!\n";
}
