#pragma once
#include <string>
#include <map>
#include "Direction.hpp"

namespace ariel
{
    class Board
    {
    private:
        std::map<std::pair<unsigned int, unsigned int>, char> _my_board;    // A map representing my Message Board

    public:
        Board() {}      // Default constructor
        ~Board() {}     // Default destructor

        void post(unsigned int row, unsigned int column, Direction direction, const std::string &message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}