/*

You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.

You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

Return true if all asteroids can be destroyed. Otherwise, return false.

Example 1:

Input: mass = 10, asteroids = [3,9,19,5,21]
Output: true


*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(),asteroids.end());
        long long int m=mass;
        
        for(int i=0;i<asteroids.size();i++){
            if(m<asteroids[i])
                return false;
            else m+=asteroids[i];
        }
        return true;
    }
};