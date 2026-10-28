// nhom 15
// thanh vien: Nguyen Van Ban 6651020001
//             Huynh Gia Bao  6651020002
//             Phan Cong Binh 6651020003
//             Luong Anh Dung 6651020006
//             Tran Phat Dat  6651020016
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

// ================= KHAI BAO HAM =================

void xoaLoiNhap();
int nhapSoNguyen();
double nhapSoTien();
void luuDuLieu();
void docDuLieu();

void phongMenu();
void themPhong();
void xoaPhong();
void hienThiPhong();
void suaPhong();

void ngthueMenu();
void themNguoiThue();
void xoaNguoiThue();
void hienThiNguoiThue();
void suaNguoiThue();
int demSoNguoiTrongPhong(string maPhong);
string nhapDong();
bool kiemTraHoTen(string ten);
bool kiemTraSoDienThoai(string sdt);

void hoadon();
void hienThiHoaDon();
void xuatHoaDon();
void capNhatThanhToan();

void searchMenu();
void timPhong();
void timNguoiThue();
void timHoaDon();

void thongkeMenu();
void thongKePhong();
void thongKeNguoiThue();
void thongKeHoaDon();
void thongKeChuaThanhToan();

void sapxepMenu();
void sapXepPhong();
void sapXepHoaDon();
void sapXepHoaDonTheoThang();
void sapXepNguoiThue();

int main()
{
    // menu chính
}

