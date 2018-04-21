/**
 * Unit Tests for TicTacToeBoard
**/

#include <string>
#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

using namespace std;
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(TicTacToeBoardTest, constructor)
{
	TicTacToeBoard();
	ASSERT_TRUE(true);
}


TEST(TicTacToeBoardTest, turnXtoO)
{ 
  TicTacToeBoard board;
  int letterInAscii = board.toggleTurn();
  ASSERT_EQ(letterInAscii, 'O');
}


TEST(TicTacToeBoardTest, turnOtoX)
{ 
  TicTacToeBoard board;
  board.toggleTurn();
  int letterInAscii = board.toggleTurn();
  ASSERT_EQ(letterInAscii, 'X');
}


TEST(TicTacToeBoardTest, spotIsBlank)
{ 
  TicTacToeBoard board;
  Piece result = board.getPiece(0,0);  
  ASSERT_EQ(result, Blank);
}


TEST(TicTacToeBoardTest, rowIsTooSmall)
{ 
  TicTacToeBoard board;
  Piece result = board.getPiece(-1, 0);  
  ASSERT_EQ(result, Invalid);
}


TEST(TicTacToeBoardTest, rowIsTooLarge)
{ 
  TicTacToeBoard board;
  Piece result = board.getPiece(0, 10);  
  ASSERT_EQ(result, Invalid);
}


TEST(TicTacToeBoardTest, columnIsTooSmall)
{ 
  TicTacToeBoard board;
  Piece result = board.getPiece(0, -1);  
  ASSERT_EQ(result, Invalid);
}


TEST(TicTacToeBoardTest, columnIsTooLarge)
{ 
  TicTacToeBoard board;
  Piece result = board.getPiece(0, 10);  
  ASSERT_EQ(result, Invalid);
}


TEST(TicTacToeBoardTest, pieceAtZeroZero)
{ 
  TicTacToeBoard board;
  ASSERT_EQ(board.placePiece(0, 0), 'X');
}


TEST(TicTacToeBoardTest, rowWinner)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(1,0);
  board.placePiece(0,1);
  board.placePiece(1,1);
  board.placePiece(0,2);
  ASSERT_EQ(board.getWinner(), 'X');
}


TEST(TicTacToeBoardTest, columnWinner)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(1,0);
  board.placePiece(1,1);
  board.placePiece(2,0);
  ASSERT_EQ(board.getWinner(), 'X');
}


TEST(TicTacToeBoardTest, itsAdraw)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(0,2);
  board.placePiece(1,0);
  board.placePiece(1,1);
  board.placePiece(1,2);
  board.placePiece(2,0);
  board.placePiece(2,1);
  board.placePiece(2,2);
  ASSERT_EQ(board.getWinner(), Blank);
}


TEST(TicTacToeBoardTest, gameNotOver)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(0,2);
  board.placePiece(1,0);
  board.placePiece(2,0);
  board.placePiece(2,1);
  ASSERT_EQ(board.getWinner(), Invalid);
}
