#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Board{
        public:
        unordered_map<int ,tuple<string, int, vector<string>> > citys;
        Board();

        bool is_clean();
        void remove_cures();
        //operators
        const int operator[](pandemic::City city) const;
        int& operator[](pandemic::City city);
        friend std::ostream& operator<< (std::ostream& os, const Board& board);


        private:
        void init_board();

    };


};
