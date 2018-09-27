/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        int res = 0;
        for (Employee emp : employees) {
            if (emp.id == id) {
                res += emp.importance;
                for (int subid : emp.subordinates)
                    res += getImportance(employees, subid);
            }
        }
        return res;
    }
}