template <typename T>
class binaryTree
{
    public:
        T data;
        binaryTree* left;
        binaryTree* right;
    binaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binaryTree()
    {
        delete left;
        delete right;
    }
};