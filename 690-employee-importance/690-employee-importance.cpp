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
        
        int ans = 0;
        
        for(auto node: employees){
            if(node->id==id){
                ans+=node->importance;
                for(int subs: node->subordinates){
                    ans+= getImportance(employees, subs);
                }
            }
        }
        return ans;
        
    }
};