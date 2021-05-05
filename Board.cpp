#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
namespace pandemic{
    
        //constructor
    Board::Board(){
        init_board();
    }
    
    void add_city(string name, string color,int disease_in, vector<string> connections){
    }
    bool Board::is_clean(){
        return false;
    }
    
    void Board::remove_cures(){}

    //This function reads from "cities_map.txt" and adds the citys,their color and connections to the board.
    void Board::init_board(){
        ifstream file{"cities_map.txt"};
        string name;
        string color;
        string line;
        vector<string> connections;
        int word_counter = 0;
        int city_counter = 0;
        //reading each line in file and adding to board
        while(getline(file,line)){
            stringstream stream(line);
            while(stream.good()){
                string sub;
                getline(stream,sub,' ');
                if(word_counter == 0){
                    name = sub;
                }
                if(word_counter == 1){
                    color = sub;
                }
                if(word_counter > 1){
                    connections.push_back(sub);
                }
                word_counter++;
            }
            //adding to board
            tuple<string, int, vector<string>> city(color,0,connections);
            citys[city_counter] = city;
            city_counter++;
            //reseting varibales
            connections.clear();
            word_counter = 0;
        }
        auto it = citys.find(12);
        file.close();
    }  

    // operators 
    const int Board::operator[](pandemic::City city) const{
        return citys.size();
    }

    int& Board::operator[](pandemic::City city){
        auto it = citys.find((int)city);
        return get<1>(it->second);
    }

    std::ostream& operator<< (std::ostream& os, const Board& board){
        os<<"How to print? that comes later";
        return os;
    };


};