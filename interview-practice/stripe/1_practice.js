const input = `t1 100 credit
t2 50 debit
t1 25 debit
t3 200 credit
bad_row_here
t4 90 credit
t2 -10 debit`.trim().split("\n");

const re = /t(\d{1}) (-?\d+) (debit|credit)/;

const isValid = (line) => re.test(line);

const getTransaction = (line) => {
  const [id, amount, type] = line.split(" ");
  return { id, amount: parseInt(amount), type };
};

const calculateNetAmounts = (input) => {
  const MAX = Number.MAX_SAFE_INTEGER;
  const MIN = Number.MIN_SAFE_INTEGER;
  const netAmounts = new Map();

  const events = input.filter(isValid).map(getTransaction);
  events.forEach((e) => {
    const current = netAmounts.get(e.id) ?? 0;
    const newAmount =
      e.type === "credit" ? current + e.amount : current - e.amount;

    if (newAmount > MAX || newAmount < MIN) {
      throw new Error(`Net amount for ${e.id} exceeds safe integer limits`);
    }

    netAmounts.set(e.id, newAmount);
  });

  return new Map(
    [...netAmounts.entries()].sort(([, a], [, b]) => Math.abs(b) - Math.abs(a))
  );
};

console.log(input);
console.log(input.join("\n"));
console.log(calculateNetAmounts(input));


import assert from "assert";

try {
  // 1. Normal input
  assert.deepStrictEqual(
    calculateNetAmounts(input),
    new Map([
      ["t3", 200],
      ["t4", 90],
      ["t1", 75],
      ["t2", -40],
    ]),
    "Net amounts should be calculated correctly"
  );

  // 2. Empty input
  assert.deepStrictEqual(
    calculateNetAmounts([]),
    new Map(),
    "Empty input should return an empty Map"
  );

  // 3. Validation
  assert.strictEqual(isValid("t3 200 credit"), true, "Valid input should return true");
  assert.strictEqual(isValid("foo bar 123"), false, "Malformed input should return false");

  // 4. Transaction parsing
  assert.deepStrictEqual(
    getTransaction("t3 200 credit"),
    { id: "t3", amount: 200, type: "credit" },
    "Valid transaction should be parsed"
  );

  console.log("All tests passed!");
} catch (err) {
  console.error("Test failed:", err);
}

