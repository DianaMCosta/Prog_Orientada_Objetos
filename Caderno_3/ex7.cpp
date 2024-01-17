#include <iostream>
#include <list>

using namespace std;

class Gestor_Num {
private:
	//declaração da lista e do tipo de váriaveis que armazena
    list<int> lista;

public:
    // Constructor
    Gestor_Num() {}

    // Destructor
    ~Gestor_Num() {}

    void SetGetNumero(list<int> _lista) {
        lista = _lista;
    };

    list<int> GetNumero() {
        return lista;
    };

    void InserirNumero(int num);
    void Remove(int num);
    void Lista();
    void Lista2();
    int ObterPosicao(int num);
    void Novo_Num();
};

void Gestor_Num::Remove(int num) {
    lista.remove(num);
}

void Gestor_Num::InserirNumero(int num) {
    lista.push_back(num);
}

void Gestor_Num::Lista(){
	list<int>::iterator p = lista.begin();
	
	while(p!=lista.end()){
		cout << *p << endl;
		p++;
	}
}




int Gestor_Num::ObterPosicao(int num){
	list<int>::iterator p = lista.begin();
	int i= -1;
	
	while(p!=lista.end()){
		i++;
		
		if (*p == num){
			return i;
		} 
		p++;
	}
}

void Gestor_Num::Novo_Num(){
	cout << "------------------ NOVA FORMA ------------------- \n";
    list <int> experiencia;
    int tam;
	int valor; 
    
    cout << "Quantos valores pretende adicionar a lista\t";
    cin >> tam;
    
    for (int i=0; i<tam; i++){
    	cout << "Valor a introduzir na lista\t";
    	cin >> valor;
    	experiencia.push_front (valor);
	}
	cout << "Imprimir valores introduzidos: ";
	for (int i=0; i<tam; i++){
		cout << experiencia.back() << "\t";
		experiencia.pop_back();
	}
}

int main(int argc, char* argv[]) {
    Gestor_Num gestorNum;
    int num_procura;
    int posicao;
    
    
    cout << "------------------ Valores -----------------------\n";
    gestorNum.InserirNumero(3);
    cout << gestorNum.GetNumero().back() << endl;
    gestorNum.InserirNumero(4);
    cout << gestorNum.GetNumero().back() << endl;
    gestorNum.InserirNumero(6);
    cout << gestorNum.GetNumero().back() << endl;
    
    //forma de introduzir valores numa lista, imprimi-los 
    gestorNum.Novo_Num();
    
    cout << "\n ----------- Funcao para listar os numeros da lista -------------------\n";
    gestorNum.Lista();
    
    cout << "\n --------------- Nova para listar --------";
	gestorNum.Lista2(); 
	
	cout << "----------- Remover o ultimo valor da lista ---------------\n";
	gestorNum.Remove(6);
	cout << gestorNum.GetNumero().front()<< "\n" << gestorNum.GetNumero().back();
	
	cout << "\n\n----------- Inserir novo numero --------------\n";
	gestorNum.InserirNumero(8);
	cout << gestorNum.GetNumero().back() << endl;
	
	cout << "\n\nInsira o numero que pretende encontrar a posicao:  ";
	cin >> num_procura;
	
	posicao = gestorNum.ObterPosicao(num_procura);
	cout << "\no numero " << num_procura << "esta na posicao " << posicao;
	
	cout << "\n\n\nFim do exercicio 7" << endl;
	
	
	
}
