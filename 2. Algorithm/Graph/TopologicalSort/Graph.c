#include "Graph.h"

Graph* CreateGraph() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->Vertices = NULL;
	graph->VertexCount = 0;

	return graph;
}

void DestroyGraph(Graph* G) {
	while (G->Vertices != NULL) {
		Vertex* Vertices = G->Vertices->Next;
		DestroyVertex(G->Vertices);
		G->Vertices = Vertices;
	}

	free(G);
}

Vertex* CreateVertex(ElementType Data) {
	Vertex* V = (Vertex*)malloc(sizeof(Vertex));

	V->Data = Data;
	V->Next = NULL;
	V->AdjacencyList = NULL;
	V->Visited = NotVisited;
	V->Index = -1;

	return V;
}

void DestroyVertex(Vertex* V) {
	while (V->AdjacencyList != NULL) {
		Edge* Edge = V->AdjacencyList->Next;
		DestroyEdge(V->AdjacencyList);
		V->AdjacencyList = Edge;
	}

	free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight) {
	Edge* E = (Edge*)malloc(sizeof(Edge));
	E->From = From;
	E->Target = Target;
	E->Weight = Weight;
	E->Next = NULL;

	return E;
}

void DestroyEdge(Edge* E) {
	free(E);
}

void AddVertex(Graph* G, Vertex* V) {
	Vertex* VertexList = G->Vertices;

	//정점리스트가 비어있으면 그래프의 첫 정점으로 정점(V) 세팅
	if (VertexList == NULL) {
		G->Vertices = V;
	}
	else {
		while (VertexList->Next != NULL) {
			VertextList = VertexList->Next;
		}

		VertexList->Next = V;

		V->Index = G->VertexCount++;
	}
}

void AddEdge(Vertex* V, Edge* E) {
	//인접리스트(간선)이 없으면 바로 정점의 인접리스트 첫번째로 간선 붙여주기
	if (V->AdjacencyList == NULL) {
		V->AdjacencyList = E;
	}
	else {
		Edge* AdjacencyList = V->AdjacencyList;
		while (AdjacencyList->Next != NULL) {
			AdjacencyList = AdjacencyList->Next;
		}

		AdjacencyList->Next = E;
	}
}

void PrintGraph(Graph* G) {
	Vertex* V = NULL;
	Edge* E = NULL;

	if ((V = G->Vertices) == NULL) {
		return;
	}

	while (V != NULL) {
		printf("%c : ", V->Data);

		if ((E = V->AdjacencyList) == NULL) {
			V = V->Next;
			printf("\n");
			continue;
		}

		while (E != NULL) {
			printf("%c[%d] ", E->Target->Data, E->Weight);
			E = E->Next;
		}

		printf("\n");

		V = V->Next;
	}

	printf("\n");
}