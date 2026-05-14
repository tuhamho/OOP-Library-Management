#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class TauVuTru {
    protected:
    string Ten;
    int NhienLieu;

    public:
    TauVuTru(string name, int nhienlieu = 100 ) : Ten(name), NhienLieu(nhienlieu) {};
TauVuTru& Bay(int tieuhao){
        if(NhienLieu >=tieuhao){
            NhienLieu-=tieuhao;
            cout << Ten<<" dang bay qua cac vi sao. Tru "<<tieuhao<<" nhien lieu!"<<endl;
        }
        else
        cout << "Canh bao: Khong du nhien lieu de thuc hien buoc nhay anpha!"<<endl;
        return *this;
    }
virtual TauVuTru& HienThi(){
    cout<<Ten<<endl;
    cout<<"Nhien lieu hien tai: "<<NhienLieu <<endl;   
    return *this;
}
};
class TauChien : public TauVuTru {
    private:
    int TenLua;
    public:
    TauChien(string name, int nhienlieu= 100, int tenlua = 3) : TauVuTru(name, nhienlieu), TenLua(tenlua) {};
TauChien& KhaiHoa(){
    if (TenLua > 0  ){
        TenLua-=1;
        cout << "PEW PEW!!! Ban 1 ten lua photon! Doi phuong bay mau!"<<endl;
    }
    else 
    cout << "Het dan! Chuan bi dam truc dien!"<<endl;
    return *this;
}
TauChien& Bay(int tieuhao){
    TauVuTru :: Bay(tieuhao);
    return *this;
}
TauChien& HienThi() override {
    TauVuTru :: HienThi();
    cout << "Ten lua con lai: "<< TenLua<<endl;
    return *this;
}
};
class TauDoTham : public TauVuTru{
    private:
    bool TangHinh;
    public:
    TauDoTham(string name, int nhienlieu = 100) : TauVuTru(name, nhienlieu) {
        TangHinh = false;
    };
TauDoTham& KichHoatTangHinh(){
    if(NhienLieu >=30){
        NhienLieu-=30;
        TangHinh = true;
        cout << "SWOOSH... "<< Ten << " da bien mat khoi radar!"<<endl;
    
    }
    else 
    cout << "He thong loi: Nhien lieu qua thap de tang hinh!"<<endl;
    return *this;
}
TauDoTham& Bay(int tieuhao){
    TauVuTru :: Bay(tieuhao);
    return *this;
}
TauDoTham& HienThi() override{
    TauVuTru::HienThi();
    if (TangHinh)
    cout << "Trang thai: Dang tang hinh"<<endl;
    else 
    cout << "Trang thai: Dang hien hinh"<<endl;
    return *this;
}

};
int main() {
    // 1. Tạo một mảng chứa được 100 "chiếc remote" (Con trỏ)
    TauVuTru* HamDoi[100]; 
    int soLuong = 0; // Biến đếm số lượng tàu thực tế

    // 2. CẤP PHÁT ĐỘNG (Dùng từ khóa 'new')
    // Lệnh 'new' sẽ tạo ra một con tàu ở đâu đó trong RAM, rồi giao remote cho mảng giữ
    HamDoi[soLuong++] = new TauChien("X-Wing Alpha", 100, 5); // Tàu chiến 5 tên lửa
    HamDoi[soLuong++] = new TauDoTham("Falcon Recon");        // Tàu dò thám
    HamDoi[soLuong++] = new TauChien("X-Wing Beta", 100, 2);  // Tàu chiến 2 tên lửa

    cout << "===== LENH TONG TAN CONG CHO " << soLuong << " TAU =====\n" << endl;

    // 3. DUYỆT MẢNG VÀ RA LỆNH ĐỒNG LOẠT
    for (int i = 0; i < soLuong; i++) {
        /*
         LƯU Ý CÚ PHÁP CỰC KỲ QUAN TRỌNG:
         - Vì HamDoi[i] đang là Con trỏ, ta KHÔNG dùng dấu chấm (.) để gọi hàm đầu tiên, mà phải dùng mũi tên (->).
         - Tuy nhiên, vì hàm Bay() của bạn thiết kế trả về Tham chiếu (*this hay TauVuTru&), 
           nên ngay sau khi hàm Bay() chạy xong, nó ném ra cái Tàu thật, lúc đó ta lại quay về dùng dấu chấm (.) để nối chuỗi tiếp.
        */
        
        HamDoi[i]->Bay(15).HienThi(); 
        cout << "--------------------------" << endl;
    }

    // 4. THU DỌN CHIẾN TRƯỜNG (Chống rò rỉ bộ nhớ - Memory Leak)
    // Nếu dùng 'new' mà quên 'delete', RAM sẽ bị chiếm dụng vĩnh viễn. Giảng viên rất hay trừ điểm lỗi này.
    for (int i = 0; i < soLuong; i++) {
        delete HamDoi[i];
    }

    return 0;
}