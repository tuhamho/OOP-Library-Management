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
XeHoi& dapga(int cs){
    CSpeed = cs;
    return *this;
}
XeHoi& dapphanh(){
    CSpeed = 0;
    cout << "Xe da dung"<<endl;
    return *this;
}
virtual XeHoi& thongtin(){
    cout << "Ten xe: "<<TenXe<<endl;
    cout << "Toc do: "<< CSpeed<<endl ;
    return *this;
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
XeDien& sacpin(int spin){
    phantrampin += spin;
    if (phantrampin > 100){
        phantrampin = 100;
    }
    return *this;
}
XeDien& dapga(int cs){
    XeHoi::dapga(cs);
    return *this;
}
XeDien& dapphanh(){
    XeHoi::dapphanh();
    return *this;
}
XeDien& sportmode(){
    if (phantrampin >= 20){
        phantrampin -= 20;
        dapga(200);
    }
    else 
    cout <<" KO DU PIN"<<endl;
    return *this;
}
XeDien& thongtin() override {
    XeHoi::thongtin();
    cout << "Phan tram pin: " << phantrampin<<endl;
    return *this;
}
};
int main(){
    XeHoi Xe1("CAMRY");
    Xe1.dapga(100).thongtin();
    XeDien Xe("Tesla",0,80);
    Xe.sacpin(50).sportmode().dapphanh().thongtin();
    XeDien Porsche("Porsche Taycan",0,50);
    Porsche.thongtin().sportmode().sacpin(50).dapga(50).thongtin();
    return 0;
}