#include <bits/stdc++.h>

using namespace std;
#define MAX_SIZE 100000
#define true 1
#define false 0

// Data structure to store heap array as well as current count.
typedef struct heap_t {
    int count;
    int a[MAX_SIZE];
}heap;

void add_integer(heap *min_heap, heap * max_heap, int value);
void print_median(heap min_heap, heap max_heap);

/* To find children of a given element */
int left_child(int i){
        return (i*2);
}
int right_child(int i){
        return (2*i)+ 1;
}

int swap(int a[], int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
}
/* This function heapifies max heap after deleting maximum
element from it */
void heapify(int a[], int i, int len){
    int largest = i;
    int left, right;

    left = left_child(i);
    right = right_child(i);
    if(left <= len && a[i]>a[left]){
        largest = left;
    }
    if(right <= len && a[largest] > a[right]){
        largest = right;
    }
    if(largest != i){
        swap(a, i, largest);
        heapify(a, largest, len);
    }
}
/* This function heapifies min heap after deleting maximum
element from it */
void min_heapify(int a[], int i, int len){
    int smallest = i;
    int left, right;

    left = left_child(i);
    right = right_child(i);
    if(left <= len && a[i]>a[left]){
        smallest = left;
    }
    if(right <= len && a[smallest] > a[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(a, i, smallest);
        min_heapify(a, smallest, len);
    }
}

/* This function heapifies min heap after inserting an
element from it */
void shift_up_min(int heap[], int i){

    int parent  =  i/2;
    if(i > 1){
        if(heap[parent] > heap[i]){
            //printf("\n Swapping %d and %d ", heap[parent], heap[i]);
            swap(heap, parent, i);
            shift_up_min(heap, parent);
        }
    }
}
/* This function inserts an element in min heap  */

void insert_min(heap *min_heap, int val){
    if((min_heap->count) >= MAX_SIZE){
        //printf("\n Underlying data structure gone full\n");
        return;
    }
    else{
        min_heap->count++;
        min_heap->a[min_heap->count] = val;
        shift_up_min(min_heap->a, min_heap->count);
    }
    return;
}

/* This function heapifies max heap after inserting an
element from it */

void shift_up_max(int heap[], int i){

    int parent  =  i/2;
    if(i > 1){
        if(heap[parent] < heap[i]){
            swap(heap, parent, i);
            shift_up_max(heap, parent);
        }
    }
}

/* This function inserts an element in min heap  */
void insert_max(heap *max_heap, int val){
    if((max_heap->count) >= MAX_SIZE){
        //printf("\n Underlying data structure gone full\n");
        return;
    }
    else{
        max_heap->count++;
        max_heap->a[max_heap->count] = val;
        shift_up_max(max_heap->a, max_heap->count);
    }
    return;
}

/* This function deletes an element in max heap  */
void delete_max(heap *heap){
    if(heap->count == 0 ){
        //printf("\n Cannot be deleted");
        return;
    }
    heap->a[1] = heap->a[heap->count--];
    heapify(heap->a, 1,heap->count);
    return;
}

/* This function deletes an element in min heap  */
void delete_min(heap *heap){
    if(heap->count == 0 ){
        //printf("\n Cannot be deleted");
        return;
    }
    heap->a[1] = heap->a[heap->count--];
    //printf("\n Minimum heap size : %d", heap->count);
    min_heapify(heap->a,1, heap->count);

    return;
}

void add_integer(heap *min_heap, heap * max_heap, int value){
    
    // Insert in max heap 
    insert_max(max_heap,value);
    if((max_heap->count - min_heap->count) >1 ||
        (min_heap->count != 0 && max_heap->a[1]>min_heap->a[1])){
        int top = max_heap->a[1];
        delete_max(max_heap);
        insert_min(min_heap,top);
    }
    /* If difference between two heap size is more than 1 */
    if((min_heap->count !=0 && (min_heap->count - max_heap->count) >1)){
        int top = min_heap->a[1];
        delete_min(min_heap);
        insert_max(max_heap,top);
    }
}

void print_median(heap min_heap, heap max_heap){

    if(max_heap.count == min_heap.count){
        printf("%.2lf ",(double)(max_heap.a[1] + min_heap.a[1])/2 );
    }
    else{
        if(max_heap.count > min_heap.count){
            printf("%.2lf ",(double)max_heap.a[1]);
        }
        else{
            printf("%.2lf ",(double)min_heap.a[1]);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif

    heap min_heap, max_heap;
    min_heap.count =0;
    max_heap.count =0;
    int n,i;
    cin>>n;
    int num;
    for(i=0;i<n;i++)
    {
        cin>>num;
        add_integer(&min_heap,&max_heap,num);
        print_median(min_heap, max_heap);
    }
    cout<<"\n";
    return 0;
}