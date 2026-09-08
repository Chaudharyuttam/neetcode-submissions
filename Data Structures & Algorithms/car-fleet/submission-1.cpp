class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();

        vector<pair<int, double>> road;

        for(int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            road.push_back({position[i], time});
        }

        // Sort cars from closest to target to farthest
        sort(road.begin(), road.end(),
             [](const pair<int, double>& a,
                const pair<int, double>& b) {
                    return a.first > b.first;
             });

        int fleets = 0;
        double lastTime = 0;

        for(int i = 0; i < n; i++) {
            double currTime = road[i].second;

            // This car cannot catch the fleet in front
            if(currTime > lastTime) {
                fleets++;
                lastTime = currTime;
            }
        }

        return fleets;
    }
};