#include <iostream>
#include <fstream>
#include <string>

    using namespace std;

    int main(){
        ofstream os;
        os.open("alunos.txt");
        if(!os){
            cout <<"Erro: nÃ£o Ã© possÃ­vel abrir o ficheiro alunos.txt "<< '\n';
            exit(1);
        }
        struct
        {
          string name;
          int age, num;

        } alunos;

    for(int i=0; i<3; ++i )
    {
        cout<< "Name: "<< endl;
        cin >> alunos.name;
        os<<alunos.name << ";";


        cout <<"Age: ";
        cin >> alunos.age;
        os << alunos.age<< ";";
        cout << "Number: ";
        cin>> alunos.num;
        os << alunos.num << ";";
    }
      
        
        os.close();
        return 0;
    }
