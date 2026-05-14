#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ThietBi {
    protected:
    string MaTB;
    string TenTB;
    long long GiaTien;
    public:
    ThietBi(string matb, string tentb, long long giatien) : MaTB(matb) , TenTB(tentb), GiaTien(giatien){};
virtual ~ThietBi(){
}    
virtual ThietBi& KiemTra(){
    cout << "Dang kiem tra trang thai thiet bi"<<endl;
    return *this;
}
virtual ThietBi& HienThi(){
    cout << MaTB<<endl;
    cout << TenTB << endl;
    cout << GiaTien <<endl;
    return *this;
}
};
class MayChuTest : public ThietBi {
    private :
    int SoCoreCPU;
    public:
    MayChuTest(string matb, string tentb, long long giatien, int socore) : ThietBi(matb, tentb, giatien) , SoCoreCPU(socore) {};
MayChuTest& KiemTra() override {
    cout << "Server "<<TenTB<<": Dang chay mo phong xac minh thiet ke (Design Verification) voi "<<SoCoreCPU<<" cores. Nhan nhiet do 85 do C!"<<endl;
    return *this;
}
MayChuTest& HienThi() override{
    ThietBi:: HienThi();
    cout << "Loai: Server - "<<SoCoreCPU<<" Cores"<<endl;
    return  *this;
}
};
class BoMachFPGA : public ThietBi{
    private :
    string ChipGiaoTiep;
    public:
    BoMachFPGA(string matb, string tentb, long long giatien, string chipgt) : ThietBi(matb, tentb, giatien), ChipGiaoTiep(chipgt) {};
BoMachFPGA& KiemTra() override{
    cout <<"Bo mach "<<TenTB<<": Dang nap code mo phong mach logic (Kiem tra cong XNOR). Tin hieu on dinh!"<<endl;
    return *this;
}
BoMachFPGA& HienThi() override{
    ThietBi::HienThi();
    cout <<"Loai: Bo mach FPGA - Chip: "<<ChipGiaoTiep<<endl;
    return *this;
}
};
int main() {
    ThietBi* Lab[100];
     int soluong = 0;
     bool trangthai = true;
     int luachon;
     while ( trangthai){
        cout <<"===== HE THONG QUAN LY LAB VI MACH ====="<<endl;
        cout <<"1.Nhap them May Chu Test (Server)"<<endl;
        cout <<"2.Nhap them Bo Mach FPGA"<<endl;
        cout <<"3.Hien thi toan bo thiet bi trong Lab"<<endl;
        cout <<"4.Chay kiem tra dong loat (Test run)"<<endl;
        cout <<"5.Dong cua Lab (Thoat chuong trinh)"<<endl;
        cout <<"Chon chuc nang(1-5): "<<endl;
        cin >> luachon;
        cin.ignore();
        switch(luachon){
            case 1: {
                cout <<"----NHAP THONG TIN MAY CHU TEST-----"<<endl;
                string ma, ten;
                long long gia;
                int core;
                cout << "Nhap ma thiet bi: "<<endl;
                getline(cin, ma);
                cout << "Nhap ten thiet bi: "<<endl;
                getline(cin, ten);
                cout <<"Nhap Gia tien (VND): "<<endl;
                cin>> gia;
                cin.ignore();
                cout <<"Nhap so core: "<<endl;
                cin >> core;
                cin.ignore();
                Lab[soluong] = new MayChuTest(ma, ten, gia, core);
                soluong++;
                cout <<"Thong tin may chu TEST da them thanh cong"<<endl;
            break;
            }
            case 2: {
                cout <<"----NHAP THONG TIN BO MACH FPGA-----"<<endl;
                string ma, ten;
                long long gia;
                string tenchipgt;
                cout << "Nhap ma thiet bi: "<<endl;
                getline(cin, ma);
                cout << "Nhap ten thiet bi: "<<endl;
                getline(cin, ten);
                cout <<"Nhap Gia tien (VND): "<<endl;
                cin>> gia;
                cin.ignore();
                cout <<"Nhap ten chip giao tiep: "<<endl;
                getline(cin, tenchipgt);
                Lab[soluong] = new BoMachFPGA(ma, ten, gia, tenchipgt);
                soluong++;
                cout <<"Thong tin bo mach FPGA da them thanh cong"<<endl;
                break;
            }
            case 3:{
            for (int i=0; i< soluong; i++){
                Lab[i]->HienThi();
                cout <<"-----------------------"<<endl;
                }
                break;
            }
            case 4: {
                for (int i=0; i< soluong; i++){
                Lab[i]->KiemTra();
                cout <<"-----------------------"<<endl;
                }
                break;
            }
            case 5: {
                for (int i=0; i< soluong; i++){
                delete Lab[i];}
                cout <<"Da don dep chuong trinh."<<endl;
                trangthai = false;
                break;
                }
            }
        }
   
    
    return 0;
}