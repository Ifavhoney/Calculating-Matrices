/*
Name: Jason N'Guessan
ID: 1079936
Date: March 9th 2020
Assignment: Assignment3
Question 2.4: Analyze performance of your brute force and Horspool programs. 
*/

The ftime were set from the beginning of the file, 
to the end of the file. This includes, inserting into an array, creating a shift table, and more necessary tools 
to build Brute Force and Horspool's algorithm

Used 10 patterns

Guelph, computer, Disabilities, co, Communication , increasing, bachelor, undergraduate, call
, GPA

Pattern             |     Horspool's                                | Brute Force
Guelph              |     2196 Matches, 73630 Shifts, 337ms         | 2196 Matches, 46276 Shifts, 713ms     
Computer            |      20 Matches, 817 Shifts, 160ms            | 20 Matches, 802 Shifts, 200ms
Disabilities        |      25 Matches, 430 Shifts, 159ms            | 25 Matches, 1955 Shifts, 613ms
Communication       |      28 Matches, 1018 Shifts, 193ms           | 28 Matches, 2580 Shifts. 251ms
increasing          |       30 Matches, 785 Shifts, 300ms           | 30 Matches, 1913 Shifts, 524ms
Bachelor            |       324 Matches, 10839 Shifts, 634ms        | 324 Matches, 11730 Shifts, 724ms
Undergraduate       |     183 Matches, 5930 shfits, 429ms           | 183 Matches, 16766 Shifts, 537ms
co                  |       11909 Matches, 403003 Shifts, 698ms     | 11909 Matches, 53111 Shifts, 288ms
GPA                 |    4 Matches, 128 Shifts, 0ms                 | 4 Matches, 24 Shifts, 0ms
call                |    730 Matches, 128 Shifts, 69ms              | 730 Matches, 9250 Shifts, 800ms 



Average ratio: 
    Horspool's had a total of 2979ms
    Brute force had a total of 4650ms
        Brute force takes on average 1.56 ((Horspool + Brute force)/2) times longer
analyze the performance of the two programs in terms of ratios

From analyzing this table, although matches remain true, one can see that Brute force requires more shifting 
which therefore increases time.


