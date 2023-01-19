#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

//   ! This is the MountainArray's API interface.
//  ! You should not implement it, or speculate about its implementation
class MountainArray {
    public:
    int get(int index);
    int length();
};
 

class Solution {
    int maxPointIndex(MountainArray &mountainArr,int l,int r){
        while(l<=r){
            int mid=(l+r)/2;
            int midVal=mountainArr.get(mid);
            if(midVal>mountainArr.get(mid+1) && midVal>mountainArr.get(mid-1)){
                return mid;
            }
            if(midVal<mountainArr.get(mid+1)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }

    int func(MountainArray &mountainArr,int tar,int l,int r,int temp){
        while(l<=r ){
            int mid=(l+r)/2;
            int midVal=mountainArr.get(mid);
            if(midVal==tar) return mid;
            if(temp && midVal<tar){
                l=mid+1;
            }else if(temp){
                r=mid-1;
            } 
            if(!temp && midVal>tar){
                l=mid+1;
            }else if(!temp){
                r=mid-1;
            } 


        }
        return -1;
    }


public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=mountainArr.length();
        int max=maxPointIndex(mountainArr,0,l-1);
        int ind=func(mountainArr,target,0,max,1);
        if(ind!=-1)return ind;
        ind=func(mountainArr,target,max+1,l-1,0);

        return ind;
    }
};

int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    fr(i,num){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int tar;
    cout<<"Target:- ";
    cin>>tar;
    Solution obj;
}