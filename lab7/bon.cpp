#include <bits/stdc++.h>

using namespace std;

struct Node {
    map<int, Node*> son;
    map<int, Node*> go;
    Node* suffLink;
    Node* up;
    Node* par;
    char cToPar;
    vector<int> term;
    Node() {
        up = NULL;
        par = NULL;
        suffLink = NULL;
    }
};

Node* root;

Node* getGo(Node* v, char c);

Node* getSuffLink(Node* v) {
    if (!v->suffLink) {
        if (v == root || v->par == root) 
            v->suffLink = root;
        else 
            v->suffLink = getGo(getSuffLink(v->par), v->cToPar);
    }
    return v->suffLink;
}

Node* getGo(Node* v, char c) {
    if (!v->go[c - 'a']) {
        if (v->son[c - 'a']) 
            v->go[c - 'a'] = v->son[c - 'a'];
        else {
            if (v == root) 
                v->go[c - 'a'] = root;
            else 
                v->go[c - 'a'] = getGo(getSuffLink(v), c);  
        }
    }
    return v->go[c - 'a'];
}

bool isTerm(Node* v) {
    return v->term.size() > 0;
}

Node* getUp(Node* v) {
    if (!v->up) {
        if (isTerm(getSuffLink(v))) 
            v->up = getSuffLink(v);
        else 
            v->up = getUp(getSuffLink(v));
    }
    return v->up;
}

void insert(string & s, int num) {
    Node* now = root;
    for (int i = 0; i < s.size(); i++) {
        if (!now->son[s[i] - 'a']) {
            now->son[s[i] - 'a'] = new Node();
            now->son[s[i] - 'a']->par = now;
            now->son[s[i] - 'a']->cToPar = s[i];
        }
        now = now->son[s[i] - 'a'];
    }
    now->term.push_back(num);
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    root = new Node();
    root->up = root;
    root->suffLink = root;
    vector<int> sz(n);
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        insert(t, i);
        sz[i] = t.size();
    }
    vector<vector<int> > ans(n);
    Node* now = root;
    for (int i = 0; i < s.size(); i++) {
        now = getGo(now, s[i]);
        Node* cur = now;
        if (!isTerm(cur)) cur = getUp(cur);
        while (cur != root) {
            for (int j = 0; j < cur->term.size(); j++) 
                ans[cur->term[j]].push_back(i - sz[cur->term[j]] + 2);
            cur = getUp(cur);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++) 
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}