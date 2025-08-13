class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int org = image[sr][sc];
        if(org == color) return image;
        queue<pair<int, int>>q;
        vector<pair<int,int>>dirs={{-1,0},{0,-1},{1,0},{0,1}};
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();
            for(auto [di, dj]:dirs){
                int ni = a+di, nj = b+dj;
                if(ni>=0 && nj>=0 && ni<n && nj<m && image[ni][nj] == org){
                    q.push({ni, nj});
                    image[ni][nj] = color;
                }
            }
        }
        return image;
    }
};