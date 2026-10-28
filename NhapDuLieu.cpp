//  NHAP DU LIEU 
// xoa trang thai loi cua cin va bo phan nhap sai
void xoaLoiNhap()
{
    // het du lieu dau vao thi thoat de tranh lap vo han Ctrl+Z
    if(cin.eof())
    {
        cout << "\nKet thuc nhap du lieu!\n";
        exit(0);
    }

    cin.clear();
    cin.ignore(1000, '\n');
}

// nhap so nguyen, nhap sai thi bat nhap lai
int nhapSoNguyen()
{
    int x;

    while(!(cin >> x))
    {
        xoaLoiNhap();
        cout << "Gia tri khong hop le, vui long nhap so: ";
    }

    return x;
}

// nhap so tien, khong cho nhap chu hoac so am
double nhapSoTien()
{
    double x;

    while(!(cin >> x) || x < 0)
    {
        if(cin.fail())
            xoaLoiNhap();
        cout << "So tien khong hop le, nhap lai: ";
    }

    return x;
}
