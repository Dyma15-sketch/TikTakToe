# Tik-Tak-Toe
X/0



# TikTakToe is a simple strategy game where the player plays aganist an opponent in a match of Tic Tac Toe on 3x3 grid. The player must fill 3 grids vertically, horizontally or diagonally in order to win, otherwise, the opponent will beat the player or the game will end in a draw. 

# In "point.hpp", Point holds the coordonates of the placement of x/0 on the columns/rows.

# In "player.hpp", the enum class Player is used to determine if the players participating are either X or 0.

# In "board.hpp" that includes "player.hpp", class Board includes esential elements for the board. Inside the class,  the "Player cells" creates the cells, Board() creates the new board with the cells being empty,   PlaceMark() check the coordonates on the grid and returns true if the cell is empty or false if the cell is filled by one of the players,  GetCell() returns the value of the cell whatever its X,0 or nothing,  IsFull checks if the entire grid is filled or not and Reset() empties the enitre grid once the match is over.

# In "rules.hpp", inside class Rules, CheckWin() will check the end result of the match if one of the players won and CheckDraw() will verify if the match ended in a draw.

# In "game_engine.hpp", which handles the logic of the game and includes player,board and rules.hpp files, Init() starts or restarts the game, MakeMove() checks if the player made a valid move on the grid, GetCurrentPlayer() checks what player is taking their turn, SwitchTurn() switches the turn to the other player, CheckWinner() checks which player won or if anyone won in the first place and GetBoard() gives a read-only acces to the board.

# In "visual.hpp", where the game sends visual feedback for the game, DrawBoard() shows the grid and ShowMessage() shows the results of the match.
 
