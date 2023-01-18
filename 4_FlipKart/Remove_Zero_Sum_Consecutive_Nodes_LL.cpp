#include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*temp=head;

        unordered_map<int,ListNode*> mp;
        mp[0]=dummy;
        int currSum=0;
        while(temp!=NULL){
            currSum+=temp->val;
            if(mp[currSum]){
                ListNode* flag= mp[currSum]->next;
                int val=currSum;
                while(flag!=temp){
                    val+=flag->val;
                    mp.erase(val);
                    flag=flag->next;
                }
                mp[currSum]->next=temp->next;
            }else{
                mp[currSum]=temp;
            }
            temp=temp->next;
        }

        return dummy->next;
    }
    
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    Solution obj;
}