# Hệ thống Quản lý Phòng trọ

Bài tập lớn môn **Cấu trúc dữ liệu và Giải thuật** – Nhóm 15  
Giảng viên hướng dẫn: ThS. Trần Thị Dung  
Lớp: CQ.66.KTĐTVT – Khóa 66

## Mô tả đề tài

### Bài toán

Ở các khu nhà trọ nhỏ, chủ trọ người lớn tuổi hoặc người hay quên thường quản lý bằng sổ tay hoặc bảng tính. Mỗi cuối tháng phải ghi chỉ số công tơ điện, nước của từng phòng, tự nhân với đơn giá, cộng tiền phòng rồi đi thu, nên dễ tính sai, khó theo dõi phòng nào còn nợ và dễ mất dữ liệu.

Đề tài xây dựng một chương trình console bằng C++ giúp **một chủ trọ** quản lý **một khu trọ** với ba nhóm đối tượng:

- **Phòng:** mã phòng, giá thuê, trạng thái trống/đã thuê (tự cập nhật theo số người ở).
- **Người thuê:** mã, họ tên, số điện thoại, phòng đang ở; mỗi phòng tối đa 4 người.
- **Hóa đơn tháng:** tiền phòng, tiền điện, tiền nước (tính tự động từ chỉ số công tơ), khoản khác, tổng tiền và trạng thái thanh toán; mỗi phòng mỗi tháng có tối đa một hóa đơn.

### Mục tiêu

- Tự động tính tiền hóa đơn, giảm sai sót khi tính tay.
- Giữ dữ liệu nhất quán: không xóa được phòng còn người ở hoặc còn nợ, không thêm quá số người cho phép, không lập hóa đơn trùng tháng hay cho phòng trống.
- Trả lời nhanh các câu hỏi quản lý: phòng nào trống, phòng nào còn nợ, doanh thu đã thu bao nhiêu.
- Lưu dữ liệu xuống tệp để lần sau mở lại vẫn còn.
- Vận dụng các nội dung của môn học: danh sách tuyến tính bằng mảng động, tìm kiếm tuần tự, sắp xếp chèn và sắp xếp chọn, phân tích độ phức tạp.

### Phạm vi

Ứng dụng console chạy trên một máy tính, một người dùng. Chưa bao gồm hợp đồng, tiền cọc, nhiều khu trọ, thanh toán trực tuyến hay giao diện đồ họa.

## Thành viên và phân công

| Vai trò | Họ tên | MSSV | Phụ trách | Tệp |
|---|---|---|---|---|
| Người 1 | Lương Anh Dũng | 6651020006 | Quản lý phòng | `phong.cpp` |
| Người 2 | Nguyễn Văn Bản | 6651020001 | Quản lý người thuê | `nguoithue.cpp` |
| Người 3 | Trần Phát Đạt | 6651020016 | Quản lý hóa đơn | `hoadon.cpp` |
| Người 4 | Huỳnh Gia Bảo | 6651020002 | Tìm kiếm và thống kê | `timkiem_thongke.cpp` |
| Người 5 | Phan Công Bình | 6651020003 | Sắp xếp, phân tích giải thuật | `sapxep.cpp` |
| Chung | Cả nhóm | | Khung chương trình, lưu/đọc tệp | `QuanLyPhongTro.h`, `main.cpp` |

## Chức năng chính

| Menu | Chức năng |
|---|---|
| 1. Quản lý phòng | Thêm, xóa (chặn khi còn người ở hoặc còn nợ), sửa giá, hiển thị kèm số người đang ở |
| 2. Quản lý người thuê | Thêm (tối đa 4 người/phòng), xóa, sửa họ tên/số điện thoại, hiển thị |
| 3. Quản lý hóa đơn | Xuất hóa đơn tháng (tiền điện 3.500 đ/kWh, nước 20.000 đ/m³ tính theo chỉ số), hiển thị, cập nhật thanh toán |
| 4. Tìm kiếm | Tìm phòng, người thuê, hóa đơn theo mã |
| 5. Sắp xếp | Phòng theo giá (chọn Insertion hoặc Selection Sort), hóa đơn theo tổng tiền, hóa đơn theo tháng/năm, người thuê theo mã phòng |
| 6. Thống kê | Phòng trống/đã thuê, số người thuê, doanh thu và tiền nợ, danh sách hóa đơn chưa thanh toán |

Mọi dữ liệu nhập đều được kiểm tra: nhập chữ vào chỗ cần số, số âm, tháng ngoài 1–12, chỉ số công tơ mới nhỏ hơn cũ, họ tên rỗng, số điện thoại không đủ 10 chữ số đều bị yêu cầu nhập lại.

## Cấu trúc dữ liệu và giải thuật

- Danh sách tuyến tính bằng mảng động `std::vector` cho 3 thực thể: `Phong`, `NguoiThue`, `HoaDon`, liên kết với nhau qua mã phòng.
- Tìm kiếm tuần tự theo mã.
- Sắp xếp chèn (Insertion Sort) và sắp xếp chọn (Selection Sort), có đếm số lần so sánh và di chuyển.
- Thống kê một lượt duyệt: phòng trống/đã thuê, số người thuê, doanh thu, hóa đơn chưa thanh toán.
- Lưu trữ bền vững bằng 3 tệp `phong.txt`, `nguoithue.txt`, `hoadon.txt`, các trường ngăn cách bởi ký tự `|`.

## Tệp nguồn

| Tệp | Nội dung |
|---|---|
| `QuanLyPhongTro.h` | Khai báo struct, danh sách dùng chung và nguyên mẫu hàm |
| `main.cpp` | Danh sách dữ liệu, nhập số an toàn, lưu/đọc tệp, hàm `main` |
| `phong.cpp`, `nguoithue.cpp`, `hoadon.cpp`, `timkiem_thongke.cpp`, `sapxep.cpp` | Phần của từng thành viên |
| `QuanLyPhongTro_gop.cpp` | Bản gộp toàn bộ code vào một tệp (chỉ để tham khảo, không dùng khi build project) |
| `QuanLyPhongTro.dev` | Project Dev-C++ |
| `.vscode/` | Cấu hình build và chạy cho Visual Studio Code |

## Biên dịch và chạy

Mã nguồn tương thích chuẩn C++98.

**Dev-C++ 5.11:** mở `QuanLyPhongTro.dev`, nhấn F11.

**Visual Studio Code:** mở thư mục này, nhấn F5 (chọn cấu hình "Chay QuanLyPhongTro").

**Dòng lệnh:**

```bash
g++ main.cpp phong.cpp nguoithue.cpp hoadon.cpp timkiem_thongke.cpp sapxep.cpp -o QuanLyPhongTro.exe
```

Dữ liệu được tự động lưu sau mỗi thao tác vào 3 tệp `.txt` trong thư mục chạy chương trình. Xóa 3 tệp này để bắt đầu lại với dữ liệu trống.

## Hướng dẫn sử dụng nhanh

1. Thêm phòng: menu `1` → `1`, nhập mã phòng và giá.
2. Thêm người thuê: menu `2` → `1`, nhập mã người thuê, mã phòng, họ tên, số điện thoại.
3. Cuối tháng lập hóa đơn: menu `3` → `2`, nhập mã hóa đơn, mã phòng, tháng/năm, chỉ số điện nước cũ và mới, tiền khác.
4. Thu tiền: menu `3` → `3`, nhập mã hóa đơn và xác nhận.
5. Xem phòng nào còn nợ: menu `6` → `4`.

## Tổ chức nhánh Git

| Nhánh | Nội dung |
|---|---|
| `main` | Mã nguồn hoàn chỉnh sau khi gộp |
| `Dung` | Người 1 – quản lý phòng |
| `Ban` | Người 2 – quản lý người thuê |
| `PhatDat` | Người 3 – quản lý hóa đơn |
| `Bao` | Người 4 – tìm kiếm và thống kê |
| `Binh` | Người 5 – sắp xếp |

Mỗi thành viên phát triển trên nhánh riêng, sau đó tạo Pull Request để gộp vào `main`.
