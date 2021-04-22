#include <iostream>
#include "Board.hpp"

const char EMPTY = '_';

using namespace std;

namespace ariel
{
    void Board::post(unsigned int row, unsigned int column, Direction direction, const string &message)
    {
        for (unsigned int i = 0; i < message.length(); i++)         // Running until the end of the message
        {
            pair<unsigned int, unsigned int> cell;
            cell = pair<unsigned int, unsigned int>(row, column);   // A pair representing a spot on the Message Board
            bool flag = (direction == Direction::Vertical);
            _my_board[cell] = message[i];                           // Adding each char of the message to a spot on the Message Board 
            flag ? row++ : column++;                                // Increments the row if the post is vertically, else increments the column
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        string str;
        for (unsigned int i = 0; i < length; i++)       // Running until we get to the desired length that we wish to read
        {
            pair<unsigned int, unsigned int> cell;
            cell = pair<unsigned int, unsigned int>(row, column);       // A pair representing a spot on the Message Board
            bool flag = (direction == Direction::Vertical);
            flag ? row++ : column++;        // Increments the row if the post is vertically, else increments the column
            try
            {
                str += _my_board.at(cell);  // Concatenating each char to the string
            }
            catch (out_of_range)
            {
                str += EMPTY;               // If we wish to read out of the post's range, concat "_" to the string instead
            }
        }
        return str;
    }

    void Board::show()
    {
        unsigned int curr = 0;
        unsigned int temp = 0;
        unsigned int last_col = 0;

        for (auto runner = _my_board.begin(); runner != _my_board.end(); ++runner)      // Iterator for the map
        {
            curr = (runner->first).first; // Row
            if (temp != curr)           // Creates a vertical post (on a column)
            {                           // if it's a horizontal post (on a row)
                temp = curr;            // continue and print the post horizontally
                last_col = 0;
                cout << "\n";
            }
            unsigned int blanks = ((runner->first).second - last_col);      // A calculation for the number of spaces we wish to add
            if (blanks > 1)
            {
                for (unsigned int i = 0; i < blanks; i++)       // Adding blank spaces to the the post as "_"
                {
                    cout << EMPTY;
                }
            }
            last_col = (runner->first).second + 1; // Column
            cout << runner->second;      // Prints a char with each iteration
        }
        cout << "\n";
    }
}
