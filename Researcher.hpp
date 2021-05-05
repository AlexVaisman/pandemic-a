#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Researcher : public Player{
        public:
        Researcher(Board board, City city);
    };
}