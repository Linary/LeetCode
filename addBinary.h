class Solution
{
public:
    /***********************************************************************/
    /*  Given two binary strings, return their sum (also a binary string). 
    /*  For example,
    /*  a = "11"
    /*  b = "1"
    /*  Return "100". 
    /***********************************************************************/

    /***********************************************************************/
    /*  思路：
    /*  1）字符串从后往前取值，若已超出字符串范围用0代替
    /*  2）两个字符串对应位以及进位相加，和的商作为新的进位，和的余作为结果
    /*     插入到结果字符串的最前面（后面的字符要移动）
    /*  3）最后一步，如果进位为 1 ，也要加上去
    /*  当然，如果先翻转字符串，那么就是在尾部添加，最后还要再翻转回来
    /*  其实可能这种效率还要高一点
    /***********************************************************************/
    string addBinary(string a, string b) {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }


    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int maxsize = max(a.size(), b.size());
        int carry = 0;
        // 返回结果
        string str;
        for (int i = 0; i < maxsize; i++) {
            int int_a = i < a.size() ? a[i] - '0' : 0;
            int int_b = i < b.size() ? b[i] - '0' : 0;
            
            int sum = int_a + int_b + carry;
            carry = sum / 2;

            str += (sum % 2 + '0');
        }
        if (carry) {
            str += (carry + '0');
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
