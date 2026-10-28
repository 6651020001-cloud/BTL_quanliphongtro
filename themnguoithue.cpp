void themNguoiThue()
{
    NguoiThue nguoi;

    cout << "\n===== THEM NGUOI THUE =====\n";
    cout << "Nhap ma nguoi thue: ";
    cin >> nguoi.maNguoi;

    // kiem tra trung ma nguoi
    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maNguoi == nguoi.maNguoi)
        {
            cout << "Ma nguoi thue da ton tai!\n";
            return;
        }
    }

    cout << "Nhap ma phong: ";
    cin >> nguoi.maPhong;

    // kiem tra phong truoc khi nhap thong tin ca nhan
    int viTri = -1;
    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == nguoi.maPhong)
        {
            viTri = i;
            break;
        }
    }

    if(viTri == -1)
    {
        cout << "Khong tim thay phong!\n";
        return;
    }

    // 1 phong o duoc nhieu nguoi nhung khong qua SO_NGUOI_TOI_DA
    if(demSoNguoiTrongPhong(nguoi.maPhong) >= SO_NGUOI_TOI_DA)
    {
        cout << "Phong nay da du " << SO_NGUOI_TOI_DA << " nguoi!\n";
        return;
    }

    // bo het phan con lai cua dong truoc khi dung getline
    cin.ignore(1000, '\n');

    cout << "Nhap ho ten: ";
    nguoi.hoTen = nhapDong();
    while(!kiemTraHoTen(nguoi.hoTen))
    {
        cout << "Ho ten khong hop le, nhap lai: ";
        nguoi.hoTen = nhapDong();
    }

    cout << "Nhap so dien thoai: ";
    nguoi.soDienThoai = nhapDong();
    while(!kiemTraSoDienThoai(nguoi.soDienThoai))
    {
        cout << "So dien thoai phai gom 10 chu so, bat dau bang 0. Nhap lai: ";
        nguoi.soDienThoai = nhapDong();
    }

    danhSachNguoiThue.push_back(nguoi);
    danhSachPhong[viTri].trangThai = "Da thue";
    luuDuLieu();

    cout << "Them nguoi thue thanh cong\n";
}
