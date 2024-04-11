#include "matrice.hpp"
#include <iostream>


using namespace std;

int main(){

    //Exercice 1
   
    Matrice  mat = Matrice(4,4);
    mat.affiche();

    Matrice mat2 =mat ;
    mat2.affiche();

   

   double a = mat(1,1);
   printf("test pour selectionner mat(0,0): %.1f \n",a);

   mat.identity(5);
   mat2.identity(5);

    printf("comparaison entre mat et mat2 :\n");
    if(mat==mat2){
        printf("Vrai\n");
    }

    printf("\n mat\n");
   mat.affiche();

   printf("\n mat2 \n");
   mat2.affiche();

    Matrice mat3 = mat+mat2+2;
    printf("\n mat3 : mat + mat2 +2\n");
    mat3.affiche();

    printf("comparaison entre mat et mat3 :\n");
     if(mat==mat3){
        printf("\nVrai\n");
    }
    else {
        printf("\nfaux\n");
    }


    printf("\nmat4 : mat2 -mat -5\n");
    Matrice mat4 = mat2-mat-5; 
    mat4.affiche();

      printf("\n mat5 = mat2 *mat2 *2\n");
    Matrice mat5 = mat2 * mat2 *2;
    mat5.affiche();

    printf("\n mat6 = mat2 + 2\n");
    Matrice mat6 = mat+2;
    mat6.affiche();

     printf("\n mat6 = mat2 -5\n");
    Matrice mat7 = mat2-5; 
    mat7.affiche();

    printf("\n matrice 8 : mat3 *1.5\n");
    Matrice mat8 = mat3 * 1.5;
       mat8.trace();
    
    printf("\n matrice random : de dimension 1 col et 2 lignes\n");
    mat8.random(2,1); 
    mat8.affiche();

    printf("\n matrice random : de dimension 1 col et 2 lignes\n");
    printf("\n");
    Matrice matdiff(2,1);
    matdiff.random(2,2); 
     printf("\n");
    matdiff.affiche();

     printf("\n multiplication entre ces deux matrice\n");
    Matrice matdiff2 = matdiff*mat8;
     printf("\n");
    matdiff2.affiche();

     printf("\n matrice random : de dimension 1 col et 2 lignes\n");
    Matrice mat9(2,1);
    mat9.random(2,1); 
    mat9.affiche();
    printf("\n soustraction entre ces deux matrice\n");
    Matrice matsous = mat9 - matdiff2;
    std::cout <<matsous<<std::endl;


     printf("\n addition entre ces deux matrice\n");
    Matrice matadd = mat9 + matdiff2;
      std::cout <<matadd<<std::endl;


      //Exercice 2 

    Vecteur vect = Vecteur(3);
    Vecteur vect2 = Vecteur(3);
    Vecteur vect3 = Vecteur(2);
    printf("\n Vecteur1\n");
    vect.random(3,1);
    vect.affiche();

     printf("\n Vecteur2\n");
    vect2.random(3,1);
    vect2.affiche();

   
   cout<< "produit scalaire entre ces deux vecteurs : " <<vect.scalaire(vect2)<<endl;


    cout<<"test de l'opérateur [], vect[0] =  "<<vect[0]<<endl;
    cout<<"vect3"<<endl;
    cout<<vect3<<endl;
    cout<<"test du produit scalaire entre vect3 (de dimension 2) et vect(dimension3)"<<endl;
    vect3.scalaire(vect);
    cout<<"test du produit vectoriel entre vect3 (de dimension 2) et vect(dimension3)"<<endl;
    vect3.vectoriel(vect);
     
    Vecteur produit = vect2.vectoriel(vect);
    cout<<"produit vectoriel entre vecteur 1 et vecteur 2  : vect2 ^ vect"<<endl;
    cout<<produit<<endl; 

    cout<<"Norme de ce dernier vecteur: "<<produit.norme()<<endl;


    


    

 
   
    
    
    }

