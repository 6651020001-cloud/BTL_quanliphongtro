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
