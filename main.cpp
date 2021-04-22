#include "Board.hpp"
#include "Board.cpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using ariel::Direction;

/**
 *----------------------------------------------------
 * Exercise 2B: Message Board
 * 
 * AUTHORS: Rotem Halbreich
 * 
 * To run main program:
 * clang++-9 -std=c++2a -Werror -Wsign-conversion main.cpp -o main
 * ./main
 *----------------------------------------------------*/

int main()
{
     unsigned int row, column, direction, length;
     ariel::Board board;
     string msg;
     Direction dir;
     int option = 0;

     cout << endl 
          << "Hey there, Welcome to the Message Board game!" << endl << endl
          << "To post to the board, please insert '1'" << endl
          << "To read from the board, please insert '2'" << endl
          << "To show a post from the board, please insert '3'" << endl
          << "To end the program, please insert '0'." << endl;
     do
     {
          cout << endl << "Please pick an option: ";
          cin >> option;
          cout << endl;

          switch (option)
          {
          case 0:
               cout << "Goodbye, see you soon! " << endl;
               break;

          case 1:
               cout << "Choose a row number: ";
               cin >> row;
               cout << endl << "Choose a column number: ";
               cin >> column;
               cout << endl << "If you wish to post horizontally insert '1', else you'll post vertically: ";
               cin >> direction;
               direction == 1 ? dir = Direction::Horizontal : dir = Direction::Vertical;
               cout << endl << "Publish your post: ";
               cin >> msg;
               board.post(row, column, dir, msg);
               break;

          case 2:
               cout << "Choose row number: ";
               cin >> row;
               cout << endl << "Choose column number: ";
               cin >> column;
               cout << endl << "If you wish to read horizontally insert '1', else you'll read vertically: ";
               cin >> direction;
               direction == 1 ? dir = Direction::Horizontal : dir = Direction::Vertical;
               cout << endl << "How far do you wish to read? ";
               cin >> length;
               cout << board.read(row, column, dir, length) << endl;
               break;

          case 3:
               board.show();
               break;

          default:
               cout << "Invalid option. please try again!" << endl;
               break;
          }
     } while (option != 0);

     return 0;
}