class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size()  ; 
         queue<int> radiant ; 
         queue<int> Dire ; 

         for(int i = 0 ; i < n ; i++ ){
            if(senate[i] == 'R'){
                radiant.push(i) ; 
            }
            else{
                Dire.push(i) ; 
            }
         }

         while(!radiant.empty() && !Dire.empty()){
            
            int r_index = radiant.front()  ; 
            int D_index = Dire.front() ; 
            radiant.pop() ; 
            Dire.pop()  ; 

            if(r_index < D_index) {
                radiant.push(r_index+n) ; 
            }
            else {
                Dire.push(D_index+n) ; 
            }
         }
        
         if(!radiant.empty()){
            return "Radiant" ;
         }
         else{
            return "Dire" ; 
         }
    }
};