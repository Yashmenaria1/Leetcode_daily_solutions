class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        int minNumber = INT_MAX;
        int maxNumber = INT_MIN;

        for (int num : arr) {
            if (minNumber > num)
                minNumber = num;
            if (maxNumber < num)
                maxNumber = num;
        }

        if ((maxNumber - minNumber) % (n - 1) != 0)
            return false;

        int difference = (maxNumber - minNumber) / (n - 1);

        int i = 0;

        while (i < n) {
            if (arr[i] == minNumber + difference * i)
                i++;
            else if ((arr[i] - minNumber) % difference != 0)
                return false;
            else {
                int pos = (arr[i] - minNumber) / difference;

                if (pos < i || arr[pos] == arr[i])
                    return false;

                int tmp = arr[pos];
                arr[pos] = arr[i];
                arr[i] = tmp;
            }
        }

        return true;
    }
};
//2nd sol
class Solution {
public:
    bool isArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for(int i = 2; i < n; i++){
            if((arr[i] - arr[i - 1]) != diff){
                return false;
            }
        }
        return true;
    }
};
