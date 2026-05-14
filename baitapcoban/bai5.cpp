#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class ThietBi {
    protected:
    string Ten;
    int Pin;
    bool TrangThai ;
    public:
    ThietBi (string name, int pin = 100): Ten(name) ,Pin(pin) {
        TrangThai = false ;   
    };
    ThietBi& Bat(){
        TrangThai = true ;
        cout <<Ten <<" da duoc BAT"<<endl;
    return *this;
}
    ThietBi& Tat(){
        TrangThai = false ;
        cout <<Ten <<" da duoc TAT"<<endl;
    return *this;
    }
virtual ThietBi& HienThi() {
    cout << Ten <<endl;
    cout << Pin << endl;
    if (TrangThai) 
    cout << "ON" <<endl;
    else 
    cout << "OFF" <<endl;
    return *this;
}
};
class RobotHutBui : public ThietBi {
    private:
    int ThungRac;
    public:
    RobotHutBui(string ten,int pin = 100,int rac=0) :ThietBi(ten, pin), ThungRac(rac) {};
RobotHutBui& DonNha(){
    if (TrangThai){
        if ( Pin >= 15){
            cout <<"Dang don nha "<<endl;
            Pin-= 15;
            ThungRac+= 20;
        }
        else
        cout << "Pin yeu, can cam sac!"<<endl;
    }
    else
    cout << "Loi: may dang TAT, ko the don nha "<<endl;
    return *this;
}
RobotHutBui& Bat(){
    ThietBi::Bat();
    return *this;
}
RobotHutBui& Tat(){
    ThietBi::Tat();
    return *this;
}
RobotHutBui& HienThi() override{
    ThietBi::HienThi();
    cout <<"Thung rac hien tai: "<<ThungRac<<"%"<<endl;
    return *this;
}
};
class Laptop : public ThietBi {
    private:
    bool CodeMode;
    public:
    Laptop(string name, int pin = 100) : ThietBi(name, pin){
        TrangThai = false;
        CodeMode = false ;
    }
Laptop& CodeCplusplus(){
    if (TrangThai){
        CodeMode = true;
        Pin -=20;
        cout << "Dang code C++ nhieu bug qua"<<endl;
    }
    else 
    cout <<"Laptop chua mo"<< endl;
    return *this;
}
Laptop& Bat(){
    ThietBi::Bat();
    return *this;
}
Laptop& Tat(){
    ThietBi::Tat();
    return *this;
}
Laptop& HienThi() override{
    ThietBi::HienThi();
    if(CodeMode)
    cout << "Ung dung dang chay VSCode"<<endl;
    else
    cout <<"Ung dung: Man hinh chinh "<< endl;
    return *this;
}
};



int main(){

    // 1. Tạo Robot
    RobotHutBui Xiaomi("Xiaomi Vacuum");
    // Thử dọn nhà lúc chưa bật máy -> Bật máy -> Dọn nhà -> Xem thông tin
    Xiaomi.DonNha().Bat().DonNha().HienThi();
    
    cout << "--------------------" << endl;

    // 2. Tạo Laptop
    Laptop Dell("Dell XPS 15");
    // Bật máy -> Code C++ -> Xem thông tin -> Tắt máy
    Dell.Bat().CodeCplusplus().HienThi().Tat();

    return 0;
}