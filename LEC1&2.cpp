#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        if (target > nums[mid])
        {
            s = mid + 1;
        }
        if (target < nums[mid])
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return -1;
}
void firstOccurence(int arr[], int n, int target2, int &ansIndex)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == target2)
        {
            // mid may or maynot be the first occurnence
            ansIndex = mid;
            e = mid - 1;
        }
        if (target2 > arr[mid])
        {
            s = mid + 1;
        }
        if (target2 < arr[mid])
        {
            e = mid - 1;
        }
        int mid = s + (e - s) / 2;
    }
}

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ansIndex = -1;
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        int number = nums[mid];
        int index = mid;
        int diff = number - index;
        if (diff == 0)
        {
            // so this means nothing is disrupted and disruption will be on the right
            s = mid + 1;
        }
        else if (diff == 1)
        {
            ansIndex = index;
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    if (ansIndex == -1)
    {
        return n;
    }
    return ansIndex;
}

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            // then its sure the answer is towards the right
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int getPivotIndex(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if ((mid + 1) < n && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        if (mid - 1 > 0 && nums[mid] < nums[mid - 1])
        {
            return mid - 1;
        }
        if (nums[mid] > s)
        {
            // means on line a so move right
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int binarySearch(vector<int> nums, int target, int s, int e)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        if (target < nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int s = 0;
    int n = nums.size();
    int e = n - 1;

    int pivotIndex = getPivotIndex(nums);
    if (target >= nums[0] && target <= nums[pivotIndex])
    {
        // its on line a
        int ans = binarySearch(nums, target, 0, pivotIndex);
        return ans;
    }
    if (target >= nums[pivotIndex + 1] && target <= nums[n - 1])
    {
        int ans = binarySearch(nums, target, pivotIndex + 1, n - 1);
        return ans;
    }
    return -1;
}

int mySqrt(int x)
{
    int s = 0;
    int e = x;
    long long int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        long long int prod = mid * mid;
        if (prod == x)
        {
            return mid;
        }
        if (prod < x)
        {
            // then it may or maynot be the answer
            // so store and compute
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int columns = matrix[0].size();
    int n = rows * columns;

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        // remember how to find the row index and col index based on the mid value

        int rowIndex = mid / columns;
        int colIndex = mid % columns;
        if (matrix[rowIndex][colIndex] == target)
        {
            return true;
        }
        if (target > matrix[rowIndex][colIndex])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return false;
}
int main()
{

    // question on binary search
    vector<int> nums;
    int target;
    // search(nums , target);

    // to find the first occurence

    int arr[] = {20, 20, 20, 30, 40, 50, 60};
    int n = 7;
    int target2 = 20;
    int ansIndex = -1;
    // firstOccurence(arr, n, target2, ansIndex);
    // cout << ansIndex;

    // to find the missing number using binary search
    //  missingNumber(nums);

    // peak index in an mountain array

    // to find the target in a rotated sorted array
    // first we try to find the peak that is the pivot and the we perform binary search twice
    // getPivotIndex(), BinarySeach(), search()

    // search space pattern leetcode problem 69
    int x = 54;
    int ans = mySqrt(x);
    cout << ans;

    // to search in a 2d array using bs
    // searchMatrix();

    return 0;
}