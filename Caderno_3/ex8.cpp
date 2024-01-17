#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
	string nome, morada;
	Data   data;

public:
	inline void SetNome(string _nome) { 
		nome = _nome; 
	}
	
	inline string GetNome(void) { 
		return nome; 
	}
	
	inline void SetMorada(string _morada) { 
		morada = _morada; 
	}
	
	inline string GetMorada(void) { 
		return morada; 
	}
	
	inline void SetData(Data _data) {
		data = _data; 
	}
	
	inline Data GetData(void) {
		return data; 
	}
	
	Pessoa();
	Pessoa(string _nome, string _morada, Data _data);
	Show();
	ReadK();
	bool MaisNovo(Pessoa p);
	operator==(Pessoa p1);
	
	friend ostream & operator << (ostream &os, const Pessoa P);
	friend istream & operator >> (istream &is, Pessoa &P);
	
	void SaveFile(ofstream& os);
	void ReadFile(ifstream& is);
};

class Funcionario : public Pessoa {
	private:
		string setor;
		int num;
		
		float ord_base;
		int h_extra;
		float p_horas_extra;
		
		
	public:
		Funcionario();
		virtual ~Funcionario();
		Funcionario(int _num, string _setor, string _nome, string _morada, Data _data, float _ord_base, int _hextra, float _p_horas_extra);
		
		void SetNum(int _num) { 
			num = _num; 
		}
		
		void SetSetor(string _setor) { 
			setor = _setor; 
		}
		
		int GetNum(void) { 
			return num; 
		}
		
		string GetSetor(void) { 
			return setor; 
		}	
		
		void Show(void);
		
		friend istream & operator >> (istream &is, Funcionario &F);
		
		void SaveFile(ofstream &os);
		void ReadFile(ifstream &is);
		void ReadLine(ifstream &is);
		
		virtual float Calcula_Ordenado() = 0;
		void ReadK(void);
		
		float GetOrdBase() { 
			return ord_base; 
		}
		
		void SetOrdBase(float _ord) { 
			ord_base = _ord; 
		}
		
		float GetPrecoHorasExtra() { 
		return p_horas_extra; 
		}
		void SetPrecoHorasExtra(float _ph) { 
		p_horas_extra = _ph; 
		}
		
		int GetHorasExtra() { 
			return h_extra; 
		}
		
		void SetHorasExtra(int _h) {
		 	h_extra = _h; 
		}
};


class Administrativo :public Funcionario
{
	public:
		Administrativo(int _num, string _setor, string _nome, string _morada, Data _data, float _ord, int _hextra);
		Administrativo();
		
		float Calcula_Ordenado();
		void ReadLine(ifstream & is);		
};


class Operario :public Funcionario
{
	private:
		bool f_turno;

	public:
		bool GetTurno() { 
			return f_turno; 
		}
		void SetTurno(bool t) { 
			f_turno = t; 
		}
		
		Operario();
		Operario(int _num, string _setor, string _nome, string _morada, Data _data, float _ord, int _hextra, bool _turno);
		
		float Calcula_Ordenado();
		
		void ReadLine(ifstream &is);
		void ReadK(void);
		void SaveFile(ofstream & os);
		
};

class Gestor_Func{
	private: 
		// variável Lista representa a lista de ponteiros para o Funcionario
		list <Funcionario*> Lista;
		
	void AddFunc();
	void RemoveFunc();
	friend ostream& operator << (ostream& os, Gestor_Func novo);
	friend istream& operator >> (istream& is, Gestor_Func novo);
};

void Gestor_Func : AddFunc (Funcionario* _f){
	for (Funcionario* f : Lista){
		if (f->GetNum() == _f->GetNum()){
			cout << "FUNCIONÁRIO JÁ EXISTENTE";
		}
	}
	Lista.push_back(_f);
}

void Gestor_Func : RemoveFunc(int num){
	list <Funcionario* > ::iterator it;
	it = Lista.begin();
	
	do {
		if((*it) -> GetNum() == num){
			Lista.erase(pos);
			
			cout << "Funcionario removido com sucesso";	
		}
		pos++;
	} while (pos != Lista.end());
}

void Gestor_Func : ShowFunc(){
	cout << "--------- Mostrar a lista de funcionarios -----------";
	for (Funcionario *f : Lista){
		if (Operario *op = dynamic_cast<Operario*>(f)){
			op->Show();
		} else{
			f ->Show();
		}
	}
}

istream & operator >>(istream& is, Gestor_Func novo){
	string escolha;
	
	cout << "Pretende inserir que categoria de trabalhador: ";
	cout << "O- operário";
	cout << "A- administrador";
	
	getline (is, escolha);
	if(escolha =='O'){
		Operario *op = new Operario();
		op-> ReadK();
		novo.AddFunc(op);
	}if(escolha =='A'){
		Administrador *admin = new Administrador();
		admin-> ReadK();
		novo.AddFunc(admin);
	}
	return is;
}

ostream & operator << (ostream &os, Gestor_Func novo){
	novo.ShowFunc();
	return os;
}

void Gestor_Func : ReadFile(){
	ifstream file;
	file.open("funcionarios.txt");
	
	if (file.is_open()){
		Operario *op = new Operario;
		op->ReadFile(file);
	}
}

int main(){
	
	
}
