#include <iostream>
#include "Board.hpp"

const char EMPTY = '_';

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
            catch (...)
            {
                str += EMPTY;
            }
        }
        return str;
    }

    void Board::show()
    {
        // unsigned int lastColum = 0;
        // pair<unsigned int, unsigned int> cell;

        // for (auto i = _my_board.begin(); i != _my_board.end(); ++i)
        // {
        //     cell.first = (i->first).first;
        //     cell.second = (i->first).second;
        //     cout << _my_board[cell] << " ";
        //     unsigned int spaces = (i->first).second - lastColum;
        //     if (spaces > 1)
        //     {
        //         for (unsigned int i = 0; i < spaces; i++)
        //         {
        //             cout << " - ";
        //         }
        //     }
        //     lastColum = (i->first).second;
        // }
        // cout << endl;

        unsigned int lastUse = 0;
        unsigned int lastColum = 0;
        for (auto itr = _my_board.begin(); itr != _my_board.end(); ++itr)
        {
            unsigned int currentUse = (itr->first).first;
            if (lastUse != currentUse)
            {
                cout << endl;
                lastColum = 0;
                lastUse = currentUse;
            }
            unsigned int spaces = (itr->first).second - lastColum;
            if (spaces > 1)
            {
                for (unsigned int i = 0; i < spaces; i++)
                {
                    cout << " - ";
                }
            }
            lastColum = (itr->first).second;
            cout << itr->second;
        }
        cout << endl;
    }
}
