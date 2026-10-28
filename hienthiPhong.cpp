void hienThiPhong()
{
    if(danhSachPhong.empty())
    {
        cout << "Danh sach phong dang rong!\n";
        return;
    }

    cout << "\n===== DANH SACH PHONG =====\n";

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        cout << "\nPhong thu " << i + 1 << endl;
        cout << "Ma phong: " << danhSachPhong[i].maPhong << endl;
        cout << "Gia phong: " << danhSachPhong[i].giaPhong << " VND" << endl;
        cout << "Trang thai: " << danhSachPhong[i].trangThai << endl;
        cout << "So nguoi dang o: " << demSoNguoiTrongPhong(danhSachPhong[i].maPhong) << endl;
        cout << "---------------------------\n";
    }
}
