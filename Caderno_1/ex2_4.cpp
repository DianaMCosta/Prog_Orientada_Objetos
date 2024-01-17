#include <fstream >
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream is;
    is.open("alunos.txt");
    if(!is){
        cout<< "Erro, Impossivel abrir o ficheiro alunos.txt"<< endl;
        exit(1);
    }

 string linha;
    while (getline(is, linha, ';')) {
        string nome, idade, numero;
        //nome = linha;  // O primeiro campo Ã© o Nome
        //getline(is, idade, ';');
        getline(is, nome) ;

        // Apresentar os campos na tela
        cout << nome << endl;
        cout << idade << endl;
        cout << numero << endl;
    }
is.close();
system("pause");
return 0;

}
