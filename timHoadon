void timHoaDon()
{
    string ma;

    cout << "Nhap ma hoa don can tim: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].maHoaDon == ma)
        {
            cout << "\n--- THONG TIN HOA DON ---\n";
            cout << "Ma hoa don: " << danhSachHoaDon[i].maHoaDon << endl;
            cout << "Ma phong: " << danhSachHoaDon[i].maPhong << endl;
            cout << "Thang/Nam: " << danhSachHoaDon[i].thang
                 << "/" << danhSachHoaDon[i].nam << endl;
            cout << "Tong tien: " << danhSachHoaDon[i].tongTien << " VND" << endl;

            if(danhSachHoaDon[i].daThanhToan)
                cout << "Trang thai: Da thanh toan\n";
            else
                cout << "Trang thai: Chua thanh toan\n";

            return;
        }
    }

    cout << "Khong tim thay hoa don!\n";
}
