import java.util.*;

class Solution {

    /*
    PATTERN:
    Backtracking (Choose → Explore → Unchoose)
    */

    public void backtrack(List<List<Integer>> list, List<Integer> l, int[] candidates, int target, int start) {

        // Base case
        if (target == 0) {
            list.add(new ArrayList<>(l)); // store result
            return;
        }

        if (target < 0) return;

        // Try all possibilities
        for (int i = start; i < candidates.length; i++) {

            l.add(candidates[i]); // choose

            backtrack(list, l, candidates, target - candidates[i], i); // explore

            l.remove(l.size() - 1); // unchoose (backtrack)
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> list = new ArrayList<>();

        backtrack(list, new ArrayList<>(), candidates, target, 0);

        return list;
    }

    // 🔹 MAIN FUNCTION
    public static void main(String[] args) {

        Solution obj = new Solution();

        int[] candidates = {2, 3, 6, 7};
        int target = 7;

        List<List<Integer>> result = obj.combinationSum(candidates, target);

        System.out.println("Output:");
        for (List<Integer> comb : result) {
            System.out.println(comb);
        }
    }
}

/*
EXPECTED OUTPUT:
Output:
[2, 2, 3]
[7]
*/