#include <iostream>
#include<vector>
using namespace std;

bool isSafeToPlaceQueen(vector<vector<bool>> box, int r, int c){
    vector<vector<int>>dirA = {{0,-1}, {-1,0}, {-1, -1}, {-1, 1}};
    
    for(int d = 0; d<dirA.size();d++){
        for(int rad = 1; rad<=box.size(); rad++){
            int x = r + rad*dirA[d][0];
            int y = c + rad*dirA[d][1];
            
            if(x>=0 && y>=0 && x<box.size() && y<box[0].size()){
                if(box[x][y]){
                    return false;
                } 
            }
            else {
                    break;
                }
        }
    }
    return true;
}

//4*4
int NQueen(vector<vector<bool>> box, int idx, int qpsf, int tnq, string ans){
    if(qpsf == tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    int n = box[0].size(); 
    for(int i=idx;i<n*n;i++){
        int r = i/n;
        int c = i%n;
        if(isSafeToPlaceQueen(box, r, c)){
            box[r][c] = true;
            count+=NQueen(box, i+1, qpsf+1, tnq, ans + "(" + to_string(r) + "," + to_string(c) + ")");
            box[r][c] = false;
        }
    }
    return count;
}

int main() {
    vector<vector<bool>>box(4, vector<bool>(4, false));
    cout<<NQueen(box, 0, 0, 4, "")<<endl;


    return 0;
}