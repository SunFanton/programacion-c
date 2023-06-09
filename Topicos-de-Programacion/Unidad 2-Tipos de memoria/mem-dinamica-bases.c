#include <stdio.h>
#include <stdlib.h>
///MALLOC
//int main()
//{
//    /// This pointer will hold the
//    /// base address of the block created
//    int* ptr;
//    int n, i;
//
//    /// Get the number of elements for the array
//    printf("ingrese number of elements:");
//    scanf("%d",&n);
//    printf("Numero de elementos ingresados: %d\n", n);
//
//    /// Dynamically allocate memory using malloc()
//    ptr = (int*)malloc(n * sizeof(int));  ///dibamico
//    int ptr[5];//estatico
//
//    /// Check if the memory has been successfully
//    /// allocated by malloc or not
//    if (ptr == NULL) {
//        printf("Memory no asignada.\n");
//        exit(0);
//    }
//
//        /// Memory has been successfully allocated
//        printf("Memory asignada satisfactoriamente con malloc.\n");
//
//        /// Get the elements of the array
//        for (i = 0; i < n; ++i) {
//            ptr[i] = i + 1;///que hago???
//
//            *ptr=i +1;
//
//        }
//
//        /// Print the elements of the array
//        printf("Los elements del array son: ");
//        for (i = 0; i < n; ++i) {
//            printf("%d, ", ptr[i]);
//        }
//
//        free(ptr);///libera la memoria
//
//    return 0;
//}
//
/////CALLOC
//
//int main()
//{
//
//    // This pointer will hold the
//    // base address of the block created
//    int* ptr;
//    int n, i;
//
//    // Get the number of elements for the array
//    n = 5;
//    printf("Enter number of elements: %d\n", n);
//
//    // Dynamically allocate memory using calloc()
//    ptr = (int*)calloc(n, sizeof(int));
//
//    // Check if the memory has been successfully
//    // allocated by calloc or not
//    if (ptr == NULL) {
//        printf("Memory not allocated.\n");
//        exit(0);
//    }
//    else {
//
//        // Memory has been successfully allocated
//        printf("Memory successfully allocated using calloc.\n");
//
//        // Get the elements of the array
//        for (i = 0; i < n; ++i) {
//            ptr[i] = i + 1;
//        }
//
//        // Print the elements of the array
//        printf("The elements of the array are: ");
//        for (i = 0; i < n; ++i) {
//            printf("%d, ", ptr[i]);
//        }
//    }
//
//    return 0;
//}
/////REALLOC()
//
int main()
{
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        /// Get the new size for the array
        n = 10;
        printf("\n\nEnter the new size of the array: %d\n", n);
        /// Dynamically re-allocate memory using realloc()
        ptr = realloc(ptr, n * sizeof(int));
        /// Memory has been successfully allocated
        printf("Memory successfully re-allocated using realloc.\n");
        /// Get the new elements of the array
        for (i = 5; i < n; ++i) {
            ptr[i] = i + 1;
        }
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
        free(ptr);
    }
    return 0;
}