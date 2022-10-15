class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int emp = logs[0][0];
        int tm = logs[0][1];
        
        for(int i=1;i<logs.size();i++){
        int diff = logs[i][1]-logs[i-1][1];
        
        if(diff > tm){
            tm = diff;
            emp = logs[i][0];
        }
        else if(diff==tm){
            emp = min(emp,logs[i][0]);
        }
        
        
        }
        return emp;
    }
};