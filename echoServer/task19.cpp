#include "task19.h"
#include <QPair>
struct node  {
    int data;
    struct node *left;
    struct node *right;
    struct node *middle;
};

struct node* newNode(int data)
{
    struct node* node = new struct node(); // declare and allocate new node
    node->data = data;      // Assign data to this node
    node->left = NULL;      // Initialize left and right children as NULL
    node->right = NULL;
    node->middle = NULL;
    return(node);
}

QVector<int> fixVector(QVector<int> test)
{
    QVector<int> order =    {2, 1, 6, 5, 4, 9, 3, 7, 8};
    QVector<int> result =   {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i = 0; i < test.size(); i++)
    {
        int i1 = test.indexOf(test[i]) + 1; //1, test -> 9
        result[order.indexOf(i1)] = test[i];
    }
    return result;
    //2 1 6 5 4 9 3 7 8

    //s s - swap(2), x - replace, i - leave as is
    //1 2 3 4 5 6 7 8 9
    //s s x s s x i i i - 1
    //2 1 6 5 4 3 7 8 9 - 3 7 8 9 | 9 3 7 8 (i+1 = i)
    //i i i i i

    //0 1 2 3 4 5 6 7 8
}

void findLastItems(struct node* Node, QVector<int>* mins){
    if(Node->left != NULL)
    {
        findLastItems(Node->left, mins);
    }
    if(Node->middle != NULL)
    {
        findLastItems(Node->middle, mins);
    }
    if(Node->right != NULL)
    {
        findLastItems(Node->right, mins);
    }
    if(Node->left == NULL and Node->middle == NULL and Node->right == NULL)
    {
        mins->append(Node->data);
    }
}

int findMinFromVector(QVector<int> source){
    int minElem = source[0];
    for(int i = 0; i < source.size(); i++)
    {
        if(minElem > source[i]) minElem = source[i];
    }
    return minElem;
}

void deleteChildFromTree(struct node* Node, int child, QVector<int>* prufer){
    if(Node->left != NULL){
        if(Node->left->data != child) deleteChildFromTree(Node->left, child, prufer);
        else
        {
            prufer->append(Node->data);
            Node->left = NULL;
            return;
        }
    }
    if(Node->middle != NULL){
        if(Node->middle->data != child) deleteChildFromTree(Node->middle, child, prufer);
        else
        {
            prufer->append(Node->data);
            Node->middle = NULL;
            return;
        }
    }
    if(Node->right != NULL)
    {
        if(Node->right->data != child) deleteChildFromTree(Node->right, child, prufer);
        else
        {
            prufer->append(Node->data);
            Node->right = NULL;
            return;
        }
    }
}
bool checkRootValid(struct node* node)
{
    int leg_count = 0;
    if(node->left != NULL) leg_count++;
    if(node->middle != NULL) leg_count++;
    if(node->right != NULL) leg_count++;
    //qDebug() << "checkroot" << leg_count;
    if(leg_count < 2) return false;
    else return true;
}
struct node* switchRoot(struct node* node)
{
    if(node->left == NULL and node->right != NULL and node->middle == NULL)
    {
        //qDebug() << "sw_right";
        if(node->right->left != NULL and node->right->right == NULL and node->right->middle == NULL)
        { //1 0 0
            node->right->right = newNode(node->data);
            struct node* temp = node->right;
            node->right = NULL;
            node = temp;
            return node;
        }
        if(node->right->left == NULL and node->right->right != NULL and node->right->middle == NULL)
        { //0 1 0
            node->right->left = newNode(node->data);
            struct node* temp = node->right;
            node->right = NULL;
            node = temp;
            return node;
        }
        if(node->right->left == NULL and node->right->right == NULL and node->right->middle != NULL)
        { //0 0 1
            node->right->left = newNode(node->data);
            struct node* temp = node->right;
            node->right = NULL;
            node = temp;
            return node;
        }
    }
    if(node->right == NULL and node->left != NULL and node->middle == NULL)
    {
        //qDebug() << "sw_left";
        if(node->left->left != NULL and node->left->right == NULL and node->left->middle == NULL)
        { //1 0 0
            node->left->right = newNode(node->data);
            struct node* temp = node->left;
            node->left = NULL;
            node = temp;
            return node;
        }
        if(node->left->left == NULL and node->left->right != NULL and node->left->middle == NULL)
        { //0 1 0
            node->left->left = newNode(node->data);
            struct node* temp = node->left;
            node->left = NULL;
            node = temp;
            return node;
        }
        if(node->left->left == NULL and node->left->right == NULL and node->left->middle != NULL)
        { //0 0 1
            node->left->left = newNode(node->data);
            struct node* temp = node->left;
            node->left = NULL;
            node = temp;
            return node;
        }
    }
    if(node->left == NULL and node->right == NULL and node->middle != NULL)
    {
        //qDebug() << "sw_mid";
        if(node->middle->left != NULL and node->middle->right == NULL and node->middle->middle == NULL)
        { //1 0 0
            node->middle->right = newNode(node->data);
            struct node* temp = node->middle;
            node->middle = NULL;
            node = temp;
            return node;
        }
        if(node->middle->left == NULL and node->middle->right != NULL and node->middle->middle == NULL)
        { //0 1 0
            node->left->left = newNode(node->data);
            struct node* temp = node->middle;
            node->middle = NULL;
            node = temp;
            return node;
        }
        if(node->middle->left == NULL and node->middle->right == NULL and node->middle->middle != NULL)
        { //0 0 1
            node->middle->left = newNode(node->data);
            struct node* temp = node->middle;
            node->middle = NULL;
            node = temp;
            return node;
        }
    }
    return NULL;
}
bool soloSideCheck(struct node* node)
{
    if(node->left != NULL and node->right == NULL and node->middle == NULL)
    {
        //qDebug() << "solodSideCheck-fail-left";
        if(node->left->left == NULL and node->left->right == NULL and node->left->middle == NULL) return true;
        else return false;
    }
    if(node->right != NULL and node->left == NULL and node->middle == NULL)
    {
        //qDebug() << "solodSideCheck-fail-right";
        if(node->right->left == NULL and node->right->right == NULL and node->right->middle == NULL) return true;
        else return false;
    }
    if(node->right == NULL and node->left == NULL and node->middle != NULL)
    {
        //qDebug() << "solodSideCheck-fail-middle";
        if(node->middle->left == NULL and node->middle->right == NULL and node->middle->middle == NULL) return true;
        else return false;
    }
    else
    {
        //qDebug() << "soloSideCheck-fail-NaN";
        return false;
    }
}
QVector<int> pruferCodeVoid(QVector<int> array)
{
    if(array.isEmpty()) return QVector<int>();
    array = fixVector(array);
    QVector<int> mins;
    int minElem;
    QVector<int> pruferCode;

    struct node *rootNode = newNode(array[0]);
    rootNode->left = newNode(array[1]);
    rootNode->right = newNode(array[2]);
    rootNode->right->middle = newNode(array[3]);
    rootNode->right->middle->left = newNode(array[4]);
    rootNode->right->middle->middle = newNode(array[5]);
    rootNode->right->middle->right = newNode(array[6]);
    rootNode->left->left = newNode(array[7]);
    rootNode->left->right = newNode(array[8]);
    while(true)
    {
        //qDebug() << "\n";
        //qDebug() << pruferCode;
        if(!checkRootValid(rootNode))
        {
            //qDebug() << "valid-false";
            if(rootNode == NULL)
            {
                delete rootNode;
                break;
            }
            if(soloSideCheck(rootNode))
            {
                //qDebug() << "soloSideCheck-success";
                delete rootNode;
                break;
            }
            rootNode = switchRoot(rootNode);
        }
        else
        {
            findLastItems(rootNode, &mins);
            minElem = findMinFromVector(mins);
            mins.clear();
            deleteChildFromTree(rootNode, minElem, &pruferCode);
        }
    }
    return pruferCode;
}
QVector<QPoint> result2(QVector<int> source){
    QVector<int> numbers = {1,2,3,4,5,6,7,8,9};
    QVector<QPoint> result;
    while(!source.empty())
    {
        for(int j = 0; j < numbers.size(); j++)
        {
            if(!source.contains(numbers[j]))
            {
                result.append(QPoint(numbers[j], source[0]));
                numbers.removeAt(numbers.indexOf(numbers[j]));
                source.removeFirst();
                break;
            }
        }
    }
    result.append(QPoint(numbers.first(), numbers.last()));
    return result;
 }






