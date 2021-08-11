#include <iostream>
#include "print.h"
// create a red-black tree class
class RBTree
{
private:             // private data members
    RBTree *lchild_; // left child
    RBTree *rchild_; // right child
    RBTree *parent_; // parent
    int key_;        // key
    bool color_;     // color
public:              // public methods
    RBTree(int key)
    {
        key_ = key;
        color_ = false;
    }
    // get left child
    RBTree *&getLchild() { return lchild_; }
    // get right child
    RBTree *&getRchild() { return rchild_; }
    // get parent
    RBTree *&getParent() { return parent_; }
    // get key
    int getKey() { return key_; }
    // get color
    bool getColor() { return color_; }
    // set left child
    void setLchild(RBTree *lchild) { lchild_ = lchild; }
    // set right child
    void setRchild(RBTree *rchild) { rchild_ = rchild; }
    // set parent
    void setParent(RBTree *parent) { parent_ = parent; }
    // set key
    void setKey(int key) { key_ = key; }
    // set color
    void setColor(bool color) { color_ = color; }
    // print
    void print() const
    {
        std::cout << "[key = " << key_ << ",";
        std::cout << " color = " << color_ << "]\n";
    }
};

class RBTreeMain
{
private:
    RBTree *root = nullptr;

    RBTree *rbt_rotate_right(RBTree *node)
    {
        RBTree *left_ = node->getLchild();
        RBTree *parent = node->getParent();
        node->setLchild(left_->getRchild());
        left_->setRchild(node);
        node->setParent(left_);
        left_->setParent(parent);
        if (parent && parent->getLchild() == node)
            parent->setLchild(left_);
        else if (parent && parent->getRchild() == node)
            parent->setRchild(left_);
        return left_;
    }

    RBTree *rbt_rotate_left(RBTree *node)
    {
        RBTree *parent = node->getParent();
        RBTree *right_ = node->getRchild();
        node->setRchild(right_->getLchild());
        right_->setLchild(node);
        node->setParent(right_);
        right_->setParent(parent);
        if (parent && parent->getLchild() == node)
            parent->setLchild(right_);
        else if (parent && parent->getRchild() == node)
            parent->setRchild(right_);
        return right_;
    }

    RBTree *left_left_case(RBTree *node)
    {
        return rbt_rotate_right(node);
    }

    RBTree *left_right_case(RBTree *node)
    {
        node->left = rbt_rotate_left(node->left);
        return left_left_case(node);
    }

    RBTree *right_right_case(RBTree *node)
    {
        return rbt_rotate_left(node);
    }

    RBTree *right_left_case(RBTree *node)
    {
        node->right = rbt_rotate_right(node->right);
        return right_right_case(node);
    }

    RBTree *perform_rotations(RBTree *node)
    {
        RBTree *granny = node->getParent()->getParent();
        if ((node == node->getParent()->left) && (node->getParent() == granny->left))
        {
            //left-left case
            return left_left_case(granny);
        }
        else if ((node == node->getParent()->left) && (node->getParent() == granny->right))
        {
            //right-left case
            return right_left_case(granny);
        }
        else if ((node == node->getParent()->right) && (node->getParent() == granny->left))
        {
            //left-right case
            return left_right_case(granny);
        }
        else
        {
            // right-right case
            return right_right_case(granny);
        }
    }

    RBTree *balance(RBTree *&parent, RBTree *&node)
    {
        if (!parent || !node)
            // root->setColor(true);
            return nullptr;
        if (node->getColor())
            // root->setColor(true);
            return nullptr;
        if (root && !root->getColor())
        {
            root->setColor(true);
            return nullptr;
        }
        if (!parent->getColor() && !node->getColor())
        {
            if (parent->getParent())
            {
                RBTree *aunt = nullptr;
                if (parent->getParent()->getLchild() == parent)
                {
                    aunt = parent->getParent()->getRchild();
                }
                else
                {
                    aunt = parent->getParent()->getLchild();
                }
                if (aunt && !aunt->getColor())
                {
                    parent->setColor(true);
                    aunt->setColor(true);
                    parent->getParent()->setColor(false);
                    return balance(parent->getParent()->getParent(), parent->getParent());
                }
                else if (!aunt || aunt->getColor())
                {
                    RBTree *temp = perform_rotations(node);
                    if (temp)
                    {
                        temp->setColor(true);
                        if (temp->getLchild())
                            temp->getLchild()->setColor(false);
                        if (temp->getRchild())
                            temp->getRchild()->setColor(false);
                    }
                    // if(temp->getParent())
                    //     balance(temp->getParent()->getParent(), temp->getParent());

                    return temp;
                }
            }
        }
        // root->setColor(true);
        return node;
    }

    RBTree *rb_insert(RBTree *&root, RBTree *&key)
    {
        if (!root)
            root = key;
        if (key->getKey() < root->getKey())
        {
            root->setLchild(rb_insert(root->getLchild(), key));
            root->getLchild()->setParent(root);
        }
        else if (key->getKey() > root->getKey())
        {
            root->setRchild(rb_insert(root->getRchild(), key));
            root->getRchild()->setParent(root);
            // balance(root, root->getRchild());
        }
        return root;
    }

    //inorder traversal
    void inorder(RBTree *root)
    {
        if (root == NULL)
            return;
        root->print();
        inorder(root->getLchild());
        inorder(root->getRchild());
    }

public:
    void insert(int key)
    {
        RBTree *node = new RBTree(key);
        rb_insert(root, node);
        RBTree *temp = balance(node->getParent(), node);
        if (temp && root->getParent())
        {
            root = temp;
        }
        root->setColor(true);
    }

    //print root
    void printRoot()
    {
        LOG(root->getKey());
        LOG("\n");
    }

    void print()
    {
        call_print(root, 60, 0);
        // inorder(root);
    }
};

int main()
{
    RBTreeMain rb;
    rb.insert(1);
    rb.insert(2);
    rb.insert(3);
    rb.insert(4);
    rb.insert(5);
    rb.insert(6);
    rb.insert(7);
    // rb.insert(3);
    // rb.insert(1);
    // rb.insert(5);
    // rb.insert(7);
    // rb.insert(6);
    // rb.insert(8);
    // rb.insert(9);
    rb.insert(8);
    rb.insert(9);
    rb.insert(10);
    rb.insert(11);
    rb.insert(12);
    rb.insert(13);
    rb.insert(14);
    rb.insert(15);
    rb.insert(16);
    rb.insert(17);
    rb.insert(18);

    rb.print();
    rb.printRoot();
    return 0;
}