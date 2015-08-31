/* 
  Authors : Jerome Nicolas & Alexandre Ravaux
  2015-01-29 
*/
#include <map>
#include <iostream>
#include "Polynome.h"

using namespace std;

int main(int argc, char const *argv[]){
  cout<<"Constructeur par défaut : "<<endl;
  Polynome<int> monPolynomeDefaut;
  cout<<"Polynome<int> monPolynomeDefaut : "<<monPolynomeDefaut<<endl;
  cout<<endl;

  cout<<"Constructeur prenant un tableau de coefficients en paramètre : "<<endl;
  // int premiers[5] = {2, 3, 5, 7, 11};
  int tableauCoeffs1[] = {0, 0, 1, 0, 0};
  int size=sizeof(tableauCoeffs1)/sizeof(*tableauCoeffs1);
  cout<<"Tableau qui sera passé en parametre : {";
  for(int i=0;i<size; i++){
    if(i>0 && i<size){
      cout<<", ";
    }
    cout<<tableauCoeffs1[i];
  }
  cout<<"}"<<endl;
  cout<<"size = "<<size<<endl;
  Polynome<int> monPolynomeTab(tableauCoeffs1, size);
  cout<<"Polynome<int> monPolynomeTab(premiers, size), monPolynomeTab = "<<monPolynomeTab<<endl;
  cout<<endl;

  cout<<"Constructeur prenant une std::map en paramètre : "<<endl;
  std::map<int, int> myMap;
  cout<<"Map utilisée (myMap) : ";
  for(int i=0; i<size; i++){
      myMap[i] = tableauCoeffs1[i];
      cout<<myMap[i];
      if(i+1<size){
        cout<<",";
      }
    }
    cout<<endl;
    Polynome<int> monPolynomeMap(myMap);
    cout<<"Polynome<int> monPolynomeMap(myMap), k = "<<monPolynomeMap<<endl;
    cout<<endl;

    cout<<"Constructeur par copie : "<<endl;
    Polynome<int> monPolynomeCopie(monPolynomeMap);
    cout<<"Polynome<int> monPolynomeCopie(monPolynomeMap), l = "<<monPolynomeCopie<<endl;
    cout<<endl;

    cout<<"Teste si la polynome est vide ou non  : "<<endl;
    cout<<"monPolynomeDefaut.isEmpty() retourne "<<monPolynomeDefaut.isEmpty()<<" donc vide"<<endl;
    cout<<"monPolynomeTab.isEmpty() retourne "<<monPolynomeTab.isEmpty()<<" donc non vide"<<endl;
    cout<<endl;

    cout<<"Surcharge du [] : "<<endl;
    cout<<"monPolynomeTab[0] : "<<monPolynomeTab[0]<<endl;
    cout<<endl;

  	cout<<"Surcharge du = : "<<endl;
  	Polynome<int>m=monPolynomeTab;
  	cout<<"Polynome<int>m=l, m = "<<m<<endl;
  	cout<<endl;

  	cout<<"Surcharge du + : "<<endl;
  	Polynome<int>n=monPolynomeTab+m;
  	cout<<"Polynome<int>n=l+m, n = "<<n<<endl;
  	cout<<endl;

  	cout<<"Surcharge du - : "<<endl;
  	Polynome<int>g=n-monPolynomeTab;
  	cout<<"Polynome<int>g=n-monPolynomeTab, g = "<<g<<endl;
  	cout<<endl;

  	cout<<"Surcharge du == : "<<endl;
  	cout<<"k==l : "<<(monPolynomeTab==monPolynomeMap)<<endl;
  	cout<<endl;  	

  	cout<<"Surcharge du += : "<<endl;
  	Polynome<int>o=monPolynomeTab;
  	cout<<"Polynome<int>o=monPolynomeTab, o = "<<o<<endl;
  	o+=monPolynomeTab;
  	cout<<"o+=monPolynomeTab, o =  "<<o<<endl;
  	cout<<endl;

  	cout<<"Surcharge du -= : "<<endl;
  	Polynome<int>p=n;
  	cout<<"p : "<<p<<endl;
  	cout<<"l : "<<monPolynomeTab<<endl;
  	cout<<"p-=monPolynomeTab :"<<endl;
  	p-=monPolynomeTab;
  	cout<<p<<endl;
  	cout<<endl;  

    cout<<"Division euclidienne : "<<endl;
    int tableauCoeffs2[] = {1, 3};
    int tableauCoeffs3[] = {0,1};
    Polynome<int> polynomeADiviser(tableauCoeffs2, 2);
    Polynome<int> dividende(tableauCoeffs3, 2);
    cout<<polynomeADiviser<<"/="<<dividende<<endl;
    polynomeADiviser/=dividende;
    cout<<"polynomeADiviser = "<<polynomeADiviser<<endl;
    cout<<endl; 

    cout<<"Composition (non fontionnel) : "<<endl;
    /* int tableauCoeffs4[] = {3, 0, 2};
    int tableauCoeffs5[] = {1, 1};
    Polynome<int> polynomeA(tableauCoeffs4, 3);
    Polynome<int> polynomeB(tableauCoeffs5, 2);
    cout<<polynomeA<<".composition("<<polynomeB<<") = ";
    polynomeA.composition(polynomeB);
    cout<<polynomeA<<endl;
    cout<<endl; */

  	cout<<"Surcharge du *= : "<<endl;
  	Polynome<int>p2=n;
  	cout<<"p2 : "<<p2<<endl;
  	cout<<"l : "<<monPolynomeTab<<endl;
  	p2*=monPolynomeTab;
    cout<<"p2*=monPolynomeTab :"<<p2<<endl;
  	cout<<endl;

    cout<<"Polynome o : "<<o<<endl;
  	cout<<"Degré du polynome o : "<<o.degre()<<endl;
  	Polynome<int>derivee=o.derivee();
  	cout<<"Derivee du polynome o : "<<derivee<<endl;
  	cout<<"Evaluation du polynome avec x=5 : "<<o.evaluer(5)<<endl;
    Polynome<double> polynomeSaisi;
    cout<<"Saisie du polynome : ";
    polynomeSaisi.saisirPolynome();
    cout<<"Polynome saisi : ";
    cout<<polynomeSaisi<<endl;



	return 0;
}