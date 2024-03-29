#include "AVL.h"

#include <queue>
#include <stack>

// for empty tree
size_t AVL::height(Node *node)
{
    return node ? node->height : 0;
}

int AVL::bfactor(Node *node)
{
    return height(node->right) - height(node->left);
}

void AVL::fix_height(Node *node)
{
    size_t h_left = height(node->left);
    size_t h_right = height(node->right);

    node->height = (h_left > h_right ? h_left : h_right) + 1;
}

Node* AVL::rotateRight(Node *node)
{
    Node *q = node->left;

    node->left = q->right;
    q->right = node;

    fix_height(node);
    fix_height(q);

    return q;
}

Node* AVL::rotateLeft(Node *node)
{
    Node *q = node->right;

    node->right = q->left;
    q->left = node;
    fix_height(node);
    fix_height(q);

    return q;
}

Node* AVL::balance(Node* const node)
{
    fix_height(node);

    if(bfactor(node) == 2)
    {
        if(bfactor(node->right) < 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    if (bfactor(node) == -2)
    {
        if (bfactor(node->left) > 0)
        {
            node->left = rotateLeft(node->left);
        }
       return rotateRight(node);
   }

   return node;
}

const Node* AVL::bfs(const int& key) const
{
    if (_root == nullptr)
    {
        return nullptr;
    }

    // Создаем пустую очередь для добавления узлов с одинакового уровня -
    // имеющие одинаковую высоту
    std::queue<Node*> q;
    // кладем корень в очередь
    q.push(_root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node->key == key)
        {
            return node;
        }

        if (node->left != nullptr)
        {
            q.push(node->left);
        }
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
    }
}

const Node* AVL::dfs(const Node* node, const int& key)
{
    if (node == nullptr || node->key == key) {
        return node;
    }

    const Node* leftResult = dfs(node->left, key);
    if (leftResult != nullptr) {
        return leftResult;
    }

    const Node* rightResult = dfs(node->right, key);
    return rightResult;
}

void AVL::insert(int&& key)
{
  Node* node = new Node(key);
  _root = insert(_root, node);
}

Node* AVL::insert(Node* root, Node* const node)
{
   if(!root)
       return node;

   if(node->key < root->key)
       root->left = insert(root->left, node);
   else
       root->right = insert(root->right, node);

   return balance(root);
}

Node* AVL::removemin(Node* node)
{
   if (!node->left)
       return node->right;

   node->left = removemin(node->left);

   return balance(node);
}

// поиск узла с минимальным ключом в дереве
// всегда будет в левом поддереве, из-за условия построения bst
Node* AVL::findmin(Node* node)
{
   return node->left ? findmin(node->left) : node;
}

void AVL::delete_node(const int& key)
{
   _root = delete_node(_root, key);
}

Node* AVL::delete_node(Node* node, const int& key)
{
   if (!node)
       return 0;

   if (key < node->key)
       node->left = delete_node(node->left, key);
   else if (key > node->key)
       node->right = delete_node(node->right, key);
   else //  k == p->key
   {
       Node* q = node->left;
       Node* r = node->right;
       node -> left = nullptr;
       node -> right = nullptr;
       delete node;

       if (!r)
           return q;

       Node* min = findmin(r);
       min->right = removemin(r);
       min->left = q;
       return balance(min);
   }

   return balance(node);
}