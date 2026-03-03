#include <stdio.h>

/*
/  EECS 348 Lab 4: Isaiah Jenks
/  This program will read in an NFL score and output every possible combination of touchdowns with two-point conversions,
/  touchdowns with field goals, touchdowns, field goals, and safeties that could have resulted in that score. A score 
/  less than or equal to 1 will stop the program.
*/


int main() {
    { // scope to prevent memory leak from recursive calls to main()
    int score;
    int scoreRemaining;

    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf ("%d", &score);

    if (score <= 1) { // stop the program if the score is a value less than or equal to 1
        return 0;
    }

    printf("\nPossible combinations of scoring plays if a team’s score is %d:\n\n", score);

    for (int i = 0; i <= score / 8; i++) {
        scoreRemaining = score - (i * 8);
        for (int j = 0; j <= scoreRemaining / 7; j++) {
            scoreRemaining = score - (i * 8) - (j * 7);
            for (int k = 0; k <= scoreRemaining / 6; k++) {
                scoreRemaining = score - (i * 8) - (j * 7) - (k * 6);
                for (int l = 0; l <= scoreRemaining / 3; l++) {
                    scoreRemaining = score - (i * 8) - (j * 7) - (k * 6) - (l * 3);
                    for (int m = 0; m <= scoreRemaining / 2; m++) {
                        if ((i * 8) + (j * 7) + (k * 6) + (l * 3) + (m * 2) == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, m);
                        }
                    }
                }
            }
        }
    }
    
    printf("\n");

    }
    main();
}