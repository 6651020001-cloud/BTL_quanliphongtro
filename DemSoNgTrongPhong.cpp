// 1 phong o toi da 4 nguoi
const int SO_NGUOI_TOI_DA = 4;

// dem so nguoi dang o trong 1 phong
int demSoNguoiTrongPhong(string maPhong)
{
    int dem = 0;

    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maPhong == maPhong)
            dem++;
    }

    return dem;
}

// doc ca 1 dong (ho ten co dau cach), het du lieu dau vao thi thoat
string nhapDong()
{
    string s;

    if(!getline(cin, s))
        xoaLoiNhap();

    return s;
}
