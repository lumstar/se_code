typedef struct DataNode
{
    char *cmd;
    char *desc;
    int (*handler)();
    struct DataNode *next;
}tDataNode;
//find a cmd in the linklist
tDataNode* FindCmd(tDataNode *head, char *cmd);
//show all cmd in list
int ShowAllCmd(tDataNode *head);
