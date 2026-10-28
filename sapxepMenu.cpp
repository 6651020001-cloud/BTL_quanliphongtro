void sapxepMenu()
{
    int luaChon;

    do
    {
        cout << "\n============= SAP XEP =============\n";
        cout << "1. Sap xep phong theo gia\n";
        cout << "2. Sap xep hoa don theo tong tien\n";
        cout << "3. Sap xep hoa don theo thang/nam\n";
        cout << "4. Sap xep nguoi thue theo ma phong\n";
        cout << "0. Quay lai\n";
        cout << "===================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                sapXepPhong();
                break;
            case 2:
                sapXepHoaDon();
                break;
            case 3:
                sapXepHoaDonTheoThang();
                break;
            case 4:
                sapXepNguoiThue();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}
