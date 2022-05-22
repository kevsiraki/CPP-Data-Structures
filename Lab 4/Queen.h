//Group 1.11: Kevin Siraki, Erick Gulyan, Nathan Arakel
//CSIS 211 Online
//Lab 4
#ifndef _QUEEN
#define _QUEEN

class Board; 

class Queen {
	private:
		int row; 
		int col; 
		static const Board* boardPtr;
		bool DiagonalAttack(const Queen* queen) const;
	public:
		Queen();
		Queen(int inRow, int inCol);
		int getCol() const;
		int getRow() const;
		void nextRow();
		bool isUnderAttack() const;
		static void setBoard(const Board* bPtr);
}; 
#endif
