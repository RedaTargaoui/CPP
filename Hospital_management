#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class hospital{
    int nb_cs ;
	string Nom [1000] ;
	string Prenom [1000] ;
	string Age[1000] ;
	string Maladie [1000] ;
	string Date [1000] ;
	public :
		hospital(){
			nb_cs = 0 ;
		}
		void add() ;
		void search() ;
		void update() ;
		void delete_pat();
		void add_to_file() ;
		void add_to_string() ;
		void afficher() ;
		
};

void hospital ::add(){
	
	char nom[100] ;
	char prenom[100] ;
	char age[100] ;
	char malad[100] ;
	char date[100] ;
	
	cout<<"Entrez le nom : ";
	cin>>nom;
	cout<<"Entrez le prenom : ";
	cin>>prenom;
	cout<<"Entrez l'age : ";
	cin>>age;
	cout<<"Entrez la maladie : ";
	cin>>malad;
	cout<<"Entrez la date (YYYY-MM-D) : ";
	cin>>date;
	
	Nom[nb_cs] = nom ;
	Prenom[nb_cs] = prenom ;
	Age[nb_cs] = age;
	Maladie[nb_cs] = malad ;
	Date[nb_cs] = date;
	
	nb_cs++;
	
	SetConsoleTextAttribute(h,11);
	cout<<" ___________________"<<endl;
	cout<<"|                   |"<<endl;
	cout<<"| Patient ajoute !  |"<<endl;
    cout<<"|___________________|"<<endl;
	SetConsoleTextAttribute(h,7);
	cout<<endl;
}

void hospital ::search(){
	char nom[100] ;
	cout<<"Entrez le nom du patient a chercher : ";
	cin>>nom ;
	string search ;
	int count = 0;
	ifstream readfile("datacpp.txt") ;
	while ( getline(readfile,search) ){
		size_t pre_pos = search.find(",");
		if ( search.substr(0,pre_pos) == nom ){
			size_t pos = search.find(",");
		    size_t pos2 = search.find(",",pos+1);
		    size_t pos3 = search.find(",",pos2+1);
		    size_t pos4 = search.find(",",pos3+1);
		    size_t pos5 = search.find(",",pos4+1);
		    cout<<endl;
		    cout<< "___________________________________________"<<endl;
		    cout<<endl;
		    cout<< "     Nom     : " << search.substr(0,pos) <<endl;
			cout<< "     Prenom  : " << search.substr(pos+1,pos2-6) <<endl; 
			cout<< "     Age     : " << search.substr(pos2+1,pos3-11) <<endl;
			cout<< "     Maladie : " << search.substr(pos3+1,pos4-14) <<endl;
			cout<< "     Date    : " << search.substr(pos4+1,pos5) <<endl;
			cout<< "___________________________________________"<<endl;
		    cout<<endl;
		    count++;
		}
	}
	if ( count == 0 ){
		cout<<endl;
		SetConsoleTextAttribute(h,4);
		cout<<" ______________________"<<endl;
		cout<<"|                      |"<<endl;
		cout<<"| Patient non trouve ! |"<<endl;
		cout<<"|______________________|"<<endl;
		SetConsoleTextAttribute(h,7);
		cout<<endl;
	}
}

void hospital ::update(){
	int count = 0;
	char nom[100] ;
	cout<<"Taper le nom du patient a modifier : ";
	cin>>nom ;
	for ( int i=0 ; i<nb_cs ; i++ ){
		if ( Nom[i] == nom ){
			cout<<" __________________________________________"<<endl;
			cout<<"|                                          |"<<endl;
			cout<<"|         1: Changer le nom                |"<<endl;
			cout<<"|         2: Changer le prenom             |"<<endl;
			cout<<"|         3: Changer l'age                 |"<<endl;
			cout<<"|         4: Changer la maladie            |"<<endl;
			cout<<"|         5: Changer la date               |"<<endl;
			cout<<"|__________________________________________|"<<endl;
			
			int choice ;
			cout<<"Taper l'indice du commande : ";
			cin>>choice ;
			count++;
			
			if ( choice == 1 ){
				char change[100];
				cout<<"Entrez le nouveau nom : ";
				cin>>change ;
				Nom[i] = change;
			}
			
			else if ( choice == 2 ){
				char change[100];
				cout<<"Entrez le nouveau prenom : ";
				cin>>change ;
				Prenom[i] = change;
			}
			
			else if ( choice == 3 ){
				char change[100];
				cout<<"Entrez l'age : ";
				cin>>change ;
				Age[i] = change;
			}
			
			else if ( choice == 4 ){
				char change[100];
				cout<<"Entrez la maladie : ";
				cin>>change ;
				Maladie[i] = change;
			}
			
			else if ( choice == 5 ){
				char change[100];
				cout<<"Entrez la date (YYYY-MM-D) : ";
				cin>>change ;
				Date[i] = change;
			}
			
		}
	}
	if ( count == 0 ){
		cout<<endl;
		SetConsoleTextAttribute(h,4);
		cout<<" ______________________"<<endl;
		cout<<"|                      |"<<endl;
		cout<<"| Patient non trouve ! |"<<endl;
		cout<<"|______________________|"<<endl;
		SetConsoleTextAttribute(h,7);
		cout<<endl;
	}
}


void hospital ::delete_pat(){
	int count = 0;
	char nom[100] ;
	cout<<"Taper le nom du patient a modifier : ";
	cin>>nom ;
	for ( int i=0 ; i<nb_cs ; i++ ){
		if ( Nom[i] == nom ){
			
			string tmp = Nom[i];
			Nom[i] = Nom[nb_cs-1];
			Nom[nb_cs-1] = tmp ;
			
			string tmp2 = Prenom[i];
			Prenom[i] = Prenom[nb_cs-1];
			Prenom[nb_cs-1] = tmp ;
			
			string tmp3 = Age[i];
			Age[i] = Age[nb_cs-1];
			Age[nb_cs-1] = tmp ;
			
			string tmp4 = Maladie[i];
			Maladie[i] = Maladie[nb_cs-1];
			Maladie[nb_cs-1] = tmp ;
			
			string tmp5 = Date[i];
			Date[i] = Date[nb_cs-1];
			Date[nb_cs-1] = tmp ;
			
			nb_cs--;
			count++;
			
	        SetConsoleTextAttribute(h,11);
	        cout<<" ________________________"<<endl;
	        cout<<"|                        |"<<endl;
	        cout<<"|   Patient Supprimee !  |"<<endl;
	        cout<<"|________________________|"<<endl;
	        SetConsoleTextAttribute(h,7);
		}
	}
	if ( count == 0 ){
		cout<<endl;
		SetConsoleTextAttribute(h,4);
		cout<<" ______________________"<<endl;
		cout<<"|                      |"<<endl;
		cout<<"| Patient non trouve ! |"<<endl;
		cout<<"|______________________|"<<endl;
		SetConsoleTextAttribute(h,7);
		cout<<endl;
	}
}


void hospital ::add_to_file(){
	ofstream file("datacpp.txt") ;
	for ( int i=0 ; i<nb_cs ; i++ ){
		file << Nom[i] << "," << Prenom[i] << "," << Age[i] << "," << Maladie[i] << "," << Date[i] << endl;
	}
}

void hospital ::add_to_string(){
	string add ;
	ifstream readfile("datacpp.txt") ;
	while ( getline(readfile,add) ){
		
		size_t pos = add.find(",");
		size_t pos2 = add.find(",",pos+1);
		size_t pos3 = add.find(",",pos2+1);
		size_t pos4 = add.find(",",pos3+1);
		size_t pos5 = add.find(",",pos4+1);
		
		Nom[nb_cs] = add.substr(0,pos) ;
		Prenom[nb_cs] = add.substr(pos+1,pos2-6) ;
		Age[nb_cs] = add.substr(pos2+1,pos3-11) ;
		Maladie[nb_cs] = add.substr(pos3+1,pos4-14) ;
		Date[nb_cs] = add.substr(pos4+1,pos5) ;
		
		nb_cs++;
	}
}

void hospital ::afficher(){
	cout<<"        Nom"<<"        prenom"<<"        age"<<"        maladie"<<"        date"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	for ( int i=0 ; i<nb_cs ; i++ ){
		cout<<"        "<< Nom[i] <<"        " << Prenom[i] <<"        " << Age[i] <<"        " << Maladie[i] <<"        " << Date[i] <<endl;
		cout<<"------------------------------------------------------------------------"<<endl;
	}
}

int main(){
	hospital p1 ;
	p1.add_to_string();
	
	int cont = 1 ;
	int choice ;
	cout<<"                          ________________________________________________________ "<<endl;
	cout<<"                         |                                                        |"<<endl;
	cout<<"                         |        1: afficher tous les patients                   |"<<endl;
	cout<<"                         |        2: Ajouter un patient                           |"<<endl;
	cout<<"                         |        3: Rechercher un patient                        |"<<endl;
	cout<<"                         |        4: Modifier les informations des patients       |"<<endl;
	cout<<"                         |        5: Supprimer un patient                         |"<<endl;
	cout<<"                         |________________________________________________________|"<<endl;
	cout<<endl;
    
	while ( cont != 0 ){
		cout<<"Taper l'indice du commande : ";
		cin>>choice ;
		cout<<endl;
		if ( choice == 1 ){
			p1.afficher();
			cout<<endl;
		}
		else if ( choice == 2 ){
			p1.add();
			p1.add_to_file();
		}
		else if ( choice == 3 ){
		    p1.search();		
		}
		else if ( choice == 4 ){
		    p1.update();
			p1.add_to_file();		
		}
		else if ( choice == 5 ){
		    p1.delete_pat();
			p1.add_to_file();		
		}
		cout<<"Taper 1 pour continuer , 0 pour sortir : ";
		cin>>cont;
	}	
}
