#include<bits/stdc++.h>
using namespace std;
void merge_step(vector<int>& a , int l , int mid , int r)
{
    vector<int> temp ;
    int i = l ;
    int j=mid+1 ;
    while(i<=mid && j<=r)
    {
        if(a[i] <= a[j])
        {
            temp.push_back(a[i]) ;
            i++;
        }
        else
        {
            temp.push_back(a[j]) ;
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(a[i]) ;
        i++;
    }
    while(j<=r)
    {
        temp.push_back(a[j]) ;
        j++;
    }

    for(int i=0 ; i<temp.size() ; i++)
    {
        a[l+i] = temp[i] ;
    }
}
void mergeSort(vector<int>& a , int l , int r)
{
    if(l < r)
    {
        int mid = (l+r) /2;
        mergeSort(a , l, mid) ;
        mergeSort(a , mid+1 , r);
        merge_step(a , l , mid , r) ;
    }
}
int main()
{
    int n;
    cin >> n ;
    vector<int> a(n) ;
    for(int i=0 ; i<n ; i++)
    {
        cin >> a[i] ;
    }
    mergeSort(a , 0 , n-1) ;
    for(int i=0 ; i< n ; i++)
    {
        cout << a[i] << " " ;
    }
    return 0;
}
