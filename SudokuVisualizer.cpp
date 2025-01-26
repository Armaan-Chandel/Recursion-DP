class Solution {
    bool canput(int i,int j,vector<vector<char>>& arr,char n){
    for(int a=0;a<9;a++){
        if(arr[i][a]==n) return false;
        if(arr[a][j]==n) return false;
        if(arr[3*(i/3)+a/3][3*(j/3)+a%3]==n) return false;
    }
    return true;
    
}
bool sudoku(vector<vector<char>> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]=='.'){
                for(char n='1';n<='9';n++){
                    if(canput(i,j,arr,n)){
                        arr[i][j]=n;
                    
                    if(sudoku(arr)){
                        return true;
                    }
                    arr[i][j]='.';
                }
                }
            
            return false;
            }
            
        }
    }
    return true;
    
}
public:
    
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};
