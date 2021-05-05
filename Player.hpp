#pragma once
#include "Board.hpp"

using namespace pandemic;
namespace pandemic{
    class Player{

        public:
        Player();
        Player(Board board, City city);
        std::string role();
        Player&  take_card(City city); 
        Player&  drive(City city);
        Player&  fly_direct(City city);
        Player&  fly_charter(City city);
        Player&  fly_shuttle(City city); 
        Player&  build();
        Player&  discover_cure(Color color); 
        Player&  treat(City city);
    };

}