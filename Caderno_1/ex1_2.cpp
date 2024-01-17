#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numero;
    char letra;
    float n2;
    string qualquercoisa;

    cout << "Insira um numero: " << endl;
    cin>> numero;
    cout <<"Insira uma letra: " << endl;
    cin>> letra;

    cout << "Insira u float: "<< endl;
    cin>> n2;
    
    cout << "O numero e: "<<numero<< " a letra e: " <<letra<< "e o float e "<<n2<< endl;
    cout <<"Inisira qualquer coisa: "<< endl;
    cin >> qualquercoisa;
    cout << "So porque sim "<< qualquercoisa<< endl;
    system ("pause");
    return 0;


}
