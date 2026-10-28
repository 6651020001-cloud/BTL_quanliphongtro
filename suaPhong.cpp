void suaPhong()
{
    string ma;

    cout << "\n===== SUA GIA PHONG =====\n";
    cout << "Nhap ma phong can sua: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == ma)
        {
            cout << "Gia hien tai: " << danhSachPhong[i].giaPhong << " VND\n";
            cout << "Nhap gia moi: ";
            danhSachPhong[i].giaPhong = nhapSoTien();
            while(danhSachPhong[i].giaPhong <= 0)
            {
                cout << "Gia phong phai lon hon 0, nhap lai: ";
                danhSachPhong[i].giaPhong = nhapSoTien();
            }

            // hoa don da xuat truoc do van giu gia cu, chi hoa don moi dung gia moi
            luuDuLieu();
            cout << "Sua gia phong thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay phong!\n";
}
