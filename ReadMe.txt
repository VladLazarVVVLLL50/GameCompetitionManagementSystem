 PA Project

1. Explanation of `main.c`

The `main` function receives two parameters: an integer `argc` and a vector of strings where input files (`c.in`, `d.in`) and the output file (`r.out`) are specified. We open the requirement and result files, initialize a task vector, and read the list of tasks. Depending on the required tasks, we solve each task through specific functions (`solve_task_"task_number"`), and all functions will be explained later. 

We will use an integer for the number of teams, a list of teams, and a list of winners necessary for tasks 4 and 5. All these variables will be updated as we progress through the tasks. At the end, we free the memory used and close the files.

2. Solving the First Task

To solve the first task, we will use a function called `solve_task_1` which is called in `main` and receives the input file containing the team data and returns the list of teams and the number of teams. 

First, we open the file with data and read the number of teams. We initialize a list of teams `list_head` with `NULL`. In a `for` loop, we read the data for each team, build it using the `create_team` function, and add the created team to the beginning of the team list according to the requirements, using specific list functions explained below.

In the `create_team` function, we create each team from the data read. We open the data file and declare buffers for the team name and the first and last name of each player. In a `for` loop, we read the list of players for each team, including their names and individual scores, and add each player to the list of players associated with each team through functions defined in the list library.

3. Solving Task 2

Task two is handled by the `solve_task_2` function, which is called in `main` and uses the information from task 1. 

In the task 2 solution, we create a variable that shows the new number of teams after reducing the total number of teams. This is calculated using the `reduce_number` function. We iterate through the team list to find the lowest scores and eliminate the teams associated with those scores, where `n = old number of teams - new number of teams`.

The score of a team is calculated using the `find_score` function, which iterates through the entire team and calculates the score based on the formula in the task requirements. The `eliminate_teams` function is used to remove the team with the lowest score from the list. This is done by finding the team with the minimum score and eliminating it using the `eliminate_team` function from the list library.

In the end, task 2 returns the updated team list and the new number of teams to `main`.

4. Solving Task 3

Task 3 is solved by the `solve_task_3` function, which is called in `main` and contains the updated team list from task 2 and the new number of teams. It returns, according to the requirements, the list of the 8 winning teams and displays the rounds and winners from each round.

We start by declaring two stacks: one for winners and one for losers, as well as a match queue. We also declare a variable that holds the current round and one for the round where only the 8 winning teams remain.

We display the list of all teams and add them to the match queue. As long as there are teams in the match queue, we display the round number and current round, and we find the maximum score between two teams in a match. According to the score, we add the team to either the winners' stack or the losers' stack, while also increasing the winner team's score according to the requirements. 

Then, we display the teams from the winners' stack and put them back into the match queue. If we are at the round with the 8 winners, we add all of them to the winners' list, which is then returned. We also remove the teams from the losers' list. This process continues until there is only one winning team left.

5. Solving Tasks 4 and 5

These tasks are solved by a single function that receives the list of winners generated in the previous task, the output file, and the task number to be solved (4 or 5). 

Initially, we insert the content of the winners' list into a binary tree using functions from the tree library, and then we traverse the tree in reverse inorder to display the teams as required. If task 5 also needs to be solved, we create an AVL tree and populate it with the teams from the binary tree traversed in inorder.

Thus, the created AVL tree will be balanced only through right rotations. After creating the AVL tree, we traverse it by levels and display the contents of level 2.

Libraries for Data Structures

For solving the tasks, we use 4 libraries that describe the functions used for creating and manipulating the following data structures: lists, stacks, queues, and trees. All the functions are similar to those presented during the course but updated for the problem requirements.
