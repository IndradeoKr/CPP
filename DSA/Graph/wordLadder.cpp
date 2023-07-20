#include<bits/stdc++.h>
using namespace std;

//wordLadder 1
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st = {wordList.begin(),wordList.end()};
        
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);//not to consider again.
        
        while(!q.empty())
        {
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(s == targetWord) return steps;
            for(int i = 0; i < s.size(); i++)
            {
                char t = s[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    s[i] = c;
                    if(st.find(s) != st.end())
                    {
                        q.push({s,steps+1});
                        st.erase(s);//not to consider again.
                    }
                    
                }
                s[i] = t;
            }
        }
        return 0;
    }
};


//wordLadder 2
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st = {wordList.begin(),wordList.end()};
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> used;
        used.push_back(beginWord);
        int lvl = 1;
        
        while(!q.empty())
        {
            vector<string> v = q.front();
            q.pop();
            if(v.size() > lvl)
            {
                lvl++;
                for(auto it:used)
                {
                    st.erase(it);
                }
            }
            
            string s = v.back();
            
            if(s == endWord)
            {
                if(ans.size() == 0) ans.push_back(v);
                else if(ans[0].size() == v.size()) ans.push_back(v);
            }
            
            
            for(int i = 0; i < s.size(); i++)
            {
                char t = s[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    s[i] = c;
                    if(st.find(s) != st.end())
                    {
                        v.push_back(s);
                        q.push({v});
                        used.push_back(s);
                        v.pop_back();
                    }
                }
                s[i] = t;
            }
        }
        return ans;
    }
};


// word ladder 2 ...... with more optamized way ...........................
class Solution {
private:
    void dfs(string &word, vector<string> &seq, string &b, vector<vector<string>> &ans,
    unordered_map<string,int> &m)
    {
        int sz = word.size();
        if(word == b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
        }

        int steps = m[word];
        for(int i = 0; i < sz; i++)
        {
            char t = word[i];
            for(char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if(m.find(word) != m.end() && m[word]+1 == steps)
                {
                    seq.push_back(word);
                    dfs(word,seq,b,ans,m);
                    seq.pop_back();
                }
            }
            word[i] = t;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st = {wordList.begin(),wordList.end()};
        unordered_map<string,int> m;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        m[beginWord] = 1;

        while(!q.empty())
        {
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(s == endWord) break;

            for(int i = 0; i < s.size(); i++)
            {
                char t = s[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    s[i] = c;
                    auto it = st.find(s);
                    if(it != st.end())
                    {
                        m[s] = steps+1;
                        q.push({s,steps+1});
                        st.erase(it);
                    }
                }
                s[i] = t;
            }
        }
        vector<vector<string>> ans;
        if(m.find(endWord) != m.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq,beginWord,ans,m);
        }
        return ans;
    }
};

int main()
{
    return 0;
}