#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
unordered_map<int, int>mp;
int Sum;
int Min;

void build_tree(vector<int>&inorder, vector<int>&postorder, int inl, int inr, int pol, int por, int sum = 0)
{
    if(inl > inr || pol > por) return;
    if(inl == inr)
    {
        if(Sum == sum + inorder[inl])
        {
            Sum = sum + inorder[inl];
            Min = min(Min, inorder[inl]);
        }
        else if(Sum > sum + inorder[inl])
        {
            Sum = sum + inorder[inl];
            Min = inorder[inl];
        }
        return;
    }
    // Find the root
    int pos = mp[postorder[por]];

    build_tree(inorder, postorder, inl, pos - 1, pol, pol + pos - inl - 1, sum + inorder[pos]) ;
    build_tree(inorder, postorder, pos + 1, inr, pol + pos - inl, por - 1, sum + inorder[pos]);

    return;
}



int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    while(getline(cin, s1))
    {
        getline(cin, s2);

        //initialize 
        Sum = INT_MAX;
        Min = INT_MAX;
        mp.clear();
        //initialize ends
        
        vector<int>inorder, postorder;
        int num;
        stringstream ss(s1);
        int i = 0;
        while(ss >> num)
        {
            mp[num] = i++;
            inorder.push_back(num);
        }
        stringstream ss1(s2);
        while(ss1 >> num)
        {
            postorder.push_back(num);
        }
        build_tree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        cout << Min << endl;
    }
    return 0;
}
