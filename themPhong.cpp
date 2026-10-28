void themPhong()
{
    Phong p;

    cout << "\n===== THEM PHONG =====\n";
    cout << "Nhap ma phong: ";
    cin >> p.maPhong;

    // kiem tra trung ma phong
    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == p.maPhong)
        {
            cout << "Ma phong da ton tai!\n";
            return;
        }
    }

    cout << "Nhap gia phong: ";
    p.giaPhong = nhapSoTien();
    while(p.giaPhong <= 0)
    {
        cout << "Gia phong phai lon hon 0, nhap lai: ";
        p.giaPhong = nhapSoTien();
    }

    p.trangThai = "Trong";
    danhSachPhong.push_back(p);
    luuDuLieu();

    cout << "Them phong thanh cong!\n";
}
