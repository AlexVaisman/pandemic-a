#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class OperationsExpert : public Player{
        public:
        OperationsExpert(Board board, City city);
    };
}