#pragma once
#include <string>
#include <map>
#include <limits.h>
#include "Direction.hpp"

namespace ariel
{
    class Board
    {
    private:
        typedef std::pair<unsigned int, unsigned int> spot;
        std::map<spot, char> _my_board;

    public:
        Board() {}
        ~Board() {}

        void post(unsigned int row, unsigned int column, Direction direction, const std::string &message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}