#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int** data;     
    int size;
    int capacity;
} ArrayList;


typedef struct {
    int col;
    int row;
    ArrayList* list; 
} SparseMatrix;


void init_list(ArrayList* list) {
    list->size = 0;
    list->capacity = 5;
    list->data = (int**)malloc(list->capacity * sizeof(int*));
}


void add_element(ArrayList* list, int r, int c, int v) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int**)realloc(list->data, list->capacity * sizeof(int*));
    }
    list->data[list->size] = (int*)malloc(3 * sizeof(int));
    list->data[list->size][0] = r;
    list->data[list->size][1] = c;
    list->data[list->size][2] = v;
    list->size++;
}

SparseMatrix* create_sparse_matrix(int r, int c) {
    SparseMatrix* sm = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sm->row = r;
    sm->col = c;
    sm->list = (ArrayList*)malloc(sizeof(ArrayList));
    init_list(sm->list);
    return sm;
}

void free_sparse_matrix(SparseMatrix* sm) {
    for (int i = 0; i < sm->list->size; i++) {
        free(sm->list->data[i]);
    }
    free(sm->list->data); 
    free(sm->list);
    free(sm);
}


SparseMatrix* transpose(SparseMatrix* sm, int* move_count) {
    SparseMatrix* tm = create_sparse_matrix(sm->col, sm->row);
    *move_count = 0;

    for (int c = 0; c < sm->col; c++) {
        for (int i = 0; i < sm->list->size; i++) {
            if (sm->list->data[i][1] == c) {
                add_element(tm->list, sm->list->data[i][1], sm->list->data[i][0], sm->list->data[i][2]);
                (*move_count)++; 
        }
    }
    return tm;
}

void print_matrix_list(SparseMatrix* sm, const char* name) {
    printf("\n=== %s ===\n", name);
    printf(" 행(Row)\t열(Col)\t값(Value)\n");
    printf("---------------------------------\n");
    for (int i = 0; i < sm->list->size; i++) {
        printf(" %d\t\t%d\t\t%d\n", sm->list->data[i][0], sm->list->data[i][1], sm->list->data[i][2]);
    }
}

int main() {
    srand((unsigned int)time(NULL));
    SparseMatrix* sm = create_sparse_matrix(10, 10);
    int count = 0;

    while (count < 20) {
        int r = rand() % 10;
        int c = rand() % 10;
        int v = (rand() % 9) + 1; 
        int is_duplicate = 0;
        for (int i = 0; i < sm->list->size; i++) {
            if (sm->list->data[i][0] == r && sm->list->data[i][1] == c) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            add_element(sm->list, r, c, v);
            count++;
        }
    }

    print_matrix_list(sm, "원본 희소행렬 (10x10)");

    int move_count = 0;
    SparseMatrix* tm = transpose(sm, &move_count);

    print_matrix_list(tm, "전치된 희소행렬");
    printf("\n>> 전치 연산 수행 중 총 데이터 이동 횟수: %d회\n", move_count);

    free_sparse_matrix(sm);
    free_sparse_matrix(tm);

    return 0;
}
