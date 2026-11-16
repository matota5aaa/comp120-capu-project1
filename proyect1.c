#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void init_board(char board[]) {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void display_board(char board[]) {
    char c[9];
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            c[i] = '0' + i;
        } else {
            c[i] = board[i];
        }
    }

    printf("\n");
    printf(" %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[6], c[7], c[8]);
    printf("\n");
}


bool is_winner(char board[], char p) {

    if (board[0] == p && board[1] == p && board[2] == p) return true;
    if (board[3] == p && board[4] == p && board[5] == p) return true;
    if (board[6] == p && board[7] == p && board[8] == p) return true;
    // columns
    if (board[0] == p && board[3] == p && board[6] == p) return true;
    if (board[1] == p && board[4] == p && board[7] == p) return true;
    if (board[2] == p && board[5] == p && board[8] == p) return true;
    // diagonals
    if (board[0] == p && board[4] == p && board[8] == p) return true;
    if (board[2] == p && board[4] == p && board[6] == p) return true;
    return false;
}


char other_player(char p) {
    if (p == 'O') {
        return 'X';
    }
    return 'O';
}

int get_human_move(char board[]) {
    int move;
    bool valid = false;

    while (!valid) {
        printf("Your turn (O). Enter a square number (0-8): ");
        if (scanf("%d", &move) != 1) {
            printf("  That is not a number.\n");
            while (getchar() != '\n') {     
            }
        } else if (move < 0 || move > 8) {
            printf("  Enter a number from 0 to 8.\n");
        } else if (board[move] != ' ') {
            printf("  That square is already taken. Choose an empty one.\n");
        } else {
            valid = true;
        }
    }
    return move;
}

int get_computer_move(char board[]) {
    int move;
    do {
        move = rand() % 9;
    } while (board[move] != ' ');
    return move;
}

void take_turn(char board[], char player) {
    int move;
    if (player == 'O') {
        move = get_human_move(board);
        board[move] = 'O';
    } else {
        printf("Computer (X) is thinking...\n");
        move = get_computer_move(board);
        board[move] = 'X';
        printf("Computer (X) chose square %d. Your move next!\n", move);
    }
}

void play_game(void) {
    char board[9];
    char player = 'O';
    bool game_over = false;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < 9 && !game_over; turn++) {
        take_turn(board, player);
        display_board(board);

        if (is_winner(board, player)) {
            printf("%c wins!\n", player);
            game_over = true;
        } else {
            player = other_player(player);
        }
    }

    if (!game_over) {
        printf("It's a draw!\n");
    }
}

bool play_again(void) {
    char answer;
    do {
        printf("\nPlay again (y) or quit (q)? ");
        if (scanf(" %c", &answer) != 1) {
            return false;  
        }
    } while (answer != 'y' && answer != 'q');

    return answer == 'y';
}

int main(void) {
    srand(time(NULL));

    printf("=====================================\n");
    printf("        TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O and you go first. The computer is X.\n");

    bool again;
    do {
        play_game();
        again = play_again();
    } while (again);

    return 0;
}