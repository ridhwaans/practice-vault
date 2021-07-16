import java.util.*;
import java.util.Map.Entry;
import java.util.stream.Collectors;

class Solution {
    private static boolean ASC = true;
    private static boolean DESC = false;

    public static void main(String[] args) {
        int[] arryNum = new int[] { 4, 4, 4, 3, 4, 5, 4, 3, 4, 4, 4, 5, 4, 5, 5, 5, 4, 3, 2, 15, 4,
            3, 4, 6, 4, 3, 4, 5, 4, 2, 4, 5, 4, 3, 2, 5, 4, 3, 5, 4, 0, 4, 3, 4, 5, 4, 3, 0, 4,
            5, 4, 3, 5, 4, 2, 3, 2, 3, 4 };
        Map<Integer, Integer> lookup = new HashMap<>();
        for (int key : arryNum) {
            if(lookup.containsKey(key)) {
                lookup.put(key, lookup.get(key) + 1);
            } else {
                lookup.put(key, 1);
            }
        }
        
        System.out.println(Arrays.toString(arryNum));
        for (Integer keys : lookup.keySet()) {
            System.out.println(keys + " Found " + lookup.get(keys) + " Times");
        }

        System.out.println("Before sorting......");
        printMap(lookup);

        System.out.println("After sorting ascending order......");
        Map<Integer, Integer> lookupAsc = sortByValue(lookup, ASC);
        printMap(lookupAsc);

        System.out.println("After sorting descending order......");
        Map<Integer, Integer> lookupDesc = sortByValue(lookup, DESC);
        printMap(lookupDesc);
      
        int originalLength = arryNum.length;
        int minRemovals = 0;
              
        for (Integer curKey : lookupDesc.keySet()) {
            // Get the key
            int num = curKey;
            // Remove the key
            arryNum = removeElements(arryNum, num);
            
            minRemovals = minRemovals + 1;
            System.out.println("Removed " + num + ", new length is " + arryNum.length);
                
            if (arryNum.length <= (originalLength/2)) {
                break;
            }
        }
        System.out.println("Initial Length: " + originalLength);
        System.out.println("Final Length: " + arryNum.length);
        System.out.println(Arrays.toString(arryNum));
        System.out.println("Answer is " + minRemovals);
    }

    private static int[] removeElements(int[] arr, int key) {
        // return a new array except given key
        return Arrays.stream(arr)
            .filter(val -> val != key)
            .toArray();
    }
    
    private static Map<Integer, Integer> sortByValue(Map<Integer, Integer> unsortMap, final boolean order) {
        List<Entry<Integer, Integer>> list = new LinkedList<>(unsortMap.entrySet());

        // Sorting the list based on values
        list.sort((o1, o2) -> order ? o1.getValue().compareTo(o2.getValue()) == 0
                ? o1.getKey().compareTo(o2.getKey())
                : o1.getValue().compareTo(o2.getValue()) : o2.getValue().compareTo(o1.getValue()) == 0
                ? o2.getKey().compareTo(o1.getKey())
                : o2.getValue().compareTo(o1.getValue()));
        return list.stream().collect(Collectors.toMap(Entry::getKey, Entry::getValue, (a, b) -> b, LinkedHashMap::new));
    }

    private static void printMap(Map<Integer, Integer> map) {
        map.forEach((key, value) -> System.out.println("Key : " + key + " Value : " + value));
    }
}