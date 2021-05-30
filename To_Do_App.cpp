#include <iostream>
#include <math.h>

using namespace std;

class Noeud{
	friend class Liste ;
	string c ;
	Noeud * next ;
	public :
		Noeud(string s = '\0' ){
			c = s;
			next = NULL ;
		}
};


class Liste{
	friend class Noeud ;
	Noeud * start ;
	public :
		Liste(){
			start = NULL;
		}
		void ajout_deb( string s );
		void ajout_fin( string s );
		int nb_elem();
		void supp( int x );
		void modifier( string s , int x );
		void operator+=( string s );
		void operator-=( int x );
		void afficher();
};

void Liste ::ajout_deb(string s){
	Noeud * N;
	N = new Noeud(s);
	N->c = s;
	N->next = start;
	start = N;
}

void Liste ::ajout_fin(string s){
	Noeud * P , * PP ;
	P = start ;
	PP = NULL ;
	while ( P != NULL && P->c != s ){
		PP = P ;
		P = P->next ;
	}
	if ( PP == NULL ){
		ajout_deb(s);
	}
	else if( P == NULL ){
		PP->next = new Noeud(s);
	}
	else{
		cout<<"Cette note est deja dans la liste !! "<<endl;
	}
}

int Liste ::nb_elem(){
	Noeud * N ;
	int c = 0 ;
	N = start ;
	while ( N != NULL ){
		c++;
		N = N->next ;
	}
	return c;
}

void Liste ::supp(int x){
	Noeud * P , * PP ;
	P = start ;
	PP = NULL ;
	int i = 1;
	while ( P != NULL && i != x ){
		i++;
		PP = P ;
		P = P->next ;	
	}
	if ( P == NULL ){
		cout<<"                                                   Valeur non trouvee "<<endl;
	}
	if ( PP == NULL ){
		start = start->next ;
	}
	else{
		PP->next = P->next ;
	}
	P->next = NULL ;
	delete P ;
}

void Liste ::modifier(string s,int x){
	Noeud *N , *NP ;
	N = start;
	NP = NULL ;
	int i = 1 ;
	while ( N != NULL && i != x ){
		NP = N ;
		i++;
		N = N->next;
	}
	if ( N == NULL ){
		cout<<"                                                   Valeur non trouvee "<<endl;
	}
	if ( NP == NULL ){
		start = start->next;
	}
	else{
		N->c = s;
    }
}

void Liste ::operator+=(string s){
	ajout_fin(s);
}

void Liste ::operator-=(int x){
	supp(x);
}

void Liste ::afficher(){
	Noeud * P ;
	P = start ;
	int i = 1 ;
	while ( P != NULL ){
		cout<<i<<" - "<< P->c <<endl;
		P = P->next;
		i++;
	}
}

int main(){
	cout<<"__________________________________________Bienvenue dans notre APP_____________________________________________"<<endl;
	Liste L ;
	string s1 = "Website to post publications with JS and PHP " ;
	string s2 = "To Do app with C++ " ;
	string s3 = "Game project with Python " ;
	L+=s1 ; L+=s2 ; L+=s3 ;
	cout<<"------------------------------------------------------"<<endl;
	L.afficher();
	cout<<"------------------------------------------------------"<<endl;
	cout<<"-> Pour le moment la liste contient "<<L.nb_elem()<<" element . "<<endl;
	int cont = 1;
	while ( cont != 0 ){
		string rep ; 
	    cout<<"-> Vous voulez faire ? " ;
	    cin>>rep;
	    if ( rep == "ajouter" || rep == "Ajouter" ){
		    string s ;
		    cout<<"-> Taper une note a ajouter : ";
		    cin>>s ;
		    L+=s;
		    cout<<"------------------------------------------------------"<<endl;
    	    L.afficher();
    	    cout<<"------------------------------------------------------"<<endl;
    	    cout<<"-> Pour le moment la liste contient "<<L.nb_elem()<<" element . "<<endl;
	    }
	    else if ( rep == "supp" || rep == "supprimer" || rep == "Supprimer" ){
		    int x;
		    cout<<"-> Entrez l'indice de l'element a supprimer : ";
		    cin>>x;
		    L-=x;
		    cout<<"------------------------------------------------------"<<endl;
		    L.afficher();
		    cout<<"------------------------------------------------------"<<endl;
	    }
	    else if ( rep == "modif" || rep =="Modifier" || rep == "modfier" ){
	    	string modif;
	    	int x ;
	    	cout<<"Entrez L'indice de l'element a modifier : ";
	    	cin>>x;
	    	cout<<"Entrez La nouvelle note: ";
	    	cin>>modif;
	    	L.modifier(modif,x);
		    cout<<"------------------------------------------------------"<<endl;
		    L.afficher();
		    cout<<"------------------------------------------------------"<<endl;
		}
	    cout<<"->Pour continuer taper 1 , pour arreter taper 0 : " ;
	    cin>>cont;
	}
}
