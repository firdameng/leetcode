
/*
*
* 20. Valid Parentheses
*
*
*/


// other  
class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> parentheses;
        for(int i = 0; i<s.size();++i)
        {
            if (s[i] == '(' || s[i]=='[' || s[i]=='{')
                parentheses.push(s[i]);
            else
            {
                if (parentheses.empty())
                    return false; //考虑到了为空的时候，如果来了一个反向括号，即判断无效
                if (s[i]==')' && parentheses.top()!='(')  // 先考虑了不成立情况
                    return false;
                if (s[i]==']' && parentheses.top()!='[')
                    return false;
                if (s[i]=='}' && parentheses.top()!='{')
                    return false;   
                parentheses.pop();                        // 剩余则为成立情况
            }
        }
        return parentheses.empty();             //最后一句判断也很c++
    }
};


// python版本，
/* class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        dict = {"]":"[", "}":"{", ")":"("}
        for char in s:
            if char in dict.values():
                stack.append(char)
            elif char in dict.keys():
                if stack == [] or dict[char] != stack.pop():
                    return False
            else:
                return False
        return stack == [] */

// me 

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> mystack;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                mystack.push(s[i]);
            else if(s[i] == ')')                //三个else if 其实是可以如以上优化一下
            {
                if(!mystack.empty() && mystack.top() == '(')
                    mystack.pop();
                else
                    return false;
            }
            else if(s[i] == '}')
            {
                if(!mystack.empty() && mystack.top() == '{')
                    mystack.pop();
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(!mystack.empty() && mystack.top() == '[')
                    mystack.pop();
                else
                    return false;
            }
        }
        if(mystack.empty())
            return true;
        return false;
    }
};