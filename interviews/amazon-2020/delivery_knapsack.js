/*
Design a delivery algorithm where you want to carry as many packages as possible under a weight limit. 
*/
const maxPackagesUnderWeightLimit = (packages, weightLimit) => {
    packages.sort((a, b) => a - b);
    
    const res = [];
    let currWeight = 0;
    for (let i = 0; i < packages.length; i += 1) {
      if (currWeight + packages[i] <= weightLimit) {
        res.push(packages[i]);
        currWeight += packages[i];
      } else {
        break;
      }
    }
    return res;
  };
  
  console.log(maxPackagesUnderWeightLimit([2,2,2,2,3,4,5], 10));
  /*
  Time complexity is O(nlogn)
  Space complexity is O(n)
  */