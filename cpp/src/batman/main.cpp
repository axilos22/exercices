#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Position2D {
        int x=0, y=0;
    public:
        Position2D(int x, int y): x(x), y(y){};
        Position2D(const Position2D &pos): x(pos.x), y(pos.y){};
        inline void setX(int value){x=value;}
        inline void setY(int value){y=value;}
        int getX(){return x;}
        int getY(){return y;}
        string getPosition() {return to_string(x)+" "+to_string(y);}
};

Position2D computeNextJump(Position2D current, string bombDir, int current_turn);
float midPoint(float start, float end);

int building_w, building_h;
int min_x=0, max_x=0, min_y=0, max_y=0;

int main()
{
    //input parsing
    cin >> building_w >> building_h; cin.ignore();
    cerr << "Building h=" << to_string(building_h) << " w=" << to_string(building_w) << endl;
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0, Y0, turn=1;
    cin >> X0 >> Y0; cin.ignore();

    // initial
    Position2D current(X0,Y0);
    max_x = building_w-1;
    max_y = building_h-1;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        cerr << "Current pos (" << current.getPosition() << ") bombdir= " << bombDir << " turn= " << to_string(turn) << endl;
        Position2D jump = computeNextJump(current, bombDir, turn);
        cout << jump.getPosition() << endl;
        //end loop
        turn++;
        current = jump;
    }
}

Position2D computeNextJump(Position2D current, string bombDir, int turn) {
    if(bombDir.size()<2)
        bombDir+=" ";
    Position2D next_jump(current);

    if(bombDir.at(0)=='U') {
        max_y = current.getY()-1;
        int next_y = midPoint(min_y,current.getY());
        cerr << "[U] Distance y="<<min_y <<" to y="<<current.getY()<<" = " << next_y << endl;
        next_jump.setY(current.getY() - next_y);
    }
    if(bombDir.at(0)=='D') {
        min_y = current.getY()+1;
        int next_y = midPoint(current.getY(),max_y);
        cerr << "[D] Distance y="<<current.getY() <<" to y="<<max_y<<" = " << next_y << endl;
        next_jump.setY(current.getY() + next_y);
    }

    if(bombDir.at(1)=='R' || bombDir.at(0)=='R') {
        min_x = current.getX()+1;
        int next_x = midPoint(current.getX(),max_x);
        cerr << "[R] Distance from x="<<current.getX() <<" to x="<<max_x<<" = " << next_x << endl;
        next_jump.setX(current.getX() + next_x);
    }
    if(bombDir.at(1)=='L' || bombDir.at(0)=='L') {
        max_x = current.getX()-1;
        int next_x = midPoint(min_x,current.getX());
        cerr << "[L] Distance from x="<<min_x<<" to x="<<current.getX()<<" = " << next_x << endl;
        next_jump.setX(current.getX() - next_x);
    }
    return next_jump;
}

float midPoint(float start, float end) {
    float mp =abs(end-start)/2.;
    return ceil(mp);
}
