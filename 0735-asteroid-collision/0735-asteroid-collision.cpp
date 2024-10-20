class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::list<int> st; // Use list as a stack
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]); // Push positive asteroids to stack
            } else {
                // Handle collisions with previous positive asteroids
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back(); // Pop smaller positive asteroids
                }
                
                // If both asteroids are equal in size, both will be destroyed
                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back(); // Both asteroids explode
                }
                // If stack is empty or the top is a negative asteroid, push the current one
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }
        
        // Convert list to vector for the final result
        return std::vector<int>(st.begin(), st.end());
    }
};
