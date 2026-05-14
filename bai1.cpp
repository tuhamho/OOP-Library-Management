#include <iostream>
#include <string> 
using namespace std;


class NhanVat{
    private:
    string ten;
    int mau;

    public:
    NhanVat(string name,int hpg = 100) : ten(name) , mau(hpg) {};
    
        //set 1
    void heal(int somauhoi){
       
        mau = mau + somauhoi;
        if ( mau > 100 ) {
            mau = 100;
           
        }
        else if ( mau <= 0){
            mau = 0;
          
        }
    };
    // set 2
    void atk(int satthuong){
        mau = mau - satthuong;
        if ( mau <=0){
            mau=0;
            cout << "nhan vat cua ban da bi quai dap chet "<<endl; } 
      
    };
    int getoutbjtch(){
        return mau;
    };
        


}; 
int main () {
    NhanVat NV1("HAIASS");
    NV1.atk(30);
    NV1.heal(80);
    NV1.atk(200);
    cout <<"Mau hien tai cua ban la: "<<  NV1.getoutbjtch();
  


    return 0;
};