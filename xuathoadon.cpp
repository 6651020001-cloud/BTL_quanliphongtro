void xuatHoaDon()
{
    HoaDon hd;

    cout << "\n===== XUAT HOA DON =====\n";
    cout << "Nhap ma hoa don: ";
    cin >> hd.maHoaDon;

    // kiem tra trung ma hoa don
    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].maHoaDon == hd.maHoaDon)
        {
            cout << "Ma hoa don da ton tai!\n";
            return;
        }
    }

    cout << "Nhap ma phong: ";
    cin >> hd.maPhong;

    bool coPhong = false;
    bool phongTrong = false;

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == hd.maPhong)
        {
            hd.tienPhong = danhSachPhong[i].giaPhong;
            coPhong = true;
            phongTrong = (danhSachPhong[i].trangThai == "Trong");
            break;
        }
    }

    if(coPhong == false)
    {
        cout << "Khong tim thay phong!\n";
        return;
    }

    // phong khong co ai o thi khong thu tien
    if(phongTrong)
    {
        cout << "Phong dang trong, khong the xuat hoa don!\n";
        return;
    }

    cout << "Tien phong: " << hd.tienPhong << " VND\n";

    cout << "Nhap thang: ";
    hd.thang = nhapSoNguyen();
    while(hd.thang < 1 || hd.thang > 12)
    {
        cout << "Thang phai tu 1 den 12, nhap lai: ";
        hd.thang = nhapSoNguyen();
    }

    cout << "Nhap nam: ";
    hd.nam = nhapSoNguyen();
    while(hd.nam < 2000 || hd.nam > 2100)
    {
        cout << "Nam khong hop le, nhap lai: ";
        hd.nam = nhapSoNguyen();
    }

    // 1 phong 1 thang chi co 1 hoa don
    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].maPhong == hd.maPhong &&
           danhSachHoaDon[i].thang == hd.thang &&
           danhSachHoaDon[i].nam == hd.nam)
        {
            cout << "Phong nay da co hoa don trong thang nay!\n";
            return;
        }
    }

    // tien dien = (chi so moi - chi so cu) * don gia
    int dienCu, dienMoi;
    cout << "Nhap chi so dien thang truoc: ";
    dienCu = nhapSoNguyen();
    while(dienCu < 0)
    {
        cout << "Chi so khong hop le, nhap lai: ";
        dienCu = nhapSoNguyen();
    }

    cout << "Nhap chi so dien thang nay: ";
    dienMoi = nhapSoNguyen();
    while(dienMoi < dienCu)
    {
        cout << "Chi so moi phai lon hon hoac bang chi so cu, nhap lai: ";
        dienMoi = nhapSoNguyen();
    }

    hd.tienDien = (dienMoi - dienCu) * GIA_DIEN;
    cout << "So dien da dung: " << dienMoi - dienCu << " kWh -> "
         << hd.tienDien << " VND\n";

    // tien nuoc tinh tuong tu tien dien
    int nuocCu, nuocMoi;
    cout << "Nhap chi so nuoc thang truoc: ";
    nuocCu = nhapSoNguyen();
    while(nuocCu < 0)
    {
        cout << "Chi so khong hop le, nhap lai: ";
        nuocCu = nhapSoNguyen();
    }

    cout << "Nhap chi so nuoc thang nay: ";
    nuocMoi = nhapSoNguyen();
    while(nuocMoi < nuocCu)
    {
        cout << "Chi so moi phai lon hon hoac bang chi so cu, nhap lai: ";
        nuocMoi = nhapSoNguyen();
    }

    hd.tienNuoc = (nuocMoi - nuocCu) * GIA_NUOC;
    cout << "So nuoc da dung: " << nuocMoi - nuocCu << " m3 -> "
         << hd.tienNuoc << " VND\n";

    cout << "Nhap tien khac: ";
    hd.tienKhac = nhapSoTien();

    hd.tongTien = hd.tienPhong + hd.tienDien
                + hd.tienNuoc + hd.tienKhac;

    int tt;
    cout << "Trang thai thanh toan (1: Da thanh toan, 0: Chua): ";
    tt = nhapSoNguyen();
    while(tt != 0 && tt != 1)
    {
        cout << "Chi nhap 1 hoac 0: ";
        tt = nhapSoNguyen();
    }

    hd.daThanhToan = (tt == 1);

    danhSachHoaDon.push_back(hd);
    luuDuLieu();

    cout << "Xuat hoa don thanh cong!\n";
    cout << "Tong tien: " << hd.tongTien << " VND\n";
}
