#include"TTT.h"

ttt::ttt()
{
	char again;
	do
	{
		char done = ' ' ;
		do
		{
			board();
			player_move();
			done = check_winner();
			if (done != ' ')
				break;
			ai_move();
			done = check_winner();
		} while (done == ' ');
		board();
		if (done == 'X')
		{
			std::cout << "Player Won" << std::endl;
			std::cout << "Want to play again (y 0r n):" << std::endl;
			std::cin >> again;
			if (again == 'y' || again == 'Y')
			{
				for (int n = 0; n <= 8; n++)
				{
					square[n] = square_reset[n];
				}
			}
			else
				exit;
		}
		else if (done == 'O')
		{
			std::cout << "Computer Won" << std::endl;
			std::cout << "Want to play again (y 0r n):" << std::endl;
			std::cin >> again;
			if (again == 'y' || again == 'Y')
			{
				for (int n = 0; n <= 8; n++)
				{
					square[n] = square_reset[n];
				}
			}
			else
				exit;
		}
		else
		{
			std::cout << "Game Draw" << std::endl;
			std::cout << "Want to play again (y 0r n):" << std::endl;
			std::cin >> again;
			if (again == 'y' || again == 'Y')
			{
				for (int n = 0; n <= 8; n++)
				{
					square[n] = square_reset[n];
				}
			}
			else
				exit;
		}
	} while (again == 'y'|| again=='Y');
}

void ttt::board()
{
	std::cout << std::endl << "\t Tic Tac Toe" << std::endl;
	std::cout << "Player 1 (X)  -  Player 2 (O)" << std::endl << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t    " << square[6] << "  |   " << square[7] << "   |   " << square[8] << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t_______|_______|_______" << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t    " << square[3] << "  |   " << square[4] << "   |   " << square[5] << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t_______|_______|_______" << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t    " << square[0] << "  |   " << square[1] << "   |   " << square[2] << std::endl;
	std::cout << "\t       |       |       " << std::endl;
	std::cout << "\t       |       |       " << std::endl;
}

char ttt::check_winner()
{
	if (square[0] == square[1] && square[1] == square[2])
		return square[0];
	else if (square[3] == square[4] && square[4] == square[5])
		return square[3];
	else if (square[6] == square[7] && square[7] == square[8])
		return square[6];
	else if (square[0] == square[4] && square[4] == square[8])
		return square[0];
	else if (square[2] == square[4] && square[4] == square[6])
		return square[2];
	else if (square[6] == square[3] && square[3] == square[0])
		return square[6];
	else if (square[7] == square[4] && square[4] == square[1])
		return square[7];
	else if (square[8] == square[5] && square[5] == square[2])
		return square[8];
	else if (square[0] == '1' || square[1] == '2' || square[2] == '3'
		|| square[3] == '4' || square[4] == '5' || square[5] == '6'
		|| square[6] == '7' || square[7] == '8' || square[8] == '9')
		return ' ';
	else
		return '_';
	getchar();
}

void ttt::player_move()
{
	int r = 0;
	do
	{
		r = 0;
		std::string input;
		int i = 0;
		char mark = 'X';
		std::cout << "Player's turn" << std::endl;
		std::cout << "Enter a number from 1-9 :";
		std::cin >> input;
		if (input == "1" && square[0] == '1')
			square[0] = mark;
		else if (input == "2" && square[1] == '2')
			square[1] = mark;
		else if (input == "3" && square[2] == '3')
			square[2] = mark;
		else if (input == "4" && square[3] == '4')
			square[3] = mark;
		else if (input == "5" && square[4] == '5')
			square[4] = mark;
		else if (input == "6" && square[5] == '6')
			square[5] = mark;
		else if (input == "7" && square[6] == '7')
			square[6] = mark;
		else if (input == "8" && square[7] == '8')
			square[7] = mark;
		else if (input == "9" && square[8] == '9')
			square[8] = mark;
		else
		{
			std::cout << "Inavlid Entry" << std::endl;
			r = 1;
		}
	} while (r == 1);
}

void ttt::ai_move()
{
	char mark = 'O';
	std::cout << "Computer's turn" << std::endl;
	if (square[0] == square[1] && square[2] == '3')
		square[2] = mark;
	else if (square[1] == square[2] && square[0] == '1')
		square[0] = mark;
	else if (square[0] == square[2] && square[1] == '2')
		square[1] = mark;
	else if (square[3] == square[4] && square[5] == '6')
		square[5] = mark;
	else if (square[3] == square[5] && square[4] == '5')
		square[4] = mark;
	else if (square[4] == square[5] && square[3] == '4')
		square[3] = mark;
	else if (square[6] == square[7] && square[8] == '9')
		square[8] = mark;
	else if (square[6] == square[8] && square[7] == '8')
		square[7] = mark;
	else if (square[7] == square[8] && square[6] == '7')
		square[6] = mark;
	else if (square[0] == square[4] && square[8] == '9')
		square[8] = mark;
	else if (square[0] == square[8] && square[4] == '5')
		square[4] = mark;
	else if (square[4] == square[8] && square[0] == '1')
		square[0] = mark;
	else if (square[2] == square[4] && square[6] == '7')
		square[6] = mark;
	else if (square[2] == square[6] && square[4] == '5')
		square[4] = mark;
	else if (square[6] == square[4] && square[2] == '3')
		square[2] = mark;
	else if (square[0] == square[3] && square[6] == '7')
		square[6] = mark;
	else if (square[0] == square[6] && square[3] == '4')
		square[3] = mark;
	else if (square[3] == square[6] && square[0] == '1')
		square[0] = mark;
	else if (square[1] == square[4] && square[7] == '8')
		square[7] = mark;
	else if (square[1] == square[7] && square[4] == '5')
		square[4] = mark;
	else if (square[4] == square[7] && square[1] == '2')
		square[1] = mark;
	else if (square[2] == square[5] && square[8] == '9')
		square[8] = mark;
	else if (square[2] == square[8] && square[5] == '6')
		square[5] = mark;
	else if (square[5] == square[8] && square[2] == '3')
		square[2] = mark;
	else if (square[4] == '5')
		square[4] = mark;
	else if (square[0] == '1')
		square[0] = mark;
	else if (square[8] == '9')
		square[8] = mark;
	else if (square[2] == '3')
		square[2] = mark;
	else if (square[5] == '6')
		square[5] = mark;
	else if (square[1] == '2')
		square[1] = mark;
	else if (square[6] == '7')
		square[6] = mark;
	else if (square[7] == '8')
		square[7] = mark;
	else if (square[3] == '4')
		square[3] = mark;
}

ttt::~ttt()
{
	getchar();
}