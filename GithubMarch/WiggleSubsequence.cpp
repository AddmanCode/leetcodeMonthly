class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int low = 1, high = 1; // to select only the peak nodes!
        for(int i=0; i<(nums.size())-1; i++) { //loop to traverse through the vector
            if(nums[i] < nums[i+1]) //case 1 : if the previous num is lesser than next num
                high = low + 1;  //balencing high using low
            if(nums[i] > nums[i+1])// case 2: if the previous num is bigger than next num
                low = high + 1; //balencing low using high
            
        }
        if(high>low) //returning the one which is max!
            return high;
        else
            return low;
    }
};