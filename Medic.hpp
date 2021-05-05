#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Medic : public Player{
        public:
        Medic(Board board, City city);
    };
}