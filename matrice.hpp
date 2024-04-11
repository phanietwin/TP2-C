#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>




class Matrice {
public:
    Matrice(int n, int m);
    Matrice(const Matrice& o);//constructeur par copie
    int get_n(); // Méthode pour obtenir n
    int get_m(); // Méthode pour obtenir m
    Matrice& operator=( Matrice & o ) ; //opérateur d'assignement =
    Matrice operator+( Matrice& o)const;//opérateur d'assignement +
    Matrice operator-( Matrice& o)const;//opérateur d'assignement -
    Matrice operator*( Matrice& o) const;//opérateur d'assignement *

    Matrice operator+( double val)const;//opérateur d'assignement +
    Matrice operator-( double val)const;//opérateur d'assignement -
    Matrice operator*( double val) const;//opérateur d'assignement *
    double trace();//méthode pour calculer la trace
    bool operator==( Matrice& o) const;//opérateur d'assignement *
   

    void affiche();//méthode pour affichier la matrice
    void identity(int n) ; //méthode pour la matrice identité
    void random(int n, int m) ; //méthode pour la matrice àléatoire
    double& operator()(int i, int j);//Méthode pour l'accès à un membre de la matrice
    void set_matrice(int i, int j, double valeur); //changer la valeur d'un membre de la matrice

protected:
    int _n; // Attribut pour n, le nombre de lignes
    int _m;//Attribut pour m, le nombre de colonnes
    double** matrice; // Attribut pour matrice, un tableau de taille n
   
};
//Pour afficher la matrice dans un flux ostream
std::ostream& operator<<(std::ostream& os, Matrice m);

class Vecteur : public Matrice {
public:
    Vecteur(int n); 
    double scalaire(Vecteur& v); // Méthode pour calculer le produit scalaire
    Vecteur vectoriel(Vecteur& v); // Méthode pour calculer le produit vectoriel
    double norme() const; // Méthode pour calculer la Norme
    double& operator[](int i);
    
};


#endif // MATRICE_HPP
