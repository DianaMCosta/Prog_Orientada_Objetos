#include <iostream >
#include <iomanip>

using namespace std;
int main()
{
    cout<<"ENSAIO do setw() ....."<< endl;
    cout << setw(10)<< 11<<endl;  // max 10 numeros
    cout << setw(10)<< 2222<< endl;
    cout << setw(10) <<4<< endl;
    cout<< setfill ('2')<< setw(10)<<11<<endl; // preeenche tds os carecters ('2')

    system("pause");
    return (0);
}
