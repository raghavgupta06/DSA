class ProductOfNumbers {
public:
vector<int>ans;
int b;

    ProductOfNumbers() { 
        ans.push_back(1);
        b=1;
    }
    void add(int num) {
        if(num==0){
           ans.clear();
           ans.push_back(1);
           b=1;
        }
        else
        {
            ans.push_back(ans.back()*num);
            b++;
        }
        
    }
    
    int getProduct(int k) {
        if(k>=b)
        {
            return 0;
        }
        else
        {
            return ans.back()/ans[b-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */