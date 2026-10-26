void timPhong()
{
    string ma;

    cout << "Nhap ma phong can tim: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == ma)
        {
            cout << "\n--- THONG TIN PHONG ---\n";
            cout << "Ma phong: " << danhSachPhong[i].maPhong << endl;
            cout << "Gia phong: " << danhSachPhong[i].giaPhong << " VND" << endl;
            cout << "Trang thai: " << danhSachPhong[i].trangThai << endl;
            return;
        }
    }

    cout << "Khong tim thay phong!\n";
}
