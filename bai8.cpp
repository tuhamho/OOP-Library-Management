#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class MayChu{
    protected:
    string Ten;
    int Ram;
    int CPU;
    public:
    MayChu(string name, int ram, int cpu) : Ten(name) ,Ram(ram), CPU(cpu) {}; 
    virtual ~MayChu(){
    }
    virtual MayChu& BaoTri(){
    Ram+=8;
    cout <<Ten<<" duoc bao tri, lap them 8GB RAM."<<endl;
    return *this;
}
virtual MayChu& XuLyDuLieu(int dungluong){
    cout <<Ten<<" dang xu ly "<< dungluong<<" GB du lieu chung..."<<endl;
    return *this;
}
virtual MayChu& HienThi(){
    cout <<Ten<<endl;
    cout <<Ram<<endl;
    cout <<CPU<<endl;
    return *this;
}

};
class ServerWeb : public MayChu {
    private:
    int LuotTruyCap;
    public:
    ServerWeb(string name, int ram, int cpu,int luottruycap = 0) : MayChu(name, ram, cpu), LuotTruyCap(luottruycap) {};
ServerWeb& XuLyDuLieu(int dungluong) override{
    if (Ram >= dungluong){
        Ram-=dungluong;
        LuotTruyCap+= dungluong* 500 ;
        cout << "Web Server hoat dong: Da phan hoi "<< LuotTruyCap <<" luot truy cap HTTP!"<<endl;
    }
    else 
    cout << "Loi 500: Server Web tran RAM, sap he thong!"<<endl;
    return *this;
}
ServerWeb& HienThi() override {
    MayChu :: HienThi();
    cout << "Tong luot truy cap: "<< LuotTruyCap<<endl;
    return *this;
}
};
class ServerDatabase : public MayChu {
    private :
    int SoBanGhi;
    public:
    ServerDatabase(string name , int ram , int cpu, int sobanghi= 0 ) : MayChu(name, ram, cpu) , SoBanGhi(sobanghi) {};
ServerDatabase& XuLyDuLieu(int dungluong) override {
    if(CPU >= dungluong) {
        CPU-= dungluong;
        SoBanGhi+= dungluong*1000;
        cout << "Database hoat dong: Da luu thanh cong "<<SoBanGhi<<" ban ghi vao CSDL SQL!"<<endl;
    }
    else
    cout << "Loi: Qua tai CPU, Database nghen co chai (Bottleneck)!"<<endl;
    return *this; 
}
ServerDatabase& HienThi() override{
    MayChu :: HienThi();
    cout << "Tong so ban ghi SQL: "<<SoBanGhi<<endl;
    return *this;
}
};

int main() {
    // 1. Tạo mảng chứa 2 con trỏ của Lớp cha
    MayChu* DataCenter[2]; 
    
    // 2. Dùng 'new' để cấp phát động, mua 2 cái server thật đặt vào RAM
    DataCenter[0] = new ServerWeb("Nginx_Frontend", 8, 16);    // Web: RAM 8, CPU 16
    DataCenter[1] = new ServerDatabase("MySQL_Backend", 32, 4); // DB: RAM 32, CPU 4

    cout << "===== HET THONG DATA CENTER BAT DAU CHAY =====\n" << endl;

    // 3. Duyệt mảng và ra lệnh đồng loạt (Method Chaining kết hợp Con trỏ)
    for (int i = 0; i < 2; i++) {
        // Con trỏ -> BaoTri() -> XuLyDuLieu(10) -> HienThi()
        // Đẩy 10 GB công việc vào cho từng Server
        DataCenter[i]->BaoTri().XuLyDuLieu(10).HienThi(); 
        cout << "---------------------------------" << endl;
    }

    // 4. CỰC KỲ QUAN TRỌNG: Giải phóng bộ nhớ (Chống Memory Leak)
    for (int i = 0; i < 2; i++) {
        delete DataCenter[i]; 
    }

    return 0;
}