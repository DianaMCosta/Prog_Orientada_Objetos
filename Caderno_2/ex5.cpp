//EXERCICIO 5 - CADERNO 2 - 2 FREQUÊNCIA
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}
	Data(){};
    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }

    int getMes() { return mes; }
    int getAno() { return ano; }
    int getDia() { return dia; }
};

class Pessoa {
private:
    string _nome;
    string _morada;
    Data datan;

public:
	Pessoa(){};
	Pessoa(string nome, string morada) {    // CONSTRUTOR PARA A PESSOA
		_nome=nome;
		_morada=morada;
	}
	
    void setNome(string nome) { _nome = nome; }
    void setData(Data data) { datan = data; }
    void setMorada(string morada) { _morada = morada; }
    string getNome() { return _nome; }
    Data getData() { return datan; }
    string getMorada() { return _morada; }
    
    
	void show(){
		cout << "Nome: " << _nome << endl;
		cout << "Morada: " << _morada << endl;	
	}
	
	
};



class Funcionario : public Pessoa {
private:
    std::string setor_trabalho;
    int num_funcionario;

public:
    Funcionario() : num_funcionario(0), setor_trabalho("") {}
    Funcionario(int num, std::string setor, std::string nome, std::string morada, Data datan)
        : Pessoa (nome, morada), num_funcionario(num), setor_trabalho(setor) {
        // Faça o que for necessário com nome, morada, e datan
    }


    void setNum(int num) { num_funcionario = num; }
    
    void setSetor(string setor) { setor_trabalho = setor; }
    
    int getNum() { return num_funcionario; }
    
    string getSetor() { return setor_trabalho; }

    void show() {
       Pessoa::show();
       cout << "Numero: " <<num_funcionario << " Setor de trabalho: " << setor_trabalho << endl;
       
    }
    
	void update(){			// não pode receber parâmetros função geral definimos a igualdade dentro nas instruções
    	int numero_f;
    	string setor_t;
    	numero_f=num_funcionario;
    	setor_t=setor_trabalho;
    	//morada_f= mor;
    	
    	cout << "\n\nNovo setor: ";
    	getline(std::cin,setor_t);
    	cout << "Nova morada: ";
    	//getline(std::cin,morada_f);
    	
    	
    	cout << "\nFuncionario   " << numero_f << "\nNovo setor de trabalho: " << setor_t;
    	
	}   
	
	void SaveFile(){
		fstream ficheiro;
		string nome_ficheiro;
		cout << "\n\nNome ficheiro para guardar informacoes: ";
		cin >> nome_ficheiro;
		
		ficheiro.open(nome_ficheiro.c_str(), ios::out);
		
		if (ficheiro.is_open()){
			ficheiro << num_funcionario;
			ficheiro << setor_trabalho;
		} else {
			cout << "ERRO NA ABERTURA DO FICHEIRO";
		}
		ficheiro.close();
	}
	
	
	
	
};
void ReadFile(string nome_ficheiro){
	fstream ficheiro;
	string linha;
		
	ficheiro.open(nome_ficheiro.c_str(), ios::in);
		
	if (ficheiro.is_open()){
		while(getline(ficheiro, linha)){
			cout << linha << endl;
		}
	} else{
		cout << "NÃO FOI POSSÍVEL ABRIR O FICHEIRO";
	}
	
	cout << "FICHEIRO LIDO COM SUCESSO";	
		
}
	
void novo_funcionario(){
	string nome_funcionario;
	string nome_ficheiro;
	cout << "\n\nApresente o nome do funcionário\n\n";
	for (int i=0; i<4;i++){
		
		ofstream ficheiro;
		string nome_ficheiro;
		
		cout << "-----------------------------CRIAR NOVOS FUNCIONÁRIOS----------------------------------------";
		cout << "\n\nNOME DO FICHEIRO: ";
		getline(cin, nome_ficheiro);
		
		cout << "NOME FUNCIONARIO: ";
		getline(cin, nome_funcionario);
		
		ficheiro.open(nome_ficheiro.c_str(), ios::out);
		
		
		if (ficheiro.is_open()){

			ficheiro << nome_funcionario << ";";
			cout<<"\n\nINFORMAÇÕES ADICIONADAS COM SUCESSO AO FICHEIRO";
			
		} else {
			cout << "ERRO AO CRIAR/ABRIR O FICHEIRO"<< endl;
		}
		
		ficheiro.close();
	}
}
	
	
	
int main() {
    Data data_f1(20, 9, 1987);
    Data data_f2(4, 2, 1990);

    Funcionario f1(25023, "Pintura", "Joca Gaio", "Rua da direita n 2", data_f1);
    Funcionario f2(25024, "Comercial", "Ana Rola", "Rua da esquerda n3", data_f2);

    f1.show();
    f2.show();
    /*
    f1.update();
    f2.update();
    
    f1.SaveFile();
    f2.SaveFile();
    */
   // f1.ReadFile();
	novo_funcionario();
    return 0;
}
