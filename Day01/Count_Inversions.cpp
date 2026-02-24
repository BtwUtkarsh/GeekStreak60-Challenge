class Solution {
public:
    int inversionCount(vector<int>& arr) {

        vector<int> freq(10001, 0); 
        int answer = 0;

    
        for (int pos = arr.size() - 1; pos >= 0; pos--) {

            int current = arr[pos];
            answer += getSmallerCount(freq, current - 1);
            addNumber(freq, current);
        }

        return answer;
    }
private:
  
    void addNumber(vector<int>& freq, int value) {
        while (value <= 10000) {
            freq[value]++;
            value = value + (value & (-value));
        }
    }
    int getSmallerCount(vector<int>& freq, int value) {
        int total = 0;
        while (value > 0) {
            total += freq[value];
            value = value - (value & (-value));
        }
        return total;
    }
};

Commit Changes

Added Day 01 GeekStreak60 solution
