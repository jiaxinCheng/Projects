#ifndef MAZESOLVER_H
#define MAZESOLVER_H


#include "visitedtracker.h"
#include "maze.h"
#include <stack>
#include <utility>
/*
 * I didn't want the students to have to deal
 * with function pointers, so I'm making the
 * MazeSolver an object with various solve
 * methods.
 *
 * I won't be offended if anyone wants to refactor
 * this to make specific functions for them to call.
 */
class MazeDisplay;
class Maze;

class MazeSolver
{
public:
    MazeSolver(Maze * m, MazeDisplay * md);

    void solveByBFS();

    void solveByDFSIterative();

    void solveByDFSRecursive();

    void solveByAStar(int heuristicChoice);
    //
    void setMaze(Maze* m);

private:
	int heuristic(int choice, int r, int c);
	void RecursiveHelper(VisitedTracker &vt,std::pair<int, int> node, std::vector<Direction> parent, int &numExplored);

    int squareNumber(int r, int c) const;

    Maze * maze;
    MazeDisplay * display;
};

#endif // MAZESOLVER_H
