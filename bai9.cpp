#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class DonHang {
    protected:
    string MaDon;
    long long TienHang;
    public:
    DonHang(string madon, long long tienhang) : MaDon(madon) , TienHang(tienhang) {};
virtual ~DonHang(){}
virtual DonHang& XacNhan(){
    cout << "Don hang "<< MaDon << " da duoc he thong xac nhan." << endl;
    return *this;
}
virtual DonHang& TinhTien(){
    cout <<"Dang tinh toan chi phi..." << endl;
    return *this;
}
virtual DonHang& HienThi(){
    cout << MaDon<<endl;
    cout << TienHang << endl;
    return *this;
}
};
class DonTieuChuan : public DonHang {
    private :
    long long PhiShip;
    public:
    DonTieuChuan(string madon, long long tienhang, long long phiship = 30000) : DonHang(madon, tienhang) , PhiShip(phiship) {};
DonTieuChuan& TinhTien() override {
    int TongTien;
    TongTien = TienHang + PhiShip;
    cout << "Giao TIEU CHUAN (3-5 ngay). Tong thu: "<<TongTien<<" VND."<<endl;
    return *this;
}
DonTieuChuan& HienThi() override{
    DonHang :: HienThi();
    cout << "Phuong thuc: Tieu Chuan"<<endl;
    return *this;
}
};
class DonHoaToc : public DonHang {
    private :
    int KhoangCach;
    public:
    DonHoaToc(string madon, long long tienhang, int khoangcach ) : DonHang (madon, tienhang) , KhoangCach(khoangcach) {};
DonHoaToc& TinhTien() override {
    long long PhiShip;
    long long TongTien;
    PhiShip = KhoangCach * 15000;
    TongTien = TienHang + PhiShip ;
    cout << "Giao HOA TOC ("<<KhoangCach<< "km). Tong thu: "<<TongTien<<" VND."<<endl;
    return *this;
}
DonHoaToc& HienThi(){
    DonHang :: HienThi();
    cout << "Phuong thuc: Hoa Toc"<<endl;
    return *this;
}

};
int main() {
    // // 1. Tạo mảng chứa 3 con trỏ Đơn Hàng
    // DonHang* HeThong[3]; 

    // // 2. Cấp phát động: Khách hàng lên Web đặt 3 đơn hàng
    // HeThong[0] = new DonTieuChuan("DH_001", 150000);             // Mua áo thun 150k, ship thường
    // HeThong[1] = new DonHoaToc("DH_002", 500000, 5);             // Mua giày 500k, ship hỏa tốc 5km
    // HeThong[2] = new DonTieuChuan("DH_003", 80000);              // Mua ốp lưng 80k, ship thường

    // cout << "===== HE THONG BAT DAU XU LY DON HANG =====\n" << endl;

    // // 3. Vòng lặp Backend xử lý hàng loạt bằng Method Chaining
    // for (int i = 0; i < 3; i++) {
    //     // Con trỏ -> Xác nhận -> Tính tiền -> Hiển thị
    //     HeThong[i]->XacNhan().TinhTien().HienThi();
    //     cout << "-----------------------------------" << endl;
    // }

    // cout << "\n===== CUOI NGAY: DON DEP SERVER =====\n" << endl;

    // // 4. Giải phóng bộ nhớ (Kích hoạt Virtual Destructor)
    // for (int i = 0; i < 3; i++) {
    //     delete HeThong[i];
    // }
    DonHang* HeThong[3];
    HeThong[0] = new DonTieuChuan ("Ao", 50000) ;
    HeThong[1] = new DonHoaToc ("Quan", 100000, 5) ;
    HeThong[2] = new DonTieuChuan ("Giay" , 200000);
    cout << "--------Xu Ly---------"<<endl; 
    for (int i = 0; i < 3; i++){
        HeThong[i]->XacNhan().TinhTien().HienThi();
        cout <<"------------------------"<<endl;
    }
    for (int i = 0; i<3 ; i++){
    delete HeThong[i];
    }
    return 0;
}