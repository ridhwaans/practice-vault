var missingPositive = require('./4 MissingPositive.js')
missingPositive = new MissingPositive();

describe('MissingPositive', function() {
  it('empty constructor', function() {
    expect(missingPositive.first()).toEqual(false);
  });
  it('undefined', function() {
    expect(missingPositive.first(undefined)).toEqual(false);
  });
  it('null', function() {
    expect(missingPositive.first(null)).toEqual(false);
  });
  it('null element in list', function() {
    expect(missingPositive.first([null])).toEqual(false);
  });
  it('null element in list', function() {
    expect(missingPositive.first([null, 2, 3, 4])).toEqual(false);
  });
  it('string in list', function() {
    expect(missingPositive.first(['1', 2, 3, 4])).toEqual(false);
  });
  it('decimal in list', function() {
    expect(missingPositive.first([1.5, 2.5])).toEqual(false);
  });
  it('empty list', function() {
    expect(missingPositive.first([])).toEqual(false);
  });
  it('valid list', function() {
    expect(missingPositive.first([1,2,3])).toEqual(4);
  });
  it('valid list', function() {
    expect(missingPositive.first([4,5,-1,1])).toEqual(2);
  });
});