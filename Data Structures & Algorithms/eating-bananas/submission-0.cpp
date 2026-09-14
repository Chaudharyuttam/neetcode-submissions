class Solution {
public:
    bool canEat(vector<int> &piles, int mid, int h){
        int totalhrs = 0;
        
        for(int &number: piles){
            totalhrs += number/mid;//hours

            if(number % mid != 0){//if cant eat piles[i] banana in one go 
               totalhrs++;
            }
        }
        return totalhrs <= h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(begin(piles), end(piles));// we are taking hours (l,r)

        while(l < r){
            int mid = l + (r - l)/2;

            if(canEat(piles, mid, h)){
                r = mid;
            } 
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
