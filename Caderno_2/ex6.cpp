#include <iostream>

using namespace std;

/*int main(){
	int vetor[5];
	int valor;
	
	for (int i=0; i<5; i++){
		cout << "Introduza o valor do vetor na posicao " << i << "\t\t";
		cin >> vetor[i];
	//	vetor[i]=valor;
	}
	
	for (int b=0; b<5; b++){
		cout << "\n" << vetor[b] << "\n";
	}
	
	return 0;
}*/

int main(){
	
	int matriz [3] [4];
	int vetor;
	int l, c;
	
	for (l=0; l<3; l++){
		for (c=0; c<4; c++){
			cout << "indique o valor que pretende colocar na matriz na posicao: " << l << "\t"<< c << ":\t";
			cin >> matriz[l][c];
			
			//alocar a memória
			vetor = new matriz[l][c];
			
			//elimina a alocação da memória
			delete vetor
		}
	}
	cout << "MATRIZ CRIADA COM SUCESSO";
	return 0;
	
}


//TEMOS POLIMORFISMO PORQUE A FUNÇÃO "FUNCAO" FOI REDEFININA NAS CLASSES DERIVADAS DA CLASSE ENTIDADE E NÃO APRESENTAM A MESMA FUNCIONALIDADE

class Entidade{
	public: 
	
	virtual void funcao(){
		cout << "OLA ENTIDADE";
	}
	
};

//REDEFINIÇÃO DE MÉTODOS VIRTUAIS
class Inimigo:public Entidade{
	void funcao(){
		cout << "OLÁ ENEMY";
	}
};

class Player:public Entidade{
	void funcao(){
		cout << "OLÁ PLAYER";
	}
};



class Entidade{ //CLASSE ABSTRATA POR TEM UMA FUNÇÃO QUE NÃO ESTÁ DEFINIDA
	public: 
	
	virtual void funcao()=0;
	
};


// OPERATOR OVERLOADING

ostream& operator<<(ostream& os, Data dt){
	os << "dia: " << dt.dia;
	os << "mes: " << dt.mes;
	os << "ano: " << dt.ano;
	
	return os;
}

istream& operator>>(istream& is, Data dt){
	cout << "INDIQUE O DIA:";
	is >> dt.dia;
	cout << "INDIQUE O MES: ";
	is >> dt.mes;
	cout << "INDIQUE O ANO: ":
	is >> dt.ano;
	
	return is;
}

//FICHEIROS ESCREVER NO FICHEIRO

void writeFile(){
	
	fstream ficheiro;
	string nome_ficheiro;
	
	cout << "INDIQUE O NOME DO FICHEIRO ONDE PRETENDE GUARDAR AS INFORMAÇÕES: ";
	getline(cin, nome_ficheiro);
	
	ficheiro.open(nome_ficheiro.c_str(), ios::out);
	
	if(ficheiro.is_open()){
		ficheiro << "OLÁ MUNDO";
		cout << "INFORMAÇÃO GUARDADA COM SUCESSO";
	} else {
		cout << "ERRO A CRIAR O FICHEIRO";
	}
	
	return 0;
	
}

// LER INFORMAÇÃO DOS FICHEIRO

void readFile(){
	
	fstream ficheiro;
	string nome_ficheiro;
	string linhas;
	
	cout << "INDIQUE O NOME DO FICHEIRO QUE PRETENDE LER: ";
	getline(cin,nome_ficheiro);
	
	ficheiro.open(nome_ficheiro.c_str(), ios::in);
	
	if (ficheiro.is_open()){
		while(getline(nome_ficheiro.c_str(), linhas){
			cout << linhas << endl;
		}
	} else {
		cout << "ERRO AO CIAR O FICHEIRO";
	}
	
	cour << "FIM DA EXECUÇÃO DO PROGRAMA";
}

//MÉTODO ESTÁTICO - para chamr uma função não necessitamos de um objeto

class Pessoa{
	private: 
		int nome;
		
	public: 
		static void Nome(){
			cout << "O NOME É .....";
		} 
	
};

int main(){
	Pessoa::Nome();
}


//Atributos estáticos - é constante em todos os objetos quando modificado uma vez, modifica em todos os objetos

class Pessoa{
	public: 
		static int idade;
		
		void Inf(){
			idade++;
		}
		
};

Pessoa::idade=0;

int main(){
	Pessoa p1;
	
	cout << p1.idade;
	
	Pessoa p2;
	
	p2.idade=4;
	
	cout << p1.idade
	
}


friend ostream& operator<< (ostream& os, data& dt){
	
	os << dt.dia;
	os << dt.mes;
	os << dta.ano;
	
	return os}

friend istream& operator>> (istream& is , data& dt){
	cout << "DIA: ";
	is >> dt.dia;
	
	cout << "MÊS: ";
	is >> dt.mes;
	
	cout << "ANO: ";
	is >> dt.ano;
	
	return is;	
}
