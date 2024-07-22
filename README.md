## Performance Comparison of Array vs Linked List Insertion Sort

This project compares the performance of inserting a stream of random numbers into two different data structures: an array and a linked list. Here’s a breakdown of the scenario and methodology:

### Scenario

You are provided with:
- An **array** named `test_array` of size `SIZE`.
- A **linked list** represented by a pre-allocated array of nodes, named `test_list`, of size `SIZE`.

Your task is to insert incoming random numbers into both the array and the linked list using the insertion sort algorithm.

### Insertion Sort Methodology

1. **For the Array:**
   - Iterate through the array to find the appropriate position where the current random number should be inserted.
   - **Shift Elements:** Move all elements to the right of the insertion point one position to the right to make space.
   - **Insert:** Place the current random number in the correct position.

2. **For the Linked List:**
   - Traverse the linked list to find the correct insertion point for the current random number.
   - **Insert:** Directly insert the number at the identified position.

### Theoretical Time Complexity

- **Linked List:** 
  - **Iterate:** \( O(\text{SIZE}) \)
  - **Insert:** \( O(1) \)
  - **Total:** \( O(\text{SIZE}) \)

- **Array:**
  - **Iterate:** \( O(\text{SIZE}) \)
  - **Shift Elements:** \( O(\text{SIZE}) \)
  - **Insert:** \( O(1) \)
  - **Total:** \( O(\text{SIZE}^2) \)

### Observations

Theoretically, the array method should take more time compared to the linked list due to the shifting of elements. However, practical results may vary. For sizes larger than 5000, you may observe that the array method performs faster than the linked list method.

### Compiler Optimization

For the best performance results, compile the code with optimization flags. Use the following command:

```bash
g++ -O3 -o myprogram a.cpp
./myprogram


This will enable optimization and allow you to see the real-world performance differences between the two methods.


| SIZE of the stream of random numbers | Time taken for Array in MicroSeconds | Time Taken for Linked List in MicroSeconds |
|-------------------------------------|--------------------------------------|--------------------------------------------|
| 10                                  | 0                                    | 0                                          |
| 50                                  | 0                                    | 1                                          |
| 100                                 | 0                                    | 3                                          |
| 200                                 | 0                                    | 11                                         |
| 500                                 | 0                                    | 65                                         |
| 1000                                | 0                                    | 248                                        |
| 2000                                | 0                                    | 2157                                       |
| 5000                                | 0                                    | 29394                                      |
| 10000                               | 0                                    | 127103                                     |
| 50000                               | 0                                    | 6318925                                    |
| 100000                              | 0                                    | 28782206                                   |

