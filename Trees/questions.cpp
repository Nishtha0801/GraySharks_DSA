// leetcode 236 ===============
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // nodeToRootPath -> p, q
        vector< TreeNode*> list1 = nodeToRootPathTwo(root, p->val);
        vector< TreeNode*> list2 = nodeToRootPathTwo(root, q->val);

        int i = list1.size()-1;
        int j= list2.size()-1;

        TreeNode* LCA = nullptr;
        while(i>=0 && j>=0){
            if(list1[i] == list2[j]){
                LCA = list1[i]; 
            }
            i--;
            j--;
        }

    return LCA;
    }

    // leetcode 112 ===================
      bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }

        if(root->left == nullptr && root->right == nullptr && targetSum-root->val == 0){
            return true;
        }

        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }

    // leetcode 113
    void pathSum(TreeNode* root, int sum, vector<vector<int>>&res, vector<int>&path){
        if(root == nullptr){
            return;
        }

        if(root->left == nullptr && root->right == nullptr && sum-root->val == 0){
           vector<int>ans(path.size(),0);
           for(int i=0;i<path.size();i++){
               ans[i] = path[i];
           }
           ans.push_back(root->val);
           res.push_back(ans);
           return;
        }

        path.push_back(root->val);
        pathSum(root->left, sum-root->val, res, path);
        pathSum(root->right, sum-root->val, res, path);
        path.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>path;
         pathSum(root, sum, res, path);
         return res;
    }

    // leetcode 1325
      TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == nullptr){
            return nullptr;
        }

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(root->left == nullptr && root->right == nullptr && root->val == target){
            return nullptr;
        }
        
        return root;
      }