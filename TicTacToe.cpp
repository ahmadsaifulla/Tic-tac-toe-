#include <stdio.h>

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) 
{
    printf("\n");
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            printf(" %c ", board[i][j]);
            if (j < 2)
			{
				printf("|");	
			} 
        }
        printf("\n");
        if (i < 2)
		{
			printf("-----------\n");	
		} 
//Above code is performed in switch, case statements
/*
switch (i) {
    case 0:
    case 1:
        printf("-----------\n");
        break;
    default:
        
		break;
}
*/		

//Above code is performed in ternary operators
/*
(i < 2) ? printf("-----------\n") : ;
*/

    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) 
{
    // Check rows and columns
    for (int i = 0; i < 3; i++) 
	{
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
		{
            return 1; // Player wins
        }
        
//Above code performed in switch, case statements
/*
int winCheckResult = checkWin(board, currentPlayer);

switch (winCheckResult) {
    case 1:
        displayBoard(board);
        printf("Player %c wins!\n", currentPlayer);
        break;
    default:
        // Handle other cases if needed
        break;
}

*/
//Above code performed in ternary operators
//(checkWin(board, currentPlayer)) ? (displayBoard(board), printf("Player %c wins!\n", currentPlayer), break) : /* handle other cases if needed */;


    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
	{
        return 1; // Player wins
    }

    return 0; // No winner yet
}

// Function to check if the board is full
int isBoardFull(char board[3][3]) 
{
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            if (board[i][j] == ' ') 
			{
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

int main() {
	printf("WELCOME TO TIC-TAC-TOE\n");
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    char currentPlayer = 'X';
	int countTurn = 0;
	
    do {
    	printf("\n 0,0 | 0,1 | 0,2\n---------------\n 1,0 | 1,1 | 1,2\n---------------\n 2,0 | 2,1 | 2,2\n");
        // Display the current board
        displayBoard(board);

        // Get player move
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
		
        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;
		
		countTurn++;
		printf("Turn : %d\n", countTurn);
		
        // Check for a win
        if(countTurn > 4){
		
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
}
        // Check for a tie
        if (isBoardFull(board)) {
            displayBoard(board);
            printf("The game is a tie!\n");
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

if(currentPlayer == 'X')
{
	currentPlayer = 'O';
}
else
{
	currentPlayer = 'X';
}

    } while (1);

    return 0;
}
