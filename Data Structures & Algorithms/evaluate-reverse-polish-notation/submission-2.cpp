class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string tocken : tokens){
            if(tocken == "+" || tocken == "-" || tocken == "*" || tocken == "/"){
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(tocken == "+"){
                    st.push(a+b);
                }
                else if(tocken == "-") st.push(a-b);
                else if(tocken == "*") st.push(a*b);
                else{
                    st.push(a/b);
                }
            }
            else{
                st.push(stoi(tocken));
            }
        }
        return st.top();
    }
};
