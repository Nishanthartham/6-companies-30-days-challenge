//https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0;
        int y=0;
        vector<int> repetitions(10,0);
        for (int i =0;i<secret.size();i++){
            if (secret[i] == guess[i]){
                x++;
                guess[i] = -1;//masking
            }
            else
                repetitions[secret[i]-'0']++;
        }
        for (int i =0;i<guess.size();i++){
            if (guess[i]!=-1 and repetitions[guess[i]-'0']>0){
                repetitions[guess[i]-'0']--;
                y++;
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};