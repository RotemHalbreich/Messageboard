#include <iostream>
#include "Board.hpp"

const char EMPTY = '_';
const int CHECK = 2;

using namespace std;

namespace ariel
{
    void Board::post(unsigned int row, unsigned int column, Direction direction, const string &message)
    {
        for (unsigned int i = 0; i < message.length(); i++)
        {
            pair<unsigned int, unsigned int> cell;
            cell = pair<unsigned int, unsigned int>(row, column);
            bool flag = (direction == Direction::Vertical);
            _my_board[cell] = message[i];
            flag ? row++ : column++;
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        string str;

        for (unsigned int i = 0; i < length; i++)
        {
            pair<unsigned int, unsigned int> cell;
            cell = pair<unsigned int, unsigned int>(row, column);
            bool flag = (direction == Direction::Vertical);
            flag ? row++ : column++;
            try
            {
                str += _my_board.at(cell);
            }
            catch (out_of_range)
            {
                str += EMPTY;
            }
        }
        return str;
    }

    void Board::show()
    {
        unsigned int curr = 0;
        unsigned int temp = 0;
        unsigned int last_col = 0; 

        for (auto runner = _my_board.begin(); runner != _my_board.end(); ++runner)
        {
            curr = (runner->first).first;
            if (temp != curr)
            {
                temp = curr;
                last_col = 0;
                cout << "\n";
            }
            unsigned int blanks = ((runner->first).second - last_col);
            if (blanks >= CHECK)
            {
                for (unsigned int i = 0; i < blanks; i++)
                {
                    cout << " - ";
                }
            }
            last_col = (runner->first).second;
            cout << runner->second;
        }
        cout << "\n";
    }
}
