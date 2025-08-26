class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
          int x=0 ;
      int n=s1.length();
        
        for(int i=0;i<s2.length();i++)
        {
            if(s1[x]==s2[i]){
                x++;
            }
        }
        return(x==n);
    }
};