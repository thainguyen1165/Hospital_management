# Hospital_management
Hệ thống Điều phối Khám bệnh và Quản lý Hàng đợi Ưu tiên (Hospital Queue Management System)
1. Tổng quan Dự án
Hệ thống Quản lý Bệnh viện Đa khoa được phát triển thuần túy trên ngôn ngữ lập trình C nhằm giải quyết bài toán quá tải tại các cơ sở y tế. Thay vì vận hành theo nguyên tắc Đến trước - Khám trước (FCFS) truyền thống dễ gây nguy hiểm cho các ca bệnh nặng, hệ thống sử dụng Hàng đợi ưu tiên (Priority Queue) để tự động điều phối bệnh nhân dựa trên tình trạng sức khỏe thực tế.

2. Kiến trúc Hệ thống & Cấu trúc Dữ liệu Cốt lõi
Hệ thống được tổ chức theo tư duy cấu trúc dữ liệu và giải thuật tối ưu nhằm cô lập luồng dữ liệu và quản lý bộ nhớ RAM an toàn

Mảng động (Dynamic Array): Dùng để lưu trữ tập trung danh sách hồ sơ gốc (Patient), danh sách bác sĩ trực (Doctor), và danh sách các khoa (Department)Cho phép tự động co giãn kích thước (realloc) linh hoạt Hàng đợi đống cực đại (Max-Heap): Được nhúng trực tiếp vào từng cấu trúc của mỗi khoa lâm sàng, quản lý danh sách các phiên chờ (PatientInQueue). Đảm bảo các thao tác thêm bệnh nhân mới hoặc trích xuất ca bệnh nguy kịch nhất luôn đạt độ phức tạp tối ưu. Liên kết mạng lưới con trỏ logic: Hàng đợi Max-Heap chỉ lưu trữ các con trỏ tham chiếu ngược về hồ sơ gốc (struct Patient* root_record). Giải pháp này giúp loại bỏ việc sao chép dữ liệu thừa, tiết kiệm bộ nhớ và tránh lỗi trỏ sai vùng nhớ khi mảng động bị dịch chuyển vị trí vật lý trong RAM do realloc.
