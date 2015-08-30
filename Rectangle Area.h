class Solution {
public:
    /***************************************************************************/
    /*  Find the total area covered by two rectilinear rectangles in a 2D plane.
    /*  Each rectangle is defined by its bottom left corner and top right corner 
    /*  as shown in the figure.
    /***************************************************************************/
    
    /***************************************************************************/
    /*  思路：关键在于找到重叠区域的四个点的坐标，最好能使得即使没有重叠区域，
    /*  这四个坐标也能为有意义的值——0
    /***************************************************************************/
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
    }
};