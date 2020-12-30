#include "PathTree.h"


PTree::PTree()
{
    reset();
}

PTree::~PTree()
{
    clear();
}

void PTree::clear()
{
    clearHelper(root);
}

void PTree::clearHelper(node* curr)
{
    if(!curr)
    {
        return;
    }

    clearHelper(curr->instr[0]);
    clearHelper(curr->instr[1]);
    clearHelper(curr->instr[2]);
    clearHelper(curr->instr[3]);
    clearHelper(curr->instr[4]);

    delete curr;
}

void PTree::reset()
{
    std::vector<node*> v{nullptr};
    v.resize(5);

    root = new node{'B', v};
    numberOfLeaves = 0;
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

void PTree::add(const std::queue<char>& newPath)
{
   numberOfLeaves++;

   std::queue<char> temp = newPath;
   node* curr = root;

   if(!isLeaf(curr))
   {
       moveTo(newPath.front(), curr);

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

void PTree::addHelper(std::queue<char> newPath, node*& curr)
{
    if(curr == nullptr)
    {
        if(newPath.empty())
        {
            return;
        }

        std::vector<node*> v{nullptr};
        v.resize(5);

        curr = new node{newPath.front(), v};
        newPath.pop();
    }

    if(!newPath.empty())
    {
        switch(newPath.front())
        {
            case 'N': 
                addHelper(newPath, curr->instr[0]);
                break;
            case 'S': 
                addHelper(newPath, curr->instr[1]);
                break;
            case 'E': 
                addHelper(newPath, curr->instr[2]);
                break;
            case 'W': 
                addHelper(newPath, curr->instr[3]);
                break;
            case 'P': 
                addHelper(newPath, curr->instr[4]);
                break;
        }
    }    
}

int PTree::leavesNum() const
{
    return numberOfLeaves;
}

void PTree::viz(std::ostream& out) const
{
    out << "digraph G{\n";
    vizHelper(out,root);
    out << "}";
}

void PTree::vizHelper(std::ostream& out, node* curr) const
{
    if(!curr)
    {
        return;
    }

    vizHelper(out,curr->instr[0]);
    vizHelper(out,curr->instr[1]);
    vizHelper(out,curr->instr[2]);
    vizHelper(out,curr->instr[3]);
    vizHelper(out,curr->instr[4]);

    out << (long)curr << "[label=\"" << curr->data << "\"]\n";
    
    for(int i = 0; i < 5; i++)
    {
        if(curr->instr[i] != nullptr)
        {
            if(curr->instr[i]->index == -1) out << (long)curr << "->" << (long)curr->instr[i]<< ";\n";
            else out << (long)curr << "->" << (long)curr->instr[i]<< "[label=" << curr->instr[i]->index << "];\n";
        }
    }
}

void PTree::createLeafIndex()
{
    int indexCounter = 0;

    createLeafIndexHelper(root, indexCounter);
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

void PTree::createLeafIndexHelper(node* curr, int& indexCounter)
{
    if(!curr)
    {
        return;
    }

    if(isLeaf(curr))
    {
        curr->index = indexCounter;
        indexCounter++;
    }
    else curr->index = -1;

    createLeafIndexHelper(curr->instr[0], indexCounter);
    createLeafIndexHelper(curr->instr[1], indexCounter);
    createLeafIndexHelper(curr->instr[2], indexCounter);
    createLeafIndexHelper(curr->instr[3], indexCounter);
    createLeafIndexHelper(curr->instr[4], indexCounter);
}

std::string PTree::wantedPath(const int& id) const
{
    std::string path;

    wantedPathHelper(id, root, std::string(), path);

    return path;
}

void PTree::wantedPathHelper(const int& id, node* curr, std::string currPath, std::string& path) const
{
    if(!curr)
    {
        return;
    }

    currPath.push_back(curr->data);

    if(curr->index == id)
    {
        path = currPath;
        return;
    }

    wantedPathHelper(id, curr->instr[0], currPath, path);
    wantedPathHelper(id, curr->instr[1], currPath, path);
    wantedPathHelper(id, curr->instr[2], currPath, path);
    wantedPathHelper(id, curr->instr[3], currPath, path);
    wantedPathHelper(id, curr->instr[4], currPath, path);
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
