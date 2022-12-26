class Board
{
    public:
    /* Create a piece on the board.
 Returns true if the piece was successfully placed on the board. */
bool initPiece(int id, Player owner, Position p);
 /* Return a pointer to the piece at the specified position,
 if the position is valid and occupied, nullptr otherwise. */
Piece* getPiece(Position p)const;
 /* Perform a move from the start Position to the end Position.
 The method returns an integer with the status
 >= 0 is success, < 0 is failure.
 This method may handle the parts of moving pieces that
 generalize over different board games. */
virtual int makeMove(Position start,Position end);/* The main gameplay loop. */
 
 virtual void run();/* Return true if the game is over. */

 virtual bool gameOver() const=0;
 protected:
 unsigned int m_width,m_height;
 int m_turn;/* The main gameplay loop. */
   

};