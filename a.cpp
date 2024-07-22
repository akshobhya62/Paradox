#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


class node{
    public:
    int val;
    node* next;
    node(){
        next = nullptr;
        val = 0;
    }
};

int main() {
    const int SIZE = 10000;          
    int random_numbers[SIZE];              

    random_device rd;            
    mt19937 generator(rd());     
    uniform_int_distribution<> distribution(1, 1000); 

    for (int i = 0; i < SIZE; ++i) {
        random_numbers[i] = distribution(generator);
    }

    // for(int i = 0; i < SIZE; i++)cout<<random_numbers[i]<<" ";cout<<endl;

    int test_array[SIZE];   
    node* test_list[SIZE];
    for(int i = 0; i < SIZE; i++)test_list[i] = new node();

    auto start = high_resolution_clock::now();

    for(int i = 0; i < SIZE; i++){
        if(i == 0)test_array[i] = random_numbers[i];
        else{
            int j = 0; 
            for(;j < i; j++){
                if(test_array[j] > random_numbers[i])break;
            }
            if(i == j)test_array[i] = random_numbers[i];
            else{
                for(int k = i - 1; k >= j; k--){
                    test_array[k + 1] = test_array[k];
                }
                test_array[j] = random_numbers[i];
            }
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time taken for array execution: " << duration.count() << " microseconds" << endl;
    // for(int i= 0; i < SIZE; i++)cout<<test_array[i]<<" ";cout<<endl;


    node* head = nullptr;
    node* cur = nullptr;

    auto start2 = high_resolution_clock::now();
    for(int i = 0; i < SIZE; i++){
        if(i == 0){
            head = test_list[i];
            head->val = random_numbers[i];
            cur = head;
        }
        else{
            node* prev = nullptr;
            cur = head;

            if(head->val > random_numbers[i]){
                head = test_list[i];
                head->val = random_numbers[i];
                head->next = cur;
                continue;
            }

            while(cur && cur->val <= random_numbers[i]){
                prev = cur;
                cur = cur->next;
            }
            if(cur == nullptr){
                prev->next = test_list[i];
                prev->next->val = random_numbers[i];
            }
            else{
                prev->next = test_list[i];
                prev->next->val = random_numbers[i];
                prev->next->next = cur;
            }
        }
    }

    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);

    cout << "Time taken for linked list execution: " << duration2.count() << " microseconds" << endl;

    // cur = head;
    // while(cur){
    //     cout<<cur->val<<" ";
    //     cur = cur->next;
    // }
    // cout<<endl;
    return 0;
}