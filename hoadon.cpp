void hoadon()
{
    int luaChon;

    do
    {
        cout << "\n========== QUAN LY HOA DON ==========\n";
        cout << "1. Hien thi hoa don\n";
        cout << "2. Xuat hoa don\n";
        cout << "0. Quay lai\n";
        cout << "=====================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                hienThiHoaDon();
                break;
            case 2:
                xuatHoaDon();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}
