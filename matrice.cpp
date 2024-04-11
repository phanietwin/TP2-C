#include <iostream>
#include "matrice.hpp"
#include <math.h>
#include<random>
#include <iomanip>


    Matrice::Matrice(int n, int m){ //constructeur avec attributs
        _n = n;
        _m= m;

             matrice = new double*[_n];
             for (int i =0; i<_n; i++){
                matrice[i]=new double[_m];
            }

        

            for(int i =0; i<_n;i++){ 
                for(int j=0; j<_m; j++){
                    matrice[i][j]= 0.0;
                } 
            }


    }

    //Opérateur 
    double& Matrice::operator()(int i, int j) {
        return matrice[i][j];
    }

    //modifier la valeur d'une matrice
    void Matrice::set_matrice(int i, int j, double valeur){
        matrice[i][j]=valeur;
    }

    //Constructeur en copie 

    Matrice::Matrice(const Matrice& o): _n(o._n) ,_m(o._m){
    matrice = new double*[_n];
    for (int i = 0; i < _n; ++i) {
        matrice[i] = new double[_m];
        for (int j = 0; j < _m; ++j) {
            matrice[i][j] = o.matrice[i][j];
        }
    }
}

//Methode pour récuperer n

    int Matrice::get_n(){return _n;}

//Methode pour récuperer m

    int Matrice::get_m(){return _m;}
   
//méthode d'affichage
    void Matrice::affiche(){
        for (int i=0; i< _n; i++){
            for(int j =0; j<_m; j++){
                printf("%.2f ", matrice[i][j]);
            }
            printf("\n");
        }
    }  
    
    // Opérateur d'assignement " = ""
    Matrice& Matrice::operator=( Matrice& o) {
        if (this != &o) {
            for (int i = 0; i < _n; ++i) {
            delete[] matrice[i];
             }
            delete[] matrice;
        
            _n = o.get_n();
            
         matrice = new double*[_n];
            for (int i =0; i<_n; i++){
                matrice[i]=new double[_n];
            }
        
            for(int i =0; i<_n;i++){ 
                for(int j =0; j<_n; j++){
                    matrice[i][j]= o.matrice[i][j];
                }
            } 
        }

        return *this;
    }


    //Transformer un matrice en matrice identité
    void Matrice::identity(int n) {
        _n = n;
        _m = n;
      

             matrice = new double*[_n];
             for (int i =0; i<_n; i++){
                matrice[i]=new double[_m];
            }

        

            for(int i =0; i<_n;i++){ 
                for(int j=0; j<_m; j++){
                    if(j==i){
                        matrice[i][j]= 1.0;
                    }
                } 
          }
    }

  
      //Méthode pour additionner 2 matrices
    Matrice Matrice::operator+( Matrice& o)const {
         if(o._n != _n || o._m != _m){
            throw std::invalid_argument("Impossible de multiplier les matrices : dimensions incompatibles.");
        }

        Matrice somme = Matrice(_n, _m);
           
            for(int i =0; i<_n;i++){ 
                for(int j =0; j<_m; j++){
                    somme.matrice[i][j]= o.matrice[i][j]+matrice[i][j];
                }
            } 
            return somme;
        }

   //Méthode pour soustraire2 matrices
     Matrice Matrice::operator-( Matrice& o) const {
        if(o._n != _n || o._m != _m){
            throw std::invalid_argument("Impossible de multiplier les matrices : dimensions incompatibles.");
        }
        Matrice somme = Matrice(_n, _m);
           
            for(int i =0; i<_n;i++){ 
                for(int j =0; j<_m; j++){
                    somme.matrice[i][j]= o.matrice[i][j]-matrice[i][j];
                }
            } 
            return somme;
        }

    //Méthode pour multiplier 2 matrices
         Matrice Matrice::operator*(Matrice& o) const {
            Matrice mult(_n,o._m); 
            if (_m != o._n){
                 printf("Impossible de multiplier les matrices : dimensions incompatibles.");
            }
            else 
            {
            for(int i = 0; i < _n; i++) { 
                for(int j = 0; j < o._m; j++) {
                    for(int k = 0; k <_m; k++) {
                        mult.matrice[i][j] +=  matrice[i][k]*o.matrice[k][j] ;
                    }
                }
            } 
            }
    return mult;
}




 //méthode pour additionner un nombre à une matrice
 Matrice Matrice::operator+( double val)const {
        Matrice somme = Matrice(_n, _m);
           
            for(int i =0; i<_n;i++){ 
                for(int j =0; j<_m; j++){
                    somme.matrice[i][j]= matrice[i][j]+ val;
                }
            } 
            return somme;
        }

    //méthode pour soustraire un nombre à une matrice
     Matrice Matrice::operator-( double val) const {
        Matrice somme = Matrice(_n, _m);
           
            for(int i =0; i<_n;i++){ 
                for(int j =0; j<_m; j++){
                    somme.matrice[i][j]= matrice[i][j]-val;
                }
            } 
            return somme;
        }

          //méthode pour multiplier un nombre à une matrice
         Matrice Matrice::operator*(double val) const {
            
            Matrice mult(_n, _m); 
            
            for(int i = 0; i < _n; i++) { 
                for(int j = 0; j < _m; j++) {
                   
                    mult.matrice[i][j] = val * matrice[i][j];
                    
                }
            } 
    return mult;
}

//Pour avoir la trace d'une matrice
double Matrice::trace(){
    if (_n == _m){
        
    double trace =0.0;
    for(int i =0; i<_n;i++){ 
                for(int j=0; j<_m; j++){
                    if(j==i){
                       trace += matrice[i][j];
                    }
                } 
          }
    printf("\n trace de la matrice : %.f\n", trace);
    return trace; }
    else {
        throw std::logic_error("Erreur : impossible de calculer la trace d'une matrice non carrée");
    
    }
}

//POur avoir une comparaison entre deux matrices
bool Matrice::operator==( Matrice& o) const{
    for(int i = 0; i < _n; i++) { 
                for(int j = 0; j < _n; j++) {
                    if (matrice[i][j] != o.matrice[i][j]){
                        return false;
                    }
                    
                }
            } 
            return true; 
}

//Pour générer une matrice random
 void Matrice::random(int n, int m) {
        _n = n;
        _m=m;

             matrice = new double*[n];
             for (int i =0; i<_n; i++){
                matrice[i]=new double[_m];
            }

         
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0); 



            for(int i =0; i<_n;i++){ 
                for(int j=0; j<_m; j++){
                        matrice[i][j]= dis(gen);
                    
                } 
          }
    }

    //Afficher la matrice avec <<
    std::ostream& operator<<(std::ostream& os, Matrice m) {
    for (int i = 0; i < m.get_n(); i++) {
        for (int j = 0; j < m.get_m(); j++) {
            os << std::setprecision(2)<< m(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}

//exercice 2 

//Constructeur
Vecteur::Vecteur(int n) : Matrice(n, 1) {}

//Méthode pour faire le produit scalaire entre deux vecteurs
double Vecteur::scalaire(Vecteur &v){
    if ( _n!=v.get_n()){
        printf("\nErreur : vecteurs de dimensions incompatibles\n");
        return -1;

    }
    double scalaire;
    for (int i=0; i< v.get_n(); i++){
        scalaire += matrice[i][0]*v(i,0);
        
    } 
    return scalaire;
}

//méthode pour l'assignement d'opérateur  []
double& Vecteur::operator[](int i){
    return matrice[i][0];
}

//méthode pour avoir le produit scalaire entre deux vecteurs
Vecteur Vecteur::vectoriel(Vecteur& v){
    if ( _n!=3 or v.get_n()!=3){
        printf("\nErreur :Vecteur de dimmensions différentes de 3\n");
        return v;

    }
    Vecteur vectoriel(3);
    vectoriel[0]= matrice[1][0]*v[2]-matrice[2][0]*v[1];
    vectoriel[1]=matrice[2][0]*v[0]-matrice[0][0]*v[2];
    vectoriel[2]=matrice[0][0]*v[1]-matrice[1][0]*v[0];
return vectoriel;
}

//Méthode pour faire la norme 
double Vecteur::norme() const{
    double norme;
    for(int i =0; i<_n;i++){
        norme += matrice[i][0]*matrice[i][0];
    }
    return sqrt(norme);
}

 









    

  
  
    



   


