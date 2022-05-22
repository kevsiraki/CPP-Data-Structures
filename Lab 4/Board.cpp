//Group 1.11: Kevin Siraki, Erick Gulyan, Nathan Arakel
//CSIS 211 Online
//Lab 4
#include "Board.h"

Board::Board() {
	Queen::setBoard(this);
}

Board::~Board() {
	clear();
}

void Board::clear() {
	for(int i=0;i<getNumQueens();i++) {
		delete queens[i];
		queens[i] = nullptr;
	}
	queens.clear();
}

void Board::display() const {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << (isQueen(i,j) == 1 ? "Q":"_")<<" ";
		}
		cout << endl;
	}
	cout << endl<<"The Queens are At: "<<endl;
	for (int i = 0; i < getNumQueens(); i++) 
		cout << "Row: " << queens[i]->getRow() + 1 << " Col: " << queens[i]->getCol() + 1 << endl;
}

void Board::doEightQueens() {
	placeQueens(new Queen(0,0));
}

int Board::getNumQueens() const {
	return queens.size();
}

const Queen* Board::getQueen(int index) const {
	return queens[index];
} 

bool Board::isQueen(int inRow, int inCol) const {
	for(int i=0;i<getNumQueens(); i++) 
		if(queens[i]->getRow()==inRow && queens[i]->getCol()==inCol)
			return true;
	return false;
}

void Board::removeQueen() {
	queens[getNumQueens()-1] = nullptr;
	queens.pop_back();
}

void Board::setQueen(Queen* queenPtr) {
	queens.push_back(queenPtr);
}

bool Board::placeQueens(Queen* queenPtr) {
	if (queenPtr->getCol() >= BOARD_SIZE) {
		delete queenPtr;
		return true;
	} 
	bool isQueenPlaced = false;
	while (!isQueenPlaced && queenPtr->getRow() < BOARD_SIZE) {
		if (queenPtr->isUnderAttack()) 
			queenPtr->nextRow();
		else {
			setQueen(queenPtr);
			Queen* newQueenPtr = new Queen(0, queenPtr->getCol() + 1);
			isQueenPlaced = placeQueens(newQueenPtr);
			if (!isQueenPlaced) {
				delete newQueenPtr;
				removeQueen();
				queenPtr->nextRow();
			} 
		} 
	} 
	return isQueenPlaced;
} 
