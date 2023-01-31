// https://leetcode.com/problems/max-points-on-a-line/submissions/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=1)return 1;
        int n = points.size();
        int maxCt = 0;
        for(int i=0;i<n;i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=0;j<n;j++) { 
                if(i==j)continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                int ct = 2;
                if(x1==x2) {
                    for(int k=0;k<n;k++) {
                        if(k==i || k==j)continue;
                        if(points[k][0]-x1==0)ct++;
                    }
                } else if(y1==y2) {
                    for(int k=0;k<n;k++) {
                        if(k==i || k==j)continue;
                        if(points[k][1]-y1==0)ct++;
                    }
                } else {
                    for(int k=0;k<n;k++) {
                        if(k==i || k==j)continue;
                        if((double)(points[k][1]-y1)*1.0==(double)((y2-y1)*(points[k][0]-x1))/(x2-x1)*1.0)ct++;
                    }
                }
                maxCt = max(maxCt, ct);
            }
        }
        return maxCt;
    }
};


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)return 1;
        int n = points.size();
        int ct = 0;
        for(int i=0;i<n-1;i++) {
            map<double,int>slopeCt;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<n;j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1==x2) {
                    slopeCt[1e9]++;
                } else {
                    double slope = (((y2-y1)*1.0)/((x2-x1)*1.0));
                    slopeCt[slope]++;
                }
            }
            for(auto it: slopeCt) {
                ct = max(ct, it.second+1);
            }
        }
        return ct;
    }
};