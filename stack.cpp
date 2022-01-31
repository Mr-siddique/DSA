#include <bits/stdc++.h>
using namespace std;
class myStack
{
public:
    vector<int> stack;
    vector<int> min;
    void push(int data)
    {
        stack.push_back(data);
        if (min.size() == 0 || min.back() >= data)
            min.push_back(data);
    }
    int pop()
    {
        if (stack.size() == 0)
            return -1;
        int d = stack.back();
        if (min.back() == stack.back())
            min.pop_back();
        stack.pop_back();
        return d;
    }
    int get_min()
    {
        if (min.size() == 0)
            return -1;
        return min.back();
    }
    int size()
    {
        return stack.size();
    }
    int peek()
    {
        if (stack.size() == 0)
            return -1;
        return stack.back();
    }
    bool isEmpty()
    {
        return stack.empty();
    }
};
//stack using linked list
class my_stack
{
public:
    list<int> stack;
    void push(int data)
    {
        stack.push_back(data);
    }
    int pop()
    {
        if (stack.size() == 0)
            return -1;
        int d = stack.back();
        stack.pop_back();
        return d;
    }
    int size()
    {
        return stack.size();
    }
    int peek()
    {
        if (stack.size() == 0)
            return -1;
        return stack.back();
    }
    bool isEmpty()
    {
        return stack.empty();
    }
    int getMin()
    {
    }
};
bool balancedParenthesis(string str)
{
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            stk.push(str[i]);
        else
        {
            char top;
            if (stk.empty())
                return false;
            top = stk.top();
            stk.pop();
            if (str[i] == ')' && top != '(' || str[i] == '}' && top != '{' || str[i] == ']' && top != '[')
                return false;
        }
    }
    return stk.empty();
}
//implementing two stacks in single array
class twoStacks
{
public:
    int *arr, capacity, top1, top2;
    twoStacks(int cap)
    {
        capacity = cap;
        top1 = -1;
        top2 = cap;
        arr = new int[cap];
    }
    void push_1(int data)
    {
        if (top1 + 1 != top2)
        {
            top1++;
            arr[top1] = data;
        }
    }
    void push_2(int data)
    {
        if (top2 - 1 != top1)
        {
            top2--;
            arr[top2] = data;
        }
    }
    int pop_1()
    {
        if (top1 != -1)
        {
            int top = arr[top1];
            arr[top1] = -1;
            top1--;
            return top;
        }
        return -1;
    }
    int pop_2()
    {
        if (top2 != capacity)
        {
            int top = arr[top2];
            arr[top2] = -1;
            top2++;
            return top;
        }
        return -1;
    }
    int top_1()
    {
        if (top1 != -1)
            return arr[top1];
        return -1;
    }
    int top_2()
    {
        if (top2 != capacity)
            return arr[top2];
        return -1;
    }
};
// class kStacks
// {
// public:
//     int *arr, *next, *top;
//     int cap, k, freeTop;
//     kStacks(int capacity, int n)
//     {
//         cap = capacity;
//         k = n;
//         freeTop = 0;
//         arr = new int[cap];
//         next = new int[cap];
//         top = new int[k];
//         for (int i = 0; i < cap - 1; i++)
//             next[i] = i + 1;
//         next[cap - 1] = -1;
//         for (int i = 0; i < k; i++)
//             top[i] = -1;
//     }
//     void push(int data, int stkNo)
//     {
//         int i = top[stkNo];
//         freeTop = next[i];
//         next[i] = top[stkNo];
//         top[stkNo] = i;
//         arr[i] = data;
//     }
//     int pop(int stackNo)
//     {
//         int i = top[stackNo];
//         if (i == -1)
//             return -1;
//         top[stackNo] = next[i];
//         next[i] = freeTop;
//         freeTop = i;
//         return arr[i];
//     }
//     int top(int stkNo)
//     {
//         if (top[stkNo] == -1)
//             return -1;
//         return arr[top[stkNo]];
//     }
// };
void stockSpan(vector<int> arr)
{
    stack<int> stk;
    stk.push(0);
    cout << 1 << " ";

    for (int i = 1; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
            stk.pop();
        int span = stk.empty() ? i + 1 : i - stk.top();
        cout << span << " ";
        stk.push(i);
    }
}
vector<int> previousGreater(vector<int> arr)
{
    stack<int> stk;
    vector<int> res;
    stk.push(arr[0]);
    cout << -1 << " ";
    res.push_back(-1);
    for (int i = 1; i < arr.size(); i++)
    {
        while (!stk.empty() && stk.top() <= arr[i])
            stk.pop();
        if (stk.empty())
        {
            cout << -1 << " ";
            res.push_back(-1);
        }
        else
        {
            cout << stk.top() << " ";
            res.push_back(stk.top());
        }
        stk.push(arr[i]);
    }
    return res;
}
vector<int> nextGreater(vector<int> arr)
{
    vector<int> res(arr.size());
    res[arr.size() - 1] = -1;
    stack<int> stk;
    stk.push(arr[arr.size() - 1]);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() <= arr[i])
            stk.pop();
        stk.empty() ? res[i] = -1 : res[i] = stk.top();
        stk.push(arr[i]);
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
vector<int> prevSmaller(vector<int> arr)
{
    stack<int> stk;
    vector<int> res;
    stk.push(0);
    res.push_back(-1);
    for (int i = 1; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
            stk.pop();
        if (stk.empty())
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(stk.top());
        }
        stk.push(i);
    }
    return res;
}
vector<int> nextSmaller(vector<int> arr)
{
    vector<int> res(arr.size());
    res[arr.size() - 1] = arr.size();
    stack<int> stk;
    stk.push(arr.size() - 1);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
            stk.pop();
        stk.empty() ? res[i] = arr.size() : res[i] = stk.top();
        stk.push(i);
    }
    return res;
}
int largestRectangularArea(vector<int> arr)
{
    vector<int> ps = prevSmaller(arr);
    vector<int> ns = nextSmaller(arr);
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];
        curr += (i - ps[i] - 1) * arr[i];
        curr += (ns[i] - i - 1) * arr[i];
        res = max(res, curr);
    }
    return res;
}
// void rectangularArea(vector<int> arr)
// {
//     stack<int> stk;
//     int res = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         while (!stk.empty() && arr[stk.top()] >= arr[i])
//         {
//             int tp = stk.pop();
//             res = max(res, arr[tp] * (stk.empty() ? i : i - stk.top() - 1));
//         }
//         stk.push(i);
//         while (!stk.empty())
//         {
//             int tp = stk.pop();
//             int curr=arr[tp] * (stk.empty() ? arr.size() : arr.size() - stk.top() - 1);
//             res = max(res, curr);
//         }
//     }
//     cout << res << endl;
// }
class getMinStack
{
public:
    vector<int> stack;
    int mn;
    void push(int data)
    {
        if (stack.size() == 0)
        {
            stack.push_back(data);
            mn = data;
        }
        else if (data <= mn)
        {
            stack.push_back(2 * data - mn);
            mn = data;
        }
        else
            stack.push_back(data);
    }
    int pop()
    {
        if (stack.size() == 0)
            return -1;
        int data = stack.back();
        stack.pop_back();
        if (data <= mn)
        {
            int res = mn;
            mn = 2 * mn - data;
            return res;
        }
        else
            return data;
    }
    int getMin()
    {
        return mn;
    }
    int peek()
    {
        if (stack.size() == 0)
            return -1;
        int d = stack.back();
        if (d <= 0)
            return mn;
        return d;
    }
};
void infixToPostfix(string str)
{
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        int x = str[i];
        if (x >= 97 && x <= 122 || x >= 65 && x <= 90 || x >= 488 && x <= 57)
            cout << str[i];
        else if (x == '(')
            stk.push(str[i]);
        else if (x == ')')
        {
            while (stk.top() != '(')
            {
                cout << stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            if (stk.empty())
                stk.push(str[i]);
            else if (x == '*' || x == '/' && stk.top() == '+' || stk.top() == '-')
                stk.push(str[i]);
            else if (x == '+' || x == '-')
            {
                if (stk.top() != '*' || stk.top() != '/')
                {
                    cout << stk.top();
                    stk.pop();
                }
                else
                {
                    while (stk.top() != '*' || stk.top() != '/' && (!stk.empty()))
                    {
                        cout<<stk.top();
                        stk.pop();
                    }
                }
                stk.push(str[i]);
            }
            else
            {
                while (!stk.empty())
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(str[i]);
            }
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}
void evaluatePostfix(string str)
{
    stack<int> stk;
    for (int i = 0; i < str.length(); i++)
    {
        char temp = str[i];
        if (str[i] >= 48 && str[i] <= 57)
            stk.push(str[i] - '0');
        else
        {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            if (temp == '+')
                stk.push(b + a);
            else if (temp == '-')
                stk.push(b - a);
            else if (temp == '/')
                stk.push(b / a);
            else if (temp == '*')
                stk.push(b * a);
            else if (temp == '^')
                stk.push(pow(b, a));
        }
    }
    cout << stk.top() << endl;
}
string infixToPrefix(string str)
{
    string prefix;
    stack<char> stk;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char x = str[i];
        if (x >= 97 && x <= 122 || x >= 65 && x <= 90 || x >= 48 && x <= 57)
            prefix += x;
        else if (x == '(')
            stk.push(x);
        else if (x == ')')
        {
            while (stk.top() != '(')
            {
                prefix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            if (stk.empty())
                stk.push(x);
            else if (x == '*' || x == '/' && stk.top() == '+' || stk.top() == '-')
                stk.push(x);
            else if (x == '+' || x == '-')
            {
                if (stk.top() == '*' || stk.top() == '/')
                {
                    prefix += stk.top();
                    stk.pop();
                }
                else
                {
                    while (stk.top() != '*' || stk.top() != '/' && (!stk.empty()))
                    {
                        prefix += stk.top();
                        stk.pop();
                    }
                }
                stk.push(x);
            }
            else
            {

                stk.push(x);
            }
        }
    }
    while (!stk.empty())
    {
        prefix += stk.top();
        stk.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int evaluatePrefix(string prefix){
    // stack<char>s1;
    stack<int>s2;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        char temp=prefix[i];
         if(temp>='0'&&temp<='9')
        s2.push(temp-'0');
        else if(temp=='*'||temp=='/'||temp=='+'||temp=='-')
        {
            int a=s2.top();s2.pop();
            int b=s2.top();s2.pop();
            if(temp=='+')
            s2.push(b+a);
            else if(temp=='-')
            s2.push(b-a);
            else if(temp=='/')
            s2.push(b/a);
            else if(temp=='*')
            s2.push(b*a);
        }

    }
    return s2.top();
}
main()
{
    myStack s;
    s.push(10);
    s.push(20);
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    my_stack stk;
    stk.push(5);
    stk.push(15);
    stk.push(25);
    cout << stk.pop() << endl;
    cout << "size" << stk.size() << endl;
    cout << stk.peek() << endl;
    cout << balancedParenthesis("{}[()]") << endl;
    twoStacks st(5);
    st.push_1(10);
    st.push_1(20);
    st.push_1(32);
    st.push_2(5);
    st.push_2(21);
    st.push_2(29);
    cout << st.top_1() << endl;
    cout << st.top_2() << endl;
    stockSpan({60, 10, 20, 40, 35, 30, 50, 70, 65});
    cout << endl;
    previousGreater({12, 10, 8});
    cout << endl;
    // nextGreater({25, 20, 15, 10});
    cout << endl;
    // cout << largestRectangularArea({6, 2, 5, 4, 1, 5, 9}) << endl;
    // evaluatePostfix("12*3+");
    cout << infixToPrefix("x+y*z")<<endl;
    cout<<evaluatePrefix("+*123")<<endl;
}
