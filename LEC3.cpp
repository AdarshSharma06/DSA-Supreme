#include <iostream>
using namespace std;

int applyBinarySearch(int arr[], int target, int n)
{
  int s = 0;
  int e = n - 1;
  int mid = s + (e - s) / 2;
  int ans = -1;
  while (s <= e)
  {
    if (arr[mid] == target)
    {
      return mid;
    }
    if (arr[mid - 1] == target)
    {
      return mid - 1;
    }
    if (arr[mid + 1] == target)
    {
      return mid + 1;
    }
    if (target > arr[mid])
    {
      // its big so we need to go the left
      s = mid + 2;
    }

    else
    {
      e = mid - 1;
    }
    mid = s + (e - s) / 2;
  }
  return -1;
}

int preciseDivision(int divisor, int dividend)
{
  int s = -dividend;
  int e = dividend;
  int ans = -1;

  // mid is the quotient we are trying to find
  int mid = s + (e - s) / 2;
  while (s <= e)
  {
    int prod = divisor * mid;
    if (prod == dividend)
    {
      return mid;
    }

    if (prod < dividend)
    {
      ans = mid;
      s = mid + 1;
    }
    if (prod > dividend)
    {
      e = mid - 1;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

int findOddOccuring(int arr[], int n)
{
  int s = 0;
  int e = n - 1;
  int mid = s + (e - s) / 2;
  int ans = -1;
  while (s <= e)
  {
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
    {
      return mid;
    }
    if (arr[mid - 1] == arr[mid] && (mid - 1) % 2 == 0)
    {
      // disruption is in the front so move right
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

int sirOddOneOccuring(int arr[], int n)
{
  int s = 0;
  int e = n - 1;
  int mid = s + (e - s) / 2;
  while (s <= e)
  {
    int rightval=-1;
    int leftval=-1;
    int currval=arr[mid];
    if(mid-1>=0){
       leftval=arr[mid-1];
    }
    if(mid+1<=n){
      rightval=arr[mid+1];
    }
    if (s == e)
    {
      return s;
    }
    if (mid - 1 >= 0 && currval != leftval && mid + 1 <= n && currval != rightval)
    {
      return mid;
    }
    // landing on the rightside of  starting index

    if (mid - 1 >= 0, currval==leftval)
    {
      int startingIndex = mid - 1;
      if (startingIndex & 1)
      {
        e = mid - 1;
      }
      else
      {
        s = mid + 1;
      }
    }

    // landing on the starting index
    if (mid + 1 <= n && currval == rightval)
    {

      if (mid & 1)
      {
        e = mid - 1;
      }
      else
      {
        s = mid + 1;
      }
    }
    mid = s + (e - s) / 2;
  }
  return -1;
}

int main()
{
  // to find the sqrt with decimal precision
  // int precision; // precision will be done later

  // cout << "enter the precision" << endl;
  // cin >> precision;

  int divisor;
  int dividend;

  // cout<<"enter the divisor";
  // cin>>dividend ;
  // cout<<"enter the dividend";
  // cin>>divisor;
  // int solution=preciseDivision(abs(dividend), abs(divisor));
  // for the negative cases we first solve it like positive and then decide the sign
  // if(dividend<0 && divisor>0 || divisor<0 && dividend>0){
  //     solution=solution*-1;
  // }
  // cout<<solution ;

  // search in a nearly sorted array
  // int arr[] = {10, 3, 40, 20, 50, 80, 70};
  // int n=7;
  // int target =  3;

  // int ans=applyBinarySearch(arr,target, n);
  // cout<<ans;
  // if(ans == -1 ){
  //     cout<<"answer not found in the array";
  // }
  // else{
  //     cout<<"answer found at the index"<<" "<<ans<<endl;
  // }

  // odd occuring element
  int arr[] = {4, 2, 2, 3, 3};
  int n = 5;
  int ans = findOddOccuring(arr, n);
  cout << "found the odd occuring element at the index" << " " << ans << " " << "and its value is" << " " << arr[ans];
  // also trying the sir's approach --> sirOddOneOut();

  return 0;
}