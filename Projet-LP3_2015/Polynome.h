/* 
  Authors : Jerome Nicolas & Alexandre Ravaux
  2015-01-29 
*/
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/* Classe Polynome */
template <typename T>
class Polynome{
	std::map<int, T> map;
	public:
		Polynome();
		Polynome(const Polynome<T>& p);
		Polynome(T coeffs[], int size);
		Polynome(std::map<int, T> m);
		std::map<int, T> getMap() const;
		void affiche();
		void affichePolynome();
		int degre() const;
		int length() const;
		bool isEmpty() const;
		T& operator[](const T i);
		Polynome<T>& operator=(const Polynome<T>& p);
		bool operator==(const Polynome<T>& p);
		Polynome<T>& operator*=(const Polynome<T>& p);
		Polynome<T>& operator*=(const T& p);
		Polynome<T>& operator+=(const Polynome<T>& p);
		Polynome<T>& operator-=(const Polynome<T>& p);
		Polynome<T>& operator/=(const Polynome<T>& p);
		Polynome<T> derivee() const;
		T evaluer(T x);
		Polynome<T> saisirPolynome();
		Polynome<T> composition(Polynome<T>& p);
};

/* Constructeur par defaut */
template <typename T>
Polynome<T>::Polynome(){}

/* Constructeur de copie */
template <typename T>
Polynome<T>::Polynome(const Polynome<T>& p){
  this->map=p.map;
}

/* Constructeur prenant en parametre un tableau de coefficients */
template <typename T>
Polynome<T>::Polynome(T coeffs[], int size){
  /* Boucle pour ajouter à la map le coeff */
  for(int i=0; i<size; i++){
    map[i] = coeffs[i];
  }
  
}

/* Constructeur prenant en parametre une map */
template <typename T>
Polynome<T>::Polynome(std::map<int, T> m){
  map=m;
}

/* getter : return map */
template <typename T>
std::map<int, T> Polynome<T>::getMap() const{
  return map;
}

/* Fonction affichant le contenu de la map : aide pour le développement */
template <typename T>
void Polynome<T>::affiche(){
	cout<<map.size()<<endl;
	typename std::map<int, T>::iterator it;
	for(it=map.begin(); it!=map.end(); it++){
		if(it->second != 0){
			std::cout << it->first << " => " << it->second << '\n';
		}
	}
}

/* Fonction pour afficher le polynome avec un iterator */
template <typename T>
void Polynome<T>::affichePolynome(){
	int i=0;
	int sizeMap=map.size();
	typename std::map<int, T>::iterator it;
	for(it=map.begin(); it!=map.end(); it++){
		if(it->second != 0){
			if((it)->first == 0){
						cout<<it->second;
					}else if((it)->first==1){
						cout<<(it)->second<<"x";
					}else{
						cout<<(it)->second<<"x^"<<(it)->first;
					}

					i++;
					it++;

					if(i != sizeMap && (it)->second <0){
						cout<<"";
					}else if(i != sizeMap && (it)->second >0){
						cout<<"+";
					}else{
						cout<<endl;
					}
					
					it--;
		}
	}
}

/* Degré du polynome : utile surtout pour la derivee du polynome */
template<typename T>
int Polynome<T>::degre() const{
	int indice=0;
	for (indice=map.size()-1; indice>0; indice--){
		if(this->getMap()[indice]!=0){
			return indice;
		}
	}
	return indice;
}

/* Retourne la longueur */
template<typename T>
int Polynome<T>::length() const{
    return map.size();
}

template<typename T>
bool Polynome<T>::isEmpty() const{
	int j=0,k=0;
	for(int i=0; i<map.size(); i++){
		if(this->getMap()[i]==0){
			j+=1;
		}else{
			k+=1;
		}
	}
	if(j==k && k==0){
		return true;
	}
    return false;
}


/* Surcharge de l'operateur de la sortie (cout) */
template <typename T>
std::ostream& operator<< (std::ostream &out, Polynome<T>& p){
	int sizeMap=p.length();
	int tmp=0;
	for (int i = 0; i < sizeMap; i++){
		if(i==0 && p.getMap()[i]!=0){
			out<<p.getMap()[i];
			if(p.getMap()[i+1]>0){
				out<<" + ";
			}else if(p.getMap()[i+1]<0){
				out<<" - ";
			}
		}else{	
			if(i!=sizeMap-1 && p.getMap()[i]!=0){
				tmp++;
				if(p.getMap()[i+1]>0){
					out<<p.getMap()[i]<<"x^"<<i<< " + ";	
				}else{
					out<<p.getMap()[i]<<"x^"<<i<< " ";	
				}
			}else if(i==sizeMap-1 && p.getMap()[i]!=0){
				tmp++;
				out<<p.getMap()[i]<<"x^"<<i;
			}else{
				if(p.getMap()[i+1]>0 && tmp>0 && sizeMap>1){
					out<<" + ";
				}else if(p.getMap()[i+1]<0 && tmp>0 && sizeMap>1){
					out<<" - ";
				}else{
					if(sizeMap==1){
						out<<"";	
					}
				}
			}
		}
	}
    return out;
}
/* Autre méthode pour afficher le polynome */
// template <typename T>
// std::ostream& operator<<(std::ostream& out, Polynome<T>& p){
// 	int sizeMap=p.length();
//     if (p.degre() == 0 && p.getMap()[0] == 0){
//         out << "0";
//         return out;
//     }
 
//     if (p.getMap()[sizeMap - 1] < 0.){
//         out << "- ";
//     }
//     for (int i(1);i<sizeMap;i++){
//         if (p[sizeMap - i] != 0){
//             out << p.getMap()[sizeMap-i] << "x^" << sizeMap - i;
//         }

//         if (p.getMap()[sizeMap - (i+1)] > 0)
//             out << " + ";
//         else if (p.getMap()[sizeMap - (i+1)] < 0)
//             out << " - ";
//     }
 
//     if (p.getMap()[0] != 0.){
//         out << p.getMap()[0];
//     }
 
//     return out;
// }



/* SURCHARGE DES OPERATEURS */

template <typename T>
T& Polynome<T>::operator[](const T i){
	return map[i];
}

template <typename T>
Polynome<T>& Polynome<T>::operator=(const Polynome<T>& p){
  this->map=p.map;
  return *this;
}

template <typename T>
bool Polynome<T>::operator==(const Polynome<T>& p){
	if(p.isEmpty() || this->isEmpty()){
		return false;
	}else{
		for (int i=0; i<p.length() && i<map.size(); ++i){
			if(map[i]!=p.getMap()[i]){
				return false;
			}
    	}
	}
	return true;
}

template <typename T>
Polynome<T>& Polynome<T>::operator+=(const Polynome<T>& p){
	for (int i=0; i<p.length() && i<map.size(); ++i){
		map[i]+=p.getMap()[i];
    }
	return *this;
}

template <typename T>
Polynome<T>& Polynome<T>::operator-=(const Polynome<T>& p){
	for (int i=0; i<p.length() && i<map.size(); ++i){
		map[i]-=p.getMap()[i];
    }
	return *this;
}

template <typename T>
Polynome<T>& Polynome<T>::operator*=(const Polynome<T>& p){
	std::map<int, T> mapTmp;
	for (int i=0; i<this->length(); i++){
		for(int j=0; j<p.length(); j++){
			mapTmp[i+j] += this->map[i] * p.getMap()[j];
		}
    }
    for (int k=0; k<mapTmp.size();k++){
    	this->map[k]=mapTmp[k];
    }
	return *this;
}

template <typename T>
Polynome<T>& Polynome<T>::operator*=(const T& p){
	std::map<int, T> mapTmp;
	for (int i=0; i<this->length(); i++){
		this->map[i] *= p;
    }
	return *this;
}

template <typename T>
Polynome<T>& Polynome<T>::operator/=(const Polynome<T>& p){
	std::map<int, T> mapTmp;
	std::map<int, T> mapReste;

	if (p.isEmpty()){
		cout << "Division par 0 impossible" << endl;
	}else if (this->length() < p.length()){
		return *this;
	}else{
		for (int i=this->length(); i>0 ;i--){
			mapTmp[i-p.degre()] = this->getMap()[i]/p.getMap()[p.degre()];
			*this = *this-p*mapTmp[i-p.degre()];			
		}
		for (int j=0; j<this->map[j];j++){
			mapReste[j]=this->map[j];
		} 
		for (int k=0; k<mapTmp.size();k++){
			this->map[k]=mapTmp[k];
		}
	}

	return *this;
}

/* TODO operator*=*/

template<typename T>
inline Polynome<T> operator+(const Polynome<T>& p, const Polynome<T>& q){
    return Polynome<T>(p) += q;
}

template<typename T>
inline Polynome<T> operator-(const Polynome<T>& p, const Polynome<T>& q){
    return Polynome<T>(p) -= q;
}

template<typename T>
inline Polynome<T> operator*(const Polynome<T>& p, const Polynome<T>& q){
    return Polynome<T>(p) *= q;
}

template<typename T>
inline Polynome<T> operator*(const Polynome<T>& p, const T& q){
    return Polynome<T>(p) *= q;
}

template<typename T>
inline Polynome<T> operator/(const Polynome<T>& p, const T& q){
    return Polynome<T>(p) /= q;
}

template<typename T>
Polynome<T> Polynome<T>::derivee() const{
    if (degre() == 0){
       // return 0;
    }
    Polynome<T> tmp(*this);
    for(int i=0; i<tmp.degre(); i++){
    	tmp[i]=tmp[i+1] * (i+1);
    }
    //tmp.getMap().pop_back();
    return tmp;
 
}

/* Remplace les valeurs de x du polynome par une valeur donnee en parametre */
template<typename T>
T Polynome<T>::evaluer(T x){
    T resultat = 0.;
    for (int i(0); i<map.size(); i++){
        resultat += map[i] * pow(x,i); 
    }
    return resultat;
}

/* Permet de saisir manuellement un polynome */
template<typename T>
Polynome<T> Polynome<T>::saisirPolynome(){
	string str;
  	string tmp, tp;
	/* Accepte les espaces, contrairement au cin tout seul */
	getline(cin, str);
	/* Au final, on supprime les espaces afin d'eviter les complications surtout avec les signes negatifs */
  	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
  	int i=0, j=0, k=0;
  	std::vector<T> arguments;
  	std::vector<T> exposants;
  	T argument, exposant, exposantMax(0);
  	bool isNegativeArg=false;
  	try{ 
	  	/* Parsing de la chainde caractere */
	  	while(i<str.length()){
	  		tmp+=str.substr(i,1);
	  		if(str.substr(i+1,1)=="x"){
	  			j=i+1;
	  			// Ajout de l'argument dans la liste d'arguments
				// Conversion du string to T		
	  			std::istringstream (tmp) >> argument;
	  			if(isNegativeArg){
	  				argument*=-1;
	  			}
	  			arguments.push_back(argument);
	  		}else if(str.substr(i+1,1)=="^"){
	  			//j est la position du "x", le "^" se trouvant tout juste apres, on fait +2 pour demarrer apres le "^"
	  			k=j+2;
	  			/* Tant que le prochain element n'est pas "+", "-" ou encore la fin de la chaine qu'on traite */
	  			while(k<str.length() && str.substr(k,1)!="+" && str.substr(k,1)!="-"){
	  				tp=str.substr(k,1);
	  				// Ajout de l'exposant dans la liste d'exposants
	  				// Conversion du string to T
	  				std::istringstream (tp) >> exposant;
	  				if(exposantMax<exposant) exposantMax=exposant;
	  				exposants.push_back(exposant);
	  				k++;
	  			}
	  		}else if(str.substr(i+1,1)=="+" || str.substr(i+1,1)=="-"){
	  			if(str.substr(i+1,1)=="-"){
	  				isNegativeArg=true;
	  			}else{
	  				isNegativeArg=false;
	  			}
	  			tmp="";
	  			i++;
	  		}
	  		i++;
	  	}
    }catch(const std::exception & e){
    	std::cerr << e.what();  
    }catch ( const std::bad_alloc & ){ 
         std::cerr << "Erreur : mémoire insuffisante.\n"; 
    }catch ( const std::out_of_range & ){ 
         std::cerr << "Erreur : débordement de mémoire.\n"; 
    } 
    
  	/* On efface la map */
  	this->map.clear();
  	/* Initialisation de la map */
  	for (int i = 0; i < exposantMax; i++){
  		this->map[i]=0;
  	}
  	/* Ajout des arguments en fonction des exposants */
  	for (int i = 0; i < exposants.size(); i++){
  		int indice=exposants[i];
  		this->map[indice]+=arguments[i];
  	}

	return *this;
}

/* Compostion non fonctionnelle */
template <typename T>
Polynome<T> Polynome<T>::composition(Polynome<T>& p){
	Polynome mapTmp;
	for (int i=this->length() ; i>=0 ; i--){
		for (int j=p.length() ; j>=0 ; j--){
			mapTmp.getMap()[i*j]=pow(p.getMap()[j],i);
			mapTmp.getMap()[i*j]=this->map[i]*p.getMap()[j];
		}
	}
	for (int k=0; k<mapTmp.length(); k++){
		this->map[k]=mapTmp.getMap()[k];
	}
	return *this;
}