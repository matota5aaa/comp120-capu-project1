comp120-capu-project1
Tic-Tac-Toe 

 How to play

- You are O and you go first. The computer is X.
- The board has 9 squares, numbered 0 to 8. Squares that are still empty show
  their number.
- Type the number of an empty square and press Enter.
- The computer picks a random empty square.
- If you type a number that is not 0 to 8, or a square that is already taken,
  the game says so and asks again.
- The game ends when someone gets three in a row, or when the board is full
  (draw).
- After each game, type y to play again or q to quit.

What I used

- A char board[9] array for the board
- bool for functions like is_winner 
- rand() and srand() for where the computer move
- while, do...while and for I used those for the loops
- I used this Functions: init_board, display_board, is_winner, other_player,
  get_human_move, get_computer_move, take_turn, play_game, play_again

AI use

I used Claude to help me with the structure of the code and to explain to me how to put some function in the code and a little bit with this readme.
