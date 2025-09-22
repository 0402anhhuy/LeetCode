# Approach: Customized Sorting

## Intuition

- To sort the numbers, we first arrange them based on their frequency in ascending order. Numbers that appear less frequently will come before those with higher frequencies. We use a hashmap, freq, to count the occurrences of each number in the array.

- If two numbers have the same frequency, we then sort them by their values in descending order. This introduces a dual sorting criterion: first by frequency and then by value.

- To accomplish this, we will apply a custom sorting function using lambda expressions. These anonymous functions let us define sorting logic inline. Specifically, our lambda function ensures that numbers are compared primarily by their frequency, and secondarily by their value if frequencies match. This approach guarantees that the final sorted list adheres to both sorting criteria.

## C++ Lambda Function for Sorting by Increasing Frequency

```cpp
sort(nums.begin(), nums.end(), [&](int a, int b) {
if (freq[a] == freq[b]) {
return a > b;
}
return freq[a] < freq[b];
});
```

## The lambda [&](int a, int b) { ... } serves as the comparator for the sort function:

- & captures all external variables (freq in this case) by reference, allowing the lambda to access and use freq

- (int a, int b) defines parameters for elements to compare

## Comparison logic:

- If frequencies are equal (freq[a] == freq[b]), sort by value in descending order (a > b)

- Otherwise, sort by frequency in ascending order (freq[a] < freq[b])
