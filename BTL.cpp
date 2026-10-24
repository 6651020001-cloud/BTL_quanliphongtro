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

int main()
{
    // menu chính
}

