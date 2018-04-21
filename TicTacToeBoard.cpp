#include "TicTacToeBoard.h"

/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
    if (turn == X)
    {
        turn = O;
    }
    else
    {
        turn = X;
    }
    return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece curPos = board[row][column];

  /* If location already has a piece, return what is already at location. */
  if (curPos == 'X' || curPos == 'O')
  {
    toggleTurn();
    return curPos; 
  }  
  /* Out of bounds coords return Piece Invalid value. */
  else if (
       row > BOARDSIZE
      || row < 0
      || column > BOARDSIZE
      || column < 0     
  )
  {
    toggleTurn();
    return Invalid;
  }
  /* Return what piece was placed. */
  else 
  {
    board[row][column] = turn;
    toggleTurn();
    return board[row][column];
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  Piece curPos = board[row][column];
  /* If no pieces at coords, return Blank. */
  if (curPos == Blank)
  {
    return curPos;
  } 
  /* Else if coords are out of bounds, return Invalid. */
  else if (
      row > BOARDSIZE
      || row < 0
      || column > BOARDSIZE
      || column < 0)
  {
    curPos = Invalid;
    return curPos;
  }
  /* Else, return Piece. */
  else 
  {
    return curPos;
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece priorPiece;
  bool invalid = false;

  /* Check rows for winner */
  for (int i = 0; i < BOARDSIZE; i++)
  {
    for (int j = 0; j < BOARDSIZE; j++)
    {
      /* If game is not over */
      if (getPiece(i,j) == Invalid ||getPiece(i,j) == Blank)
      {
        invalid = true;
      }
      
      /* First time through has no prior piece. */
      if (j == 0)
      {
        priorPiece = getPiece(i,j); 
      }
      /* If pieces are not consecutive. */
      else if (priorPiece != getPiece(i,j))
      {
        j = BOARDSIZE;
      }
      /* Winner, winner, chicken dinner. */
      else if (j == (BOARDSIZE - 1))
      {
        return getPiece(i,j); 
      }
    } 
  }

  /* Check columns for winner */
  for (int j = 0; j < BOARDSIZE; j++)
  {
    for (int i = 0; i < BOARDSIZE; i++)
    {
      /* If game is not over */
      if (getPiece(i,j) == Invalid || getPiece(i,j) == Blank)
      {
        invalid = true;
      }
      
      /* First time through has no prior piece. */
      if (i == 0)
      {
        priorPiece = getPiece(i,j); 
      }
      /* If pieces are not consecutive. */
      else if (priorPiece != getPiece(i,j)) 
      {
        i = BOARDSIZE;
      }
      /* Winner, winner, chicken dinner. */
      else if (i == (BOARDSIZE - 1))
      {
        return getPiece(i,j); 
      }
    } 
  }
  if (invalid == true)
  {
    return Invalid;
  }
  else 
  {
    return Blank;
  }
}

