#include<iostream>
#include<climits>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        std::cout << node->data << std::endl;
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}

void solve(Node* root, int sum, int &maxSum, int length, int &maxLenght)
{
    if(root==NULL)
    {
        if(length>maxLenght)
        {
            maxLenght = length;
            maxSum = sum;
        }

        else if(maxLenght==length)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum+= root->data;
    solve(root->left, sum, maxSum, length+1, maxLenght);
    solve(root->right,sum, maxSum, length+1, maxLenght);
}

int MaxPathSum(Node* root)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int length = 0;
    int maxLenght = 0;

    solve(root, sum, maxSum, length, maxLenght);

    return maxSum;
}



int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    return 0;
}