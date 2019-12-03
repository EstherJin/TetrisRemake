#ifndef BASICBOARD_H
#define BASICBOARD_H
#include "board.h"

class BasicBoard:public Board {
	StringGenerator sg;
	std::vector<Row> grid;
	std::vector<Block2> activeBlocks;
	int score = 0;
	std::unique_ptr<Level> lvl;
	std::unique_ptr<Block1> nextBlock;
	bool random;
	int player;
	const int maxLevel = 4;
protected:
	const int gridRows = 18;
	std::unique_ptr<Block1> currentBlock;
	bool specialEffect = false;
public:
	BasicBoard(int player, bool random, int level = 0, bool textOnly = false, string script = "", unsigned seed = 0);
	~BasicBoard();
	std::string print(bool blind = false) override;
	void turnBlock(int amount) override;
	void moveBlock(int amount) override;
	void downBlock(int amount) override;
	int dropBlock() override; // returns number of lines cleared
	void changeLevel(int direction, bool rand, std::string filename) override;
	int getScore() override;
	void getNextBlock() override;
	bool validMove(vector<Coordinates> newPos) override;
	bool inSpecialEffect() override;
	void setSpecialEffect(bool se = true) override;
	int getLevel() override;
	bool originalPos() override;
	bool validDownPos() override;
	bool validStartPos() override;
};

#endif
