The code here compares the performance of two scenarios where a stream of random numbers is coming and you are given an array "test_array" of size SIZE and you are also given a "test_list" array of size SIZE
that contains pre memory allocated nodes using which you can create a linked list and you don't have to dynamically allocate memory for the nodes of the linked list. Your task is to insert the random numbers to the
array and the linked list using insertion sort. So basically, when a number comes you iterate over array or linkedlist and get to the point where the value of the current element is greater than the current random
number and then you insert it. Incase of linked list you just insert there and it's over, however in case of array you will have first move the elements that are present from this element to the right side of this 
element(which is greater than the current random number). After this you can replace the value of the current element with the current random number. This is simply how you do insertion sort. 

Now, theoretically above method should take O(SIZE + 1) time in linked list O(SIZE) for iterating over the list and then O(1) for insertion and O(SIZE + SIZE + 1) incase of array, O(SIZE) for iterating, O(SIZE) for 
shifing values by 1 that are right of the current element and then O(1) for replacing the current value with the current random number. However, practically it doesn't happen. When you simply run the code you will
see that after SIZE = 5000 the array method takes less time than linked list method. 
However, when you run the code with compiler optimisation you will see the real magic. For that you will have to run this command ==> g++ -O3 -o myprogram a.cpp; ./myprogram
