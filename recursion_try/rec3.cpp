#include<iostream>
#include<vector>
using namespace std;
void printDs(vector<int> ds){
    for(auto it : ds){
        cout<<it<<" ";
    }
    cout<<endl;
}

//PATTERN:
/*
when we have to give multiple output with different combinations like while taking an element and not taking that element.
simply we can say when we have choice of take and not take, we can use this approach.
first we take that element and check whether it would be answer or not by making recursive call for another elements.
after that we will not take that element and check whether it would be answer or not by making recursive call for another elements.
when idx reaches to end it will print the subsequence.
*/
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

//PATTERN:
/*
It is similiar to above pattern , we need a liitle correction here,
while taking that element ,we will add it to sum variable also, and while not taking it we will subtract from sum variable as well.
before printing the subsequence we need to check where its sum is equal to target or not.
*/
//Function to print all subsequence whose sum is equal to given target value. 
void sumOfSubSequence(int idx,vector<int> &ds,int arr[],int n,int sum,int target){
    //Base Condition where index goes beyond the array whose sum is equal to target value.
    if(idx==n){
            if(sum==target){
                printDs(ds);}
        return;
    }
    //Take or picking the index for making subsequence
    ds.push_back(arr[idx]);
    sum+=arr[idx];
    //making recursion call for other patterns
    sumOfSubSequence(idx+1,ds,arr,n,sum,target);
    //Not Take or not picking the index for making subsequence
    sum-=arr[idx];
    ds.pop_back();
    sumOfSubSequence(idx+1,ds,arr,n,sum,target);

}
//PATTERN:
/*
When we have to give only one/first output then we can use this approach:
we will take a flag value that whether we got the answer or not.If we got the answer we simply return true to parent function/node.
if we don't get we will return false. 
no moving forward for checking the answer while not taking condition, we check whether the function returned true or false,
we will move forward for another recursive call if and only if the function have returned false,
else we return true. 
*/

//Function to print only one subsequence whose sum is equal to given target value by avoiding unnecessary calls. 
bool SumOfSubSequence(int idx,vector<int> &ds,int arr[],int n,int sum,int target){
    //Base Condition where index goes beyond the array whose sum is equal to target value.
    if(idx==n){
            if(sum==target){
                printDs(ds);
                return true;        //it means we got one subsequence and no need of further recursion calls.
                }
    else return false;          //it means we didn't get the subsequence and need for another recursion call.
    }
    //Take or picking the index for making subsequence
    ds.push_back(arr[idx]);
    sum+=arr[idx];
    //making recursion call for other patterns
    if(SumOfSubSequence(idx+1,ds,arr,n,sum,target) == true) return true;
    //Not Take or not picking the index for making subsequence
    sum-=arr[idx];
    ds.pop_back();
    if(SumOfSubSequence(idx+1,ds,arr,n,sum,target) == true) return true;

return false;
}

//Function to just print the number os subsequences.

//PATTERN :
/*
when we want to provide number of output, in this pattern we use this approach :
first we check in left , whether it is out answer or not.If yes, then add and check for right part as well.
return the total answers (we got from left and right ) to parent node(parent function).
In this way we will get the total output for the starting node from where we start the recursion calls.
then we will simply return the final count of answers.
*/

int numberOfSubSequence(int idx,int arr[],int n,int sum,int target){
    //Base Condition where index goes beyond the array whose sum is equal to target value.
    //can be strictly use when all the elements in the array are positive.
    //if(sum>target) return 0;
    if(idx==n){
        if(sum==target){
            return 1;        //it means we got one subsequence and need of further subsequences.
            }
        else return 0;          //it means we didn't get the subsequence and need for another recursion call.
    }
    //Take or picking the index for making subsequence
    sum+=arr[idx];
    //making recursion call for other patterns
    int l = numberOfSubSequence(idx+1,arr,n,sum,target);
    //Not Take or not picking the index for making subsequence
    sum-=arr[idx];
    int r = numberOfSubSequence(idx+1,arr,n,sum,target);

return l+r;     //returing the total subsequences we got to parent node.                N
//                                                                                     / \
//                                                                                    L   R               
}

int main(){
    vector<int> ds;
    int arr[] = {1,2,3,2,1};
    //subSequence(0,ds,arr,3);
    //sumOfSubSequence(0,ds,arr,3,0,2);
    //SumOfSubSequence(0,ds,arr,3,0,2);
    cout<<numberOfSubSequence(0,arr,5,0,5);
    return 0;
}