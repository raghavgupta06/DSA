class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>div;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                div.push_back(i); 
            }
        }
        for(int d:div){
            bool check=true;
            int mini=-1;
            for(int i=0;i<n;i+=d){
                int bmini=nums[i];
                int bmaxi=nums[i];
                int count=0;
                for(int j=0;j<d;j++){
                    int c=nums[i+j];
                    int ne=nums[i+(j+1)%d];
                    bmini=min(bmini,c);
                    bmaxi=max(bmaxi,c);
                    if(c>ne){
                        count++;
                    }
                }
                if(count>1){
                    check=false;
                    break;
                }
                if(mini!=-1 && mini>bmini){
                    check=false;
                    break;
                }
                mini=bmaxi;
            }
            if(check){
                sum+=d;
            }
        }
        return sum;
    }
};