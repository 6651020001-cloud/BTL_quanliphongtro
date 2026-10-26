void hienThiHoaDon()
{
    if(danhSachHoaDon.empty())
    {
        cout << "Danh sach hoa don dang rong!\n";
        return;
    }

    cout << "\n===== DANH SACH HOA DON =====\n";

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        cout << "\nHoa don thu " << i + 1 << endl;
        cout << "Ma hoa don: " << danhSachHoaDon[i].maHoaDon << endl;
        cout << "Ma phong: " << danhSachHoaDon[i].maPhong << endl;
        cout << "Thang/Nam: " << danhSachHoaDon[i].thang
             << "/" << danhSachHoaDon[i].nam << endl;
        cout << "Tien phong: " << danhSachHoaDon[i].tienPhong << " VND" << endl;
        cout << "Tien dien: " << danhSachHoaDon[i].tienDien << " VND" << endl;
        cout << "Tien nuoc: " << danhSachHoaDon[i].tienNuoc << " VND" << endl;
        cout << "Tien khac: " << danhSachHoaDon[i].tienKhac << " VND" << endl;
        cout << "Tong tien: " << danhSachHoaDon[i].tongTien << " VND" << endl;

        if(danhSachHoaDon[i].daThanhToan)
            cout << "Trang thai: Da thanh toan\n";
        else
            cout << "Trang thai: Chua thanh toan\n";

        cout << "-------------------------------------\n";
    }
}
