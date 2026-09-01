class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.length();
        
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                continue;
            }
            
            string temp = "";
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            
            if (temp == ".") {
                continue; 
            } 
            else if (temp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            else {
                st.push_back(temp);
            }
        }
        
        string ans = "";
        for (int i = 0; i < st.size(); i++) {
            ans += "/" + st[i];
        }
        
        if (ans.length() == 0) {
            return "/";
        }
        
        return ans;
    }
};