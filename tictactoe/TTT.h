#include<iostream>
#include<string>

class ttt
{
public:
	ttt();
	~ttt();
	void board();
	char check_winner();
	void player_move();
	void ai_move();
private:
	char square[9]={ '1','2','3','4','5','6','7','8','9' };
	char square_reset[9] = { '1','2','3','4','5','6','7','8','9' };
};