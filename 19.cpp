
//Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        
        string result="";
        int i= a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        while(i>=0 || j>=0  || carry == 1)   /// if carry == 1 is important because when both i and j are not >=0 and still a carry is left then we need to add it
        {
            int sum= carry;
            
            if(i>=0)
            {
                sum += a[i--] - '0';   // string to integer
            }
            if(j>=0)
            {
                sum += b[j--] - '0';  // string to integer
            }
            
            result =  char (sum%2 + '0') + result;    // integer to string
            
            carry = sum/2;
        }
        
        
        
        return result;
        
    }
};
