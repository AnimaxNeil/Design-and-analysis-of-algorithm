// Create a Red-Black Tree and perform following operations on it:
// i. Insert a node
// ii. Delete a node
// iii. Search for a number & also report the color of the node containing this number.

#include <iostream>
using namespace std;

// Implementing Red-Black Tree in C++

#include <iostream>
using namespace std;

struct Node
{
    int data, color;
    Node *parent_node, *left_node, *right_node;

public:
    Node(int data)
    {
        this->data = data;
        color = 1;
        parent_node = left_node = right_node = NULL;
    }
    void flipColor()
    {
        color = color == 0 ? 1 : 0;
    }
    bool isLeftNode()
    {
        return this == parent_node->left_node;
    }
};

class RedBlackTree
{
    Node *root_node;

    Node *leftRotate(Node *node)
    {
        Node *r_node = node->right_node;
        Node *r_l_node = r_node->left_node;
        r_node->left_node = node;
        if (r_node->left_node != NULL)
        {
            r_node->left_node->parent_node = r_node;
        }
        node->right_node = r_l_node;
        if (node->right_node != NULL)
        {
            node->right_node->parent_node = node;
        }
        return r_node;
    }

    Node *rightRotate(Node *node)
    {
        Node *l_node = node->left_node;
        Node *l_r_node = l_node->right_node;
        l_node->right_node = node;
        if (l_node->right_node != NULL)
        {
            l_node->right_node->parent_node = l_node;
        }
        node->left_node = l_r_node;
        if (node->left_node != NULL)
        {
            node->left_node->parent_node = node;
        }
        return l_node;
    }

    Node *inorderPredecessor(Node *node)
    {
        if (node == NULL)
        {
            cout << "Node is null";
            return NULL;
        }
        if (node->left_node == NULL)
        {
            return node->isLeftNode() ? NULL : node->parent_node;
        }
        node = node->left_node;
        while (node->right_node != NULL)
        {
            node = node->right_node;
        }
        return node;
    }

    void insert_fix(Node *node)
    {
        if (node != root_node && node->parent_node->color == 1)
        {
            Node *temp_node;
            Node *uncle_node = node->parent_node->isLeftNode() ? node->parent_node->parent_node->right_node : node->parent_node->parent_node->left_node;
            if (uncle_node != NULL && uncle_node->color == 1)
            {
                node->parent_node->flipColor();
                uncle_node->flipColor();
                node->parent_node->parent_node->flipColor();
                insert_fix(node->parent_node->parent_node);
            }
            else if (node->parent_node->isLeftNode()) // left-left or left-right
            {
                node->parent_node->flipColor();
                node->parent_node->parent_node->flipColor();
                bool changeRoot = node->parent_node->parent_node == root_node;
                Node *ggp_node = node->parent_node->parent_node->parent_node == NULL ? NULL : node->parent_node->parent_node->parent_node;
                if (!node->isLeftNode())
                {
                    node = leftRotate(node->parent_node);
                    node = rightRotate(node->parent_node);
                }
                else
                {
                    node = rightRotate(node->parent_node->parent_node);
                }
                // cout << "New root " << node->data << endl;
                if (ggp_node != NULL && node->data < ggp_node->data)
                {
                    ggp_node->left_node = node;
                    if (ggp_node->left_node != NULL)
                    {
                        ggp_node->left_node->parent_node = ggp_node;
                    }
                }
                else if (ggp_node != NULL && node->data > ggp_node->data)
                {
                    ggp_node->right_node = node;
                    if (ggp_node->right_node != NULL)
                    {
                        ggp_node->right_node->parent_node = ggp_node;
                    }
                }
                if (changeRoot)
                {
                    root_node = node;
                }
                // cout << "New root " << node->data << endl;
                insert_fix(node);
            }
            else if (!node->parent_node->isLeftNode()) // right-right or right-left
            {
                node->parent_node->flipColor();
                node->parent_node->parent_node->flipColor();
                bool changeRoot = node->parent_node->parent_node == root_node;
                Node *ggp_node = node->parent_node->parent_node->parent_node == NULL ? NULL : node->parent_node->parent_node->parent_node;
                if (node->isLeftNode())
                {
                    node = rightRotate(node->parent_node);
                    node = leftRotate(node->parent_node);
                }
                else
                {
                    node = leftRotate(node->parent_node->parent_node);
                }
                // cout << "New root " << node->data << endl;
                if (ggp_node != NULL && node->data < ggp_node->data)
                {
                    ggp_node->left_node = node;
                    if (ggp_node->left_node != NULL)
                    {
                        ggp_node->left_node->parent_node = ggp_node;
                    }
                }
                else if (ggp_node != NULL && node->data > ggp_node->data)
                {
                    ggp_node->right_node = node;
                    if (ggp_node->right_node != NULL)
                    {
                        ggp_node->right_node->parent_node = ggp_node;
                    }
                }
                if (changeRoot)
                {
                    root_node = node;
                }
                // cout << "New root " << node->data << endl;
                insert_fix(node);
            }
        }
        root_node->color = 0;
    }

    void print_inorder_recursive(const Node *node)
    {
        if (root_node == NULL)
        {
            cout << "empty\n";
            return;
        }
        if (node != NULL)
        {
            print_inorder_recursive(node->left_node);
            cout << node->data << ", ";
            print_inorder_recursive(node->right_node);
        }
        if (node == root_node)
        {
            cout << "\n";
        }
    }

public:
    RedBlackTree()
    {
        root_node = NULL;
    }

    void insert(int data)
    {
        if (root_node == NULL)
        {
            root_node = new Node(data);
            root_node->color = 0;
            return;
        }
        Node *node = root_node, *pre_node;
        while (node != NULL)
        {
            pre_node = node;
            if (node->data > data)
            {
                node = node->left_node;
            }
            else if (node->data < data)
            {
                node = node->right_node;
            }
            else
            {
                cout << "Insertion failed. Node already present.\n";
                return;
            }
        }
        if (pre_node->data > data)
        {
            pre_node->left_node = new Node(data);
            pre_node->left_node->parent_node = pre_node;
            node = pre_node->left_node;
        }
        else
        {
            pre_node->right_node = new Node(data);
            pre_node->right_node->parent_node = pre_node;
            node = pre_node->right_node;
        }
        insert_fix(node);
    }

    void remove(int data)
    {
        // root_node = remove_recursive(data, root_node);
    }

    void print()
    {
        print_inorder_recursive(root_node);
    }
};

int main()
{
    RedBlackTree rbt;
    rbt.insert(7);
    rbt.insert(2);
    rbt.insert(13);
    rbt.insert(5);
    rbt.insert(19);
    rbt.insert(23);
    rbt.insert(12);
    rbt.insert(72);
    rbt.insert(6);
    // rbt.insert(52);
    rbt.print();
    cin.get();
    return 0;
}
