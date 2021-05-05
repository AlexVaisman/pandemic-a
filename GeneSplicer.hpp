#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class GeneSplicer : public Player{
        public:
        GeneSplicer(Board board, City city);
    };
}