#include<iostream>
#include "pathfinder.h"
#include<cstdlib>
#include<ctime>
#include"disjointSet.h"
#include"Sampler.h"
#include"stack.h"

using namespace std;

int nC;
int nR;
unsigned char maze[50][50];
void GenerateMaze(int nR, int nC);
void FindPath(unsigned char maze[][50]);

int main(int argc, char *argv[]) {
	srand(time(NULL));

	 if (!(argc == 3))
    {
        cout << "This must have two parameters, please check again!\n";
        return 1;
    }
    nR = atoi(argv[1]);
    nC = atoi(argv[2]);
    GenerateMaze(nR,nC);
    //cout<<"Print Test1 For Generate Maze" << endl;
    FindPath(maze);
    //cout<<"Print Test2" << endl;
    printMaze(maze,nR,nC);
   // cout<<"Print Test3" << endl;
    return 0;
}


void GenerateMaze(int nR, int nC) {
	 int i, r, c,e, d;
	for (r = 0; r < nR; r++) {

       for (c = 0; c < nC; c++) {
          maze[r][c] = 15; //1 + 2 + 4 + 8 walls
        }
    }
	DisjointSet ds(nR*nC);
	Sampler sample(4*(nR*nC));
	i = 0;
	while(i < (nR*nC - 1)) {
		e = sample.getSample();
		cout << i << "   " << e;
		//Decode
		d = e % 4; 
		e = e / 4;
		c = e % nC;
		r = e / nC;
		cout << "   " << d << ' ' << r << ' ' << c << endl;
		//looking up
		if(d == 0) {
			//Up wall is exterior 
			if(r == 0)
				continue;
			if((maze[r][c] & WALL_UP) == 0)
				continue;
			if(ds.find(r * nC + c) ==  ds.find((r-1) * nC + c)) //Find Loop
				continue;
			//removing walls from both sides
			maze[r][c] &= ~WALL_UP;
			maze[r-1][c] &= ~WALL_DOWN;
			ds.Join(r * nC + c,(r-1) * nC + c);
			i++;
		}
		//while looking right
		else if(d == 1) {
			//checking if right exterior is a Wall
			if(c == nC - 1)
				continue;
			// checking if bottom exterior wall
            if ((maze[r][c] & WALL_RIGHT) == 0)
                continue;
             if (ds.find(r * nC + c) == ds.find(r * nC + (c + 1))) //Find Loop
             	continue;
             //removing walls from both sides
            maze[r][c] &= ~WALL_RIGHT;
            maze[r][c+1] &= ~WALL_LEFT;
            ds.Join(r * nC + c,r * nC + (c + 1));
            i++;
		}
		//while looking down
		else if(d == 2) {

			if(r == nR - 1)
				continue;
			 if ((maze[r][c] & WALL_DOWN) == 0)
                continue;
            if (ds.find(r * nC + c) == ds.find((r + 1) * nC + c)) 
                continue; 
            // removing walls from both sides
            maze[r][c] &= ~WALL_DOWN;
            maze[r + 1][c] &= ~WALL_UP;
            ds.Join(r * nC + c,(r + 1) * nC + c);
            i++;
		}
		else {
				if (c == 0)
		            continue;
		        if ((maze[r][c] & WALL_LEFT) == 0)
		            continue;
		        if (ds.find(r * nC + c) == ds.find(r * nC + (c - 1))) 
		            continue; 
		        // removing walls from both sides
		        maze[r][c] &= ~WALL_LEFT;
		        maze[r][c -1] &= ~WALL_RIGHT;

		        ds.Join(r * nC + c,r * nC + (c - 1));
		        i++;
		}
	}
}

void FindPath(unsigned char maze[][50]) {
	Stack<int> S;
    int temp;
    int R, C;
    S.push(0);
    //(r,c) == VISITED;
    maze[0][0] |= VISITED;
    bool flag = true;
    while (flag)
    {
        int e = S.peek();
        int c = e % nC;
        e /= nC;
        int r = e % nR;
        int d = e / nR;

        if ((r == nR - 1) && (c == nC - 1))
        {
            break;
        }

        if (d == 4)
        {
            //(r,c) = DEAD_END;
            maze[r][c] |= DEAD_END;
            S.pop();
        }
        else if (d == 0)
        {
            R = r - 1;
            C = c;
            temp = S.peek();
            S.pop();
            temp += nR * nC;
            S.push(temp);
            if ((maze[r][c] & WALL_UP) == 0 && (maze[R][C] & VISITED) == 0)
            {
                S.push(C + nC * R);
                maze[R][C]  |= VISITED;
            }
        }
        else if (d == 1)
        {
            R = r;
            C = c + 1;
            temp = S.peek();
            S.pop();
            temp += nR * nC;
            S.push(temp);
            if ((maze[r][c] & WALL_RIGHT) == 0 && (maze[R][C] & VISITED) == 0)
            {
                S.push(C + nC * R);
                maze[R][C] |= VISITED;
            }
        }
        else if (d == 2)
        {
            R = r + 1;
            C = c;
            temp = S.peek();
            S.pop();
            temp+= nR* nC;
            S.push(temp);
            if( (maze[r][c] & WALL_DOWN) == 0 && (maze[R][C] & VISITED) == 0)
            {
                S.push(C + nC * R);
                maze[R][C] |= VISITED;
            }
        }
        else
        {
            R = r;
            C = c-1;
            temp = S.peek();
            S.pop();
            temp+= nR * nC;
            S.push(temp);
            if ((maze[r][c] & WALL_LEFT) == 0 && (maze[R][C] & VISITED) == 0)
            {
                S.push(C + nC *R);
                maze[R][C] |= VISITED;
            }
        }
    }

}