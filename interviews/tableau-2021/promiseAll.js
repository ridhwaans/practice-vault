const promiseAll = (arguments) => {
    if (!arguments || arguments.length === 0) {
      return Promise.resolve(null);
    }
    var values = [];
    function resolveHandler(val, resolve) {
        values.push(val);
        if (values.length === arguments.length) {
            resolve(values);
        }
    }
    return new Promise(function(resolve, reject) {
      for (var i = 0; i < total; i++) {
        Promise.resolve(args[i])
          .then(function(value) {
            resolveHandler(value, resolve);
          })
          .catch(function(error) {
            reject(error);
          });
      }
    });
  }