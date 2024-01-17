#include <fstream >
#include <iostream>

using namespace std;
int main()
{
    ifstream is; //abrir ficheiro modo leitura
    ofstream os; // abrir ficheiro modo escrita

    // para abrir o ficheiro em modo de escrita e leitura
    // deve usar-se a class fstream

    is.open("dados_ent.txt");
    if(!is){
        cout << "Erro. Nao e possivel abrir o ficheiro dados_ent.txt"<< '\n';
        exit(1);
    }
    os.open("dados_saida.txt");
    if(!os){
        cout << "Erro: Nao e possivel abrir o ficheiro dados_saida.txt"<< '\n';
        exit(1);
    }
    int a,b;
    is>>a>>b;
    cout <<a <<endl<<b<<endl;
    os << a*a << ' '<<b*b;
    is.close();
    os.close();
    system("pause");
    return 0;
}
