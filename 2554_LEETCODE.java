// 2554. Maximum Number of Integers to Choose From a Range I 
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {


        // approach 
        // we need to find max no element with sum = maxsum but we cant choose some of the banned one so skip them 
        //  start from smallest number you can take that way you can maintain low sum  
        // if in set just continue ;
        // check if  not in set add it sum  
        // but before increasing count gotta make sure that sum < maxSUm
        //  if bigger return count because no new number can be added we are already maintaning min sum 
        //  else increase count 
         
       HashSet<Integer> set = new HashSet<>();
       int count=0 , sum = 0  ;
        for(int ban : banned ){
            set.add(ban);
        }

        for(int i=1 ; i<= n ; i++ ){
            if( !set.contains(i)){
                sum += i;
                if(sum > maxSum ) return count ;
                count++ ; 
            }
        }
        return count ;
    }
}