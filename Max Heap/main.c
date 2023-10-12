#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENT 200

typedef struct element {
	int key;
}element;
// Heap 구조체
typedef struct heapType {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;
// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화
void init(HeapType* h) {
	h->heap_size = 0;
}
// 비어있는지 확인
int is_empty(HeapType* h) {
	return (h->heap_size == 0);
}
// 포화 확인
int is_full(HeapType* h) {
	return(h->heap_size == (MAX_ELEMENT - 1));
}
// 추가
void insert_max_heap(HeapType* h, element item, int* visit_count) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		(*visit_count)++;
		
		h->heap[i] = h->heap[i / 2];
		i /= 2;
		for (int j = 1; j <= h->heap_size; j++) {
			printf("%d ", h->heap[j]);
		}
		printf("\n");
	}
	h->heap[i] = item;
}
//삭제
element delete_max_heap(HeapType* h, int* visit_count) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size--)];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		(*visit_count)++;

		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;

		child *= 2;

		for (int j = 1; j <= h->heap_size; j++) {
			printf("%d ", h->heap[j]);
		}
		printf("\n");
	}
	h->heap[parent] = temp;
	return item;
}

int main()
{
	int visit_count;  // 방문 카운터
	 
	HeapType* heap = create(); // 히프 생성
	init(heap); // 히프 초기화

	element e1 = { 90 }, e2 = { 89 }, e3 = { 70 }, e4 = { 36 };
	element e5 = { 75 }, e6 = { 63 }, e7 = { 65 }, e8 = { 21 };
	element e9 = { 18 }, e10 = { 15 };
	//초기값 입력
	insert_max_heap(heap, e1, &visit_count);
	insert_max_heap(heap, e2, &visit_count);
	insert_max_heap(heap, e3, &visit_count);
	insert_max_heap(heap, e4, &visit_count);
	insert_max_heap(heap, e5, &visit_count);
	insert_max_heap(heap, e6, &visit_count);
	insert_max_heap(heap, e7, &visit_count);
	insert_max_heap(heap, e8, &visit_count);
	insert_max_heap(heap, e9, &visit_count);
	insert_max_heap(heap, e10, &visit_count);

	char input; // 메뉴 변수
	element insert; // 추가 값 저장
	element delete; // 삭제 값 저장
	int k; // Heap 최고 레벨 저장

	do {
		visit_count = 0; // 노드 카운터

		// 메뉴
		printf("-----------------------------\n");
		printf("|  i : 노드 추가            |\n");
		printf("|  d : 노드 삭제            |\n");
		printf("|  p : 레별별 출력          |\n");
		printf("|  c : 종료                 |\n");
		printf("-----------------------------\n");
		printf("\n");

		printf("메뉴 입력 : ");
		scanf_s("%c", &input);
		while (getchar() != '\n'); // 입력 버퍼 지우기

		switch (input)
		{
		case 'i': // 추가
			printf("추가할 값 입력 : ");
			scanf_s("%d", &insert);
			while (getchar() != '\n'); // 입력 버퍼 지우기

			insert_max_heap(heap, insert,&visit_count);
			// 출력
			for (int i = 1; i <= heap->heap_size; i++) {
				printf("%d ", heap->heap[i]);
			}
			printf("\n방문한 노드 수 : %d\n\n",visit_count);

			break;
		case 'd': // 삭제
			delete = delete_max_heap(heap, &visit_count);
			// 출력
			for (int i = 1; i <= heap->heap_size; i++) {
				printf("%d ", heap->heap[i]);
			}
			printf("\n방문한 노드 수 : %d\n\n", visit_count);
			break;
		case 'p': // 레벨별 출력
			k = (int)log2(heap->heap_size); // max heap 의 최대 레벨 구하기

			for (int i = 1; i <= k + 1; i++) {
				printf("[%d] : ", i);
				for (int j = pow(2,i-1); j <= pow(2,i)-1; j++) {
					printf("%d ", heap->heap[j]);

					// heap size 보다 크면 종료
					if (j > heap->heap_size-1) break;
				}
				printf("\n");
			}
			printf("\n");
			break;
		case 'c': // 종료
			printf("종료합니다.\n\n");
			break;
		default: // 오입력
			printf("잘못된 메뉴 선택입니다. 다시 선택해 주세요.\n\n");
			break;
		}
	} while (input != 'c');  // c 입력 들어올 때까지 반복

	free(heap);
	return 0;
}