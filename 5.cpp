//Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        string s =  decToBinary(x);
        string s1 =  decToBinary(y);
        int count = 0;
        ///cout<<s<<"\n";
        //cout<<s1<<"\n";
        for(int i=0;i<s.length();i++){
            if(s[i] != s1[i])
                count++;
        }
        return count;
        
    }
    string decToBinary(int n) 
    { 
        string s = "";
        for (int i = 31; i >= 0; i--) { 
            int k = n >> i; 
            if (k & 1) 
                s+= "1"; 
            else
                s+='0';
        }
        return s;
        
    } 
};
