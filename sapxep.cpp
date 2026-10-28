#include "QuanLyPhongTro.h"

// ================= SAP XEP =================

// a dung truoc b ma sai thu tu thi tra ve true
bool saiThuTu(double a, double b, bool tangDan)
{
    if(tangDan)
        return a > b;
    return a < b;
}

// insertion sort: lay tung phong chen vao dung vi tri trong doan da sap xep
// soSoSanh, soDiChuyen de dem so buoc, dung de so sanh 2 thuat toan
void insertionSortPhong(bool tangDan, int &soSoSanh, int &soDiChuyen)
{
    for(int i = 1; i < (int)danhSachPhong.size(); i++)
    {
        Phong x = danhSachPhong[i];
        int j = i - 1;

        while(j >= 0)
        {
            soSoSanh++;
            if(!saiThuTu(danhSachPhong[j].giaPhong, x.giaPhong, tangDan))
                break;

            danhSachPhong[j + 1] = danhSachPhong[j];
            soDiChuyen++;
            j--;
        }

        danhSachPhong[j + 1] = x;
    }
}

// selection sort: moi luot tim phong re nhat (hoac dat nhat) dua len dau
void selectionSortPhong(bool tangDan, int &soSoSanh, int &soDiChuyen)
{
    int n = danhSachPhong.size();

    for(int i = 0; i < n - 1; i++)
    {
        int viTri = i;

        for(int j = i + 1; j < n; j++)
        {
            soSoSanh++;
            if(saiThuTu(danhSachPhong[viTri].giaPhong, danhSachPhong[j].giaPhong, tangDan))
                viTri = j;
        }

        if(viTri != i)
        {
            Phong tam = danhSachPhong[i];
            danhSachPhong[i] = danhSachPhong[viTri];
            danhSachPhong[viTri] = tam;
            soDiChuyen++;
        }
    }
}
