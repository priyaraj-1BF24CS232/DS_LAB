#include <stdio.h>

#define MAX 10

int n;
int adj[MAX][MAX];
int visited[MAX];

/* ---------- QUEUE FOR BFS ---------- */
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v)
{
    queue[++rear] = v;
}

int dequeue()
{
    return queue[++front];
}

/* ---------- BFS FUNCTION ---------- */
void BFS(int start)
{
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = -1;

    visited[start] = 1;
    enqueue(start);

    printf("BFS Traversal: ");

    while (front != rear)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

/* ---------- DFS FUNCTION ---------- */
void DFS(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

/* ---------- CHECK CONNECTED GRAPH ---------- */
void checkConnected()
{
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    DFS(0);

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("Graph is NOT Connected\n");
            return;
        }
    }

    printf("Graph is Connected\n");
}

/* ---------- MAIN FUNCTION WITH SWITCH CASE ---------- */
int main()
{
    int i, j, choice, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. BFS Traversal\n");
        printf("2. Check Connected Graph (DFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &start);
                BFS(start);
                break;

            case 2:
                checkConnected();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}

