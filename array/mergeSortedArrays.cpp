#include <iostream>
#include <vector>
using namespace std;

void mergeSorted(vector<int> &arr1,int m, vector<int> &arr2, int n){
    int i=0, j = 0;
    vector<int> temp;

    while((i<m)&&(j<n)){
        if(arr1[i]<=arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else if(arr2[j]<=arr1[i]){
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while(i<m){
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<n){
        temp.push_back(arr2[j]);
        j++;
    }
    for(int k=0; k<m+n; k++){
        arr1[k] = temp[k];
    }
    return ;
}

int main(){
    vector<int> arr1 = {1,2,34,76,89,0,0,0,0,0};
    vector<int> arr2 = {3,24,78,3456,24120};
    mergeSorted(arr1,5,arr2,5);
    for(int i=0; i<arr1.size(); i++){
        cout << arr1[i] << " ";
    }

    
    return 0;
}