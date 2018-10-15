#include<stdio.h>
#include<string.h>
#include <ctype.h>



struct stack{
    int bot;
    char array[100];
}infix, opstack, postfix;


void push(struct stack * input, char c){
    input->array[++input->bot] = c;
    return;
}


void moveFromTo(struct stack * op, struct stack * op1){
    if(op->array[op->bot] == '('){
        --op->bot;
        return;
    }
    op1->array[++op1->bot] = op->array[op->bot];
    --op->bot;
    return;
}

int checkPrecedence(char c){
    switch(c) {
        case '~': return -1;
        case '^': return -2;
        case 'V': return -3;
        case '>': return -4;
        default: return -6;
    }
}
char pop(struct stack * s){
    char i = s->array[s->bot];
    --s->bot;
    return i;
}



void infixToPostfix(struct stack input, struct stack * operator, struct stack *post){
   int len;
   len = strlen(input.array);
   int i;

   for(i =0; i< len; i++){
    //    push(post.array,input.array[i]);
    /* You are a shit coder */
    /* I am ashamed to be you*/
        if(input.array[i] >= 97 && input.array[i] <= 122){
            push(post, input.array[i]);
        }else if(input.array[i] == '~' || input.array[i] == '^' || input.array[i] == 'V' || input.array[i] == '>'){
                if(operator->array[operator->bot] == -1 || (checkPrecedence(input.array[i]) > checkPrecedence(operator->array[operator->bot]))){
                    push(operator, input.array[i]);
                //  printf("%s", input.array[i]);
                //   printf("\n");
                // }else if(operator->array[operator->bot] == '('){
                //     push(operator, input.array[i]);

                // }else if(input.array[i] == ')'){
                //     while(operator->array[operator->bot] != '(' && operator->bot >= 0){
                //         moveFromTo(operator, post);
                //     }
                }else{
                    while((checkPrecedence(input.array[i]) < checkPrecedence(operator->array[operator->bot])) && operator->bot >= 0 ){
                        moveFromTo(operator , post);
                        //  printf("op moveFromTo\n");
                    }
                    // push(operator, input.array[i]);
                    printf("\n");
                }

        }else if(input.array[i] == '('){
                    push(operator, input.array[i]);
        }else if(input.array[i] == ')'){
                    while(operator->array[operator->bot] != '(' && operator->bot >= 0){
                        moveFromTo(operator, post);
                    }
                    operator->bot--;
        }


        // printf("\n%s\t",operator->array);
        // printf("\t%s",post->array);

    }
    printf("\n");
    while(operator->bot >= 0){
     moveFromTo(operator, post);


    // operator->bot = -1;
    }
     operator->bot = -1;
    return;
}


struct node{
    struct node * parent;
    struct node * left;
    struct node * right;
    char ch;
};

struct node * parseTree = NULL;
struct node * p = NULL;


void pushTree(char c){

//    struct node * p;
//    p = (struct node *)malloc(sizeof(struct node));
//    p = NULL;
   printf("\nbegin\n");

    if(parseTree->ch == NULL && parseTree->right == NULL && parseTree->parent == NULL && parseTree->left == NULL ){
        printf("1\n");
        parseTree->ch = c;
        parseTree->left = NULL;
        parseTree->right = NULL;
        parseTree->parent = NULL;
        return;
    }else if(parseTree->left == NULL){
        printf("2\n");
        p->ch = c;
        p->parent = parseTree->left;
        p->left = NULL;
        p->right = NULL;
        parseTree->left = p;
        return;
    }else if(parseTree->right == NULL){
        printf("3\n");
       p->ch = c;
       p->parent = parseTree->right;
       p->left = NULL;
       p->right = NULL;
       parseTree->right = p;
       printf("hello\n");
       return;
    }else {
        printf("4\n");
        struct node * t;
        t = parseTree;
        parseTree->left = t;
        parseTree->right = NULL;
        parseTree->parent = NULL;
        parseTree->ch = c;
        printf("hello\n");
        return;
    }
printf("out\n");
return;

}

void treeTraverse(){
   struct node * t;
   printf("hello");
   t = parseTree;
   while(t->left!=NULL){
       t = t->left;
   }
   printf("%c",t->ch);

}



void postfixToTree(struct stack postfix ){

    int len1;
    len1 = strlen(postfix.array);
    struct stack tree;
        tree.bot = -1;
    struct stack parse;
    parse.bot = -1;

    // int tail = len-1;
    int i;
    for(i = 0; i<len1; i++){

        // if(isalpha(postfix.array[i])){
        if(postfix.array[i] >= 97 && postfix.array[i] <= 122  ){
            // printf("\n%c", postfix.array[i]);
            push(&tree,postfix.array[i]);
            printf("\n%c",postfix.array[i]);

        }else if(postfix.array[i]== '^' || postfix.array[i]== 'V' || postfix.array[i]== '>' ){



            pushTree(postfix.array[i]);



            // printf("\n%c",postfix.array[i]);
            // push(&parse,postfix.array[i]);
            // printf("\n%c",pop(&tree));
            // push(&parse,pop(&tree));
            pushTree(pop(&tree));
            // push(&parse,pop(&tree));
            pushTree(pop(&tree));

            printf("hello\n");
            // printf("\n%s",parse.array);
            // printf("     %c",pop(&tree));

        }

    }

    printf("\nhello");

}


int main()
{
/*  1.  ~ = NEGATION
    2.  ^ = AND
    3.  V = OR
    4.  > = Implication */
    opstack.bot = -1;
    postfix.bot = -1;


    scanf("%s",infix.array);
    infix.bot = strlen(infix.array) -1;
    infixToPostfix(infix,&opstack,&postfix);

    printf("%s",postfix.array);


    postfixToTree(postfix);
     printf("hello");
    // treeTraverse();

   return 0;

}


