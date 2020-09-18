/*
Implement a function generate_template(...)
The goal is to create a random word, phrase or full sentence from a given template data source

Template Data
[
    {
        "group_id": 154,
        "children": [234, 124, 36]
    },
    {
        "group_id": 234,
        "content": "I"
    },
    {
        "group_id": 234,
        "content": "You"
    },
    {
        "group_id": 234,
        "content": "We"
    },
    {
        "group_id": 124,
        "content": "like to"
    },
    {
        "group_id": 124,
        "content": "sometimes"
    },
    {
        "group_id": 36,
        "content": "jog"
    },
    {
        "group_id": 36,
        "children": [46, 242]
    },
    {
        "group_id": 46,
        "content": "eat"
    },
    {
        "group_id": 242,
        "content": "sandwiches"
    },
    {
        "group_id": 242,
        "content": "eggs"
    }
]
Visual representation of template_data https://i.imgur.com/srwj1a0.jpg

Here are some examples returned by generate_template(...) if it were given the above template data

generate_template(46, template_data) would return
"eat"

generate_template(124, template_data) would return one of the following
"like to"
"sometimes"

generate_template(36, template_data) would return one of the following
"jog"
"eat sandwiches"
"eat eggs"

generate_template(154, template_data) would return one of the following
"I like to jog"
"We like to eat sandwiches"
"You sometimes eat eggs"
"I sometimes eat sandwiches"
[and many other possible sentences]

FAQ
Does generate_templates(...) always return a full sentence?
No. Depending on the given group_id it might return a single word, a sequence of words, or a coherent sentence

Does generate_template(...) return all possible outputs for a given group_id?
No. generate_template(...) should return only one of the possible outputs for a given template

Are the group IDs numbered in any meaningful way?
No. The group_id for each template is randomly generated & completely arbitrary

Hint
This is a tree-based algorithm, not a NLP problem
Focus on functional code
Python has a built-in random module. random.choice(arr) might come in handy
*/
import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 */

class Solution {
  public static void main(String[] args) {
    ArrayList<String> strings = new ArrayList<String>();
    strings.add("Hello, World!");
    strings.add("Welcome to CoderPad.");
    strings.add("This pad is running Java " + Runtime.version().feature());

    for (String string : strings) {
      System.out.println(string);
    }
    
    List<TemplateData> tempData = Arrays.asList(
    new TemplateData(154,Arrays.asList(234, 124, 36)),
    new TemplateData(234,"I"),
    new TemplateData(234, "You"),
    new TemplateData(234, "We"),
    new TemplateData(124, "like to"),
    new TemplateData(124, "sometimes"),
    new TemplateData(36,"jog"),
    new TemplateData(36,Arrays.asList(46, 242)),
    new TemplateData(46,"eat"),
    new TemplateData(242, "sandwiches"),
    new TemplateData(242, "eggs"));
    
    System.out.println(getRandomSentence(46, tempData));
    System.out.println(getRandomSentence(124, tempData));
    System.out.println(getRandomSentence(36, tempData));
    System.out.println(getRandomSentence(154, tempData));
  }
  
  // returns a random element from the list
  public static Object getRandom(List<Object> list) {
    Random rand = new Random();
    return list.get(rand.nextInt(list.size()));
  }

  // translate template data into a Map<Integer, Object>
  // perform a modified BFS - keep queue of the next group ID I should traverse to -  As I traverse - if my content object is a string, I'll add it to an output StringBuilder, or if it is a list of Strings, I'll continue traversing through a random path on that list of strings

  public static class TemplateData {
    int groupId;
    String content;
    List<Integer> children;
    
    public TemplateData(int groupId, String content) {
      this.groupId = groupId;
      this.content = content;
    }
    
    public TemplateData(int groupId, List<Integer> children) {
      this.groupId = groupId;
      this.children = children;
    }
  }

  // Time: O(N + C)
  // Space: O(N + C) -> Space(N) on call stack
  public static String getRandomSentence(int groupId, List<TemplateData> templateData) {
    if (templateData == null || templateData.size() == 0) return "";
    
    Map<Integer, List<Object>> map = new HashMap<>();
    for (TemplateData tempData : templateData) {
      List<Object> list = map.getOrDefault(tempData.groupId, new ArrayList<>());
      if (tempData.content == null)
        list.add(tempData.children);
      else
        list.add(tempData.content);
      map.put(tempData.groupId, list);
    }
    
    StringBuilder builder = new StringBuilder();
    
    dft(map, groupId, builder);
    
    return builder.toString();
  }

  private static void dft(Map<Integer, List<Object>> map, int groupId, StringBuilder builder) {
    List<Object> currentList = map.get(groupId);
    Object currentObject = getRandom(currentList);
    if (currentObject instanceof String) {
      if (builder.length() != 0) builder.append(" ");
      builder.append(currentObject.toString());
    } else {
      List<Integer> nextGroupIds = (List<Integer>) currentObject;
      for (int nextGroupId : nextGroupIds) {
        dft(map, nextGroupId, builder);
      }
    }
  }
}
/*
Time complexity is O(N + C)
Space complexity is O(N + C) -> Space(N) on call stack
*/