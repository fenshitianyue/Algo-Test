#include <vector>
using namespace std;

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int map[9] = {0};
        int k = 0;
        for(size_t i = 0; i != board.size(); ++i){
            for(size_t j = 0; j != board[0].size(); ++j){
                map[k++] = board[i][j];
            }
        }
        if(1 == map[0] && 1 == map[1] && 1 == map[2]){
            return true;
        }else if(1 == map[3] && 1 == map[4] && 1 == map[5]){
            return true;
        }else if(1 == map[6] && 1 == map[7] && 1 == map[8]){
            return true;
        }else if(1 == map[0] && 1 == map[3] && 1 == map[6]){
            return true;
        }else if(1 == map[1] && 1 == map[4] && 1 == map[7]){
            return true;
        }else if(1 == map[2] && 1 == map[5] && 1 == map[8]){
            return true;
        }else if(1 == map[0] && 1 == map[4] && 1 == map[8]){
            return true;
        }else if(1 == map[2] && 1 == map[4] && 1 == map[6]){
            return true;
        }else{
            return false;
        }
    }
};
