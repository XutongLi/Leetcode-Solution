class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S1 = (C - A) * (D - B), S2 = (G - E) * (H - F);
        int overlap;
        if (C <= E || G <= A || B >= H || F >= D)   //无重叠
            overlap = 0;
        else {
            overlap = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
        }
        return S1  - overlap + S2;
    }
};
//两矩形面积相加，减去重叠部分