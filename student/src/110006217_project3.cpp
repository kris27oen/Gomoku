#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <climits>


enum SPOT_STATE {
    EMPTY = 0,
    BLACK = 1,
    WHITE = 2
};

int player, opp;
const int SIZE = 15;
int point_x = 6, point_y = 7;
std::array<std::array<int, SIZE>, SIZE> board;


int dirx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; //x-direction, to be used as prediction
int diry[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; //y-direction, to be used as prediction


int check_hori_player(std::array<std::array<int, SIZE>, SIZE> B){
    int counter = 0, total = 0, flag = 0, consec = 0; //define all the needed part
    //check player
    for(int i = 0; i < 15; i++){ //check through y
        counter = 0; //reset counter each y
        for(int j = 0; j < 15; j++){ //check through x
            if(counter == 5 && consec == 5){total += 1000; return total;}
            if(B[i][j] == player){
                counter++;
            }
            else if(B[i][j] == opp){
                if(counter == 3 && flag == 0) total += 50;
                else if(counter == 2 && flag == 0) total += 10;
                else if(counter == 3 && flag == 1) total += 20;
                else if(counter == 4 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    for(int i = 0; i < 15; i++){ //check through y
        counter = 0; //reset counter each y
        for(int j = 0; j < 15; j++){ //check through x
            if(counter == 4){total += 1000; return total;}
            if(B[i][j] == opp){
                counter++;
            }
            else if(B[i][j] == player){
                if(counter == 3 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    return total;
}

int check_verti_player(std::array<std::array<int, SIZE>, SIZE> B){
    int counter = 0, total = 0, flag = 0, consec = 0; //define all the needed part
    //check player
    for(int i = 0; i < 15; i++){ //check through y
        counter = 0; //reset counter each y
        for(int j = 0; j < 15; j++){ //check through x
            if(counter == 5 && consec == 5){total += 1000; return total;}
            if(B[j][i] == player){
                counter++;
            }
            else if(B[j][i] == opp){
                if(counter == 3 && flag == 0) total += 50;
                else if(counter == 2 && flag == 0) total += 10;
                else if(counter == 3 && flag == 1) total += 20;
                else if(counter == 4 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    for(int i = 0; i < 15; i++){ //check through y
        counter = 0; //reset counter each y
        for(int j = 0; j < 15; j++){ //check through x
            if(counter == 4){total += 1000; return total;}
            if(B[j][i] == opp){
                counter++;
            }
            else if(B[j][i] == player){
                if(counter == 3 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    return total;
}

int check_leftD_player(std::array<std::array<int, SIZE>, SIZE> B){
    int counter = 0, total = 0, flag = 1, consec = 0;
    for(int i = 0; i < 25; i++){
        int s = 0, e = 15;
        if(s > i-16) s = i-16;
        if(e < i) e = i;

        counter = 0;
        for(int j = s; j < e; j++){
            int k = i-1;
            if(counter == 5 && consec == 5){total += 1000; return total;}
            if(B[j][k] == player){
                counter++;
            }
            else if(B[j][k] == opp){
                if(counter == 3 && flag == 0) total += 50;
                else if(counter == 2 && flag == 0) total += 10;
                else if(counter == 3 && flag == 1) total += 20;
                else if(counter == 4 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    for(int i = 0; i < 25; i++){
        int s = 0, e = 15;
        if(s > i-16) s = i-16;
        if(e < i) e = i;

        counter = 0, total = 0, flag = 1, consec = 0;
        for(int j = s; j < e; j++){
            int k = i-1;
            if(counter == 4){total += 1000; return total;}
            if(B[j][k] == opp){
                counter++;
            }
            else if(B[j][k] == player){
                if(counter == 3 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    return total;
}

int check_rightD_player(std::array<std::array<int, SIZE>, SIZE> B){
    int counter = 0, total = 0, flag = 1, consec = 0;
    for(int i = 1-SIZE; i < SIZE; i++){
        int s = 0, e = SIZE+i-1;
        if(s < i) s = i;
        if(e < SIZE-1) e = SIZE-1;

        counter = 0;
        for(int j = s; j < e; j++){
            int k = i-1;
            if(counter == 5 && consec == 5){total += 1000; return total;}
            if(B[j][k] == player){
                counter++;
            }
            else if(B[j][k] == opp){
                if(counter == 3 && flag == 0) total += 50;
                else if(counter == 2 && flag == 0) total += 10;
                else if(counter == 3 && flag == 1) total += 20;
                else if(counter == 4 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    for(int i = 1-SIZE; i < SIZE; i++){
        int s = 0, e = SIZE+i-1;
        if(s < i) s = i;
        if(e < SIZE-1) e = SIZE-1;

        counter = 0, total = 0, flag = 1, consec = 0;
        for(int j = s; j < e; j++){
            int k = i-1;
            if(counter == 4){total += 1000; return total;}
            if(B[j][k] == opp){
                counter++;
            }
            else if(B[j][k] == player){
                if(counter == 3 && flag == 0) total += 50;
                flag = 1;
                counter = 0;
            }
            else{
                flag = 0;
                counter = 0;
            }
        }
    }
    return total;
}

int state_val(std::array<std::array<int, SIZE>, SIZE> B){
    int count = 0; //keep the counter/total, which to be return to minimax
    count += check_hori_player(B); //check horizontally
    count += check_verti_player(B); //check vertically
    count += check_leftD_player(B); //check diagonally left
    count += check_rightD_player(B); //check diagonally right
    //std::cout << "value:" << count << std::endl;
    return count; //return count
}

int minimax(std::array<std::array<int, SIZE>, SIZE> B, int depth, int alpha, int beta, bool max_player){
    if(depth == 0){ //when depth reaches 0, it will return the value of the current board
        return state_val(B);
    }
    if(max_player){ //check whether the current prediction branch is a player or enemy
        int value = INT_MIN; //take the most minimum value as the 
        for(int i = 0; i < 15; i++){ //check from y
            for(int j = 0; j < 15; j++){ //check from x
                if(board[i][j] == BLACK || board[i][j] == WHITE){ //check sign from which player
                    for(int k = 0; k < 8; k++){ //check all the possible direction
                        if(board[i+diry[k]][j+dirx[k]] == EMPTY && i+diry[k] > 0 && i+diry[k] < 15 && j+dirx[k] > 0 && j+dirx[k] < 15){ //insert all the possibilities as the tree node
                            std::array<std::array<int, SIZE>, SIZE> temp_board = board;
                            temp_board[i+diry[k]][j+dirx[k]] = player;
                            int temp = minimax(temp_board, depth-1, alpha, beta, false);
                            if(temp > value){
                                value = temp;
                                point_x = j+dirx[k];
                                point_y = i+diry[k];
                            }
                            alpha = std::max(alpha, value);
                            if(alpha >= beta) break;
                        }
                    }
                }
            }
        }
        return value;
    }
    else{
        int value = INT_MAX;
        for(int i = 0; i < 15; i++){ //check from y
            for(int j = 0; j < 15; j++){ //check from x
                if(board[i][j] == BLACK || board[i][j] == WHITE){ //check sign from which player
                    for(int k = 0; k < 8; k++){ //check all the possible direction
                        if(board[i+diry[k]][j+dirx[k]] == EMPTY && i+diry[k] > 0 && i+diry[k] < 15 && j+dirx[k] > 0 && j+dirx[k] < 15){ //insert all the possibilities as the tree node
                            std::array<std::array<int, SIZE>, SIZE> temp_board = board;
                            temp_board[i+diry[k]][j+dirx[k]] = player;
                            int temp = minimax(temp_board, depth-1, alpha, beta, true);
                            if(temp < value){
                                value = temp;
                                point_x = j+dirx[k];
                                point_y = i+diry[k];
                            }
                            alpha = std::min(beta, value);
                            if(alpha >= beta) break;
                        }
                    }
                }
            }
        }
        return value;
    }
}

void read_board(std::ifstream& fin) {
    fin >> player;
    opp = (player == BLACK)? WHITE : BLACK;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> board[i][j];
        }
    }
    //std::cout << "First:" << point_x << " " << point_y << std::endl;
}

void write_valid_spot(std::ofstream& fout) {
    srand(time(NULL));
    // Keep updating the output until getting killed.
    /*
    while(true) {
        // Choose a random spot.
        //int x = (rand() % SIZE);
        //int y = (rand() % SIZE);
        int x = point_x;
        int y = point_y;
        if (board[x][y] == EMPTY) {
            break;
        }
    }*/
    //minimax(board, 4, INT_MIN, INT_MAX, true);
    while(true){
        if(board[point_y][point_x] != EMPTY && point_x < 15 && point_y < 15){
            point_x++;
            point_y++;
            break;
        }
        else if(point_x > 15 || point_y > 15){
            point_x = rand() % SIZE;
            point_y = rand() % SIZE;
            break;
        }
    }
    // Remember to flush the output to ensure the last action is written to file.
    fout << point_x << " " << point_y << std::endl;
    fout.flush();
}

int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}
