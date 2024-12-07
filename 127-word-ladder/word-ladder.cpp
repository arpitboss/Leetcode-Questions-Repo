class Solution {
public:
    bool diff(const string& x, const string& y) {
        int c=0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i]!=y[i]) {
                c++;
            }
        }
        return (c==1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int res = 1;

        unordered_map<string, bool> visited;
        visited[beginWord] = true;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string f = q.front();
                q.pop();

                for (int j = 0; j < f.size(); ++j) {
                    string newWord = f;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[j] = ch;

                        if (newWord == endWord) {
                            return res + 1;
                        }

                        if (wordSet.find(newWord) != wordSet.end() && !visited[newWord]) {
                            visited[newWord] = true;
                            q.push(newWord);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};
