/*
Suppose there is a graph of relationships between parents and children over multiple generations.
The data is formatted as a list of (parent, child) pairs.

Write a function that takes in the input list and returns a list of individuals containing zero known parents and a list of individuals with exactly one known parent

 parentChildPairs = [
  [1, 3],
  [2, 3],
  [3, 6],
  [5, 6],
  [5, 7],
  [4, 5],
  [4, 8],
  [8, 10]
];

nodesWithZeroAndOneParents = [
  [1, 2, 4]
  [5, 7, 8, 10]
]
*/

parentChildPairs = [
  [1, 3],
  [2, 3],
  [3, 6],
  [5, 6],
  [5, 7],
  [4, 5],
  [4, 8],
  [8, 10]
];

function nodes(arr) {

  const [parents, childs] = arr.reduce( 
    ([parents, childs], [first, second]) => [ 
      //  Build two arrays, one for fisrt column and another for the second, basically a map function
      [...new Set(parents), first], [...childs.sort( (a, b) => a - b), second]
    ], [ [], [] ]);
  //   Filter all that does not appear in the second column
  const zero = parents.filter( i => !childs.includes(i) );
  //   Filter the ones that appear just once
  const one = childs.filter( i => childs.indexOf(i) === childs.lastIndexOf(i) );
  
  return [zero, one]

}

console.log(nodes(parentChildPairs));