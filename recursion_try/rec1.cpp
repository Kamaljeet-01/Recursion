#include<iostream>
using namespace std;
//function to print number from count to 10
void counting(int count){
    if(count == 11) return;
    cout<<count<<endl;
    counting(++count);
}

//function to print my name n number of times;          **O(N)**

void printName(int count){
   if(count==0) return;
    cout<<"Kamaljeet Yadav"<<endl;
    printName(--count);
}

//Function to print from 1 to n (By BackTracking):               **O(N)**

void print1ToN(int count){
    if(count==0) return;
    print1ToN(--count);
    cout<<count+1<<endl;
}

//function to print from N to 1 (By BackTracking):                 **O(N)** 
void printNTo1(int count){
    if(count==0) return;
    cout<<count<<endl;
    printNTo1(--count);
}
//function to print sum of 1 to n numbers :

void Sum(int count,int sum){
    if(count==0) {
        cout<<"sum : "<<sum<<endl;
        return;
        }
    sum+=count;
    Sum(--count,sum);
}

//Function to print sum (using function):

int sigma(int count){
    if(count==0) return 0;
    return (count+sigma(count-1));
     
}

//Function to print factorial of any  number :
int factorial(int n){
    if(n==0) return 1;
    return (n*factorial(n-1));
}


int main(){
    int count,sum=0;
    cin>>count;
    //printNTo1(count);

    //printName(count);
    
    //print1ToN(count);
    
    //cout<<sigma(count)<<endl;

    cout<<factorial(count)<<endl;

    cout<<"Hello Program ends here.";
    return 0;
}