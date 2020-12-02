#include "PathTree.h"


PTree::PTree()
{
    std::vector<node*> v{nullptr};
    v.resize(5);

    root = new node{'B', v};
}


void PTree::moveTo(const char& c, node*& curr)
{
    if(c == 'N' && curr->instr[0]) curr = curr->instr[0];
    else if(c == 'S' && curr->instr[1]) curr = curr->instr[1];
    else if(c == 'E' && curr->instr[2]) curr = curr->instr[2];
    else if(c == 'W' && curr->instr[3]) curr = curr->instr[3];
    else if(c == 'P' && curr->instr[4]) curr = curr->instr[4];
    else return;
}

bool PTree::hasSymbolChild(const char& c, node* curr) const
{
    if(c == 'N') return curr->instr[0];
    if(c == 'S') return curr->instr[1];
    if(c == 'E') return curr->instr[2];
    if(c == 'W') return curr->instr[3];
    if(c == 'P') return curr->instr[4];

    return false;
}

bool PTree::hasChild(node* curr) const
{
    return curr->instr[0] || curr->instr[1] || curr->instr[2] || curr->instr[3] || curr->instr[4];
}

void PTree::add(const std::queue<char>& q)
{
   std::queue<char> temp = q;
   node* curr = root;

   if(hasChild(curr))
   {
       moveTo(q.front(), curr);

        while(temp.front() == curr->data)
        {
            if(temp.front() == 'N')
            {
                temp.pop();
                if(hasSymbolChild(temp.front(), curr))
                {
                    moveTo(temp.front(), curr);
                } else break;
            }
            else if(temp.front() == 'S')
            {
               temp.pop();
                if(hasSymbolChild(temp.front(), curr))
                {
                    moveTo(temp.front(), curr);
                } else break;
            }
            else if(temp.front() == 'E')
            {
                temp.pop();
                if(hasSymbolChild(temp.front(), curr))
                {
                    moveTo(temp.front(), curr);
                } else break;
            }
            else if(temp.front() == 'W')
            {
                temp.pop();
                if(hasSymbolChild(temp.front(), curr))
                {
                    moveTo(temp.front(), curr);
                } else break;
            }
            else if(temp.front() == 'P')
            {
                temp.pop();
                if(hasSymbolChild(temp.front(), curr))
                {
                    moveTo(temp.front(), curr);
                } else break;
            }
        }
   }

    addHelper(temp, curr);
}

void PTree::addHelper(std::queue<char> c, node*& curr)
{
    if(curr == nullptr)
    {
        if(c.empty())
        {
            return;
        }

        std::vector<node*> v{nullptr};
        v.resize(5);

        curr = new node{c.front(), v};
        c.pop();
    }

    if(!c.empty())
    {
        switch(c.front())
        {
            case 'N': 
                addHelper(c, curr->instr[0]);
                break;
            case 'S': 
                addHelper(c, curr->instr[1]);
                break;
            case 'E': 
                addHelper(c, curr->instr[2]);
                break;
            case 'W': 
                addHelper(c, curr->instr[3]);
                break;
            case 'P': 
                addHelper(c, curr->instr[4]);
                break;
        }
    }    
}

void PTree::print() const
{
    printHelper(root);
    std::cout << std::endl;    
}

void PTree::printHelper(node* curr) const
{
    if(!curr)
    {
        return;
    }

    printHelper(curr->instr[0]);
    printHelper(curr->instr[1]);

    std::cout << curr->data << " ";

    printHelper(curr->instr[2]);
    printHelper(curr->instr[3]);
    printHelper(curr->instr[4]);
}

void PTree::viz(std::ostream& out) const
{
    out << "digraph G{\n";
    vizHelper(out,root);
    out << "}";
}

void PTree::vizHelper(std::ostream& out, node* curr) const
{
    if(curr == nullptr)
    {
        return;
    }

    vizHelper(out,curr->instr[0]);
    vizHelper(out,curr->instr[1]);
    vizHelper(out,curr->instr[2]);
    vizHelper(out,curr->instr[3]);
    vizHelper(out,curr->instr[4]);

    out << (long)curr << "[label=\"" << curr->data << "\"]\n";
    
        if(curr->instr[0] != nullptr)
        {
            out << (long)curr << "->" << (long)curr->instr[0]<< ";\n";
        }
        if(curr->instr[1] != nullptr)
        {
            out << (long)curr << "->" << (long)curr->instr[1]<< ";\n";
        }
        if(curr->instr[2] != nullptr)
        {
            out << (long)curr << "->" << (long)curr->instr[2]<< ";\n";
        }
        if(curr->instr[3] != nullptr)
        {
            out << (long)curr << "->" << (long)curr->instr[3]<< ";\n";
        }
        if(curr->instr[4] != nullptr)
        {
            out << (long)curr << "->" << (long)curr->instr[4]<< ";\n";
        }
}
