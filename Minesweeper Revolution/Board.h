#pragma once
#include "Cell.h"

class Board {
private:
	Cell* cells;
	int rows, cols;

private:
	inline int get2DIndex(int row, int col);


};