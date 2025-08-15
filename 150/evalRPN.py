from typing import List
class Solution:
    def evalRPN(self,token:List[str]):
        st=[]
        for ch in token:
            if ch not in ["+","-","*","/"]:
                st.append(int(ch))
            else:
                a=st.pop()
                b=st.pop()
                if ch=='+':
                    st.append(a+b)
                elif ch=="-":
                    st.append(a - b)
                elif ch=="*":
                    st.append(a * b)
                else:
                    st.append(a / b)
        return st[-1]


sol = Solution()
token=["2","1","+","3","*"]
print(sol.evalRPN(token))