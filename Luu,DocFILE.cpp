const string FILE_PHONG = "phong.txt";
const string FILE_NGUOI_THUE = "nguoithue.txt";
const string FILE_HOA_DON = "hoadon.txt";

// tach 1 dong thanh cac truong theo dau '|'
vector<string> tachDong(const string &dong)
{
    vector<string> truong;
    stringstream ss(dong);
    string s;

    while(getline(ss, s, '|'))
        truong.push_back(s);

    return truong;
}

void luuDuLieu()
{
    ofstream fPhong(FILE_PHONG.c_str());
    ofstream fNguoi(FILE_NGUOI_THUE.c_str());
    ofstream fHoaDon(FILE_HOA_DON.c_str());

    if(!fPhong || !fNguoi || !fHoaDon)
    {
        cout << "Loi: khong the ghi file du lieu!\n";
        return;
    }

    fPhong << fixed << setprecision(2);
    fHoaDon << fixed << setprecision(2);

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        fPhong << danhSachPhong[i].maPhong << "|"
               << danhSachPhong[i].giaPhong << "|"
               << danhSachPhong[i].trangThai << "\n";
    }

    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        fNguoi << danhSachNguoiThue[i].maNguoi << "|"
               << danhSachNguoiThue[i].hoTen << "|"
               << danhSachNguoiThue[i].soDienThoai << "|"
               << danhSachNguoiThue[i].maPhong << "\n";
    }

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        fHoaDon << danhSachHoaDon[i].maHoaDon << "|"
                << danhSachHoaDon[i].maPhong << "|"
                << danhSachHoaDon[i].thang << "|"
                << danhSachHoaDon[i].nam << "|"
                << danhSachHoaDon[i].tienPhong << "|"
                << danhSachHoaDon[i].tienDien << "|"
                << danhSachHoaDon[i].tienNuoc << "|"
                << danhSachHoaDon[i].tienKhac << "|"
                << danhSachHoaDon[i].tongTien << "|"
                << danhSachHoaDon[i].daThanhToan << "\n";
    }
}

void docDuLieu()
{
    string dong;
    int soDongLoi = 0;

    // file chua ton tai (chay lan dau) thi bo qua
    ifstream fPhong(FILE_PHONG.c_str());
    while(getline(fPhong, dong))
    {
        vector<string> t = tachDong(dong);
        if(t.size() != 3)
        {
            soDongLoi++;
            continue;
        }

        Phong p;
        p.maPhong = t[0];
        p.giaPhong = atof(t[1].c_str());
        p.trangThai = t[2];
        danhSachPhong.push_back(p);
    }

    ifstream fNguoi(FILE_NGUOI_THUE.c_str());
    while(getline(fNguoi, dong))
    {
        vector<string> t = tachDong(dong);
        if(t.size() != 4)
        {
            soDongLoi++;
            continue;
        }

        NguoiThue nguoi;
        nguoi.maNguoi = t[0];
        nguoi.hoTen = t[1];
        nguoi.soDienThoai = t[2];
        nguoi.maPhong = t[3];
        danhSachNguoiThue.push_back(nguoi);
    }

    ifstream fHoaDon(FILE_HOA_DON.c_str());
    while(getline(fHoaDon, dong))
    {
        vector<string> t = tachDong(dong);
        if(t.size() != 10)
        {
            soDongLoi++;
            continue;
        }

        HoaDon hd;
        hd.maHoaDon = t[0];
        hd.maPhong = t[1];
        hd.thang = atoi(t[2].c_str());
        hd.nam = atoi(t[3].c_str());
        hd.tienPhong = atof(t[4].c_str());
        hd.tienDien = atof(t[5].c_str());
        hd.tienNuoc = atof(t[6].c_str());
        hd.tienKhac = atof(t[7].c_str());
        hd.tongTien = atof(t[8].c_str());
        hd.daThanhToan = (t[9] == "1");
        danhSachHoaDon.push_back(hd);
    }

    cout << "Da doc du lieu: " << danhSachPhong.size() << " phong, "
         << danhSachNguoiThue.size() << " nguoi thue, "
         << danhSachHoaDon.size() << " hoa don.\n";

    if(soDongLoi > 0)
        cout << "Canh bao: bo qua " << soDongLoi << " dong du lieu bi loi!\n";
}
