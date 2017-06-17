# include <iostream>

using namespace std;

int maxArea(vector<int>& height) {
    int i = 0, j=height.size()-1;
    int water, h;
    while (i < j) {
        h = min(height[i], height[j]);
        water = max(water, (j-i)*h);
        while (height[j] <= h && i < j) j--;
        while (height[i] <= h && i < j) i++;
    }
    
    return water;
}

int main() {

    return 0;
}