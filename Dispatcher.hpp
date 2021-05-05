#pragma once
#include "Player.hpp"

using namespace pandemic;
namespace pandemic{
    class Dispatcher : public Player{
        public:
        Dispatcher(Board board, City city);
    };
}