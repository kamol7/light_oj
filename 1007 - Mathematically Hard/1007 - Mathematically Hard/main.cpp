//
//  main.cpp
//  1007 - Mathematically Hard
//
//  Created by Kamol Kumar paul on 12/7/19.
//  Copyright © 2019 Kamol Kumar paul. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define p(x) cout<<"dg "<<x<<endl;
#define pb push_back
#define ppb pop_back();
#define ll unsigned long long
#define dd double
#define MAX 5000005
using namespace std;
ll phi[MAX];


void cal_phi(){
    for(ll i=0;i<MAX;i++) phi[i]=i;
    
    for(ll i=2;i<MAX;i++){
        if(phi[i]==i){
            for(ll j=i;j<MAX;j+=i) phi[j]-=phi[j]/i;
        }
    }
    
}


void add_phi(){
    for(ll i=1;i<MAX;i++) {
        phi[i]*=phi[i];
    }
    for(ll i=1;i<MAX;i++)
    {
        phi[i]+=phi[i-1];
    }
    
}



int main() {
    cal_phi();
    add_phi();
    //p(phi[5000000]-phi[1])
    ll test;
    scanf("%lld",&test);
    
    for(ll i=1;i<=test;i++){
        ll a, b;
        scanf("%lld%lld",&a,&b);
        
        ll ans=phi[b];
        ans-=phi[a-1];
        
        printf("Case %lld: %llu\n",i,ans);
    }
    
    
    return 0;
}
