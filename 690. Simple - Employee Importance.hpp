/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if(!employees.size())   return 0;
        for(auto e:employees){
            handle[e->id] = e;
        }
        
        Travel(id);
        return ans;
    }
private:
    unordered_map<int, Employee*> handle;
    int ans=0;
    void Travel(int id){
        ans += handle[id]->importance;
        for(const int sub: handle[id]->subordinates){
            Travel(sub);
        }
    }
};