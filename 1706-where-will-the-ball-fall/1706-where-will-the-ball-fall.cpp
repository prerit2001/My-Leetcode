enum position {tlbrup, tlbrdown, trblup, trbldown};

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        // traps points -> 
        // 1. col1 and left border
        // 2. colm and right border
        // 3. v shape
        
        
        // dimension of grid
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        // required answer vector needed to be filled
        vector<int> answer(colSize, 0);
        
        // traverse to each and every col and feed our answer vector
        for(int col = 0; col < colSize; col ++){
            
            int curRow = 0;
            int curCol = col;
            enum position pos;
            
            int &curCell = grid[curRow][curCol];
            if(curCell == 1){
                pos = tlbrup;
            }
            else{
                pos = trblup;
            }
            
            // checksum
            if(pos == trblup and col == 0){
                answer[col] = -1;
                continue;
            }
            if(pos == tlbrup and col == colSize - 1){
                answer[col] = -1;
                continue;
            }
            if(col < colSize - 1 and pos == tlbrup and grid[0][col + 1] == -1){
                answer[col] = -1;
                continue;
            }
            if(col > 0 and pos == trblup and grid[0][col - 1] == 1){
                answer[col] = -1;
                continue;
            }
            
            // naive traversing
            while(curRow < rowSize){
                if(pos == tlbrup){
                    if(curCol == colSize - 1){
                        answer[col] = -1;
                        break;
                    }
                    int &next = grid[curRow][curCol + 1];
                    if(next == -1){
                        answer[col] = -1;
                        break;   
                    }
                    pos = tlbrdown;
                    curCol ++;
                    continue;
                }
                if(pos == tlbrdown){
                    if(curRow == rowSize - 1){
                        answer[col] = curCol;
                        break;
                    }
                    int &next = grid[curRow + 1][curCol];
                    if(next == 1){
                        pos = tlbrup;
                    }
                    else{
                        pos = trblup;
                    } 
                    curRow ++;
                    continue;
                }
                if(pos == trblup){
                    if(curCol == 0){
                        answer[col] = -1;
                        break;
                    }
                    int &next = grid[curRow][curCol - 1];
                    if(next == 1){
                        answer[col] = -1;
                        break;   
                    }
                    pos = trbldown;
                    curCol --;
                    continue;
                }
                if(pos == trbldown){
                     if(curRow == rowSize - 1){
                        answer[col] = curCol;
                        break;
                    }
                    int &next = grid[curRow + 1][curCol];
                    if(next == 1){
                        pos = tlbrup;
                    }
                    else{
                        pos = trblup;
                    } 
                    curRow ++;
                    continue;
                }
            }            
        }
        
        return answer;
        
    }
};