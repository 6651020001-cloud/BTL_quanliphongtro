void xoaNguoiThue()
{
    string ma;

    cout << "\n===== XOA NGUOI THUE =====\n";
    cout << "Nhap ma nguoi thue can xoa: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maNguoi == ma)
        {
            string maPhong = danhSachNguoiThue[i].maPhong;

            danhSachNguoiThue.erase(danhSachNguoiThue.begin() + i);

            // kiem tra phong con nguoi thue khac khong
            bool conNguoi = false;
            for(int j = 0; j < (int)danhSachNguoiThue.size(); j++)
            {
                if(danhSachNguoiThue[j].maPhong == maPhong)
                {
                    conNguoi = true;
                    break;
                }
            }

            if(conNguoi == false)
            {
                for(int j = 0; j < (int)danhSachPhong.size(); j++)
                {
                    if(danhSachPhong[j].maPhong == maPhong)
                        danhSachPhong[j].trangThai = "Trong";
                }
            }

            luuDuLieu();

            cout << "Xoa nguoi thue thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay nguoi thue!\n";
}
