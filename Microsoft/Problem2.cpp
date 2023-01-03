//https://leetcode.com/problems/combination-sum-iii/

//Backtracking 
class Solution {
    void findSubsets(int k,int pos ,vector<vector<int>> &res,int n,int currsum,vector<int> &op){
        if (currsum == n ){
            if (op.size() == k)
            res.push_back(op);
            return ;
        }
        if (currsum >n || pos>9)
        return ;
        
        op.push_back(pos);
        findSubsets(k,pos+1,res,n,currsum+pos,op);
        op.pop_back();
        findSubsets(k,pos+1,res,n,currsum,op);
        return ;

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> op;
        findSubsets(k,1,res,n,0,op);
        return res;
    }
};

//DP


//bit Manipulation