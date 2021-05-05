#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Virologist : public Player{
        public:
        Virologist(Board board, City city);
    };
}