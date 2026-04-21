#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} ArrayList;

void init(ArrayList* list) {
    list->size = 0;
    list->capacity = 2;
    list->data = (int*)malloc(list->capacity * sizeof(int));
    if (list->data == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
}

int is_full(ArrayList* list) {
    return list->size == list->capacity;
}

void insert(ArrayList* list, int pos, int item) {
    if (item <= 0) {
        printf(" 양의 정수만 입력가능.\n");
        return;
    }
    if (pos < 0 || pos > list->size) {
        printf(" 잘못된 위치 선정 (가능한 위치: 0 ~ %d)\n", list->size);
        return;
    }

    if (is_full(list)) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
        if (list->data == NULL) {
            printf("메모리 재할당 실패\n");
            exit(1);
        }
        printf("용량을 %d으로 늘림\n", list->capacity);
    }


    for (int i = list->size; i > pos; i--) {
        list->data[i] = list->data[i - 1];
    }

    list->data[pos] = item;
    list->size++;
    printf("%d 위치에 %d 추가\n", pos, item);
}

void delete_item(ArrayList* list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("삭제할 위치 선정 실패\n");
        return;
    }
    int deleted_item = list->data[pos];

    for (int i = pos; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    printf(" %d 위치의 값 %d 삭제 \n", pos, deleted_item);
}


void replace(ArrayList* list, int pos, int item) {
    if (item <= 0) {
        printf("양의 정수만 입력 가능\n");
        return;
    }
    if (pos < 0 || pos >= list->size) {
        printf(" 변경할 위치 선정 실패\n");
        return;
    }
    int old_item = list->data[pos];
    list->data[pos] = item;
    printf("%d 위치의 값을 %d에서 %d로 변경\n", pos, old_item, item);
}


void print_list(ArrayList* list) {
    printf("\n-- 양의 정수 리스트 --\n");
    if (list->size == 0) {
        printf("리스트가 비었음\n");
    }
    else {
        for (int i = 0; i < list->size; i++) {
            printf("[%d]: %d   ", i, list->data[i]);
        }
        printf("\n");
    }
    printf("(size: %d / capacity: %d)\n---------------\n", list->size, list->capacity);
}


void clear(ArrayList* list) {
    list->size = 0; 
    printf(" 리스트 값 삭제 완료\n");
}

void free_list(ArrayList* list) {
    free(list->data);
}

int main() {
    ArrayList list;
    init(&list);
    int choice, pos, val;

    while (1) {
        printf("\n1. 추가 2. 삭제  3. 변경 4. 출력 5. 초기화  0. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 위치와 양의 정수 입력: ");
            scanf("%d %d", &pos, &val);
            insert(&list, pos, val);
            break;
        case 2:
            printf("삭제할 위치: ");
            scanf("%d", &pos);
            delete_item(&list, pos);
            break;
        case 3:
            printf("변경할 위치와 새로운 양의 정수: ");
            scanf("%d %d", &pos, &val);
            replace(&list, pos, val);
            break;
        case 4:
            print_list(&list);
            break;
        case 5:
            clear(&list);
            break;
        case 0:
            free_list(&list);
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("오류 발생\n");
        }
    }
    return 0;
}
