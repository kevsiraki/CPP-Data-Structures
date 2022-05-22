//Group 1.11: Kevin Siraki, Erick Gulyan, Nathan Arakel
//CSIS 211 Online
//Lab 4
#include "Board.h"
#include "Queen.h"

const Board* Queen::boardPtr;

Queen::Queen() {
	row=0;
	col=0;
}

Queen::Queen(int inRow, int inCol) {
	row = inRow;
	col = inCol;
} 

int Queen::getCol() const {
	return col;
} 

int Queen::getRow() const {
	return row;
} 

void Queen::nextRow() {
	row++;
} 

void Queen::setBoard(const Board* bPtr) {
	boardPtr = bPtr;
}

bool Queen::DiagonalAttack(const Queen* queen) const {
	double diagonal = (double)(queen->getCol()-col) / (double)(queen->getRow()-row);
	if(diagonal==1 || diagonal == -1)
		return true;
	else 
		return false;
}

bool Queen::isUnderAttack() const {
	for (int i = 0; i < boardPtr->getNumQueens(); i++) {
		if (boardPtr->getQueen(i)->getRow() == row && boardPtr->getQueen(i)->getCol() == col){}
		else if(boardPtr->getQueen(i)->getRow() == row || boardPtr->getQueen(i)->getCol() == col || DiagonalAttack(boardPtr->getQueen(i)))
			return true;
		
	}
	return false;
}
