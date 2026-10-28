void thongKePhong()
{
    int phongTrong = 0;
    int phongDaThue = 0;

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].trangThai == "Trong")
            phongTrong++;
        else
            phongDaThue++;
    }
    cout << "\n=========== THONG KE PHONG ===========\n";
    cout << "Tong so phong: " << danhSachPhong.size() << endl;
    cout << "So phong trong: " << phongTrong << endl;
    cout << "So phong da thue: " << phongDaThue << endl;
    cout << "======================================\n";
}
