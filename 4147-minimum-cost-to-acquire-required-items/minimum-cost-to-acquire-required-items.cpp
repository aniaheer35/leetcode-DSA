// class Solution {
// public:
//     long long minimumCost(int cost1, int cost2, int costboth, int need1, int need2) {
//         long long ans=0; 
//         if(costboth <= cost1 && costboth <= cost2){
//                ans = max(need1 , need2)*costboth ; 
//         }
//        else if(costboth >= cost1+cost2 ){
//              ans = cost1*need1 + cost2*need2 ; 
//        }
//        else if(costboth <= cost1 + cost2 ) { 
//             if(need1  < need2 ) {
//                 ans = costboth*need1 + (need2-need1)*cost2  ; 
//             }
//             else {
//                 ans = costboth*need2 + (need1-need2)*cost1  ; 
//             }
//        }
//        else if( (costboth < cost1 && costboth > cost2 ) || (costboth > cost1 && costboth < cost2)){
//              if(cost1 > cost2 ) {
//                 if( (need2 - need1) > 0 ){
//                 ans = costboth*need1 + (need2-need1)*cost2 ; }
//                 else {
//                     ans = costboth*need1 ; 
//                 }
//              }
//              else {
//                      if( (need1 - need2) > 0 ){
//                 ans = costboth*need2 + (need1-need2)*cost1 ; }
//                 else {
//                     ans = costboth*need2 ; 
//                 }
//              }
//        }
//         return ans ; 
//     }
// };

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        // 1. Buy all items individually
        long long allSeparate = n1 * c1 + n2 * c2;

        // 2. Use combo items for the shared overlap, then buy the rest individually
        long long overlap = min(n1, n2);
        long long comboPlusSeparate = overlap * cb + (n1 - overlap) * c1 + (n2 - overlap) * c2;

        // 3. Use combo items to cover the larger requirement completely
        long long allCombo = max(n1, n2) * cb;

        return min({allSeparate, comboPlusSeparate, allCombo});
    }
};
