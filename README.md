-implementation.cpp
    this is the implementation of my code

    The code takes in 81 inputs of numbers to fill a 9x9 Sudoku board going from left to right.

    0 - represents an empty cell of a Sudoku board

    1-9 - represent predetermined cells
    
    example input: 

    9 0 0 0 0 0 0 8 0
    0 1 0 0 0 0 0 0 0
    0 0 2 0 0 0 0 0 0
    0 0 0 3 0 0 0 0 0
    0 0 0 0 4 0 0 0 0
    0 0 0 0 0 5 0 0 0
    0 0 0 0 0 0 6 0 0
    0 0 0 0 0 0 0 7 0
    0 0 0 0 0 0 0 0 8

    This code will print you the neatly formatted initial board and solution board after the function is complete using the Sudoku backtracking algorithm on your given numbers.

    -test inputs/outputs are located in the implementationTests folder


-runtimeanalysis.cpp
    this is the code that was used for the run time analysis that is shown on my report.

    The program is relatively simple and utilizes all the aspects on my implementation but also allows game boards of size 16x16,9x9 for Sudoku. The functions themselves are timed using the chrono library and the results are displayed after the function completes. The game boards hard coded for repetitive testing and this program doesn't require any input.

    - if you wish to change the board numbers, they are labeled as "board" which is a 9x9 two dimension array, and "board2" which is a 16x16 two dimension array which are both located in "main". The numbers are implemented in the same fashion as my implementation.cpp

    -formatting will be off for 16x16 solution and initial boards as it is tricky to get it aligned with larger numbers


-Giovanni DiSalvo, Report, CSCI411
    my report on the algorithm

-Giovanni DiSalvo, Slides, CSCI411
    the slides used for my presentation
