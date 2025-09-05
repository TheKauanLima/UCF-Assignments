/* COP 3502C Assignment 2
This program is written by: Kauan Lima*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY NULL
#define MAX_QUEUES 12
#define NAME_SIZE 16

// customer struct to hold customer data
typedef struct customer{
    char* name;
    int numTickets;
    int lineNum;
    int timeEnteringLine;
}Customer;

// node struct to use in linked lists
typedef struct node {
    Customer* customer;
    struct node* next;
}Node;

// queues abstract data type
typedef struct queue{
    Node* front;
    Node* back;
}Queue;

// allocate memory and initialize a customer struct
Customer* createCustomer(int time, int line, char* cName, int tickets)
{
    Customer* c = (Customer*)malloc(sizeof(Customer));

    int length = strlen(cName) + 1;
    c->name = (char*)malloc(length * sizeof(char));
    strcpy(c->name, cName);

    c->timeEnteringLine = time;
    c->lineNum = line;
    c->numTickets = tickets;

    return c;
}

// free customer struct
void freeCustomer(Customer* c)
{
    free(c->name);
    free(c);
}

// allocate memory for a node which will hold a customer
Node* createNode(Customer* c)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->customer = c;
    n->next = NULL;

    return n;
}

// initialize back and front pointers in queue as null
void init(Queue* q)
{
    q->front = NULL;
    q->back = NULL;
}

// check if queue is empty, 0 if not, 1 if so
int Empty(Queue* q)
{
    return q->front == NULL;
}

// add a value into the cue at the back of a linked list
int Enqueue(Queue* q, Customer* c)
{
    Node* temp = createNode(c);

    if(!temp) return 0;

    if(Empty(q))
    {
        q->front = temp;
        q->back = temp;
        return 1;
    }

    q->back->next = temp;
    q->back = temp;
    return 1;
}

// return the next value in the queue and delete it
Customer* Dequeue(Queue* q)
{
    if (Empty(q)) return EMPTY;

    Customer* savedCustomer = q->front->customer;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (Empty(q)) q->back = NULL;

    return savedCustomer;
}

// peek at the next value in the queue
Customer* Peek(Queue* q)
{
    if (q->front) return q->front->customer;
    return EMPTY;
}

// main
int main(void)
{
    // declare all queues
    Queue queues[MAX_QUEUES];

    // input the number of cases for the program to run
    int numCases = 0;
    scanf("%d", &numCases);

    // loop for each case
    for (int i = 0; i < numCases; i++)
    {
        // initialize each queue to null
        for (int i = 0; i < MAX_QUEUES; i++)
            init(&queues[i]);

        // input the number of customers in a case
        int numCustomers = 0;
        scanf("%d", &numCustomers);

        //loop to enqueue each new customer
        for (int j = 0; j < numCustomers; j++)
        {
            int time = 0, lineNum = 0, numTickets = 0;
            char customerName[NAME_SIZE];
            scanf("%d %d %s %d", &time, &lineNum, customerName, &numTickets);

            Customer* customer = createCustomer(time, lineNum, customerName, numTickets);

            Enqueue(&queues[lineNum - 1], customer);
        }

        // tracker variable initialization and structs to dequeue
        int currTime = -1;
        Queue* toDeQ = NULL;
        Customer* dequeued = NULL;

        // loop through each customer
        for (int j = 0; j < numCustomers; j++)
        {
            // keep track of the time and ticket values
            int lowestTime = -1;
            int lowestTickets = -1;

            // loop through each queue
            for (int k = 0; k < MAX_QUEUES; k++)
            {
                // check if a customer exists at the front of a queue
                Customer* peek = Peek(&queues[k]);
                if (!peek) continue;

                // track the queue of the first customer found
                if (lowestTime == -1)
                {
                    lowestTime = peek->timeEnteringLine;
                    lowestTickets = peek->numTickets;
                    toDeQ = &queues[k];
                }
                // check for queue to dequeue by tickets if many customers are in line already
                else if (peek->timeEnteringLine < currTime)
                {
                    if (lowestTickets == -1)
                    {
                        lowestTickets = peek->numTickets;
                        toDeQ = &queues[k];
                    }
                    else if (peek->numTickets < lowestTickets)
                    {
                        lowestTickets = peek->numTickets;
                        toDeQ = &queues[k];
                    }
                }
                // adjust the queue to dequeue to the customer with the lowest time
                else if (peek->timeEnteringLine < lowestTime)
                {
                    lowestTime = peek->timeEnteringLine;
                    lowestTickets = peek->numTickets;
                    toDeQ = &queues[k];
                }
            }

            // check if a customer exists in line after one is checked out
            if (lowestTime > currTime)
            {
                dequeued = Dequeue(toDeQ);
                currTime = (dequeued->numTickets * 10) + 20 + dequeued->timeEnteringLine;
            }
            else
            {
                dequeued = Dequeue(toDeQ);
                currTime += (dequeued->numTickets * 10) + 20;
            }

            // print and free values.
            printf("%s left the counter at time %d from line %d.\n", dequeued->name, currTime, dequeued->lineNum);
            freeCustomer(dequeued);
        }
        printf("======\n");
    }
}