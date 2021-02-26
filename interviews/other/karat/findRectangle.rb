# This question was asked by Wayfair, Karat (2021)
#
# Imagine we have an image. We'll represent this image as a simple 2D array where every pixel is a 1 or a 0. The image you get is known to have a single rectangle of 0s on a background of 1s.
# 
# Write a function that takes in the image and returns one of the following representations of the rectangle of 0's: top-left coordinate and bottom-right coordinate OR top-left coordinate, width, and height.
# 
# image1 = [
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 0, 0, 0, 1],
#   [1, 1, 1, 0, 0, 0, 1],
#   [1, 1, 1, 1, 1, 1, 1],
# ]
# 
# Sample output variations (only one is necessary):
# 
# findRectangle(image1) =>
#   row: 2, column: 3, width: 3, height: 2
#   2,3 3,5 -- row,column of the top-left and bottom-right corners
# 
# Other test cases:
# 
# image2 = [
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 0],
# ]
# 
# findRectangle(image2) =>
#   row: 4, column: 6, width: 1, height: 1
#   4,6 4,6
# 
# image3 = [
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 0, 0],
#   [1, 1, 1, 1, 1, 0, 0],
# ]
# 
# findRectangle(image3) =>
#   row: 3, column: 5, width: 2, height: 2
#   3,5 4,6
#   
# image4 = [
#   [0, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
#   [1, 1, 1, 1, 1, 1, 1],
# ]
# 
# findRectangle(image4) =>
#   row: 0, column: 0, width: 1, height: 1
#   0,0 0,0
# 
# image5 = [
#   [0],
# ]
# 
# findRectangle(image5) =>
#   row: 0, column: 0, width: 1, height: 1
#   0,0 0,0
# 
# n: number of rows in the input image
# m: number of columns in the input image

image1 = [
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 1, 1, 1, 1],
]

image2 = [
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 0],
]

image3 = [
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 0, 0],
  [1, 1, 1, 1, 1, 0, 0],
]

image4 = [
  [0, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
]

image5 = [
  [0],
]


def rectangleSearch(image)
  zeroes = []
  
  if image.length <= 1
    [0,0, 0,0] 
  end
    
  count = 0
  image.each_with_index do |row, r_i|
    puts row, r_i
    row.each_with_index do |item, c_i|
      if image[r_i][c_i] == 0
        gridHelper(image, zeroes, r_i, c_i)
        count += 1
      end
    end
  end
  
  [zeroes[0], zeroes[-1]]
end

def gridHelper(image, zeroes, i , j)
  if i < 0 or j >= image.length or i >= image[0].length or j < 0
    return
  end
  zeroes << [i,j]
  
  gridHelper(image, zeroes,i + 1, j)
  gridHelper(image, zeroes, i - 1, j)
  gridHelper(image, zeroes, i, j + 1)
  gridHelper(image, zeroes, i, j - 1)
end

#puts rectangleSearch([0])

puts rectangleSearch([
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1, 1, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 0, 0, 0, 1],
  [1, 1, 1, 1, 1, 1, 1],
])