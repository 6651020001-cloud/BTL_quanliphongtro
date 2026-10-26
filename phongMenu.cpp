void phongMenu()
{
    int luaChon;

    do
    {
        cout << "\n========== QUAN LY PHONG ==========\n";
        cout << "1. Them phong\n";
        cout << "2. Xoa phong\n";
        cout << "3. Hien thi danh sach phong\n";
        cout << "0. Quay lai\n";
        cout << "===================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                themPhong();
                break;
            case 2:
                xoaPhong();
                break;
            case 3:
                hienThiPhong();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}
