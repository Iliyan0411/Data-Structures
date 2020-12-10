#include "PathTree.h"


PTree::PTree()
{
    std::vector<node*> v{nullptr};
    v.resize(5);

    root = new node{'B', v};
}

PTree::~PTree()
{
    clear(root);
}

void PTree::clear(node* curr)
{
    if(!curr)
    {
        return;
    }

    clear(curr->instr[0]);
    clear(curr->instr[1]);
    clear(curr->instr[2]);
    clear(curr->instr[3]);
    clear(curr->instr[4]);

    delete curr;
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

void PTree::add(const std::queue<char>& q)
{
   std::queue<char> temp = q;
   node* curr = root;

   if(!isLeaf(curr))
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

void PTree::addHelper(std::queue<char> q, node*& curr)
{
    if(curr == nullptr)
    {
        if(q.empty())
        {
            return;
        }

        std::vector<node*> v{nullptr};
        v.resize(5);

        curr = new node{q.front(), v};
        q.pop();
    }

    if(!q.empty())
    {
        switch(q.front())
        {
            case 'N': 
                addHelper(q, curr->instr[0]);
                break;
            case 'S': 
                addHelper(q, curr->instr[1]);
                break;
            case 'E': 
                addHelper(q, curr->instr[2]);
                break;
            case 'W': 
                addHelper(q, curr->instr[3]);
                break;
            case 'P': 
                addHelper(q, curr->instr[4]);
                break;
        }
    }    
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

void PTree::createLeafIndex()
{
    createLeafIndexHelper(root);
}

bool PTree::isLeaf(node* curr) const
{
    for(int i = 0; i < 5; i++)
    {
        if(curr->instr[i])
        {
            return false;
        }
    }

    return true;
}

void PTree::createLeafIndexHelper(node* curr)
{
    if(!curr)
    {
        return;
    }

    if(isLeaf(curr))
    {
        curr->index = PTree::indexCounter;
        PTree::indexCounter++;
    }
    else curr->index = -1;

    createLeafIndexHelper(curr->instr[0]);
    createLeafIndexHelper(curr->instr[1]);
    createLeafIndexHelper(curr->instr[2]);
    createLeafIndexHelper(curr->instr[3]);
    createLeafIndexHelper(curr->instr[4]);
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

    std::cout << "(" << curr->data << "->" << curr->index << ") ";

    printHelper(curr->instr[0]);
    printHelper(curr->instr[1]);
    printHelper(curr->instr[2]);
    printHelper(curr->instr[3]);
    printHelper(curr->instr[4]);
}

std::string PTree::wantedPath(const int& id) const
{
    std::string path;

    wantedPathHelper(id, root, path);

    return path;
}

void PTree::wantedPathHelper(const int& id, node* curr, std::string& str) const
{
    if(!curr || !member(id, curr) || (isLeaf(curr) && curr->index != id))
    {
        return;
    }

    if(curr->index == id)
    {
        str.push_back(curr->data);
        return;
    }
    if(member(id, curr))
    {
        str.push_back(curr->data);
    }

    wantedPathHelper(id, curr->instr[0], str);
    wantedPathHelper(id, curr->instr[1], str);
    wantedPathHelper(id, curr->instr[2], str);
    wantedPathHelper(id, curr->instr[3], str);
    wantedPathHelper(id, curr->instr[4], str);
}

bool PTree::member(const int& id, node* curr) const
{
    return curr && (curr->index == id ||
                    member(id, curr->instr[0]) ||
                    member(id, curr->instr[1]) ||
                    member(id, curr->instr[2]) ||
                    member(id, curr->instr[3]) ||
                    member(id, curr->instr[4]));
}
