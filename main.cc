#include "GameOfLife.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  int iterationNb = 110; // nombre d’itérations que l’on va faire
  //GameOfLife game(52, 52, "Canon"); // définition d’un objet "game" de taille 50x50
  GameOfLife *game; //création du pointeur
  int a=1; //définition de la variable permettant de choisir l'initialisation
  std::cout << "Choisissez votre initialisation :" << std::endl;
  std::cout << "1) initialisation par defaut" << std::endl;
  std::cout << "2) initialisation Clown" << std::endl ;
  std::cout << "3) initialisation Canon" << std::endl ;
  std::cout << "Votre réponse (1,2 ou 3) :";
  std::cin >> a ; //demande "a" a l'utilisateur
  std::cout << std::endl;

  switch(a) //sélection du schéma correspondant
  {
    case 1:
    game = new GameOfLife(52, 52);
    break;
    case 2:
    game = new GameOfLife(52,52,"Clown");
    break;
    case 3:
    game = new GameOfLife(52,52,"Canon");
    break;
    default:
    cout << "Ce choix n’est pas possible." << endl;
    exit(0);
  }
  if (a!=2)
  {
    std::cout << "Nombre d'itérations";
    std::cin >> iterationNb;
  }


  game->initialisation(); // on initialise
  game->saveSolution(0); // on sauvegarde l’initialisation
  for(int i=1; i<=iterationNb; i++) // boucle sur les itérations
  {
    game->play(); // on joue (mise à jour du statut des cellules)
    game->saveSolution(i); // on sauvegarde les solutions obtenues
  }
   delete game;
   game=0;

  return 0;
}
# Code
