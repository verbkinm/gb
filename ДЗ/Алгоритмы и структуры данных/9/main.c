#include <stdio.h>
#include <stdlib.h>

typedef struct Queue_unit_struct Queue_unit;
typedef struct Queue_struct Queue;

struct Queue_unit_struct
{
    int value;
    int priority;
    struct Queue_unit_struct *next;
};

struct Queue_struct
{
    struct Queue_unit_struct *first;
    struct Queue_unit_struct *last;
    size_t size;
};

Queue_unit* createQueueUnit(int value, int priority);
Queue* createQueue();

void clearQueue(Queue *queue);
void printQueue(Queue *queue);

void push(Queue *queue, Queue_unit* current);
void pop(Queue *queue);

typedef struct Stack_struct Stack;

struct Stack_struct
{
    char *data;
    char* pointer;
    size_t size;
};

Stack* createStack(size_t size);
void clearStack(Stack *stack);

void pushStack(Stack *stack, char c);
char popStack(Stack *stack);

int main()
{
    // Очередь
    Queue *queue = createQueue();
    Queue_unit *unit1 = createQueueUnit(1, 0);
    Queue_unit *unit2 = createQueueUnit(2, 1);

    push(queue, unit1);
    printQueue(queue);
    push(queue, unit2);
    printQueue(queue);
    push(queue, createQueueUnit(55, 1));
    printQueue(queue);
    push(queue, createQueueUnit(66, 2));
    printQueue(queue);
    push(queue, createQueueUnit(-1, -2));
    printQueue(queue);

    pop(queue);
    printQueue(queue);
    pop(queue);
    printQueue(queue);

    clearQueue(queue);
    printQueue(queue);

    free(queue);

    //Стек
    Stack *stack = createStack(10);

    int a = 7;
    while(a)
    {
       pushStack(stack, (a & 1) + '0');
       a >>= 1;
    }

    while(stack->pointer > stack->data)
        printf("%c", popStack(stack));

    printf("\n");

    clearStack(stack);
    free(stack);

    return 0;
}

Stack* createStack(size_t size)
{
    Stack *stack = (Stack*) malloc(sizeof (Stack));
    stack->data = calloc(size, sizeof(char));
    stack->pointer = stack->data;
    stack->size = size;

    return stack;
}

void clearStack(Stack *stack)
{
    stack->pointer = NULL;
    free(stack->data);
}

void pushStack(Stack *stack, char c)
{
    if(stack->pointer >= (stack->data + stack->size))
    {
        printf("Stack full!\n");
        return;
    }

    *stack->pointer = c;
    stack->pointer++;
}

char popStack(Stack *stack)
{
    if(stack->pointer == stack->data)
    {
        printf("\nStack empty!\n");
        return 0;
    }
    stack->pointer--;

    char result = *stack->pointer;
    *stack->pointer = '\0';

    stack->size--;

    return result;
}

Queue_unit *createQueueUnit(int value, int priority)
{
    Queue_unit *unit = (Queue_unit*) malloc(sizeof (Queue_unit));
    unit->value = value;
    unit->priority = priority;
    unit->next = NULL;

    return unit;
}

Queue* createQueue()
{
    Queue *queue = (Queue*) malloc(sizeof (Queue));
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;

    return queue;
}

void clearQueue(Queue *queue)
{
    if(!queue || (!queue->first && !queue->last))
        return;

    while(queue->first)
        pop(queue);
}

void printQueue(Queue *queue)
{
    if(!queue || queue->first == NULL)
        return;

    Queue_unit* currentUnit = queue->first;
    while(currentUnit)
    {
        printf("[%d, %d] ", currentUnit->value, currentUnit->priority);
        currentUnit = currentUnit->next;
    }
    printf("\n");
}

void push(Queue *queue, Queue_unit* current)
{
    if(!queue || !current)
        return;

    if(!queue->first)
    {
        queue->first = current;
        queue->last = current;
        queue->size++;

        return;
    }

    current->next = queue->first;
    queue->first = current;
    queue->size++;

    while ( 1 )
    {
        if(current->next == NULL)
            break;

        if(current->priority > current->next->priority)
        {
            Queue_unit *next = current->next;

            int value = next->value;
            int priority = next->priority;

            next->value = current->value;
            next->priority = current->priority;

            current->value = value;
            current->priority = priority;

            current = next;
        }
        else
            break;
    }
}

void pop(Queue *queue)
{
    if(!queue || !queue->first)
        return;

    if(queue->first == queue->last)
    {
        free(queue->first);
        queue->first = NULL;
        queue->last = NULL;
        queue->size--;

        return;
    }

    Queue_unit *current = queue->first;
    Queue_unit *preLast = queue->first;

    while (current)
    {
        if(current->next)
        {
            preLast = current;
            current = current->next;
        }
        else
            break;
    }

    free(queue->last);
    queue->last = preLast;
    queue->last->next = NULL;

    queue->size--;
}
