/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode *makeTree(queue<string> &q)
    {
        if (q.empty())
            return NULL;

        string val = q.front();
        q.pop();
        if (val.compare("null") == 0)
            return NULL;

        TreeNode *root;
        root = new TreeNode(stoi(val));
        root->left = makeTree(q);
        root->right = makeTree(q);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        queue<string> q;
        int i = 0;
        string temp = "";
        while (i < data.size())
        {
            if (data[i] == ',')
            {
                q.push(temp);
                temp = "";
            }
            else
                temp += data[i];
            i++;
        }
        return makeTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));