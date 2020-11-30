#include <iostream>
#include <stack>
#include <string>

struct Expression
{
    bool correctTag(const std::string& c)
    {
        std::stack<char> s;

        for(size_t i = 0; i < c.size(); ++i)
        {
            if(c[i] == '<')
            {
                s.push(c[i]);
            }
            else if(std::isalpha(c[i]) && s.top() == '<')
            {
                s.push(c[i]);
            }
            else if(c[i] == '/')
            {
                s.pop();

                if(std::isalpha(c[i+1]) && c[i + 1] == s.top())
                {
                    s.pop();
                    s.pop();
                    i++;
                }
            }
        }

        return s.empty();
    }
};

double ErmitPolynom(const int& n, const double& x)
{
    std::stack<double> s;
    s.push(1);
    s.push(2*x);

    for(int i = 2; i <= n; ++i)
    {
        double a = s.top(); s.pop();
        double b = s.top(); s.pop();
        s.push(a);

        b = 2*x*a + 2*(i-1)*b;
        s.push(b);
    }

    return s.top();
}

//===================

struct ListNode {
      int val;
      ListNode *next;
    
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    void print(ListNode* l)
    {
       ListNode* curr = l;
        
        while(curr != nullptr)
        {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
         
        ListNode* l3 = nullptr;
        int status = 0;
        
        while(l1 || l2)
        {
            int a = 0;
            
            if(l1 && l2){
            a = l1->val + l2->val;
            }
            else if(l1 && !l2){
            a = l1->val;
            }
            else {
            a = l2->val;
            }
            
            a += status;
            
            if(a >= 10)
            {
                a = a % 10;
                status = 1;
            }
            else {
                status = 0;
            }
            
            l3 = new ListNode(a,l3);
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(status == 1)
        {
            l3 = new ListNode(1,l3);
        }

        return l3;
    }
};

int main()
{
    ListNode *l1 = new ListNode(9, new ListNode(2, new ListNode(5, nullptr)));
	ListNode *l2 = new ListNode(4, new ListNode(5, new ListNode(6, nullptr)));

    Solution s;
    
    print(s.addTwoNumbers(l1,l2));
}
