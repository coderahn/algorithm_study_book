#include "TopologicalSort.h"

void TopologicalSort(Vertex* V, Node** List) {
	while (V != NULL && V->Visited == NotVisited) {
		TS_DFS(V, List);

		V = V->Next;
	}
}

void TS_DFS(Vertex* V, Node** List) {
	Node* NewHead = NULL;
	Edge* E = NULL;

	V->Visited = Visitied;

	//정점의 간선(첫번째)를 꺼냄
	E = V->AdjacencyList;

	while (E != NULL) {
		//간선에 연결된 정점을 아직 방문 안했으면 그 정점으로 재귀호출
		if (E->Target != NULL && E->Target->Visited == NotVisited) {
			TS_DFS(E->Target, List);
		}
		
		E = E->Next;
	}

	printf("%c\n", V->Data);

	//간선(진출간선?)이 더 없다면 리스트의 헤드로 넣음
	NewHead = SLL_CreateNode(V);
	SLL_InsertNewHead(List, &NewHead);

}