public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int lastOccur[]=new int[256],n=s.length(),i,j,k,curr=-1,ans=0;
        for(i=0;i<256;i++)lastOccur[i]=-1;
        for(i=0;i<n;i++){
            curr=Math.max(curr,lastOccur[s.charAt(i)]);
            ans=Math.max(ans,i-curr);
            lastOccur[s.charAt(i)]=i;
        }
        return ans;
    }
}