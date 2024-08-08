#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int amt=0;
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int pmax[n];
    pmax[0]=a[0];
    for(int i=1;i<n;i++){
        pmax[i]=max(pmax[i-1],a[i]);
    }
    int smax[n];
    smax[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        smax[i]=max(smax[i+1],a[i]);
    }
    for(int i=1;i<n-1;i++){
        if(a[i]<pmax[i-1] && a[i]<smax[i+1]){
            int d_h=min(pmax[i-1],smax[i+1]);
            if(d_h>a[i]){
                amt+=d_h-a[i];
            }
        }
    }
    cout << amt;
    return 0;
}