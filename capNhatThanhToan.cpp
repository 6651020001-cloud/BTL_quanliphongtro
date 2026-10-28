// khi nguoi thue dong tien thi chuyen hoa don sang da thanh toan
void capNhatThanhToan()
{
    string ma;

    cout << "\n===== CAP NHAT THANH TOAN =====\n";
    cout << "Nhap ma hoa don: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].maHoaDon == ma)
        {
            if(danhSachHoaDon[i].daThanhToan)
            {
                cout << "Hoa don nay da thanh toan roi!\n";
                return;
            }

            cout << "Phong " << danhSachHoaDon[i].maPhong << " - thang "
                 << danhSachHoaDon[i].thang << "/" << danhSachHoaDon[i].nam << endl;
            cout << "So tien can thu: " << danhSachHoaDon[i].tongTien << " VND\n";
            cout << "Xac nhan da thu tien? (1: Co, 0: Khong): ";

            int xacNhan = nhapSoNguyen();
            if(xacNhan != 1)
            {
                cout << "Da huy cap nhat!\n";
                return;
            }

            danhSachHoaDon[i].daThanhToan = true;
            luuDuLieu();

            cout << "Cap nhat thanh toan thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay hoa don!\n";
}
