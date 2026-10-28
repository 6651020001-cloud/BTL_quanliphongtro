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
