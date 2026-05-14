#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class XeHoi{
    protected:
    string TenXe;
    int CSpeed;
    public:
    XeHoi (string name, int crspeed=0) : TenXe(name) , CSpeed(crspeed) {} ;
void dapga(int cs){
    CSpeed = cs;
}
void dapphang(){
    CSpeed = 0;
    cout << "Xe da dung";
}
virtual void thongtin(){
    cout << "Ten xe: "<<TenXe<<endl;
    cout << "Toc do:"<< CSpeed<<endl ;
}
// getter để lấy thuộc tính của lớp cha ( khi các thuộc tinh đó bảo mật )
//  int GetSpeed()const{
//      return CSpeed;
//  }
//  string GetTen()const{
//      return TenXe;
//  }

};
class XeDien : public XeHoi {
    private:
    int phantrampin;
    public:
    XeDien(string name,int crspeed,int pin) : XeHoi(name, crspeed), phantrampin(pin){};
void sacpin(int spin){
    phantrampin += spin;
    if (phantrampin > 100){
        phantrampin = 100;
    }
}
void sportmode(){
    if (phantrampin >= 20){
        phantrampin -= 20;
        dapga(200);
    }
    else 
    cout <<" KO DU PIN"<<endl;
}
void thongtin() override {
    cout << "Ten xe: "<<TenXe<<endl;
    cout << "Toc do:"<< CSpeed<<endl ;
    cout << "Phan tram pin:" << phantrampin<<endl;
};
};
int main(){
    XeHoi Xe1("CAMRY");
    Xe1.dapga(100);
    Xe1.thongtin();
    XeDien Xe("Tesla",0,80);
    Xe.sacpin(132193213);
    Xe.sportmode();
    Xe.thongtin();
    return 0;
}