class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int back = height.size() - 1;
        int area = INT_MIN;
        
        while (front < back) {
            int temp = (back - front) * min(height[front], height[back]);
            if (temp > area) {
                area = temp;
            }
            
            if (height[back] > height[front]) {
                front++;
            } 
            else {
                back--;    
            }
        }
        
        return area;
    }
};
