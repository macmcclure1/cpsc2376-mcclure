#include <iostream>
#include "Game.hpp"

int main( ){
    char choice;
    std::cout << "Welcome to Connect Four! \n";
    std::cout << "Rules: Players take turns dropping pieces into the columns. The first player to have four in a row wins! /n";

    do{
        Game game; 
        game.play();
        std::cout << "Play again? (y/n): ";
        std::cin >> choice;
    }
    while(choice == 'y' || choice == 'Y');

    std::cout <<"Thanks for playing!\n";
    return 0;

}