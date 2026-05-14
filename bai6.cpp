#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class TaiKhoan{
    protected:
    string ChuTaiKhoan;
    long long SoDu;
    bool BiKhoa;

    public:
    TaiKhoan(string ten,long long sodu) : ChuTaiKhoan(ten), SoDu(sodu) {
        BiKhoa = false ;
    };
TaiKhoan& NapTien(long long tien){
    SoDu+=tien;
    cout<<"+"<<tien<<"VND. Giao dich thanh cong! "<<endl;
    return *this;
}
TaiKhoan& KhoaThe(){
    BiKhoa = true;
    cout <<"Tai khoan cua " <<ChuTaiKhoan <<" bi KHOA!"<<endl;
    return *this;

}
virtual TaiKhoan& InSaoKe(){
    cout << ChuTaiKhoan <<endl;
    cout << SoDu << endl;
    if(!BiKhoa)
    cout <<"Hoạt động"<<endl;
    else 
    cout <<"Bị khóa"<<endl;
    return *this;
}
};
class ViDienTu : public TaiKhoan{
    private:
    int DiemThuong;
    public:
    ViDienTu(string name, long long sodu, int diem= 0) : TaiKhoan(name, sodu), DiemThuong(diem) {};
ViDienTu& ThanhToan(long long tien){
    if(!BiKhoa){
        if(SoDu > tien){
            SoDu-=tien;
            DiemThuong += tien/1000;
            cout << "Thanh toan "<<tien<<" VND thanh cong!. Tich luy duoc "<<DiemThuong<<"."<<endl;
        }
        else 
        cout <<"So du khong du de thanh toan!"<<endl;
    }
    else
    cout <<"Giao dich that bai vi tai khoan da bi KHOA!"<<endl;
    return *this;
}
ViDienTu& KhoaThe(){
    TaiKhoan::KhoaThe();
    return *this;
}
//hàm của hàm cha
ViDienTu& NapTien(long long tien){
    TaiKhoan :: NapTien(tien);
    return *this;
}

ViDienTu& InSaoKe() override {
    TaiKhoan::InSaoKe();
    cout<<"Diem thuong: "<<DiemThuong<<endl;
    return *this;
}
};
class TaiKhoanTietKiem : public TaiKhoan{
    private:
    float LaiSuat;
    public:
    TaiKhoanTietKiem(string name, long long sodu,float laisuat ) : TaiKhoan(name, sodu), LaiSuat(laisuat) {};
TaiKhoanTietKiem& CongLaiThang(){
    if(!BiKhoa){
        float tienlai;
        tienlai = SoDu * LaiSuat ;
        SoDu += tienlai;
        cout <<"Da cong "<<tienlai<<" VND tien lai vao tai khoan."<<endl;
    }
    else
    cout << "Tai khoan dang bi khoa, khong the sinh lai!"<<endl;
    return *this;
}
TaiKhoanTietKiem& KhoaThe(){

    TaiKhoan::KhoaThe();
    return *this;

}
TaiKhoanTietKiem& NapTien(long long tien){
    TaiKhoan :: NapTien(tien);
    return *this;
}
TaiKhoanTietKiem& InSaoKe() override{
    TaiKhoan ::InSaoKe();
    cout <<"Lai suat hien tai: "<<LaiSuat*100<<"% / thang"<<endl;
    return *this;
}

};
int main() {
    // 1. Tạo Ví Điện Tử
    ViDienTu Momo("Nguyen Van A", 500000); // 500k VNĐ
    
    // Nạp thêm 200k -> Thanh toán 300k (Thành công, tích điểm) -> Thanh toán tiếp 1 triệu (Thất bại do thiếu tiền) -> In sao kê
    Momo.NapTien(200000).ThanhToan(300000).ThanhToan(1000000).InSaoKe();

    cout << "\n----------------------------------\n" << endl;

    // 2. Tạo Tài Khoản Tiết Kiệm (Gửi 10 triệu, lãi suất 5%/tháng)
    TaiKhoanTietKiem VCB("Le Thi B", 10000000, 0.05);

    // Cộng lãi tháng 1 -> Khóa thẻ -> Thử cộng lãi tháng 2 (Thất bại) -> In sao kê
    VCB.CongLaiThang().KhoaThe().CongLaiThang().InSaoKe();

    return 0;
}