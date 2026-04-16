import java.util.*;

class Solution {

    /*
    PATTERN:
    Backtracking + Sorting + Duplicate Skipping
    */

    public void backtrack(List<List<Integer>> list, List<Integer> l, int[] a, int k, int i) {

        // ✅ Base case
        if (k == 0) {
            list.add(new ArrayList<>(l)); // ✅ direct add
            return;
        }

        for (int j = i; j < a.length; j++) {

            // ✅ Skip duplicates
            if (j > i && a[j] == a[j - 1]) continue;

            // ✅ Pruning
            if (a[j] > k) break;

            // choose
            l.add(a[j]);

            // recurse
            backtrack(list, l, a, k - a[j], j + 1);

            // backtrack
            l.remove(l.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        Arrays.sort(candidates); // ✅ must

        List<List<Integer>> list = new ArrayList<>();
        backtrack(list, new ArrayList<>(), candidates, target, 0);
        return list;
    }

    // ✅ MAIN FUNCTION (your format)
    public static void main(String[] args) {

        Solution obj = new Solution();

        int[] candidates = {10, 1, 2, 7, 6, 1, 5};
        int target = 8;

        List<List<Integer>> ans = obj.combinationSum2(candidates, target);

        System.out.println("Combinations:");
        for (List<Integer> res : ans) {
            System.out.println(res);
        }
    }
}

/*
PATTERN USED:
Backtracking with duplicate skipping

EXPECTED OUTPUT:
Combinations:
[1, 1, 6]
[1, 2, 5]
[1, 7]
[2, 6]
*/