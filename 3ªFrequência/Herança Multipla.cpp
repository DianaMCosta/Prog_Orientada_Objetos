#include <iostream>

using namespace std;

class Base1{
public: 
    void frase1(){
        cout << "classe base 1" << endl;
    }
    void f(){
        cout << "OLÁ\n";
    }
};

class Base2{
public:
    void frase2(){
        cout << "classe base 2"<<endl;
    }
    
    void f(){
        cout << "Holanda\n";
    }
    
};

class Derivada: public Base2 , public Base1{
public:

    void frase3(){
            cout << "classe base 3" <<endl;
        }
};



int main(){

    Derivada objeto;

    objeto.Base1::f();
    objeto.Base2::f();
    objeto.frase1();

    return 0;
}
