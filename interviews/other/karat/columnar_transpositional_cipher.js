/* 
This question was asked by Compass, Karat (2021)

Given a plain-text message and a numeric key, cipher/de-cipher the given text using Columnar Transposition Cipher
*/
function to_grid(sentence, row_length){
    var grid = [];
    var current_row;
    for (var i = 0; i < sentence.length; i++){
      if (i % row_length == 0){
        current_row === undefined ? current_row = 0 : current_row = current_row + 1;
        grid[current_row] = [];
      } 
        grid[current_row][i % row_length] = sentence.charAt(i);
    }
    return grid;
  }
  
  function transpose(original) {
      var copy = [];
      for (var i = 0; i < original.length; ++i) {
          for (var j = 0; j < original[i].length; ++j) {
              // skip undefined values to preserve sparse array
              if (original[i][j] === undefined) continue;
              // create row if it doesn't exist yet
              if (copy[j] === undefined) copy[j] = [];
              // swap the x and y coords for the copy
              copy[j][i] = original[i][j];
          }
      }
      return copy;
  }
  
  function to_string(arr) {
    let new_string = ""; // empty string to avoid undefined concatenation
    for (var i = 0; i < arr.length; i++){
      for (var j = 0; j < arr[i].length; j++){
        new_string = new_string.concat(arr[i][j]);
      }
    }
    return new_string;
  }
  
  function columnar_transpositional_cipher(sentence, row_length) {
    let grid = to_grid(sentence, row_length);
    grid = transpose(grid);
    return to_string(grid);
  }
  
  let sentence = "This is a dragon";
  console.log(`Given: ${sentence} \nOutput is: ` + columnar_transpositional_cipher(sentence, 4));

  // Time complexity is O(n*m)
  // Space complexity is O(n*m)