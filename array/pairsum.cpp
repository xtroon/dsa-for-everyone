#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector< vector<int>> ans;
   for(int i =0; i<arr.size(); i++){
         for(int j=i+1; j<arr.size() ;j++){
            vector<int> temp;
            if((arr[i]+ arr[j]) == s){
               temp.push_back(min(arr[i],arr[j]));
               temp.push_back(max(arr[i],arr[j]));
               ans.push_back(temp);
            }
         }
   }
   sort(ans.begin(), ans.end());
   return ans;
}


int main(){
    int n,s;
    cin >> n>>  s;
    vector<int> arr(n);
     for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    vector<vector<int>> result = pairSum(arr,s);
    
     for(auto pair : result) {
        cout << pair[0] << " " << pair[1] << endl;
    }
return 0;
}