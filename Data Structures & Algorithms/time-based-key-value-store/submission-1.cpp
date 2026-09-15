class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }

        vector<pair<int, string>>& v = mp[key];
        int start = 0, end = v.size()-1;
        string ans = "";

        while(start <= end){
            int mid = start + (end - start)/2;
            if(v[mid].first <= timestamp){
                ans = v[mid].second;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};
