// /advent of code / leetcode/
//
//  c101.c
//  testc
//
//  Created by Benjamin Alexander on 12/10/2023.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void if_statement(void) {
    bool condition = true;
    bool another_condition = true;
    if (condition) {
        // do this if true
    } 
    else if (another_condition) {
        // do something if this is true
    }
    else {
        // if none of the conditions are true do this
    }
}

int basic_recursion(int arg) {
    // this line just so the program compiles
    bool base_condition = false;
    // okay actual code again
    
    if (base_condition == true) {
        // return values here
        return 0;
    }
    
    // this line just so the program compiles
    int stuff = 5;
    // okay actual code again
    
    int y = basic_recursion(stuff);
    // now do what you want with y
    return y;
}

void for_loop(int n) {
    // this should be done in your sleep by the end of the year
    
    // for (iterator val; exit condition; increment) {
    //     do something
    // }
    for (int i = 0; i < n; i++) {
        printf("%i", n);
    }
}

// this useful for a bubble sort
void nested_for_loop(int n, int m) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            int val = m * i + j;
            printf("%i", val);
        }

    }
}

void optimised_nested_for_loop(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("*");
        }
        printf("\n");

    }
}
// helper function
void run_game(void) {}
// use this if the loop needs to be completed 0 or more times
void while_loop(void) {
    bool condition;
    while (condition) {
        // do stuff
        bool something;
        if (something) {
            break;
        }
        
    }

    bool alive;
    while (alive) {
        run_game();
    }
}


// helper function
bool reconnect(void) { return true; }
// use this if the loop needs to be completed at least once e.
void do_while(void) {
    bool condition;
    do {
        // do something
    } while (condition);

    // for example
    bool connected = false;
    do {
        connected = reconnect();
    } while (connected == false);
}

// heres how you make your own struct
// these are like classes, which cannot have any methods (like @dataclass in python)
struct MyPoint {
    int x;
    int y;
};


void use_struct(void) {
    struct MyPoint point;
    point.x = 5;
    point.y = 6;
}

struct MyPoint make_point(int x, int y) {
    struct MyPoint point;
    point.x = x;
    point.y = y;
    return point;
}

// you can also create your own types
typedef struct _point {
    int x;
    int y;
} point;

// pointer fun :D
void pointer_fun(void) {
    // this creates a pointer to the integer variable x
    int* x;
    // this just creates a normal variable integer x
    int y = 6;
    
    //        x        y
    // &:  address->[value]
    //        ^
    //
    // always spits out an address of whatever you give it
    // if y is a pointer then &y is a pointer to a pointer
    x = &y;
    
    
    //                 z
    // *:  address->[value]
    //                 ||
    //                 \/
    //            [other value]
    //                  ^
    //
    // interprets the content of the variable as a pointer and dereferences it
    int z = *x;
    

    // pointer to a struct
    point* p;
    
    // if you want to set values of a struct but you only have a pointer
    // you can use arrows
    p->x = 1;
    p->y = 2;
    
    // or
    point actualPoint = *p;
    
    actualPoint.x = 1;
    actualPoint.y = 2;
    
}


// Now lets have some fun with arrays
void static_array_shenanigans(void) {
    
    // this defines an array in stack memory
    int length = 5;
    int int_arr[length];
    for (int i = 0; i < length; i++) {
        int_arr[i] = i;
    }

    int_arr[1];
    
    // they can also be defined like this
    int some_arr[] = {1,2,3,4,5};

    // somehow this **technically** works, but for the love of god dont.
    3[some_arr] = 10;
    some_arr[3] = 10;

    int arr1[3];
    
    int arr2[4];

    // since due to pointer logic, this takes the address number 5, then increments it by the address of the array
    // instead of taking the address of the array then incrementing 5
}

// Array pointers and mallocs
void pointer_array_shenanigans(int length) {
    if (length < 3) {
        length = 3;
    }
    // to create an array in heap memory, then we malloc
    // make sure to include <stdlib.h>
    // this creates a pointer to the first element of an array
    int* arr = malloc(length * sizeof(int));
    // dereferencing the pointer to get the first element
    int first_index = *arr;
    // increment the array, then dereference to get second element
    int second_index = *(arr++);
    
    // you can also use bracket syntax
    int third_index = arr[3];
    
    while (arr++) {
        int someval = *arr;
    }

    // make sure to free your array when youre done with it
    free(arr);
}

// very very very very very useful for doing matrices without having to double malloc
void array_2d_as_1d(int row_length, int col_length) {
    // here were representing a 2d array as a 1d array, by doing arr[i * row_length + j]
    
    int* arr = (int*)malloc(row_length * col_length * sizeof(int));

    int j = row_length - 1;
    int i = col_length - 1;
    arr[i * row_length + j] = 5;

    // to loop over the entire array
    for (int i = 0; i < (col_length * row_length); i++) {
        arr[i] = 0;
    }
    
    // to loop over a row
    int row_index = 1;
    for (int i = row_index * row_length; i < row_length; i++) {
        arr[i] = i;
    }
    
    // to loop over a column
    int col_index = 2;
    for (int i = col_index; i < col_length; i *= row_length) {
        arr[i] = i;
    }

}

void print_2d_array(int* arr) {
    // you guys can give this a go.
    // if youre back here from the matrix program and trying to get a free copy paste then hahah nice try
}

// helper function to free a 2d array (this isnt tested so may not work)
void free_2d_arr(int** arr, int col_length) {
    for (int i = 0; i < col_length; i++) {
        free(arr[i]);
    }
    free(arr);
}

// now lets have some (fun) with actual 2d arrays
void array_2d_double_malloc(int row_length, int col_length) {
    int** arr = (int**)malloc(row_length * sizeof(int));
    for (int i = 0; i < col_length; i++) {
        arr[i] = (int*)malloc(col_length * sizeof(int));
    }
    
    // not gonna go any further with this cuz just please for the love of god dont do this
    free_2d_arr(arr, col_length);
}



// if you get bored typing struct StructName, you can do this instead
typedef struct _node {
    struct _node* next;
    int value;
} Node; // this is the name which will be used throughout the program

// creating a linked list
typedef struct _linked_list {
    Node* head;
    int length;
} LinkedList;



int main(void) {
    optimised_nested_for_loop(5);
    return 0;
}




