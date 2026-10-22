class Solution {
public:
    int minOperations(vector<int>& nums) {
        int idx=0,idx2=0;
        int nid=0,nid2=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                idx=i;
            }
            if(nums[i]==n-1){
                idx2=i;
            }
        }
        nid=idx;
        nid2=idx2;
        bool check1=false;
        int size=n-1;
        while(size--){
            if(nums[(idx)%n]>nums[(idx+1)%n]){
                check1=true;
                break;
            }
            idx=(idx+1)%n;
        }
        bool check2=false;
        size=n-1;
        while(size--){
            if(nums[(idx2)%n]<nums[(idx2+1)%n]){
                check2=true;
                break;
            }
            idx2=(idx2+1)%n;
        }
        if(check1 && check2){
            return -1;
        }
        int mini=INT_MAX;
        if(!check1){
            mini=min(mini,nid);
            mini=min(mini,n-nid+2);
        }
        if(!check2){
            mini=min(mini,nid+2);
            mini=min(mini,n-nid);
        }  
       return mini; 
    }
};