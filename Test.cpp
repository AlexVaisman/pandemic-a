#include "doctest.h"
#include <string>
#include <algorithm>  
#include <iostream> 
#include <sstream> 

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"


TEST_CASE("Checking [] input"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	
	board[City::Kinshasa] = 3;            
	board[City::MexicoCity] = 3;    
	board[City::HoChiMinhCity] = 1; 
	board[City::Chicago] = 1;
    board[City::Bogota] = 9;
    board[City::Washington] = 10;

    CHECK((board[City::Kinshasa])==(3));
    CHECK((board[City::MexicoCity])==(3));
    CHECK((board[City::HoChiMinhCity])==(1));
    CHECK((board[City::Chicago])==(1));
    CHECK((board[City::Bogota])==(9));
    CHECK((board[City::Washington])==(10));
    

}

TEST_CASE("Checking [] throws with bad input"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).

    CHECK_THROWS(board[City::Kinshasa] = -5;);
    CHECK_THROWS(board[City::HoChiMinhCity] = -1;);
    CHECK_THROWS(board[City::Washington] = -2;);
}

TEST_CASE("Checking is_clean()"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    board[City::Kinshasa] = 0;            
	board[City::MexicoCity] = 3;    
	board[City::HoChiMinhCity] = 1; 
	board[City::Chicago] = 1;
    board[City::Bogota] = 9;
    board[City::Washington] = 10;

    CHECK((board.is_clean())==(false));

    board[City::MexicoCity] = 0;
    CHECK((board.is_clean())==(false));
    board[City::HoChiMinhCity] = 0;
    CHECK((board.is_clean())==(false));
    board[City::Chicago] = 0;
    CHECK((board.is_clean())==(false));
    board[City::Bogota] = 0;
    CHECK((board.is_clean())==(false));
    board[City::Washington] = 0;
    CHECK((board.is_clean())==(true));    
}

TEST_CASE("Checking drive()"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    OperationsExpert player {board, City::Atlanta}; //Chicago Miami Washington

    CHECK_NOTHROW(player.drive(City::Chicago));
    CHECK_NOTHROW(player.drive(City::Atlanta));
    CHECK_NOTHROW(player.drive(City::Miami));
    CHECK_NOTHROW(player.drive(City::Atlanta));
    CHECK_NOTHROW(player.drive(City::Washington));
    CHECK_NOTHROW(player.drive(City::Atlanta));

    CHECK_THROWS(player.drive(City::Johannesburg));
    CHECK_THROWS(player.drive(City::SanFrancisco));
    CHECK_THROWS(player.drive(City::NewYork));
    CHECK_THROWS(player.drive(City::Tokyo));
}


TEST_CASE("Checking drive()"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    OperationsExpert player {board, City::Atlanta}; //Chicago Miami Washington

    CHECK_NOTHROW(player.drive(City::Chicago));
    CHECK_NOTHROW(player.drive(City::Atlanta));
    CHECK_NOTHROW(player.drive(City::Miami));
    CHECK_NOTHROW(player.drive(City::Atlanta));
    CHECK_NOTHROW(player.drive(City::Washington));
    CHECK_NOTHROW(player.drive(City::Atlanta));

    CHECK_THROWS(player.drive(City::Johannesburg));
    CHECK_THROWS(player.drive(City::SanFrancisco));
    CHECK_THROWS(player.drive(City::NewYork));
    CHECK_THROWS(player.drive(City::Tokyo));
}

TEST_CASE("Checking fly_direct()"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	OperationsExpert player {board, City::Atlanta};  
	player.take_card(City::Johannesburg)
	 .take_card(City::Khartoum)
	 .take_card(City::SaoPaulo)
	 .take_card(City::BuenosAires)
	 .take_card(City::HoChiMinhCity);


    CHECK_NOTHROW(player.fly_direct(City::Johannesburg));
    CHECK_NOTHROW(player.fly_direct(City::Khartoum));
    CHECK_NOTHROW(player.fly_direct(City::SaoPaulo));
    CHECK_NOTHROW(player.fly_direct(City::BuenosAires));
    CHECK_NOTHROW(player.fly_direct(City::HoChiMinhCity));


    CHECK_THROWS(player.fly_direct(City::Johannesburg));
    CHECK_THROWS(player.fly_direct(City::Khartoum));
    CHECK_THROWS(player.fly_direct(City::SaoPaulo));
    CHECK_THROWS(player.fly_direct(City::BuenosAires));
    CHECK_THROWS(player.fly_direct(City::HoChiMinhCity));
    CHECK_THROWS(player.fly_direct(City::Tokyo));
    CHECK_THROWS(player.fly_direct(City::Tehran));
    CHECK_THROWS(player.fly_direct(City::Taipei));

}

TEST_CASE("Checking fly_charter()"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	OperationsExpert player {board, City::Atlanta};  
	player.take_card(City::Atlanta);


    CHECK_NOTHROW(player.fly_charter(City::Johannesburg));
    player.take_card(City::Johannesburg);
    CHECK_NOTHROW(player.fly_direct(City::Khartoum));
    player.take_card(City::Khartoum);
    CHECK_NOTHROW(player.fly_direct(City::SaoPaulo));
    player.take_card(City::SaoPaulo);
    CHECK_NOTHROW(player.fly_direct(City::BuenosAires));
    player.take_card(City::BuenosAires);
    CHECK_NOTHROW(player.fly_direct(City::HoChiMinhCity));


    CHECK_THROWS(player.fly_direct(City::Johannesburg));
    CHECK_THROWS(player.fly_direct(City::Khartoum));
    CHECK_THROWS(player.fly_direct(City::SaoPaulo));
    CHECK_THROWS(player.fly_direct(City::BuenosAires));
    CHECK_THROWS(player.fly_direct(City::Tokyo));
    CHECK_THROWS(player.fly_direct(City::Tehran));
    CHECK_THROWS(player.fly_direct(City::Taipei));

}

TEST_CASE("Checking build()-- throw"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).

	OperationsExpert player {board, City::Atlanta};
    CHECK_NOTHROW(player.build());

    Dispatcher player1 {board, City::Atlanta};
    CHECK_THROWS(player1.build());
    FieldDoctor player2 {board, City::Atlanta};
    CHECK_THROWS(player2.build());
    GeneSplicer player3 {board, City::Atlanta};
    CHECK_THROWS(player3.build());
    Medic player4 {board, City::Atlanta};
    CHECK_THROWS(player4.build());
    Researcher player5 {board, City::Atlanta};
    CHECK_THROWS(player5.build());
    Scientist player6 {board, City::Atlanta , 0};
    CHECK_THROWS(player6.build());
    Virologist player7 {board, City::Atlanta};
    CHECK_THROWS(player7.build());
}

TEST_CASE("Checking build() -- not throw"){
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).

	OperationsExpert player {board, City::Atlanta};
    CHECK_NOTHROW(player.build());

    Dispatcher player1 {board, City::Atlanta};
    player1.take_card(City::Atlanta);
    CHECK_NOTHROW(player1.build());
    FieldDoctor player2 {board, City::Atlanta};
    player2.take_card(City::Atlanta);
    CHECK_NOTHROW(player2.build());
    GeneSplicer player3 {board, City::Atlanta};
    player3.take_card(City::Atlanta);
    CHECK_NOTHROW(player3.build());
    Medic player4 {board, City::Atlanta};
    player4.take_card(City::Atlanta);
    CHECK_NOTHROW(player4.build());
    Researcher player5 {board, City::Atlanta};
    player5.take_card(City::Atlanta);
    CHECK_NOTHROW(player5.build());
    Scientist player6 {board, City::Atlanta , 0};
    player6.take_card(City::Atlanta);
    CHECK_NOTHROW(player6.build());
    Virologist player7 {board, City::Atlanta};
    player7.take_card(City::Atlanta);
    CHECK_NOTHROW(player7.build());
}