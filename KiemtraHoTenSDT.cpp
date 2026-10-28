// ho ten khong duoc de trong va khong chua dau '|' 
bool kiemTraHoTen(string ten)
{
    if(ten == "")
        return false;

    for(int i = 0; i < (int)ten.size(); i++)
    {
        if(ten[i] == '|')
            return false;
    }

    return true;
}

// so dien thoai phai co 10 chu so va bat dau bang so 0
bool kiemTraSoDienThoai(string sdt)
{
    if(sdt.size() != 10 || sdt[0] != '0')
        return false;

    for(int i = 0; i < (int)sdt.size(); i++)
    {
        if(sdt[i] < '0' || sdt[i] > '9')
            return false;
    }

    return true;
}
