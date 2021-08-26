class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        vector<vector<string>> answer(searchWord.size());
        string temp = "";
        for(int i=0; i<searchWord.size(); i++){
            
            temp += searchWord[i];
            
            auto start = lower_bound(products.begin(),products.end(),temp);
            auto end   = upper_bound(products.begin(),products.end(),temp+"~");
            if(start == products.end()) break;
            int k=0;
            for(auto j=start; j<end&&k<3; j++,k++){
            //for(auto j=start, int k=0; j<end&&k<3; j++,k++){
                answer[i].push_back(*j);
            }
            
        }
        return answer;
    }
    
};








