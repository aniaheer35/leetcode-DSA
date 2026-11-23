class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size() ;  
       int prod = INT_MIN ; 
       
       for(int i = 0 ; i < n ; i++){
        int inprod = 1; 
        for(int j = i ; j < n ;j++){
               inprod *= nums[j] ; 
               prod = max(inprod , prod ) ;   
         } 
       }
       return prod ;
    }
};