//Sudoku Solver : https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>& board,vector<long long> &row,vector<long long>&col,vector<vector<long long>> &box){
        if(i==9)
            return true;
        if(j==9)
            return solve(i+1,0,board,row,col,box);
        if(board[i][j]!='.')
            return solve(i,j+1,board,row,col,box);
        
        for(int n=1;n<=9;n++){
            int mask=1<<(n-1);
            if(!(row[i]&mask) && !(col[j]&mask) && !(box[i/3][j/3]&mask)){
                row[i]|=mask;
                col[j]|=mask;
                box[i/3][j/3]|=mask;
                board[i][j]='0'+n;
                if(solve(i,j+1,board,row,col,box)) return true;
                
                row[i]&=(~mask);
                col[j]&=(~mask);
                box[i/3][j/3]&=(~mask);
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<long long> row(9,0),col(9,0);
        vector<vector<long long>> box(3,vector<long long>(3,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    row[i]|=(1<<(board[i][j]-'1'));
                    col[j]|=(1<<(board[i][j]-'1'));
                    box[i/3][j/3]|=(1<<(board[i][j]-'1'));
                }
            }
        }
        solve(0,0,board,row,col,box);
    }
};
