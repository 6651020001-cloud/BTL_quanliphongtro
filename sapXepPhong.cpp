void sapXepPhong()
{
    if(danhSachPhong.empty())
    {
        cout << "Danh sach phong dang rong!\n";
        return;
    }

    int kieu;
    cout << "\n1. Gia tang dan\n";
    cout << "2. Gia giam dan\n";
    cout << "0. Huy\n";
    cout << "Nhap lua chon: ";
    kieu = nhapSoNguyen();
    while(kieu < 0 || kieu > 2)
    {
        cout << "Lua chon khong hop le, nhap lai: ";
        kieu = nhapSoNguyen();
    }

    if(kieu == 0)
        return;

    int thuatToan;
    cout << "\nChon thuat toan:\n";
    cout << "1. Insertion sort\n";
    cout << "2. Selection sort\n";
    cout << "Nhap lua chon: ";
    thuatToan = nhapSoNguyen();
    while(thuatToan != 1 && thuatToan != 2)
    {
        cout << "Chi nhap 1 hoac 2: ";
        thuatToan = nhapSoNguyen();
    }

    int soSoSanh = 0;
    int soDiChuyen = 0;

    if(thuatToan == 1)
        insertionSortPhong(kieu == 1, soSoSanh, soDiChuyen);
    else
        selectionSortPhong(kieu == 1, soSoSanh, soDiChuyen);

    luuDuLieu();
    cout << "\nDa sap xep phong thanh cong!\n";
    cout << "So lan so sanh: " << soSoSanh << endl;
    cout << "So lan di chuyen/doi cho: " << soDiChuyen << endl;
    hienThiPhong();
}
