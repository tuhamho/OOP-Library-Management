#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class NRO {
    protected:
    string Ten;
    int SucManh;
    int KI;
    
    
    public:
    NRO(string name, int sm = 1000, int ki = 500) : Ten(name), SucManh(sm), KI(ki) {};
NRO& bay(int mana){
        KI -= mana ;
        return *this;
    }
virtual NRO& hienthi(){
    cout << "Tên, SM, KI: "<< Ten <<" "<< SucManh << " "<< KI<<endl;
    return *this;
}};
class TD : public NRO {
    public :
    TD(string name, int sm = 1000, int ki = 500) : NRO(name, sm, ki){} ;
    TD& TDHS(){
        cout<<"Toan bo ke thu da bi choang!" << endl;
        return *this;
    }
    TD& hienthi() override{
    NRO::hienthi();
    cout << "He pha: Trai Dat"<<endl;
    return *this;
}
TD& bay(int mana){
        NRO::bay(mana);
        return *this;
    }
};
class XD : public NRO {
    private:
    bool TrangThaiSuper;
    public:
    XD(string name, int sm =1000, int ki = 500 ) : NRO(name, sm , ki){
        TrangThaiSuper = false ;
    } ;
XD& BienXD(){
    if (SucManh >= 5000){
        cout << " Bien thanh Super Xayda" << endl;
    TrangThaiSuper = true ;
    KI*=2;
    }
    else 
    cout << "Chua du suc manh de bien hinh" << endl;
    return *this;
}
XD& bay(int mana){
        NRO::bay(mana);
        return *this;
    }
XD& hienthi() override{
    NRO::hienthi();
    cout << "He phai: Xayda "<<endl;
    if(TrangThaiSuper)
    cout << "Trang thai: Super Xayda"<<endl;
    else 
    cout << "Trang thai: Binh thuong"<<endl;
    return *this;
} 
};



int main() {
    TD NV1("Krillin",1000,500);
    NV1.hienthi().bay(50).TDHS().hienthi();
    XD NV2("Goku",6000,2000);
    NV2.bay(50).BienXD().hienthi();

    return 0;
}