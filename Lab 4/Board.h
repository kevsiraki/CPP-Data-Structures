//Group 1.11: Kevin Siraki, Erick Gulyan, Nathan Arakel
//CSIS 211 Online
//Lab 4
#ifndef _BOARD 
#define _BOARD 
#include "Queen.h" 
#include <vector> 
#include <cassert> 
#include <iostream> 
using namespace std; 
static const int BOARD_SIZE = 8; 

class Board {
	private:
		vector<Queen*> queens;
		bool isQueen(int inRow, int inCol) const; 
		bool placeQueens(Queen* queenPtr); 
        void removeQueen(); 
        void setQueen(Queen* queenPtr); 
	public: 
		Board();
		~Board();
		void clear(); 
		void display() const;
		void doEightQueens(); 
		int getNumQueens() const; 
		const Queen* getQueen(int index) const; 
}; 
 #endif 
