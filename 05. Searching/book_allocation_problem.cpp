/*
PROBLEM : 
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90
Sample Output
113 
*/

//SOLUTION
//our goal is to minimize the no. of pages for each student

#include<iostream>
#include<climits>
using namespace std;

bool ispossible(int books[],int n,int m,int curr_min){
    int studentused=1;
    int pages=0;

    for(int i=0;i<n;i++){
        if(pages+books[i]>curr_min){
            studentused++;

            pages=books[i];
            if(studentused>m){
                return false;
            }
        }
        else{
            pages+=books[i];
        }
    }
    return true;
}
int book_allocation(int books[],int n,int m){

   int sum=0;
     //For counting the number of pages
     for(int i=0;i<n;i++){
            sum+=books[i];
         }
    //search space 
    int s=books[n-1];
    int e=sum;
  
    int ans=INT_MAX;
    
    if(n<m){
        return -1;
    }

    while(s<=e){
        int mid = (s+e)/2;
        if(ispossible(books,n,m,mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    int test_cases;
    cin>>test_cases;
    for(int i=0;i<test_cases;i++){
    int n;
    cin>>n;

    int m; 
    cin>>m;

    int books[n];

    for(int i=0;i<n;i++){
        cin>>books[i];
    }

    cout<<book_allocation(books,n,m)<<endl;
    }
    return 0;
}
