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
int main(){
    int arr[5] = {2,4,6,8,10};
    //reverse(arr,0,4);
    rev(arr,5,0);
    printArray(arr,5);
    cout<<"Program ends here....."<<endl;
    return 0;
}