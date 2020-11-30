#include "tree.h"

bool BSTree::empty() const {
    return !root;
}

bool BSTree::member(const int& element) const {
    return memberHelper(element, root);
}

bool BSTree::memberHelper(const int& element, const BSTree::BTreeNode* _root) const {
    if (empty()) {
        return false;
    }

    if (element > _root->data) {
        return memberHelper(element, _root->right);
    }

    if (element < _root->data) {
        return memberHelper(element, _root->left);
    }

    return true;
}

void BSTree::add(const int& element) {
    addHelper(element, root);
}

void BSTree::addHelper(const int& element, BSTree::BTreeNode*& _root) {
    if (!_root) {
        _root = new BSTree::BTreeNode{element}; 
        return;
    } 
    else if (element > _root->data) {
        addHelper(element, _root->right);
    } 
    else if (element < _root->data) {
        addHelper(element, _root->left);
    }

    _root->height = std::max(heightHelper(_root->left), heightHelper(_root->right)) + 1;
    int rootBalance = balance(_root);

    if(rootBalance < -1 && element > _root->right->data)
    {
        leftRotation(_root);
    }
    else if(rootBalance < -1 && element < _root->right->data)
    {
        rightRotation(_root->right);
        leftRotation(_root);
    }
    else if(rootBalance > 1 && element < _root->left->data)
    {
        rightRotation(_root);
    }
    else if(rootBalance > 1 && element > _root->left->data)
    {
        leftRotation(_root->left);
        rightRotation(_root);
    }
}

void BSTree::print() const
{
    printHelper(root);
    std::cout << std::endl;
}

void BSTree::printHelper(BSTree::BTreeNode* curr) const
{
    if(!curr)
    {
        return;
    }

    printHelper(curr->left);
    std::cout << curr->data << " ";
    printHelper(curr->right);
}

void BSTree::printDot(std::ostream& out) const
{
    out << "digraph G{\n";
    printDotHelp(out,root);
    out << "}";
}

void BSTree::printDotHelp(std::ostream& out, BSTree::BTreeNode* curr) const
{
    if(curr == nullptr)
    {
        return;
    }

    printDotHelp(out,curr->left);

    out << (long)curr << "[label=\"" << curr->data << "\"]\n";
    
    if(curr->left != nullptr)
    {
        out << (long)curr << "->" << (long)curr->left << "[color=red]"<< ";\n";
    }

    if(curr->right != nullptr)
    {
        out << (long)curr << "->" << (long)curr->right << "[color=blue]"<< ";\n";
    }

    printDotHelp(out,curr->right); 
}

void BSTree::remove(const int& element) {
    removeHelper(element, root);
}

void BSTree::removeHelper(const int& element, BTreeNode*& _root) {
    if (!_root) {
        return;
    }
    if (element < _root->data) {
        removeHelper(element, _root->left);
    }

    if (element > _root->data) {
        removeHelper(element, _root->right);
    }

    if (element == _root->data) {
        if (!_root->left && !_root->right) {
            BTreeNode* save = _root;
            _root = nullptr;
            delete save;
        }
        if (!_root->left && _root->right) {
            BTreeNode* save = _root;
            _root = _root->right;
            delete save;
        }
        if (_root->left && !_root->right) {
            BTreeNode* save = _root;
            _root = _root->left;
            delete save;
        } else {
            BTreeNode* minRightNode = findMinInRightSubtree(_root->right);
            std::swap(_root->data, minRightNode->data);
            removeHelper(element, _root->right);
        }
    }
}

int BSTree::height() const
{
    return heightHelper(root);
}

int BSTree::heightHelper(BSTree::BTreeNode* _root) const
{
    if(!_root)
    {
        return -1;
    }

    return std::max(heightHelper(_root->right), heightHelper(_root->left)) + 1;
}

int BSTree::balance(const BSTree::BTreeNode* curr) const
{
    return heightHelper(curr->left) - heightHelper(curr->right);
}

void BSTree::leftRotation(BSTree::BTreeNode*& _root)
{
    BTreeNode* rightChild = _root->right;
    
    if(rightChild->left)
    {
        BTreeNode* leftGrandChild = rightChild->left;
        _root->right = leftGrandChild;
    }

    rightChild->left = _root;
    _root = rightChild;
}

void BSTree::rightRotation(BSTree::BTreeNode*& _root)
{
    BTreeNode* leftChild = _root->left;
    
    if(leftChild->right)
    {
        BTreeNode* rightGrandChild = leftChild->right;
        _root->left = rightGrandChild;
    }

    leftChild->right = _root;
    _root = leftChild;
}

BSTree::BTreeNode* BSTree::findMinInRightSubtree(BSTree::BTreeNode* _root) {
    while(_root->left) {
        _root = _root->left;
    }
    return _root;
}