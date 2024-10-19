class Solution {
public:
    
    int maxTime = INT_MIN;
    string answer = "";

    void helper(vector<int> &arr, string res, vector<bool> &visited){

        if(visited[0] and visited[1] and visited[2] and visited[3]){
            if(getTime(res) > maxTime){
                maxTime = getTime(res);
                answer = res;
            }
            return;
        }

        for(int i = 0 ; i < 4 ; i++){
            if(!visited[i]){
                visited[i] = true;
                res += to_string(arr[i]);
                helper(arr, res, visited);
                visited[i] = false;
                res.pop_back();
            }
        }
    }

    int getTime(string res){
        int first = res[0] - '0';
        int second = res[1] - '0';
        int third = res[2] - '0';
        int fourth = res[3] - '0';
        int hours = first * 10 + second;
        int minutes = third * 10 + fourth;
        if(hours > 23 or minutes > 59) return INT_MIN;
        return hours * 60 + minutes;
    }

public:
    string largestTimeFromDigits(vector<int>& arr) {
        // Intution
        // The solution in here is divided in total into three different steps.
        // Finding all the valid strings
        vector<bool> visited(4, false);
        helper(arr, "", visited);
        return answer != "" ? answer.substr(0, 2) + ":" + answer.substr(2) : answer;
   
};