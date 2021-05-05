#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Scientist : public Player{
        public:
        Scientist(Board board, City city ,int num);
    };
}