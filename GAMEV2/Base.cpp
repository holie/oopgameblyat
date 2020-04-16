#include "GameField.h"
//#include "FieldBlock.h"
#include "Units.h"
#include "Base.h"
#include "Factory.h"
#include "FieldBlock.h"


Base::Base(int size, GameField& board) {
	this->size = board.size;
	x = size / 2;
	y = 0;
	health = 99;
	maxUnits = size * size / 2;
	numOfUnits = 0;
}

Base::Base(int size, GameField& board, int x, int y) {
	this->size = board.size;
	x = x;
	y = y;
	health = 99;
	maxUnits = size * size / 2;
	numOfUnits = 0;
}


Base::~Base() {
	
}

Unit* Base::createArcher(int x, int y) {
	if (numOfUnits <= maxUnits) {
		numOfUnits++;
		ArcherFactory archerFact;
		return archerFact.createUnit(x, y);
	}
	return NULL;
}

Unit* Base::createBallista(int x, int y) {
	if (numOfUnits <= maxUnits) {
		numOfUnits++;
		BallistaFactory ballistaFact;
		return ballistaFact.createUnit(x, y);
	}
	return NULL;
}

Unit* Base::createAtFarm(int x, int y) {
	if (numOfUnits <= maxUnits) {
		numOfUnits++;
		AtFarmFactory atFarmFact;
		return atFarmFact.createUnit(x, y);
	}
	return NULL;
}

Unit* Base::createBomber(int x, int y) {
	if (numOfUnits <= maxUnits) {
		numOfUnits++;
		BomberFactory bombFact;
		return bombFact.createUnit(x, y);
	}
	return NULL;
}

Unit* Base::createGeneral(int x, int y) {
	if (numOfUnits <= maxUnits) {
		numOfUnits++;
		GeneralBombFactory generalFact;
		return generalFact.createUnit(x, y);
	}
	return NULL;
}


void Base::deleteUnit(int x, int y, GameField& board) { //rework
	numOfUnits--;
	delete board.field[y * board.size + x].unit;
	board.field[y * board.size + x].unit = nullptr;
	board.numOfEmptyBlocks++;
}

void Base::enableSpots() {
	std::cout << "There are " << maxUnits - numOfUnits << " spots on the board\n";
}

void Base::baseHealth() {
	std::cout << "Base hp is " << health << "\n";
}







