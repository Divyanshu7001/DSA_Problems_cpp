class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 1)
            return false;
        stack<char> st;
        for (char& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else {
                if(st.size()<1)
                    return false;
                char topEle = st.top();
                cout << topEle << " " << ch << endl;
                if (topEle == '(') {
                    if (ch == ')') {
                        st.pop();
                        continue;
                    }
                    return false;
                } else if (topEle == '{') {
                    if (ch == '}') {
                        st.pop();
                        continue;
                    }
                    return false;
                } else if (topEle == '[') {
                    if (ch == ']') {
                        st.pop();
                        continue;
                    }
                    return false;
                } else
                    return false;
            }
        }
        return st.empty() == true;
    }
};