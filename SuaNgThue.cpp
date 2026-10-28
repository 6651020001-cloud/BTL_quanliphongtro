void suaNguoiThue()
{
    string ma;

    cout << "\n===== SUA THONG TIN NGUOI THUE =====\n";
    cout << "Nhap ma nguoi thue can sua: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maNguoi == ma)
        {
            cout << "Ho ten: " << danhSachNguoiThue[i].hoTen << endl;
            cout << "So dien thoai: " << danhSachNguoiThue[i].soDienThoai << endl;
            cout << "1. Sua ho ten\n";
            cout << "2. Sua so dien thoai\n";
            cout << "0. Huy\n";
            cout << "Nhap lua chon: ";

            int chon = nhapSoNguyen();
            cin.ignore(1000, '\n');

            if(chon == 1)
            {
                string tenMoi;
                cout << "Nhap ho ten moi: ";
                tenMoi = nhapDong();
                while(!kiemTraHoTen(tenMoi))
                {
                    cout << "Ho ten khong hop le, nhap lai: ";
                    tenMoi = nhapDong();
                }
                danhSachNguoiThue[i].hoTen = tenMoi;
            }
            else if(chon == 2)
            {
                string sdtMoi;
                cout << "Nhap so dien thoai moi: ";
                sdtMoi = nhapDong();
                while(!kiemTraSoDienThoai(sdtMoi))
                {
                    cout << "So dien thoai phai gom 10 chu so, bat dau bang 0. Nhap lai: ";
                    sdtMoi = nhapDong();
                }
                danhSachNguoiThue[i].soDienThoai = sdtMoi;
            }
            else
            {
                cout << "Da huy sua!\n";
                return;
            }

            luuDuLieu();
            cout << "Sua thong tin thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay nguoi thue!\n";
}
