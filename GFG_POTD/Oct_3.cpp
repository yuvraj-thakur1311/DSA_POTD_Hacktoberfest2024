
// question link: https://www.geeksforgeeks.org/problems/majority-vote/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
 // Function to find the majority elements in the array
 vector<int> findMajority(vector<int> &nums)
 {
  // Your code goes here.
  
  // map for storing the candidates votes and frequency of votes
  map<int, int> m;
  int n = nums.size();
  
  // storing the frequencies to the map
  for (int i = 0; i < n; i++)
  {
   m[nums[i]]++;
  }

  // vector for prinitng result
  vector<int> v;
  
  auto itr = m.begin();
  // transversal on the entire map to checj if some value is greater than n/3
  // If yes, put in the vector v
  // else move on
  while (itr != m.end())
  {
   if (itr->second > n / 3)
   {
    v.push_back(itr->first);
   }
   itr++;
  }

  // if v is empty => no candidates have votes greater than 1/3 of the total votes 
  if (v.empty())
  {
   v.push_back(-1);
  }
 // else print the candidates
  return v;
 }
};

//{ Driver Code Starts.
int main()
{
 int t;
 cin >> t;
 cin.ignore();
 while (t--)
 {

  string s;
  getline(cin, s);
  stringstream ss(s);
  vector<int> nums;
  int num;
  while (ss >> num)
  {
   nums.push_back(num);
  }
  Solution ob;
  vector<int> ans = ob.findMajority(nums);
  for (auto &i : ans)
   cout << i << " ";
  cout << "\n";
 }
 return 0;
}
// } Driver Code Ends
