#include "mazesolver.h"
#include "mazedisplay.h"
#include "visitedtracker.h"
#include "heap/heap.h"
#include <QMessageBox>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
MazeSolver::MazeSolver(Maze * m, MazeDisplay * md)
    : maze(m), display(md)
{}

void MazeSolver::setMaze(Maze* m) { maze = m; }

void MazeSolver::solveByDFSRecursive()
{
    // delcaring all the things that needed for following helper
    int numSquares = maze -> numRows() * maze -> numCols();
    VisitedTracker vt(maze->numRows(), maze -> numCols());
    vt.setVisited(maze->getStartRow(), maze->getStartCol());
    std::vector <Direction> parent(numSquares);
    std::pair<int, int> node;
    node.first = maze -> getStartRow();
    node.second = maze -> getStartCol();
    int a = 1;
    RecursiveHelper(vt,node, parent,a);

}

void MazeSolver::RecursiveHelper(VisitedTracker &vt,std::pair<int, int> node, std::vector <Direction> parent, int& numExplored){    
    if( node.first == maze->getGoalRow() && node.second == maze->getGoalCol() ){
        std::vector<Direction> path;
        std::stack<Direction> st;
        int r = node.first;
        int c = node.second;
        while( r != maze->getStartRow() || c != maze->getStartCol()){// if ever find the path, put all the nodes in the path in the vector and output
            st.push( parent[ squareNumber(r,c) ]);
            switch( st.top() ){
                case UP: r++; break; // this is oppisite from the direction because when we have UP the parent we pushed in is UP
                case DOWN: r--; break;
                case LEFT: c++; break;
                case RIGHT: c--; break;
            }
        }
        while ( ! st.empty() ){
            path.push_back(st.top());
            st.pop();
        }
        display->reportSolution(path, vt, numExplored);
        return;
    }
    else{
        int r = node.first;
        int c = node.second;
        if ( maze->canTravel(RIGHT, r, c) && ! vt.isVisited(r, c+1) ){//check all the directions that the current node can go
            parent[squareNumber(r, c+1)] = RIGHT;
            vt.setVisited(r, c+1);
            node.first = r;
            node.second =c+1;
            numExplored++;
            RecursiveHelper(vt, node,parent, numExplored);
        }
        if ( maze->canTravel(LEFT, r, c) && ! vt.isVisited(r,c-1) ){
            parent[squareNumber(r, c-1)] = LEFT;
            vt.setVisited(r, c-1);
            node.first = r;
            node.second =c-1;
            numExplored++;
            RecursiveHelper(vt, node,parent, numExplored);//recursively call all the function again
        }
        if ( maze->canTravel(DOWN, r, c) && ! vt.isVisited(r+1,c) ){
            parent[squareNumber(r+1, c)] = DOWN;
            vt.setVisited(r+1, c);
            node.first = r+1;
            node.second =c;
            numExplored++;
            RecursiveHelper(vt, node,parent, numExplored);
        }
        if ( maze->canTravel(UP, r, c) && ! vt.isVisited(r-1,c)){
            parent[squareNumber(r-1, c)] = UP;
            vt.setVisited(r-1,c);
            node.first = r-1;
            node.second =c;
            numExplored++;
            RecursiveHelper(vt, node,parent, numExplored);
        }  
        return;
    }
}

void MazeSolver::solveByAStar(int choice)
{
    // TODO:
    //    if choice is 1, solve by A* using heuristic of "return 0"
    //    else if choice is 2, solve by A* using heuristic of Manhattan Distance
    //    else if choice is 3, solve by A* using heuristic of Euclidean Distance

    // else completely up to you.
    int numSquares = maze->numRows() * maze->numCols();
    VisitedTracker vt(maze->numRows(), maze->numCols());
    VisitedTracker bt(maze -> numRows(),maze ->numCols());
    std::vector<Direction> parent( numSquares );
    int numExplored = 0;
    vt.setVisited(maze->getStartRow(), maze->getStartCol());
    vector<int> dis(numSquares);// use a priority queue to store all the nodes
    MinHeap<pair<int, int> > pq(2);
    dis[0]  = heuristic(choice,maze -> getStartRow(), maze -> getStartCol());
    pq.add(make_pair(maze -> getStartRow(), maze -> getStartCol()), dis[0]);
    while (!pq.isEmpty()){
        pair<int, int> v =pq.peek();
        pq.remove(); // then peek and remove node that needed to be explored
        int r = v.first;
        int c = v.second;
        if (bt.isVisited(r,c)){
            continue;
        }
        bt.setVisited(r,c);
        numExplored++;
        if(r == maze->getGoalRow() && c == maze->getGoalCol()){
            std::vector<Direction> path;
            std::stack<Direction> st;
            //int length = 0;
            while( r != maze->getStartRow() || c != maze->getStartCol()){
                st.push(parent[squareNumber(r,c)]);
                switch(st.top()){
                    case UP: r++; break; 
                    case DOWN: r--; break;
                    case LEFT: c++; break;
                    case RIGHT: c--; break;
                }
            }
            while (!st.empty()){
                path.push_back(st.top());
                st.pop();
                //length++;
            }
            display->reportSolution(path, vt, numExplored);
            //cout << length << endl;
            return;
        }
        if ( maze->canTravel(UP, r, c) ){
            int a = heuristic(choice, r, c);
            int b = heuristic(choice, r-1,c);
            if (!vt.isVisited(r-1,c)){
                parent[squareNumber(r-1, c)] = UP;
                vt.setVisited(r-1,c);
                dis[squareNumber(r-1,c)] = dis[squareNumber(r,c)]+1 -a +b;
                pq.add(std::pair<int,int>(r-1, c), dis[squareNumber(r-1,c)]);
            }
            else{
                if (dis[squareNumber(r-1,c)] > dis[squareNumber(r,c)]+1-a+b){
                    parent[squareNumber(r-1,c)] =UP;
                    dis[squareNumber(r-1,c)] = dis[squareNumber(r,c)]+1 -a +b;
                    pq.add(std::pair<int,int>(r-1, c), dis[squareNumber(r-1,c)]);
                }
            }
        }
        // Note:  this is NOT "else if" ...
        if ( maze->canTravel(DOWN, r, c)){
            int a = heuristic(choice, r, c);
            int b = heuristic(choice, r+1,c);
            if (!vt.isVisited(r+1,c)){
                parent[squareNumber(r+1, c)] = DOWN;
                vt.setVisited(r+1,c);                
                dis[squareNumber(r+1,c)] = dis[squareNumber(r,c)]+1 -a +b;
                pq.add(std::pair<int,int>(r+1, c), dis[squareNumber(r+1,c)]);
            }
            else{
                if (dis[squareNumber(r+1,c)] > dis[squareNumber(r,c)]+1-a+b){
                    parent[squareNumber(r+1,c)] =DOWN;
                    dis[squareNumber(r+1,c)] = dis[squareNumber(r,c)]+1-a+b;
                    pq.add(std::pair<int,int>(r+1, c), dis[squareNumber(r+1,c)]);
                }
            }
        }

        if ( maze->canTravel(LEFT, r, c)){
            int a = heuristic(choice, r, c);
            int b = heuristic(choice, r,c-1);
            if (!vt.isVisited(r,c-1)){
                parent[squareNumber(r, c-1)] = LEFT;
                vt.setVisited(r,c-1);
                dis[squareNumber(r,c-1)] = dis[squareNumber(r,c)]+1 -a +b;
                pq.add(std::pair<int,int>(r, c-1), dis[squareNumber(r,c-1)]);
            }
            else{
                if (dis[squareNumber(r,c-1)] > dis[squareNumber(r,c)]+1-a+b){
                    parent[squareNumber(r,c-1)] =LEFT;
                    dis[squareNumber(r,c-1)] = dis[squareNumber(r,c)]+1 -a +b;
                    pq.add(std::pair<int,int>(r, c-1), dis[squareNumber(r,c-1)]);
                }
            }
        }
        if ( maze->canTravel(RIGHT, r, c)){
            int a = heuristic(choice, r, c);
            int b = heuristic(choice, r,c+1);
            if (!vt.isVisited(r,c+1)){
                parent[squareNumber(r, c+1)] = RIGHT;
                vt.setVisited(r,c+1);    
                dis[squareNumber(r,c+1)] = dis[squareNumber(r,c)]+1-a+b;
                pq.add(std::pair<int,int>(r, c+1), dis[squareNumber(r,c+1)]);
            }
            else{
                if (dis[squareNumber(r,c+1)] > dis[squareNumber(r,c)]+1-a+b){
                    parent[squareNumber(r,c+1)] =RIGHT;
                    dis[squareNumber(r,c+1)] = dis[squareNumber(r,c)]+1-a+b;
                    pq.add(std::pair<int,int>(r, c+1), dis[squareNumber(r,c+1)]);
                }
            }
        }

    }

}




void MazeSolver::solveByDFSIterative()
{
    int r, c;
    int numSquares = maze->numRows() * maze->numCols();
    VisitedTracker vt(maze->numRows(), maze->numCols());

    std::vector<Direction> parent( numSquares ); // what was my immediate prior direction to get here?
    int numExplored = 0;
    vt.setVisited(maze->getStartRow(), maze->getStartCol());
    std::stack<std::pair<int, int>> q;
    q.push(std::pair<int,int>(maze->getStartRow(), maze->getStartCol()));

    while( ! q.empty() ){
        std::pair<int, int> v = q.top();
        q.pop();
        numExplored++;

        r = v.first;
        c = v.second;

        /* This one if statement is different from the pseudo-code provided
           in lecture, because we want to stop when we've reached the goal.
           The code provided in lecture was for if you wanted to do a BFS
           that explored the entire graph.
        */
        if( r == maze->getGoalRow() && c == maze->getGoalCol() ){
            std::vector<Direction> path;
            std::stack<Direction> st;
            //int length = 0;
            while( r != maze->getStartRow() || c != maze->getStartCol()){
                st.push( parent[ squareNumber(r,c) ]);
                
                switch( st.top() ){
                    case UP: r++; break; // yes, r++.  I went up to get here...
                    case DOWN: r--; break;
                    case LEFT: c++; break;
                    case RIGHT: c--; break;
                }
            }
            while ( ! st.empty() ){
                path.push_back(st.top());
                st.pop();
                //length++;
            }
            display->reportSolution(path, vt, numExplored);
            //cout << length << endl;
            return;
        }

        /*
         * Now we're back to code that looks like the pseudo-code you've seen.
         * The difference here is that we aren't keeping track of distances;
           that's similar to the difference above.  You could add, and ignore,
           the vector that would result if you wanted to do so.
         */
        if ( maze->canTravel(UP, r, c) && ! vt.isVisited(r-1,c)){
            parent[squareNumber(r-1, c)] = UP;
            vt.setVisited(r-1,c);
            q.push(std::pair<int,int>(r-1, c));
        }
        // Note:  this is NOT "else if" ...
        if ( maze->canTravel(DOWN, r, c) && ! vt.isVisited(r+1,c) ){
            parent[squareNumber(r+1, c)] = DOWN;
            vt.setVisited(r+1, c);
            q.push(std::pair<int,int>(r+1, c));
        }
        if ( maze->canTravel(LEFT, r, c) && ! vt.isVisited(r,c-1) ){
            parent[squareNumber(r, c-1)] = LEFT;
            vt.setVisited(r, c-1);
            q.push(std::pair<int,int>(r, c-1));
        }
        if ( maze->canTravel(RIGHT, r, c) && ! vt.isVisited(r, c+1) ){
            parent[squareNumber(r, c+1)] = RIGHT;
            vt.setVisited(r, c+1);
            q.push(std::pair<int,int>(r, c+1));
        }
    }
}

void MazeSolver::solveByBFS(){
    /* In lecture on Tuesday March 22, we had a graph
       with vertices numbered 0 to n-1, inclusive.
       Instead, we have vertices with two numbers,
       row and col, in the range:
       [0, maze->numRows()-1], [0, maze->numCols() -1 ]
       to assign each a unique number [0, maze->numRows() * maze->numCols() -1]
       we will say that maze square (r,c) is really number
       r * maze->numCols() + c
    */
    int r, c;
    int numSquares = maze->numRows() * maze->numCols();
    VisitedTracker vt(maze->numRows(), maze->numCols());

    std::vector<Direction> parent( numSquares ); // what was my immediate prior direction to get here?
    int numExplored = 0;
    vt.setVisited(maze->getStartRow(), maze->getStartCol());
    std::queue<std::pair<int, int>> q;
    q.push(std::pair<int,int>(maze->getStartRow(), maze->getStartCol()));

    while( ! q.empty() )
    {
        std::pair<int, int> v = q.front();
        q.pop();
        numExplored++;

        r = v.first;
        c = v.second;

        /* This one if statement is different from the pseudo-code provided
           in lecture, because we want to stop when we've reached the goal.
           The code provided in lecture was for if you wanted to do a BFS
           that explored the entire graph.
        */
        if( r == maze->getGoalRow() && c == maze->getGoalCol() )
        {
            std::vector<Direction> path;
            std::stack<Direction> st;
            //int length = 0;
            while( r != maze->getStartRow() || c != maze->getStartCol())
            {
                st.push( parent[ squareNumber(r,c) ]);
                switch( st.top() )
                {
                case UP: r++; break; // yes, r++.  I went up to get here...
                case DOWN: r--; break;
                case LEFT: c++; break;
                case RIGHT: c--; break;
                }
            }
            while ( ! st.empty() )
            {
                path.push_back(st.top());
                //length ++;
                st.pop();
            }
            display->reportSolution(path, vt, numExplored);
            //cout << length << endl;
            return;
        }

        /*
         * Now we're back to code that looks like the pseudo-code you've seen.
         * The difference here is that we aren't keeping track of distances;
           that's similar to the difference above.  You could add, and ignore,
           the vector that would result if you wanted to do so.
         */
        if ( maze->canTravel(UP, r, c) && ! vt.isVisited(r-1,c))
        {
            parent[squareNumber(r-1, c)] = UP;
            vt.setVisited(r-1,c);
            q.push(std::pair<int,int>(r-1, c));
        }
        // Note:  this is NOT "else if" ...
        if ( maze->canTravel(DOWN, r, c) && ! vt.isVisited(r+1,c) )
        {
            parent[squareNumber(r+1, c)] = DOWN;
            vt.setVisited(r+1, c);
            q.push(std::pair<int,int>(r+1, c));
        }
        if ( maze->canTravel(LEFT, r, c) && ! vt.isVisited(r,c-1) )
        {
            parent[squareNumber(r, c-1)] = LEFT;
            vt.setVisited(r, c-1);
            q.push(std::pair<int,int>(r, c-1));
        }
        if ( maze->canTravel(RIGHT, r, c) && ! vt.isVisited(r, c+1) )
        {
            parent[squareNumber(r, c+1)] = RIGHT;
            vt.setVisited(r, c+1);
            q.push(std::pair<int,int>(r, c+1));
        }
    }
}


int MazeSolver::squareNumber(int r, int c) const
{
    return maze->numCols() * r + c;
}

int MazeSolver::heuristic(int choice, int r, int c){// all the heurstic I have for the problems
    if (choice == 1){
        return 0;
    }
    else if (choice == 2){
        int a = maze -> getGoalCol()-c;
        int b = maze -> getGoalRow()-r;
        return a+b;
    }
    else{
        int a = maze -> getGoalCol()-c;
        int b = maze -> getGoalRow()-r;
        return sqrt(a*a + b*b);
    }
}

