// nhom 15
// thanh vien: Nguyen Van Ban 6651020001
//             Huynh Gia Bao 6651020002
//             Phan Cong Binh 6651020003
//             Luong Anh Dung 6651020006
//             Tran Phat Dat 6651020017
// De Tai: He Thong Quan Ly Phong Tro

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

struct Phong
{
    string maPhong;
    double giaPhong;
    string trangThai;
};

struct NguoiThue
{
    string maNguoi;
    string hoTen;
    string soDienThoai;
    string maPhong;
};

struct HoaDon
{
    string maHoaDon;
    string maPhong;
    int thang;
    int nam;
    double tienPhong;
    double tienDien;
    double tienNuoc;
    double tienKhac;
    double tongTien;
    bool daThanhToan;
};

vector<Phong> danhSachPhong;
vector<NguoiThue> danhSachNguoiThue;
vector<HoaDon> danhSachHoaDon;

// khai bao ham
void phongMenu();
void themPhong();
void xoaPhong();
void hienThiPhong();

void ngthueMenu();
void themNguoiThue();
void xoaNguoiThue();
void hienThiNguoiThue();

void hoadon();
void hienThiHoaDon();
void xuatHoaDon();

void searchMenu();
void timPhong();
void timNguoiThue();
void timHoaDon();

void sapxepMenu();
void sapXepPhong();
void sapXepHoaDon();

void thongkeMenu();
void thongKePhong();
void thongKeNguoiThue();
void thongKeHoaDon();

// ================= NHAP DU LIEU =================

// xoa trang thai loi cua cin va bo phan nhap sai
void xoaLoiNhap()
{
    // het du lieu dau vao (Ctrl+Z / Ctrl+D) thi thoat de tranh lap vo han
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

// ================= LUU / DOC FILE =================
// file nam cung thu muc voi chuong trinh, moi dong 1 ban ghi,
// cac truong cach nhau boi dau '|'

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


// ================= QUAN LY PHONG =================

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

void themPhong()
{
    Phong p;

    cout << "\n===== THEM PHONG =====\n";
    cout << "Nhap ma phong: ";
    cin >> p.maPhong;

    // kiem tra trung ma phong
    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == p.maPhong)
        {
            cout << "Ma phong da ton tai!\n";
            return;
        }
    }

    cout << "Nhap gia phong: ";
    p.giaPhong = nhapSoTien();

    p.trangThai = "Trong";
    danhSachPhong.push_back(p);
    luuDuLieu();

    cout << "Them phong thanh cong!\n";
}

void xoaPhong()
{
    string ma;

    cout << "\n===== XOA PHONG =====\n";
    cout << "Nhap ma phong can xoa: ";
    cin >> ma;

    // khong cho xoa phong dang co nguoi thue
    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maPhong == ma)
        {
            cout << "Phong dang co nguoi thue!\n";
            return;
        }
    }

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == ma)
        {
            danhSachPhong.erase(danhSachPhong.begin() + i);
            luuDuLieu();
            cout << "Xoa phong thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay phong!\n";
}

void hienThiPhong()
{
    if(danhSachPhong.empty())
    {
        cout << "Danh sach phong dang rong!\n";
        return;
    }

    cout << "\n===== DANH SACH PHONG =====\n";

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        cout << "\nPhong thu " << i + 1 << endl;
        cout << "Ma phong: " << danhSachPhong[i].maPhong << endl;
        cout << "Gia phong: " << danhSachPhong[i].giaPhong << " VND" << endl;
        cout << "Trang thai: " << danhSachPhong[i].trangThai << endl;
        cout << "---------------------------\n";
    }
}

// ================= QUAN LY NGUOI THUE =================

void ngthueMenu()
{
    int luaChon;

    do
    {
        cout << "\n======= QUAN LY NGUOI THUE =======\n";
        cout << "1. Them nguoi thue\n";
        cout << "2. Xoa nguoi thue\n";
        cout << "3. Hien thi danh sach\n";
        cout << "0. Quay lai\n";
        cout << "==================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                themNguoiThue();
                break;
            case 2:
                xoaNguoiThue();
                break;
            case 3:
                hienThiNguoiThue();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}

void themNguoiThue()
{
    NguoiThue nguoi;

    cout << "\n===== THEM NGUOI THUE =====\n";
    cout << "Nhap ma nguoi thue: ";
    cin >> nguoi.maNguoi;

    // kiem tra trung ma nguoi
    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maNguoi == nguoi.maNguoi)
        {
            cout << "Ma nguoi thue da ton tai!\n";
            return;
        }
    }

    cout << "Nhap ma phong: ";
    cin >> nguoi.maPhong;

    // kiem tra phong truoc khi nhap thong tin ca nhan
    int viTri = -1;
    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == nguoi.maPhong)
        {
            viTri = i;
            break;
        }
    }

    if(viTri == -1)
    {
        cout << "Khong tim thay phong!\n";
        return;
    }

    if(danhSachPhong[viTri].trangThai == "Da thue")
    {
        cout << "Phong nay da co nguoi thue!\n";
        return;
    }

    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, nguoi.hoTen);

    cout << "Nhap so dien thoai: ";
    getline(cin, nguoi.soDienThoai);

    danhSachNguoiThue.push_back(nguoi);
    danhSachPhong[viTri].trangThai = "Da thue";
    luuDuLieu();

    cout << "Them nguoi thue thanh cong!\n";
}

void xoaNguoiThue()
{
    string ma;

    cout << "\n===== XOA NGUOI THUE =====\n";
    cout << "Nhap ma nguoi thue can xoa: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maNguoi == ma)
        {
            string maPhong = danhSachNguoiThue[i].maPhong;

            danhSachNguoiThue.erase(danhSachNguoiThue.begin() + i);

            // kiem tra phong con nguoi thue khac khong
            bool conNguoi = false;
            for(int j = 0; j < (int)danhSachNguoiThue.size(); j++)
            {
                if(danhSachNguoiThue[j].maPhong == maPhong)
                {
                    conNguoi = true;
                    break;
                }
            }

            if(conNguoi == false)
            {
                for(int j = 0; j < (int)danhSachPhong.size(); j++)
                {
                    if(danhSachPhong[j].maPhong == maPhong)
                        danhSachPhong[j].trangThai = "Trong";
                }
            }

            luuDuLieu();

            cout << "Xoa nguoi thue thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay nguoi thue!\n";
}

void hienThiNguoiThue()
{
    if(danhSachNguoiThue.empty())
    {
        cout << "Danh sach nguoi thue dang rong!\n";
        return;
    }

    cout << "\n===== DANH SACH NGUOI THUE =====\n";

    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        cout << "\nNguoi thue thu " << i + 1 << endl;
        cout << "Ma nguoi: " << danhSachNguoiThue[i].maNguoi << endl;
        cout << "Ho ten: " << danhSachNguoiThue[i].hoTen << endl;
        cout << "So dien thoai: " << danhSachNguoiThue[i].soDienThoai << endl;
        cout << "Ma phong: " << danhSachNguoiThue[i].maPhong << endl;
        cout << "-----------------------------\n";
    }
}

// ================= QUAN LY HOA DON =================

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

void hienThiHoaDon()
{
    if(danhSachHoaDon.empty())
    {
        cout << "Danh sach hoa don dang rong!\n";
        return;
    }

    cout << "\n===== DANH SACH HOA DON =====\n";

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        cout << "\nHoa don thu " << i + 1 << endl;
        cout << "Ma hoa don: " << danhSachHoaDon[i].maHoaDon << endl;
        cout << "Ma phong: " << danhSachHoaDon[i].maPhong << endl;
        cout << "Thang/Nam: " << danhSachHoaDon[i].thang
             << "/" << danhSachHoaDon[i].nam << endl;
        cout << "Tien phong: " << danhSachHoaDon[i].tienPhong << " VND" << endl;
        cout << "Tien dien: " << danhSachHoaDon[i].tienDien << " VND" << endl;
        cout << "Tien nuoc: " << danhSachHoaDon[i].tienNuoc << " VND" << endl;
        cout << "Tien khac: " << danhSachHoaDon[i].tienKhac << " VND" << endl;
        cout << "Tong tien: " << danhSachHoaDon[i].tongTien << " VND" << endl;

        if(danhSachHoaDon[i].daThanhToan)
            cout << "Trang thai: Da thanh toan\n";
        else
            cout << "Trang thai: Chua thanh toan\n";

        cout << "-------------------------------------\n";
    }
}

void xuatHoaDon()
{
    HoaDon hd;

    cout << "\n===== XUAT HOA DON =====\n";
    cout << "Nhap ma hoa don: ";
    cin >> hd.maHoaDon;

    // kiem tra trung ma hoa don
    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].maHoaDon == hd.maHoaDon)
        {
            cout << "Ma hoa don da ton tai!\n";
            return;
        }
    }

    cout << "Nhap ma phong: ";
    cin >> hd.maPhong;

    bool coPhong = false;

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == hd.maPhong)
        {
            hd.tienPhong = danhSachPhong[i].giaPhong;
            coPhong = true;
            break;
        }
    }

    if(coPhong == false)
    {
        cout << "Khong tim thay phong!\n";
        return;
    }

    cout << "Tien phong: " << hd.tienPhong << " VND\n";

    cout << "Nhap thang: ";
    hd.thang = nhapSoNguyen();
    while(hd.thang < 1 || hd.thang > 12)
    {
        cout << "Thang phai tu 1 den 12, nhap lai: ";
        hd.thang = nhapSoNguyen();
    }

    cout << "Nhap nam: ";
    hd.nam = nhapSoNguyen();
    while(hd.nam < 2000 || hd.nam > 2100)
    {
        cout << "Nam khong hop le, nhap lai: ";
        hd.nam = nhapSoNguyen();
    }

    // 1 phong 1 thang chi co 1 hoa don
    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].maPhong == hd.maPhong &&
           danhSachHoaDon[i].thang == hd.thang &&
           danhSachHoaDon[i].nam == hd.nam)
        {
            cout << "Phong nay da co hoa don trong thang nay!\n";
            return;
        }
    }

    cout << "Nhap tien dien: ";
    hd.tienDien = nhapSoTien();

    cout << "Nhap tien nuoc: ";
    hd.tienNuoc = nhapSoTien();

    cout << "Nhap tien khac: ";
    hd.tienKhac = nhapSoTien();

    hd.tongTien = hd.tienPhong + hd.tienDien
                + hd.tienNuoc + hd.tienKhac;

    int tt;
    cout << "Trang thai thanh toan (1: Da thanh toan, 0: Chua): ";
    tt = nhapSoNguyen();
    while(tt != 0 && tt != 1)
    {
        cout << "Chi nhap 1 hoac 0: ";
        tt = nhapSoNguyen();
    }

    hd.daThanhToan = (tt == 1);

    danhSachHoaDon.push_back(hd);
    luuDuLieu();

    cout << "Xuat hoa don thanh cong!\n";
    cout << "Tong tien: " << hd.tongTien << " VND\n";
}

// ================= TIM KIEM =================

void searchMenu()
{
    int luaChon;

    do
    {
        cout << "\n============= TIM KIEM =============\n";
        cout << "1. Tim phong\n";
        cout << "2. Tim nguoi thue\n";
        cout << "3. Tim hoa don\n";
        cout << "0. Quay lai\n";
        cout << "====================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                timPhong();
                break;
            case 2:
                timNguoiThue();
                break;
            case 3:
                timHoaDon();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}

void timPhong()
{
    string ma;

    cout << "Nhap ma phong can tim: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachPhong.size(); i++)
    {
        if(danhSachPhong[i].maPhong == ma)
        {
            cout << "\n--- THONG TIN PHONG ---\n";
            cout << "Ma phong: " << danhSachPhong[i].maPhong << endl;
            cout << "Gia phong: " << danhSachPhong[i].giaPhong << " VND" << endl;
            cout << "Trang thai: " << danhSachPhong[i].trangThai << endl;
            return;
        }
    }

    cout << "Khong tim thay phong!\n";
}

void timNguoiThue()
{
    string ma;

    cout << "Nhap ma nguoi thue can tim: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachNguoiThue.size(); i++)
    {
        if(danhSachNguoiThue[i].maNguoi == ma)
        {
            cout << "\n--- THONG TIN NGUOI THUE ---\n";
            cout << "Ma nguoi thue: " << danhSachNguoiThue[i].maNguoi << endl;
            cout << "Ho ten: " << danhSachNguoiThue[i].hoTen << endl;
            cout << "So dien thoai: " << danhSachNguoiThue[i].soDienThoai << endl;
            cout << "Ma phong: " << danhSachNguoiThue[i].maPhong << endl;
            return;
        }
    }

    cout << "Khong tim thay nguoi thue!\n";
}

void timHoaDon()
{
    string ma;

    cout << "Nhap ma hoa don can tim: ";
    cin >> ma;

    for(int i = 0; i < (int)danhSachHoaDon.size(); i++)
    {
        if(danhSachHoaDon[i].maHoaDon == ma)
        {
            cout << "\n--- THONG TIN HOA DON ---\n";
            cout << "Ma hoa don: " << danhSachHoaDon[i].maHoaDon << endl;
            cout << "Ma phong: " << danhSachHoaDon[i].maPhong << endl;
            cout << "Thang/Nam: " << danhSachHoaDon[i].thang
                 << "/" << danhSachHoaDon[i].nam << endl;
            cout << "Tong tien: " << danhSachHoaDon[i].tongTien << " VND" << endl;

            if(danhSachHoaDon[i].daThanhToan)
                cout << "Trang thai: Da thanh toan\n";
            else
                cout << "Trang thai: Chua thanh toan\n";

            return;
        }
    }

    cout << "Khong tim thay hoa don!\n";
}

// ================= SAP XEP =================

void sapxepMenu()
{
    int luaChon;

    do
    {
        cout << "\n============= SAP XEP =============\n";
        cout << "1. Sap xep phong theo gia\n";
        cout << "2. Sap xep hoa don theo tong tien\n";
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
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);
}

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

    if(kieu == 0)
        return;

    // insertion sort
    for(int i = 1; i < (int)danhSachPhong.size(); i++)
    {
        Phong x = danhSachPhong[i];
        int j = i - 1;

        if(kieu == 1)
        {
            while(j >= 0 && danhSachPhong[j].giaPhong > x.giaPhong)
            {
                danhSachPhong[j + 1] = danhSachPhong[j];
                j--;
            }
        }
        else if(kieu == 2)
        {
            while(j >= 0 && danhSachPhong[j].giaPhong < x.giaPhong)
            {
                danhSachPhong[j + 1] = danhSachPhong[j];
                j--;
            }
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
            return;
        }

        danhSachPhong[j + 1] = x;
    }

    luuDuLieu();
    cout << "\nDa sap xep phong thanh cong!\n";
    hienThiPhong();
}

void sapXepHoaDon()
{
    if(danhSachHoaDon.empty())
    {
        cout << "Danh sach hoa don dang rong!\n";
        return;
    }

    int kieu;
    cout << "\n1. Tong tien tang dan\n";
    cout << "2. Tong tien giam dan\n";
    cout << "0. Huy\n";
    cout << "Nhap lua chon: ";
    kieu = nhapSoNguyen();

    if(kieu == 0)
        return;

    // insertion sort
    for(int i = 1; i < (int)danhSachHoaDon.size(); i++)
    {
        HoaDon x = danhSachHoaDon[i];
        int j = i - 1;

        if(kieu == 1)
        {
            while(j >= 0 && danhSachHoaDon[j].tongTien > x.tongTien)
            {
                danhSachHoaDon[j + 1] = danhSachHoaDon[j];
                j--;
            }
        }
        else if(kieu == 2)
        {
            while(j >= 0 && danhSachHoaDon[j].tongTien < x.tongTien)
            {
                danhSachHoaDon[j + 1] = danhSachHoaDon[j];
                j--;
            }
        }
        else
        {
            cout << "Lua chon khong hop le!\n";
            return;
        }

        danhSachHoaDon[j + 1] = x;
    }

    luuDuLieu();
    cout << "\nDa sap xep hoa don thanh cong!\n";
    hienThiHoaDon();
}

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

void thongKeNguoiThue()
{
    cout << "\n======== THONG KE NGUOI THUE ========\n";
    cout << "Tong so nguoi dang thue: "
         << danhSachNguoiThue.size() << endl;
    cout << "=====================================\n";
}

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

int main()
{
    int luaChon;

    // hien thi tien day du (2000000 thay vi 2e+06)
    cout << fixed << setprecision(0);

    // doc du lieu da luu tu lan chay truoc
    docDuLieu();

    do
    {
        cout << "\n========================================\n";
        cout << "       QUAN LY DAY NHA TRO\n";
        cout << "========================================\n";
        cout << "1. Quan ly phong\n";
        cout << "2. Quan ly nguoi thue\n";
        cout << "3. Quan ly hoa don\n";
        cout << "4. Tim kiem\n";
        cout << "5. Sap xep\n";
        cout << "6. Thong ke\n";
        cout << "0. Thoat\n";
        cout << "========================================\n";
        cout << "Nhap lua chon: ";
        luaChon = nhapSoNguyen();

        switch(luaChon)
        {
            case 1:
                phongMenu();
                break;
            case 2:
                ngthueMenu();
                break;
            case 3:
                hoadon();
                break;
            case 4:
                searchMenu();
                break;
            case 5:
                sapxepMenu();
                break;
            case 6:
                thongkeMenu();
                break;
            case 0:
                cout << "Da thoat chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }while(luaChon != 0);

    return 0;
}
