class Solution {
public:
    bool diff(string x, string y) {
        int c=0;
        for (int i=0;i<x.size();i++) {
            if (x[i]!=y[i]) {
                c++;
            }
        }
        if (c==1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        int res=1;
        unordered_map<string,vector<string>> graph;
        vector<string> v;
        for (auto x:wordList) {
            if (diff(beginWord,x)==1) {
                v.push_back(x);
            }
        }
        graph[beginWord]=v;

        for (auto x:wordList) {
            vector<string> v;
            for (auto y:wordList) {
                if (diff(x,y)==1) {
                    v.push_back(y);
                }
            }
            graph[x]=v;
        }

        unordered_map<string,int> vis;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord]=1;

        while (!q.empty()) {
            int n=q.size();
            for (int i=0;i<n;i++) {
                string f=q.front();
                q.pop();
                for (auto z:graph[f]) {
                    if (z==endWord) {
                        return res+1;
                    }
                    if (!vis[z]) {
                        vis[z]=1;
                        q.push(z);
                    }
                }
            }
            res++;
        }

        return 0;
    }
};