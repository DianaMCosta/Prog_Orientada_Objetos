#include <iostream>
#include <string>
using namespace std;
int main(){
        int idade;
        string nome; //string
        char animal[30];

        cout<<"Escreva o seu nome:" <<endl;
        getline (cin, nome);
		cout << "Insira a sua idade: "<< endl;
        cin>> idade;
        cout<<"Animal:" << endl;
        cin>> animal;
        cout <<"O seu nome e: "<< nome <<" e tem:" << idade<< " anos" << endl;
        cout<<"Animal e " << animal;
        system("pause");
        return (0);
}
