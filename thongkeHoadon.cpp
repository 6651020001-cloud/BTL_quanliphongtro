void thongKeHoaDon()
{
    int soDaThanhToan = 0;
    int soChuaThanhToan = 0;
    double tongDoanhThu = 0;
    double tongNo = 0;

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].daThanhToan == true)
        {
            soDaThanhToan++;
            tongDoanhThu += danhSachHoaDon[i].tongTien;
        }
        else
        {
            soChuaThanhToan++;
            tongNo += danhSachHoaDon[i].tongTien;
        }
    }

    cout << "\n========== THONG KE HOA DON ==========\n";
    cout << "Tong so hoa don: " << danhSachHoaDon.size() << endl;
    cout << "So hoa don da thanh toan: " << soDaThanhToan << endl;
    cout << "So hoa don chua thanh toan: " << soChuaThanhToan << endl;
    cout << "Tong doanh thu: " << tongDoanhThu << " VND" << endl;
    cout << "Tong tien con no: " << tongNo << " VND" << endl;
    cout << "======================================\n";
}
