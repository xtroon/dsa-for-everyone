#include <iostream>
#include <vector>
using namespace std;

void movezeroes(vector<int> &arr){
    // int j = arr.size();
    // int k =0;
    // for(int i=0; i<j; i++){
    //     if(arr[i] != 0){
    //         swap(arr[i], arr[k]);
    //         k++;
    //     }
    // }

    int i=0, j=0, n =arr.size();
    while(i<n){
        if(arr[i]!=0){
            arr[j] = arr[i];
            j++;
        }
        i++;
    }
    while(j<n){
        arr[j] = 0;
        j++;
    }
}


int main(){
    vector<int> arr = {0,1,0,3,12};
    movezeroes(arr);
    for(int i=0; i <arr.size(); i++){
        cout << arr[i]<< " ";
    }
    
    return 0;
}