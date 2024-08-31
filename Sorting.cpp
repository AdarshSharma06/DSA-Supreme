#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &nums){
    int n=nums.size();
    
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
           if(nums[j]< nums[min]){
              min = j;

           }
        }
        swap(nums[i], nums[min]);
    }
}

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1]){
                swap(nums[j] ,nums[j+1]);
            }
        }
    }
}

int main()
{
    // bubble sort
    vector<int> nums = {5, 4, 3, 2, 1};
    selectionSort(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }

    return 0;
}