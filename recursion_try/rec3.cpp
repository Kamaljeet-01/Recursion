#include<iostream>
#include<vector>
using namespace std;
void printDs(vector<int> ds){
    for(auto it : ds){
        cout<<it<<" ";
    }
    cout<<endl;
}
//Sub-Sequence of any string or array                       T.C. =  O(2^N)*N     S.C.  =  O(N)
void subSequence(int idx,vector<int> &ds,int arr[],int n){
    //Base Condition where index goes beyond the array.
    if(idx>=n){
        printDs(ds);
        return;
    }
    //Take or picking the index for making subsequence
    ds.push_back(arr[idx]);
    //making recursion call for other patterns
    subSequence(idx+1,ds,arr,n);
    //Not Take or not picking the index for making subsequence
    ds.pop_back();
    subSequence(idx+1,ds,arr,n);

}

int main(){
    vector<int> ds;
    int arr[] = {1, 2, 3};
    subSequence(0,ds,arr,3);

    return 0;
}