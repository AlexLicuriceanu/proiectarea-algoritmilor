#include "Solution.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int Solution1::find(vector<int> arr, int left, int right) {

    // Base case.
    if (left == right) {
        return arr[left];
    }

    // Find the middle index.
    int mid = (left + right) / 2;

    // If mid is odd.
    if (mid & 1)
    {
        // If the element before mid is the same as the middle element, the odd
        // element lies on the right side; otherwise, it lies on the left side.
        if (arr[mid] == arr[mid-1]) {
            return find(arr, mid + 1, right);
        }
        else {
            return find(arr, left, mid - 1);
        }
    }

    // If mid is even.
    else {
        // If the element next to mid is the same as the middle element, the odd
        // element lies on the right side; otherwise, it lies on the left side
        if (arr[mid] == arr[mid+1]) {
            return find(arr, mid + 2, right);
        }
        else {
            return find(arr, left, mid);
        }
    }
}

void Solution1::run() {

    // Open the input and output files.
    ifstream fin(DIVIDE_IN_PATH);
    ofstream fout(DIVIDE_OUT_PATH);

    // Read the number of elements.
    int n;
    fin >> n;

    // Read the elements.
    vector<int> arr;

    for (int i=0; i<n; i++) {
        int element;
        fin >> element;
        arr.push_back(element);
    }

    // Solve.
    int result = find(arr, 0, n - 1);

    // Output the result.
    fout << result;

    // Close the files.
    fin.close();
    fout.close();
}

struct Solution2::cmp {
    bool operator()(const PAIR& a, const PAIR& b)
    {
        if(a.second < b.second) return true;
        else if(a.second > b.second) return false;
        else return a.first > b.first;
    }
};

void Solution2::rearrange(string &str, int d) {

    // Length of the string
    int n = str.length();

    // A structure to store a character and its frequency
    unordered_map<char, int> m;

    // Traverse the input string and store frequencies of
    // all characters.
    for (int i = 0; i < n; i++) {
        m[str[i]]++;
        str[i] = '\0';
    }

    // max-heap
    priority_queue<PAIR, vector<PAIR>, Solution2::cmp> pq(m.begin(), m.end());

    // Now one by one extract all distinct characters from
    // heap and put them back in str with the d
    // distance constraint
    while (!pq.empty()) {
        char x = pq.top().first;

        // Find the first available position in str
        int p = 0;
        while (str[p] != '\0')
            p++;

        // Fill x at p, p+d, p+2d, .. p+(frequency-1)d
        for (int k = 0; k < pq.top().second; k++) {

            // If the index goes beyond size, then the string
            // cannot be rearranged.
            if (p + d * k >= n) {
                str = "Impossible";
                return;
            }
            str[p + d * k] = x;
        }
        pq.pop();
    }
}

void Solution2::run() {

    // Open the input and output files.
    ifstream fin(GREEDY_IN_PATH);
    ofstream fout(GREEDY_OUT_PATH);

    // Read the distance.
    int d;
    fin >> d;

    // Read the string.
    string str;
    fin >> str;

    // Solve.
    rearrange(str, d);

    // Output.
    fout << str;

    // Close the files.
    fin.close();
    fout.close();
}

// function to pre-calculate the array in[]
// which stores the maximum height when travelled
// via branches
void Solution3::dfs1(vector<int> v[], int u, int parent)
{
    // initially every node has 0 height
    in[u] = 0;

    // traverse in the subtree of u
    for (int child : v[u]) {

        // if child is same as parent
        if (child == parent)
            continue;

        // dfs called
        dfs1(v, child, u);

        // recursively calculate the max height
        in[u] = max(in[u], 1 + in[child]);
    }
}

// function to pre-calculate the array out[]
// which stores the maximum height when traveled
// via parent
void Solution3::dfs2(vector<int> v[], int u, int parent)
{
    // stores the longest and second
    // longest branches
    int firstLongest = -1, secondLongest = -1;

    // traverse in the subtrees of u
    for (int child : v[u]) {
        if (child == parent)
            continue;

        // compare and store the longest
        // and second longest
        if (in[child] >= firstLongest) {
            secondLongest = firstLongest;
            firstLongest = in[child];
        }

        else if (in[child] > secondLongest)
            secondLongest = in[child];
    }

    // traverse in the subtree of u
    for (int child : v[u]) {
        if (child == parent)
            continue;

        int longest = firstLongest;

        // if longest branch has the node, then
        // consider the second-longest branch
        if (firstLongest == in[child])
            longest = secondLongest;

        // recursively calculate out[i]
        out[child] = 1 + max(out[u], 1 + longest);

        // dfs function call
        dfs2(v, child, u);
    }
}

vector<int> Solution3::heights(vector<int> v[], int n) {

    // traversal to calculate in[] array
    dfs1(v, 1, 0);

    // traversal to calculate out[] array
    dfs2(v, 1, 0);

    vector<int> result;
    result.reserve(n);

    for (int i = 1; i <= n; i++) {
        result[i] = max(in[i], out[i]);
    }

    return result;
}

void Solution3::run() {

    // Open the input and output files.
    ifstream fin(DYNAMIC_IN_PATH);
    ofstream fout(DYNAMIC_OUT_PATH);

    // Read number of nodes, number of edges.
    int n, m;
    fin >> n >> m;

    vector<int> tree[n+1];

    for (int i=0; i < m; i++) {
        int node1, node2;
        fin >> node1 >> node2;

        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    // Initialize in and out vectors.
    in.resize(n+1, 0);
    out.resize(n+1, 0);

    vector<int> result = heights(tree, n);
    for (int i=1; i<=n; i++) {
        fout << "Root: " << i << ", max height: " << result[i] << endl;
    }

    fin.close();
    fout.close();
}

/* A utility function to check whether a word
  is present in dictionary or not.  An array of
  strings is used for dictionary.  Using array
  of strings for dictionary is definitely not
  a good idea. We have used for simplicity of
  the program*/
int Solution4::dictionaryContains(string &word) {

    int n = dictionary.size();

    for (int i = 0; i < n; i++)
        if (dictionary[i] == word)
            return true;
    return false;
}

// Result store the current prefix with spaces
// between words
void Solution4::wordBreakUtil(const string &str, int n, string result, vector<string> *resultsVector) {

    //Process all prefixes one by one
    for (int i=1; i<=n; i++) {

        // Extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);

        // If dictionary contains this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next
        if (dictionaryContains(prefix)) {

            // If no more elements are there, print it
            if (i == n) {

                // Add this element to previous prefix
                result += prefix;
                resultsVector->push_back(result);
                return;
            }
            wordBreakUtil(str.substr(i, n - i), n - i,
                          result + prefix + " ", resultsVector);
        }
    }
}

// Prints all possible word breaks of given string
vector<string> Solution4::wordBreak(const string& str) {

    vector<string> result;

    // 3rd argument is prefix
    wordBreakUtil(str, str.size(), "", &result);
    return result;
}


void Solution4::run() {

    // Open the input and output files.
    ifstream fin(BACKTRACKING_IN_PATH);
    ofstream fout(BACKTRACKING_OUT_PATH);

    // Read number of words in dictionary.
    int n;
    fin >> n;

    // Read the dictionary.
    for (int i = 0; i<n; i++) {
        string word;
        fin >> word;
        dictionary.push_back(word);
    }

    // Read the string to break.
    string s;
    fin >> s;
    vector<string> result = wordBreak(s);

    for (auto & i : result) {
        fout << i << endl;
    }

    // Close the files.
    fin.close();
    fout.close();
}