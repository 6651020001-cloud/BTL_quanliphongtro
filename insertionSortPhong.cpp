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
