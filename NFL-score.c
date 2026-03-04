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

    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf ("%d", &score);

    if (score <= 1) { // stop the program if the score is a value less than or equal to 1
        return 0;
    }

    printf("\nPossible combinations of scoring plays if a team’s score is %d:\n\n", score);


    // Try all possible combinations of scoring plays (8, 7, 6, 3, and 2 point values)
    // Iterate through touchdowns with 2-point conversions (8 points each)
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
        int remainingAfter8pt = score - (td2pt * 8);
        
        // Iterate through touchdowns with field goals (7 points each)
        for (int tdFg = 0; tdFg * 7 <= remainingAfter8pt; tdFg++) {
            int remainingAfter7pt = remainingAfter8pt - (tdFg * 7);
            
            // Iterate through regular touchdowns (6 points each)
            for (int touchdowns = 0; touchdowns * 6 <= remainingAfter7pt; touchdowns++) {
                int remainingAfter6pt = remainingAfter7pt - (touchdowns * 6);
                
                // Optimization: Start field goals at either 0 or 1 (even or odd) so that there is always an even remainder for safeties
                // Increment by 2 to skip impossible point combinations
                int startFg = remainingAfter6pt % 2; // Start at 1 if the remaining points after touchdowns is odd, otherwise start at 0
                for (int fieldGoals = startFg; fieldGoals * 3 <= remainingAfter6pt; fieldGoals += 2) {
                    int remainingAfter3pt = remainingAfter6pt - (fieldGoals * 3);
                    int safeties = remainingAfter3pt / 2;
                    // No need to check if the total points equals the input score, because the loop conditions ensure that it will always be the case
                    // i.e. There will be no unnecessary loops
                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFg, touchdowns, fieldGoals, safeties);
                }
            }
        }
    }
    
    printf("\n");

    }
    main();
}