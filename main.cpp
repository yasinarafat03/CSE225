#include <iostream>
#include "binarysearchtree.cpp"

using namespace std;

class TreeType2
{
    public:
    int data;
    TreeType2* left;
    TreeType2* right;
};

TreeType2* newNode(int data);//prototype

TreeType2* MinDepTree(int arr[],int first, int last)
{

    if (first > last)
    {
        return NULL;
    }

    int m id = (first + last)/2;
    TreeType2 *root = newNode(arr[mid]);
    root->left = MinDepTree(arr, first,mid - 1);
    root->right = MinDepTree(arr, mid + 1, last);

    return root;
}


TreeType2* newNode(int data)
{
    TreeType2* node = new TreeType2();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void PrintPreO(TreeType2* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    PrintPreO(node->left);
    PrintPreO(node->right);
}


int main()
{
    int arr[]={11,9,4,2,7,3,17,0,5,1};

    int arrSize=sizeof(arr)/sizeof(int);


    TreeType<int> tree1=TreeType<int>();

    for(int i=0;i<arrSize;i++)
    {
        tree1.InsertItem(arr[i]);
    }
    //tree1.Print();
    tree1.ResetTree(IN_ORDER);

    bool finished;
    int item=0;
    int InOrderArr[arrSize];

    for(int i=0;i<arrSize;i++)
    {
    tree1.GetNextItem(item,IN_ORDER,finished);
    InOrderArr[i]=item;
    }

    cout<<"Inorder"<<endl;
    for(int i=0;i<10;i++)
    {
    cout<<InOrderArr[i]<<" ";
    }
    cout<<endl;

    TreeType2* root = MinDepTree(InOrderArr,0,arrSize-1);

    cout << "PreOrder Traversal of Minimum Heigth BST \n";
    PrintPreO(root);
    cout<<endl;
    cout << "Done!" << endl;

    return 0;
}
