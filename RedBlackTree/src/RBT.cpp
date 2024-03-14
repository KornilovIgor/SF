#include "RBT.h"

//insert
void RBTree::insert(int key)
{
   Node* z = new Node(key);
   insert(root, z);
}

void RBTree::insert(Node* root, Node* node)
{
   Node* currentNode = root;
   Node* parentNode = nullptr;

   while (currentNode != nullptr)
   {
       parentNode = currentNode;
       if (node->key > currentNode->key)
           currentNode = currentNode->right;
       else
           currentNode = currentNode->left;
   }
   node->parent = parentNode;

   if (parentNode != nullptr)
   {
       if (node->key > parentNode->key)
           parentNode->right = node;
       else
           parentNode->left = node;
   }
   else
       root = node;

   node->color = Red;
   InsertFixUp(root, node);
}

// block 1
void RBTree::InsertFixUp(Node*& root, Node* node)
{
   Node* parent;
   parent = node->parent;

   while (node != RBTree::root  && parent->color == Red)
   {
       Node* gparent = parent->parent;
       if (gparent->left == parent)
       {
           Node*uncle = gparent->right;
           if (uncle != nullptr && uncle->color == Red)
// block 2
           {
               parent->color = Black;
               uncle->color = Black;
               gparent->color = Red;
               node = gparent;
               parent = node->parent;
           }
// block 3
           else
// block 4
           {
               if (parent->right == node)
               {
                   leftRotate(root, parent);
                   swap(node, parent);
               }
               rightRotate(root, gparent);
               gparent->color = Red;
               parent->color = Black;
               break;
           }
// block 5
       }
       else
       {
           Node* uncle = gparent->left;
           if (uncle != nullptr && uncle->color == Red)
// block 6
           {
               gparent->color = Red;
               parent->color = Black;
               uncle->color = Black;

               node = gparent;
               parent = node->parent;
           }
// block 7
           else
// block 8
           {
               if (parent->left == node)
               {
                   rightRotate(root, parent);
                   swap(parent, node);
               }
               leftRotate(root, gparent);
               parent->color = Black;
               gparent->color = Red;
               break;
           }
// block 9
       }
   }
   root->color = Black;
}

Node* RBTree::search(int key)
{
   return search(root, key);
}

Node* RBTree::search(Node*node, int key) const
{
   if (node == nullptr || node->key == key)
       return node;
   else
       if (key > node->key)
           return search(node->right, key);
       else
           return search(node->left, key);
}

void RBTree::remove(int key)
{
   Node* deletenode = search(root,key);
   if (deletenode != nullptr)
       remove(root, deletenode);
}

void RBTree::remove(Node*& root, Node* node)
{
   Node* child;
   Node* parent;
   Color color;
   // Узел слева и справа от удаляемого узла не пуст
   if (node->left != nullptr && node->right != nullptr)
       Node *replace = node;
       // Находим узел-преемник (самый нижний узел правого поддерева текущего узла)
       replace = node->right;
       while (replace->left != nullptr)
       {
           replace = replace->left;
       }

       // Удаленный узел не является корнем
       if (node->parent != nullptr)
       {
           if (node->parent->left == node)
               node->parent->left = replace;
           else
               node->parent->right = replace;
       }
       else
           root = replace;
       // сохраняем нужные указатели заменяемого элемента и цвет
       child = replace->right;
       parent = replace->parent;
       color = replace->color;

       // Узел заменяется родительским узлом замены
       if (parent == node)
           parent = replace;
       else
       {
           // Есть дочерние узлы
           if (child != nullptr)
               child->parent = parent;
           parent->left = child;

           replace->right = node->right;
           node->right->parent = replace;
       }
       replace->parent = node->parent;
       replace->color = node->color;
       replace->left = node->left;
       node->left->parent = replace;
       if (color == Black)
           removeFixUp(root, child, parent);

       delete node;
       return;
   }
   // Когда удаленный узел имеет только левый (правый) узел, находим дочерний узел удаленного узла
   if (node->left != nullptr)
       child = node->left;
   else
       child = node->right;

   parent = node->parent;
   color = node->color;
   if (child)
   {
       child->parent = parent;
   }
   // Удаленный узел не корень
   if (parent)
   {
       if (node == parent->left)
           parent->left = child;
       else
           parent->right = child;
   }
   // Удаленный узел - корень
   else
       RBTree::root = child;

   if (color == Black && root)
   {
       removeFixUp(root, child, parent);
   }
   delete node;

}

// block 1
void RBTree::removeFixUp(Node*& root, Node* node, Node* parent)
{
   Node* othernode;
   while ((!node) || node->color == Black && node != RBTree::root)
   {
       if (parent->left == node)
// block 2
       {
           othernode = parent->right;
           if (othernode->color == Red)
           {
               othernode->color = Black;
               parent->color = Red;
               leftRotate(root, parent);
               othernode = parent->right;
           }
// block 3
           else
           {
// block 4 
               if (!(othernode->right) || othernode->right->color == Black)
               {
                   othernode->left->color=Black;
                   othernode->color = Red;
                   rightRotate(root, othernode);
                   othernode = parent->right;
               }
               othernode->color = parent->color;
               parent->color = Black;
               othernode->right->color = Black;
               leftRotate(root, parent);
               node = root;
               break;
// block 5
           }
       }
       else
       {
// block 6
           othernode = parent->left;
           if (othernode->color == Red)
           {
               othernode->color = Black;
               parent->color = Red;
               rightRotate(root, parent);
               othernode = parent->left;
           }
// block 7
           if ((!othernode->left || othernode->left->color == Black) 
               && (!othernode->right || othernode->right->color == Black))
           {
               othernode->color = Red;
               node = parent;
               parent = node->parent;
           }
           else
           {
               if (!(othernode->left) || othernode->left->color == Black)
               {
                   othernode->right->color = Black;
                   othernode->color = Red;
                   leftRotate(root, othernode);
                   othernode = parent->left;
               }
               othernode->color = parent->color;
               parent->color = Black;
               othernode->left->color = Black;
               rightRotate(root, parent);
               node = root;
               break;
           }
// block 8
       }
   }
   if (node)
       node->color = Black;
}