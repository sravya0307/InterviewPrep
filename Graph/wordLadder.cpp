/*Given a begin word, end word adn a wordlist, the shortest transformation sequence of begin to end via wordlist, every word in the sequence is one letter different from the previous one

T(C)- n*26*wordlength*log(n)
S(C)- O(n)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>dic;
        for(auto i:wordList){
            dic.insert(i);
        }
        int c=0,f=0;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            q.push("");
            while(q.front()!=""){
                string s=q.front();
                if(s==endWord)
                {
                    f=1;
                    break;
                }
                for(int j=0;j<s.size();j++){
                    s=q.front();
                    for(int i=0;i<26;i++){
                        s[j]='a'+i;
                        if(dic.find(s)!=dic.end())
                        {
                        q.push(s);
                        dic.erase(s);
                        }
                    }
                    
                }
                q.pop();
            }
            c++;
            q.pop();
            if(f==1)
            break;
        }
        if(f==0)
        return 0;
        return c;

    }
};
