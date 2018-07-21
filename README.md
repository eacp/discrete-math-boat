# "Herbivores and Carnivores" Problem
### Eduardo Castillo
### A0102948
### Discrete Math

This is the solution for a problem for my Discrete Math course. This is the problem 17A of the course. 

## Problem
The problem consists of using the data structure knonw  as Graph to plot the possible trips of a ship to complete a task, give a certain group of rules every travel must follow.

The rules are the following:

* At no point on the trip the amoun of carnivores should exceed the amount of herbivores in either side, **unless** the boat is in that side. This is because the boat may prevent the animals from eating each other
* You can only carry 1 or 2 animals in the boat and there has to be at least one animal in the boat ir order for the boat to function properly

You **don't** have to find the shortest path to solve the problem. That's outside the scope of this excersice. Just generate the graph, either by printing the adyacency matrix or by creating an image of it.

## Solution

To solve the problem, and other similar problems, we can use a program to generate all posible combinations of states, each state specifies how many herbivores and carnivores are at every side of the river, and the location of the boat. Then, filter the valid combinations (those who follow the rules above) and discard the invalid. After filtering the valid combinations, create an adyacency matrix of them and print the adyacency matrix. 

This gets resumed as:

1. Generate possible combinations. These may be generated oreviously and held as constants. 
2. Filter the combinations and keep the valid ones
3. Stablish connections between them
4. Store those connections in a matrix
5. Print the matrix

## Update:

Now you can use an arbitrary number N for the animals of each type, and generate the combinations. You can either type the number in the command line or pass it as n argument to the program.
