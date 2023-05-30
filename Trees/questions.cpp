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

      // leetcode 98
        TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        if(!isValidBST(root->left)){
            return false;
        }

        // kuchh kaam krenge
        if(prev != nullptr && prev->val >= root->val){
            return false;
        }
        prev = root;

        if(!isValidBST(root->right)){
            return false;
        }

        return true;
    }



    // leetcode 701 =========================================
      TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }

        if(val<root->val){
            root->left = insertIntoBST(root->left, val);
        } else{
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }

    // leetcode 450
      int maxVal(TreeNode* node){
        while(node->right != nullptr){
            node = node->right;
        }
        return node->val;
    }

    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }

        if(val < root->val){
            root->left = deleteNode(root->left, val);
        }

        else if(val > root->val){
            root->right = deleteNode(root->right, val);
        }

        else{ 
            // different cases
            if(root->left == nullptr || root->right == nullptr){
                TreeNode* node = root->left != nullptr ? root->left : root->right;
                delete root;
                return node; 
            }
            // 4th case =========================
            int mVal = maxVal(root->left);
            root->val = mVal;
            root->left = deleteNode(root->left, mVal);


        }

        return root;
    }

    // leetcode 235 ========================================
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->val < p->val && curr->val < q->val){
                curr = curr->right;   
            }
            else if(curr->val > p->val && curr->val > q->val){
                curr = curr->left;
            }
             else {
                 break;
             }
        }
        return curr;
    }

    //leetcode 105 =============================================
     TreeNode* buildTree(vector<int>& preorder, int psi, int pei, vector<int>& inorder, int isi, int iei) {
        if(psi>pei){
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[psi]);

        int idx = isi;
        while(inorder[idx] != preorder[psi]){
            idx++;
        }

        int count = idx - isi; // count of nodes in left subtree!

        node->left = buildTree(preorder, psi+1, psi+count, inorder, isi, idx-1);
        node->right = buildTree(preorder, psi+count+1, pei, inorder, idx+1, iei);

        return node;

    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return nullptr;
        }

        int n = preorder.size();
        return buildTree(preorder, 0, n-1, inorder, 0, n-1);
    }

    // leetcode 106 ===================================

     TreeNode* buildTree(vector<int>& postorder, int psi, int pei, vector<int>& inorder, int isi, int iei) {
         if(psi>pei){
             return nullptr;
         }

          TreeNode* node = new TreeNode(postorder[pei]);

        int idx = isi;
        while(inorder[idx] != postorder[pei]){
            idx++;
        }

        int count = idx - isi;

        node->left = buildTree(postorder, psi, psi+count-1, inorder, isi, idx-1);
        node->right = buildTree(postorder, psi+count, pei-1, inorder, idx+1, iei);

        return node;
     }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          if(postorder.size() == 0){
            return nullptr;
        }

        int n = postorder.size();
        return buildTree(postorder, 0, n-1, inorder, 0, n-1);
    }

    // leetcode 1008 ==============================
      int idx = 0;
    TreeNode* buildTree(vector<int>&arr, int lrange, int rrange){
        if(idx>=arr.size() || arr[idx] < lrange || arr[idx] > rrange){
            return nullptr;
        }

        int data = arr[idx++];
        TreeNode* node = new TreeNode(data);

        node->left = buildTree(arr, lrange, data);
        node->right = buildTree(arr, data, rrange);

        return node;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, -(int)1e9, (int)1e9);
    }

    // leetcode 230 =============
    void addAllLeft(TreeNode* node, stack<TreeNode*>&st){
        while(node!=nullptr){
            st.push(node);
            node = node->left;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        addAllLeft(root, st);

        while(--k > 0){
            TreeNode* rn = st.top();
            st.pop();

            addAllLeft(rn->right, st);
        }
        return st.top()->val;
    }