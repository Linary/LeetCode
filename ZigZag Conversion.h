class Solution {
public:

    /************************************************************************/
    /*  The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
    /*  number of rows like this: (you may want to display this pattern in a 
    /*  fixed font for better legibility)
    /*  P   A   H   N
    /*  A P L S I I G
    /*  Y   I   R
    /*  And then read line by line: "PAHNAPLSIIGYIR"
    /*  Write the code that will take a string and make this conversion given a number of rows:
    /*  string convert(string text, int nRows);
    /*  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
    /************************************************************************/
    
    /************************************************************************/
    /*  思路：跳跃式的读取，关键在于间隔的确定
    /*  1）从第一个元素开始读取，第一次的间隔 d = 2 * numRows - 2
    /*  2）第二次从第二个元素开始，初始间隔为 d_t = d - 2，d_t 会振荡
    /*  3）循环，直到 d == 0，将 d 重设为初始间隔
    /************************************************************************/
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string str;
        int dis = numRows * 2 - 2;
        int pos_max = dis;
		bool last = false;
		for (int i = 0; i < numRows; i++) {
			for (int j = i, dis_t = dis; j < s.size(); j += dis_t) {
                str += s[j];
				if (j!= i && i > 0 && i < numRows - 1)
					dis_t = pos_max - dis_t;
			}
			if (last) break;
			else if ((dis -= 2) ==  0) {
				last = true;
				dis = pos_max;
			}
        }
        return str;
    }
};