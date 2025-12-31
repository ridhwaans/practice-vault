# Stripe practice exercises

# 1. Payment Ledger Reconciliation

## Problem Description

You receive raw ledger events, one per line, each containing a transaction id, amount, and type (`credit` or `debit`). Some lines may be malformed.

Example input:

t1 100 credit
t2 50 debit
t1 25 debit
t3 200 credit
bad_row_here
t4 90 credit
t2 -10 debit

**Tasks**

1. Parse each row into a structured object `{ id, amount, type }`.
2. Ignore malformed rows.
3. Compute each transaction’s net amount.
4. Return a map `{ id → netAmount }` sorted by descending absolute value.
5. Add tests for:
   - empty input
   - invalid rows
   - duplicate transaction IDs
   - extremely large integers


# 2. Rate-Limiter Simulation

## Problem Description

You are given a list of integer timestamps representing API calls from a single user:

Example input:

1 1 2 2 2 3 10 11 11 11 11

Limit rule:
- At most 3 requests per sliding window of 5 seconds.

**Tasks**

1. Implement `isAllowed(timestamp)` that returns `true` or `false`.
2. Process the full array and output which timestamps were permitted.
3. Optimize for O(n) time and O(k) memory.
4. Print a debug log explaining why a request is rejected.
5. Add randomized tests up to 100,000 timestamps.

# 3. Payment Description Normalizer

## Problem Description

You receive payment descriptions from external systems. Some examples:

GOOGLE*SERVICES-1234
Apple.com/Billing
UBER trip 5566

**Tasks**

1. Normalize each description:
   - Collapse repeated whitespace to a single space.
   - Remove non-alphanumeric characters except spaces.
   - Convert to lowercase.
   - Trim leading/trailing spaces.
2. Group normalized descriptions by the first word (merchant root).
3. Produce an object containing:
   - `merchant`: string
   - `count`: number
   - `examples`: array of normalized strings
4. If a description becomes empty after normalization, group under `"unknown"`.

# 4. Idempotency Key Consistency Checker

## Problem Description

You receive API request logs, each with an idempotency key, status code, and amount:

Example input:

abc 200 50
xyz 500 20
abc 200 50
abc 400 50

**Tasks**

1. Identify keys used more than once.
2. Determine whether repeated uses are consistent (same inputs & outputs).
3. Flag inconsistent keys.
4. Detect “phantom retries”: a repeated key without a successful original request.
5. Add debug output reconstructing request flows for each key.

# 5. Mini Query Language Parser

## Problem Description

Input is a small filter language, e.g.:

amount > 100 AND currency = 'USD'
status != 'FAILED' OR country = 'CA'

**Tasks**

1. Tokenize operators, identifiers, numbers, and quoted strings.
2. Build an AST supporting:
   - comparisons
   - logical AND / OR
3. Evaluate the AST against a payment record object.
4. Produce clear error messages for bad syntax:
   - missing quotes
   - unmatched parentheses
   - unknown operators
5. Stress test with hundreds of randomly generated expressions.

# 6. Subscription Period Calculator

## Problem Description

Given:
- Start date string: `"2023-05-17"`
- Billing period: `"monthly"`, `"quarterly"`, or `"yearly"`
- Number of periods purchased

**Tasks**

1. Parse the start date safely.
2. Add the billing period repeatedly, handling:
   - leap years
   - month boundaries
   - last-day-of-month behavior
3. Output all billing boundaries as ISO strings.
4. Handle invalid input formats gracefully.
5. Bench test with millions of iterations.

# 7. Currency Formatter (Large Integers)

## Problem Description

You are given integer amounts in the smallest currency unit (e.g., cents):

Example input:

123
5000000
-3100


**Tasks**

1. Convert integer amounts to formatted currency strings using only integer math.
2. Add thousands separators.
3. Handle negative values correctly.
4. Make decimal places configurable per currency.
5. Fuzz test with large 64-bit integers.

