#include<bits/stdc++.h>
using namespace std;
int find_pivot(vector<int>&a , int l , int h)
{
    int p = a[h];
    int i = l -1 ;
    for(int j=l; j<h ; j++)
    {
        if(a[j] < p)
        {
            i++;
            swap(a[j] , a[i]) ;
        }
    }
    swap(a[i+1] , a[h]) ;
    return i+1 ;
}
void quickSort(vector<int>& a , int l , int h)
{
    if(l < h)
    {
        int p = find_pivot(a , l , h) ;
        quickSort(a , l , p-1);
        quickSort(a , p+1 , h);
    }
}
int main()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> a[i];
    }
    quickSort(a , 0 , n-1);
     for(int i=0 ; i<n ; i++)
    {
        cout << a[i] << " " ;
    }

    return 0;
}
