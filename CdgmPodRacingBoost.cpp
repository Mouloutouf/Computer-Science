#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    bool start_game = true;
    // game loop
    while (1) {
        int x;
        int y;
        int next_checkpoint_x; // x position of the next check point
        int next_checkpoint_y; // y position of the next check point
        int next_checkpoint_dist; // distance to the next checkpoint
        int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
        int opponent_x;
        int opponent_y;
        cin >> opponent_x >> opponent_y; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        bool first_turn;
        bool start_checkpoint;

        int first_checkpoint_x; // x position of the first check point
        int first_checkpoint_y; // y position of the first check point

        // initialize first checkpoint and start checkpoint and first turn as game starts
        if (start_game == true){
            first_checkpoint_x = next_checkpoint_x;
            first_checkpoint_y = next_checkpoint_y;
            first_turn = true;
            start_checkpoint = true;
            start_game = false;
        }

        // if start checkpoint is not next checkpoint mark it passed
        if (first_checkpoint_x != next_checkpoint_x && first_checkpoint_y != next_checkpoint_y){
            start_checkpoint = false;
        }

        // if next checkpoint is first checkpoint and start checkpoint is passed finish first turn
        if (start_checkpoint == false && first_checkpoint_x == next_checkpoint_x && first_checkpoint_y == next_checkpoint_y){
            first_turn = false;
        }

        int max_checkpoint_dist; // distance to the furthest checkpoint
        int max_checkpoint_x; // x position of the furthest check point
        int max_checkpoint_y; // y position of the furthest check point

        // during first turn record the furthest checkpoint
        if (first_turn == true && next_checkpoint_dist > max_checkpoint_dist){
            max_checkpoint_dist = next_checkpoint_dist;
            max_checkpoint_x = next_checkpoint_x;
            max_checkpoint_y = next_checkpoint_y;
        }

        string thrust = "";
        // if going forward
        if (next_checkpoint_angle < 90 && next_checkpoint_angle > -90){
            // if going staright forward
            if (next_checkpoint_angle < 45 && next_checkpoint_angle > -45){
                // if not in first turn and the next checkpoint is the furthest checkpoint
                if (first_turn == false && max_checkpoint_x == next_checkpoint_x && max_checkpoint_y == next_checkpoint_y){
                    // perform a boost acceleration
                    thrust = " BOOST";
                }
                else{
                    // perform a normal acceleration
                    thrust = " 100";
                }
            }
            else{
                // perform a normal acceleration
                thrust = " 100";
            }
        }
        else{
            thrust = " 0";
        }

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        cout << next_checkpoint_x << " " << next_checkpoint_y << thrust << endl;
    }
}