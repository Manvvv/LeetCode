class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        // Step 1: Sort the cards
        sort(deck.begin(), deck.end());

        int n = deck.size();
        vector<int> ans(n);

        // Step 2: Store positions in a queue
        queue<int> q;

        for (int i = 0; i < n; i++) {
            q.push(i);
        }

    
        for (int card : deck) {

            
            int pos = q.front();
            q.pop();

            ans[pos] = card;

            
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};