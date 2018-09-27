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
        HashMap<Integer, Employee> map = new HashMap<>();
        for (Employee emp : employees)
            map.put(emp.id, emp);
        return getRes(map, id);
    }
    private int getRes(HashMap<Integer, Employee> map, int id) {
        Employee emp = map.get(id);
        int res = emp.importance;
        for (int subid : emp.subordinates) 
            res += getRes(map, subid);
        return res;
    }
}