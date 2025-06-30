#include <stdio.h>

//B1: Xay dung cau truc sinh vien
struct Student {
    int id;
    char name[20];
    int age;
};

//[
//  { id: 1, name: "Alice", age: 20 },
//  { id: 2, name: "Bob", age: 21 },
//  { id: 3, name: "Charlie", age: 22 },
//  { id: 4, name: "David", age: 20 },
//  { id: 5, name: "Eva", age: 23 }
//];

int linearSearch(struct Student students[], int value, int size){
    for(int i =0; i<size; i++){
        if(students[i].id == value){
            return i;
        }
    }
    return -1;
}

int main(void) {
    int numbers[5] = {1,2,4,5};
    //B2: Khoi tao mang sinh vien tu cau truc
    struct Student students[5] = {
        {1, "Alice", 20},
        {2, "Bob", 21},
        {3, "Charlie", 22},
        {4, "David", 23},
        {5, "Eva", 24}
    };
    for(int i =0; i<5; i++){
        printf("id: %d ", students[i].id);
        printf("name: %s ", students[i].name);
        printf("age: %d ", students[i].age);
        printf("\n");
    }
    //B3: Xay dung ham tim kiem

    //B4: Goi ham va in ket qua
    return 0;
}