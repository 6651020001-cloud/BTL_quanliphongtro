// ================= THONG KE =================

void thongkeMenu()
{
    int luaChon;

    do
    {
        cout << "\n============= THONG KE =============\n";
        cout << "1. Thong ke phong\n";
        cout << "2. Thong ke nguoi thue\n";
        cout << "3. Thong ke hoa don\n";
        cout << "0. Quay lai\n";
        cout << "====================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                thongKePhong();
                break;
            case 2:
                thongKeNguoiThue();
                break;
            case 3:
                thongKeHoaDon();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}
