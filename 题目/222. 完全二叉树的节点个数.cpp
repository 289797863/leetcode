//方法一：利用完全二叉树结点的特殊性质，每个结点的编号可以用二进制编码来表示(具体可以看题解)。

//方法二：利用完全二叉树的递归性质，完全二叉树左子树或者右子树必有一个是完全二叉树。递归到深度最小的非完全二叉子树，其他部分都可以用完全二叉树的性质计算结点数。

//方法一：
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};

//方法二：
class Solution {
public:
    // 统计树的深度
    int countLevels(TreeNode* root) {
        int levels = 0;
        while (root) {
            root = root->left; levels += 1;
        }
        return levels;
    }
    int countNodes(TreeNode* root){
        // 2. 利用完全二叉树性质简化遍历次数
        if(root == nullptr) return 0;
        int left_levels = countLevels(root->left);
        int right_levels = countLevels(root->right);
        // 左子树深度等于右子树深度, 则左子树是满二叉树
        if(left_levels == right_levels){
            return countNodes(root->right) + (1<<left_levels);
        }else{
            return countNodes(root->left) + (1<<right_levels);
        }
    }
};
