#include<iostream>
#include<bits/stdC++.h>
using namespace std;
//Function to reverse an array with 2 pointers using recursion
void reverse(int arr[],int l,int r){
    int temp;
    if(r<=l) return;
    //swaping elements 
    temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
    //calling the same   function to reverse the next pair
    reverse(arr,l+1,r-1);
}

//Function to reverse an array with single pointer using recursion

void rev(int arr[],int size,int i){
    if(i>(size/2)) return;
    //else swap the element of ith index by (n-i-1)th index element
    swap(arr[i],arr[size-i-1]);
    rev(arr,size,++i);
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool palindrome(char arr[],int i,int n){
    if(i>=n/2) return true;
    if(arr[i] != arr[n-i-1]) return false;
    palindrome(arr,i+1,n);
}
int fab(int n){
    if(n<=1) return n;
    return (fab(n-1)+fab(n-2));
}
int main(){
    int arr[5] = {2,4,6,8,10};
    char arr2[5]={'m','a','d','s','m'};
    //reverse(arr,0,4);
    //rev(arr,5,0);
    //printArray(arr,5);
    //(palindrome(arr2,0,5))?cout<<"True"<<endl:cout<<"False"<<endl;
    cout<<fab(4)<<endl;
    cout<<"Program ends here....."<<endl;
    return 0;
}