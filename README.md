# FLA-generate-accepted-word
Formal Languages and Automata - Generate accepted word of given length
  
##Task##
You are given a deterministic finite automata and an integer n. Generate a word of length n that will be accepted by the automata, if possible.
  
##Conventions##
-the start state is 0  
-states will be numbered from 0  
-we are given the last not final state (nefin), and all the states that have bigger index will be final 

##Input##
On the first line of the file there will be nr and nefin, where:  
-nr = the number of states  
-nefin = the last state that is not final  
*(states from 0 to nefin are not final, states from nefin+1 to nr are final)*  
The next lines will have the format *state1 c state2*, meaning that from *state1* with character *c* you get to *state2*.  
We read n from keyboard.

##Output##
An accepted word of length n.

###Sample Input###
4 2  
0 a 1  
0 c 0  
1 b 2  
2 b 1  
2 c 3  
  
n = 6

###Sample output###
cabbbc

##Implemented solution##
*We read the input then we create **mat**, the adjacency matrix for the tree of states we will use.  
*We start from the initial state 0 that will be the root of the tree.  
*We use BFS algorithm principle to generate all the possible paths from all our states and we will stop only when we get to level n. 
*When we have generated level n, we check to see if we have any final states on level n.  
 *If so, we track back our path, find and print the word we need.  
 *If not, there is no possible way of generating the word.  
   
For our example, the generated tree will look like this at the beginning: 
![Example tree](https://s22.postimg.org/sfm0umiap/tree.png)

##Use of variables/functions##
-**Nod** -> structure in which for every node of the tree we hold the state it contains, its parent, the letter with which we reach it, the level on the tree it is on   
-**c** -> queue of nodes  
-**a** -> the initial matrix we create using the input; the columns correspond with letters (column 0 - letter a, column 1 - letter b and so on); a[i][j] has the meaning: from state i with letter corresponding with the column number we get to state a[i][j]  
-**mat** -> matrix of adjacency for the tree; mat[i][j] has the meaning: from state i we get to state j    
-**BFS(int n)** -> generates and prints the word or corresponding message if that is impossible  
-**initialize (int x, int a[100][100])** -> function that initializes elements of matrix a with the value x
