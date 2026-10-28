void thongKeChuaThanhToan()
{
    int dem = 0;
    double tongNo = 0;

    cout << "\n====== HOA DON CHUA THANH TOAN ======\n";

    if(danhSachHoaDon.empty())
    {
        cout << "Chua co hoa don nao!\n";
        return;
    }

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].daThanhToan == false)
        {
            dem++;
            tongNo += danhSachHoaDon[i].tongTien;

            cout << dem << ". " << danhSachHoaDon[i].maHoaDon
                 << " - Phong " << danhSachHoaDon[i].maPhong
                 << " - Thang " << danhSachHoaDon[i].thang << "/" << danhSachHoaDon[i].nam
                 << ": " << danhSachHoaDon[i].tongTien << " VND\n";
        }
    }

    if(dem == 0)
        cout << "Tat ca hoa don da duoc thanh toan!\n";
    else
        cout << "Tong cong: " << dem << " hoa don, " << tongNo << " VND\n";

    cout << "=====================================\n";
}
