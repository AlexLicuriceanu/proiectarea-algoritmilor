#include <vector>
#include <string>

#define DIVIDE_IN_PATH "./divide-et-impera/test.in"
#define DIVIDE_OUT_PATH "./divide-et-impera/test.out"

#define GREEDY_IN_PATH "./greedy/test.in"
#define GREEDY_OUT_PATH "./greedy/test.out"

#define DYNAMIC_IN_PATH "./dynamic-programming/test.in"
#define DYNAMIC_OUT_PATH "./dynamic-programming/test.out"

#define BACKTRACKING_IN_PATH "./backtracking/test.in"
#define BACKTRACKING_OUT_PATH "./backtracking/test.out"

using namespace std;

class Solution1 {
    public:
        void run();

    private:
        int find(std::vector<int> arr, int left, int right);
};

class Solution2 {
    public:
        void run();

    private:
        void rearrange(string &str, int d);
        struct cmp;
        typedef pair<char, int> PAIR;
};

class Solution3 {
    public:
        void run();

    private:
        vector<int> heights(vector<int> *v, int n);
        void dfs1(vector<int> *v, int u, int parent);
        void dfs2(vector<int> *v, int u, int parent);
        vector<int> in, out;
};

class Solution4 {
    public:
        void run();

    private:
        vector<string> wordBreak(const string& str);
        void wordBreakUtil(const string &str, int n, string result, vector<string> *resultsVector);
        vector<string> dictionary;
        int dictionaryContains(string &word);
};