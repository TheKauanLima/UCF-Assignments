#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMECOUNT 31
#define NUMCOUNT 100

typedef struct Tree
{

char customer[NAMECOUNT];
int numTickets;
struct Tree* left;
struct Tree* right;

}Tree;

int levelFinder(struct Tree* root, int level, char name[])
{
    if(root == NULL) {
        return -1;
    }
    if(strcmp(root->customer, name) == 0) {
        return level;
    }

    int left = levelFinder(root->left, level + 1, name);
    if(left != -1) {
        return left;
    }

    return levelFinder(root->right, level + 1, name);
}

struct Tree* createCustomer(int num, char name[])
{
  struct Tree* new = malloc(sizeof(struct Tree));
  strcpy(new->customer, name);
  new->numTickets = num;
  new->left = NULL;
  new->right = NULL;

  return new;
}

struct Tree* buyInsert(Tree* root, Tree* insert)
{

  if(root == NULL)
  {
    return insert;
  }
  else
  {
    int compareNum = strcmp(insert->customer, root->customer);

    if(compareNum > 0)
    {
      if(root->right != NULL)
      {
        root->right = buyInsert(root->right, insert);
      }
      else
      {
        root->right = insert;
      }

    }
    else if (compareNum < 0)
    {
      if(root->left != NULL)
      {
        root->left = buyInsert(root->left, insert);
      }
      else
      {
        root->left = insert;
      }
    }
    else
    {
      root->numTickets = root->numTickets + insert->numTickets;
      free(insert);
    }
  }
  return root;

}

void searchFindCustomer(struct Tree* root, char name[], int* depth)
{

  if(root != NULL)
  {
    int compareNum = strcmp(name, root->customer);

    if(compareNum == 0)
    {
      int level = levelFinder(root, 0, name);
      printf("%s %d %d\n", root->customer, root->numTickets, level);
    }
    (*depth)++;
    if(compareNum > 0)
    {
      return searchFindCustomer(root->right, name);
    }
    else
    {
      return searchFindCustomer(root->left, name);
    }
  }
  else
  {
    printf("%s not found\n", name);
    return;
  }

}

int sumOfTickets(struct Tree* root)
{
  if(root!= NULL)
  {
    return root->numTickets + sumOfTickets(root->left) + sumOfTickets(root->right);
  }
  else
  {
    return 0;
  }
}

int sumOfCustomers(struct Tree* root)
{
  if(root != NULL)
  {
    return 1 + sumOfCustomers(root->left) + sumOfCustomers(root->right);
  }
  else
  {
    return 0;
  }
}

double meanOfTickets(struct Tree* root)
{
  double allTickets = sumOfTickets(root);
  double allCustomers = sumOfCustomers(root);
  double mean = allTickets / allCustomers;

  return mean;
}

int heightOfTree(struct Tree* root)
{
  if(root != NULL)
  {
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    if(left > right)
    {
      return left + 1;
    }
    else
    {
      return right + 1;
    }
  }
  else
  {
    return -1;
  }
}

void balanceOfTree(struct Tree* root)
{
  if(root != NULL)
  {
  int left = heightOfTree(root->left);
  int right = heightOfTree(root->right);

  printf("left height = %d right height = %d ", left, right);
  if(left == right)
  {
    printf("balanced\n");
  }
  else
  {
    printf("not balanced\n");
  }

  }
  else
  {
    return;
  }
}

int countBefore(struct Tree* root, char name[])
{
  if(root == NULL)
  {
    return 0;
  }
  else
  {
    int check = strcmp(root->customer, name);
    if(check <= 0)
    {
       return root->numTickets + countBefore(root->left, name) + countBefore(root->right, name);
    }
      else
      {
        return countBefore(root->left, name);
      }
}
  
}

struct Tree* parentInTree(struct Tree* root, struct Tree* node)
{
  if(root == NULL || root == node || node == NULL)
  {
    return NULL;
  }
  if(root->left == node || root->right == node)
  {
    return root;
  }
  int check = strcmp(root->customer, node->customer);
  if(check < 0)
  {
    return parentInTree(root->left, node);
  }
  else
  {
    return parentInTree(root->right, node);
  }
}

struct Tree* minVal(struct Tree* root)
{
  if(root->left == NULL)
  {
    return root;
  }
  else
  {
    return minVal(root->left);
  }
}

struct Tree* maxVal(struct Tree* root)
{
  if(root->right == NULL)
  {
    return root;
  }
  else
  {
    return maxVal(root->right);
  }
}

int leafNode(struct Tree* root)
{
  return ((root->left == NULL) && (root->right == NULL));
}

int leftChild(struct Tree* root)
{
  return((root->left != NULL) && (root->right == NULL));
}

int rightChild(struct Tree* root)
{
  return((root->right != NULL) && (root->left == NULL));
}

struct Tree* customerInHand(struct Tree* root, char name[])
{
  if(root != NULL)
  {
    int value = strcmp(name, root->customer);

    if(value == 0)
    {
      return root;
    }
    else if(value > 0)
    {
      return customerInHand(root->right, name);
    }
    else
    {
      return customerInHand(root->left, name);
    }

  }
  else
  {
    return NULL;
  }

}

struct Tree* deleteFromTree(struct Tree* root, char name[], int remove, int* checkDelete)
{
    if (root == NULL) {
        return NULL;
    }
  struct Tree* delete1 = NULL;
  struct Tree* delete2 = NULL;
  struct Tree* save = NULL;
  struct Tree* parent = NULL;

  delete1 = customerInHand(root, name);
  if(delete1 == NULL)
  {
    printf("%s not found\n", name);
    return root;
  }
  parent = parentInTree(root, delete1);
    
    int check = strcmp(name, root->customer);
    //int check2 = strcmp(delete1->customer, parent->customer);

    if (check < 0) {
        root->left = deleteFromTree(root->left, name, remove, checkDelete);
    } 
    else if (check > 0) {
        root->right = deleteFromTree(root->right, name, remove, checkDelete);
    } 
    else {
        // Found the node to update
        root->numTickets -= remove;

        if (root->numTickets > 0)
        {
            return root;
        }

        *checkDelete = 1;

        // Case 1: Leaf node
        if (leafNode(delete1))
        {
            if(parent == NULL)
            {
              free(root);
              return NULL;
            }

          if(parent->left == delete1)
          {
            free(parent->left);
            parent->left = NULL;
          }
          else
          {
            free(parent->right);
            parent->right = NULL;
          }
          return root;
        }

        // Case 2: Only left child
        if (leftChild(delete1))
        {
          
          if(parent == NULL)
          {
            save = delete1->left;
            free(delete1);
            return save;
          }

          if(parent->left == delete1)
          {
            save = parent->left;
            parent->left = parent->left->left;
            free(save);
          }
          else
          {
            save = parent->right;
            parent->right = parent->right->left;
            free(save);
          }
          return root;
        }

        // Case 3: Only right child
        if (rightChild(delete1))
        {
          if(parent == NULL)
          {
            save = delete1->right;
            free(delete1);
            return save;
          }
          if(parent->left == delete1)
          {
            save = parent->left;
            parent->left = parent->left->right;
            free(save);
          }
          else
          {
            save = parent->right;
            parent->right = parent->right->right;
            free(save);
          }
          return root;
        }
      delete2 = maxVal(delete1->left);
      strcpy(delete1->customer, delete2->customer);
      delete1->numTickets = delete2->numTickets;
      delete1->left = deleteFromTree(delete1->left, delete2->customer, delete2->numTickets, checkDelete);
      
    }
    return root;
}


void printFunction(struct Tree* root, char name[], int isDeleteOperation) {
    if (root == NULL) {
        printf("%s not found\n", name);
        return;
    }

    struct Tree* node = customerInHand(root, name);
    if (node != NULL) {
        // Only print if not deleted or has tickets remaining
        if (!isDeleteOperation || node->numTickets > 0) {
            int level = levelFinder(root, 0, name);
            printf("%s %d %d\n", node->customer, node->numTickets, level);
        }
    } else {
        printf("%s not found\n", name);
    }
}


int main(void)
{
  int numCommands;
  int amountOfTickets;
  char command[20];
  char name[NAMECOUNT];
  struct Tree* root = NULL;

  scanf("%d", &numCommands);
  //printf("\n");
for(int i = 0; i < numCommands; i++)
    {
      scanf("%s", command);

      if(strcmp(command, "buy") == 0)
      {
        scanf("%s %d", name, &amountOfTickets);
        struct Tree* newRoot = createCustomer(amountOfTickets, name);
        root = buyInsert(root, newRoot);
        printFunction(root, name, 0);
      }
        else if(strcmp(command, "use") == 0)
        {
            scanf("%s %d", name, &amountOfTickets);
          int checkDelete = 0;
            root = deleteFromTree(root, name, amountOfTickets, &checkDelete);
          if(checkDelete)
          {
            printf("%s deleted\n", name);
          }
          else
          {
            struct Tree* node = customerInHand(root, name);
            if (node != NULL) {
                printFunction(root, name, 0);
            }
          }
        }
      else if(strcmp(command, "find") == 0)
      {
        scanf("%s", name);
        //searchFindCustomer(root, name);
        printFunction(root, name, 0);

      }
      else if(strcmp(command, "mean_tickets") == 0)
      {
        double mean = meanOfTickets(root);
        printf("%.2lf\n", mean);
      }
      else if(strcmp(command, "height_balance") == 0)
      {
        balanceOfTree(root);
      }
      else if(strcmp(command, "count_before") == 0)
      {
        scanf("%s", name);
        int count = countBefore(root, name);
        printf("%d\n", count);
      }
    }
  free(root);
}
