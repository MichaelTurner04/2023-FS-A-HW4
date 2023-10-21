-   -2.5: Compiler warnings
-   -2.5: Incorrect behavior

## Detailed Comments

-   You did not structure your ternaries correctly, which caused a compiler warning, but did not create incorrect behavior (as far as I can tell).
-   You did not properly account for the fact that choosing the 4th option from the main menu would change the anxiety, and thus the anxiety could be an invalid value since the loop does not run again. This meant that the anxiety could become negative at the end of the program.

Score: 95

