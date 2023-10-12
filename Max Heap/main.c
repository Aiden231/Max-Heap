#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENT 200

typedef struct element {
	int key;
}element;

typedef struct heapType {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

int is_empty(HeapType* h) {
	return (h->heap_size == 0);
}

int is_full(HeapType* h) {
	return(h->heap_size == (MAX_ELEMENT - 1));
}

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
	int visit_count;

	HeapType* heap = create();
	init(heap);

	element e1 = { 90 }, e2 = { 89 }, e3 = { 70 }, e4 = { 36 };
	element e5 = { 75 }, e6 = { 63 }, e7 = { 65 }, e8 = { 21 };
	element e9 = { 18 }, e10 = { 15 };

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

	char input; // �޴� ����
	element insert; // �߰� �� ����
	element delete; // ���� �� ����
	int k; // ������ �Լ��� ���Ǵ� �α� ���� �κ� ������ �� ���

	do {
		visit_count = 0; // ��� ī����

		// �޴�
		printf("-----------------------------\n");
		printf("|  i : ��� �߰�            |\n");
		printf("|  d : ��� ����            |\n");
		printf("|  p : ������ ���          |\n");
		printf("|  c : ����                 |\n");
		printf("-----------------------------\n");
		printf("\n");

		printf("�޴� �Է� : ");
		scanf_s("%c", &input);
		while (getchar() != '\n'); // �Է� ���� �����

		switch (input)
		{
		case 'i': // �߰�
			printf("�߰��� �� �Է� : ");
			scanf_s("%d", &insert);
			while (getchar() != '\n'); // �Է� ���� �����

			insert_max_heap(heap, insert,&visit_count);

			for (int i = 1; i <= heap->heap_size; i++) {
				printf("%d ", heap->heap[i]);
			}
			printf("\n�湮�� ��� �� : %d\n\n",visit_count);

			break;
		case 'd': // ����
			delete = delete_max_heap(heap, &visit_count);
			for (int i = 1; i <= heap->heap_size; i++) {
				printf("%d ", heap->heap[i]);
			}
			printf("\n�湮�� ��� �� : %d\n\n", visit_count);
			break;
		case 'p': // ������ ���
			k = (int)log2(heap->heap_size);

			// ���� �ؾߵ�
			for (int i = 1; i <= k + 1; i++) {
				printf("[%d] : ", i);
				for (int j = 1; j <= pow(2,i)-1; j++) {
					printf("%d ", heap->heap[i]);
				}
				printf("\n");
			}
			printf("\n");
			break;
		case 'c': //����
			printf("�����մϴ�.\n\n");
			break;
		default: // ���Է�
			printf("�߸��� �޴� �����Դϴ�. �ٽ� ������ �ּ���.\n\n");
			break;
		}
	} while (input != 'c');

	free(heap);
	return 0;
}