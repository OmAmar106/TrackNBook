#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define N 20
char locations[N][20] = {"Butibori","IIIT Nagpur","Airport Metro"};
int arr[N][N];
struct node{
    char name[50];
    struct node* next;
    struct node* prev;
};
//use a queue to do something that admin can approve and let others go through.
//it would just need a push operation, and if they want to hide their user profile from being seen by the admin.
//they can hide their ids
//i will also let other users see their ids.
//this would add lots of lines and make it more interesting and use one more data structure now how could i 
//possibly use queues , that is the quesiton. 
struct stack{
    char name[50];
    struct stack* next;
};
struct queue{
    char name[500];
    struct queue* next;
};
struct queue* newnodeq(char name1[500]){
    struct queue* head = (struct queue*)malloc(sizeof(struct queue));
    head->next = NULL;
    strcpy(head->name,name1);
    return head;
}
struct queue* insertatbeg(char name1[500],struct queue* head){
    struct queue* head1 = newnodeq(name1);
    head1->next = head;
    return head1;
}
struct queue* delfrombeg(struct queue* head){
    struct queue* head1 = head;
    head = head->next;
    free(head1);
    return head;
}
void printq(struct queue* head){
    int i = 0;
    if(head==NULL){
        printf("No New Messages");
        printf("\n");
        return;
    }
    while(head!=NULL){
        printf("%d. %s",i+1,head->name);
        head=head->next;
        i++;
    }
    printf("\n");
    return;
}
void printS(struct stack* head){
    int i = 0;
    printf("List of users previosuly loginned : \n");
    while(head!=NULL){
        printf("\n%d. %s",i+1,head->name);
        i += 1;
        head = head->next;
    }
    printf("\n");
}
struct stack* newnode(char name1[50]){
    struct stack* head = (struct stack*)malloc(sizeof(struct stack));
    strcpy(head->name,name1);
    head->next = NULL;
    return head;
}
struct stack* push(struct stack* head,char name1[50]){
    if(head==NULL){
        head = newnode(name1);
        return head;
    }
    struct stack* head1 = head;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next = newnode(name1);
    return head1;
}
//add all the orange line and aqua line stations to the struct and then traverse through it 
void printLL(struct node* head){
    int i = 0;
    while(head!=NULL){
        printf("\n%d. %s",i+1,head->name);
        head = head->next;
        i++;
    }
}
void print(char arr[N][20]){
    for(int i=0;i<N;i++){
        printf("\n%d. %s",i+1,arr[i]);
    }
}
struct node* createnode(char name[]){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    strcpy(new->name,name);
    new->next=NULL;
    new->prev=NULL;
    return new;
}
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < N; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void printSolution(int dist[],int dest,int src)
{
    printf("\nDistance from %s to %s is %d\n",locations[src],locations[dest],dist[dest]);
}
void dijkstra(int graph[N][N], int src,int dest)
{
    int dist[N]; 
    bool sptSet[N];
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < N; v++)
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist,dest,src);
}
struct node* enteratpos(struct node* head,int data){
    struct node* head1 = head;
    char str[50];
    for(int i=0;i<data;i++){
        head=head->next;
    }
    printf("\nEnter Name of the station : ");
    scanf("%s",str);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name,str);
    newnode->next = head->next;
    newnode->prev=head;
    head->next = newnode; 
    newnode->next->prev = newnode;
    return head1;
}
//make insert at beg and at end depending upon the input
struct node* add(struct node*head,char name[])
{
    struct node*newstation=createnode(name);
    if(head==NULL)
    {
        return newstation;
    }
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newstation;
    newstation->prev=temp;
    return head;
}
struct stack* pop(struct stack* head){
    struct stack* head3 = head;
    if(head->next==NULL){
        head=NULL;
        return head;
    }
    while(head->next->next!=NULL){
        head=head->next;
    }
    struct stack* head1 = head->next;
    head->next = NULL;
    free(head1);
    return head3;
}
struct node* aqua(){
    struct node*head=NULL;
    head=add(head,"PRAJAPATI NAGAR");
    head=add(head,"VAISHNODEVI SQUARE");
    head=add(head,"AMBEDKAR SQUARE");
    head=add(head,"TELEPHONE EXCHANGE");
    head=add(head,"CHITAROLI SQUARE");
    head=add(head,"AGRASEN SQUARE");
    head=add(head,"DOSAR VAISHYA SQUARE");
    head=add(head,"NAGPUR RAILWAY STATION");
    head=add(head,"COTTON MARKET");
    head=add(head,"SITABULDI");
    head=add(head,"JHANSI RANI SQUARE");
    head=add(head,"INSTITUTE OF ENGINEERS");
    head=add(head,"SHANKAR NAGAR SQUARE");
    head=add(head,"L.A.D. COLLLEGE SQUARE");
    head=add(head,"AMBAZARI LAKE");
    head=add(head,"SUBHASH NAGAR");
    head=add(head,"RACHANA RING ROAD JUNCTION");
    head=add(head,"VASUDEV NAGAR");
    head=add(head,"BANSI NAGAR");
    head=add(head,"LOKMANYA NAGAR");
    return head;
}
struct node*orange(){
    struct node*head=NULL;
    head=add(head,"AUTOMATIVE SQUARE");
    head=add(head,"NARI ROAD");
    head=add(head,"INDORA SQUARE");
    head=add(head,"KADVI SQUARE");
    head=add(head,"GADDI GODAM SQUARE");
    head=add(head,"KASTURCHAND PARK");
    head=add(head,"ZERO MILE");
    head=add(head,"SITABULDI");
    head=add(head,"CONGRESS NAGAR");
    head=add(head,"RAHATE COLONY");
    head=add(head,"AJNI SQUARE");
    head=add(head,"CHHATRAPATI SQUARE");
    head=add(head,"JAIPRAKASH NAGAR");
    head=add(head,"UJJWAL NAGAR");
    head=add(head,"AIRPORT");
    head=add(head,"AIRPORT SOUTH");
    head=add(head,"NEW AIRPORT");
    head=add(head,"KHAPRI");
    return head;
}
int main(){
    printf(" ________  _______        _       ______  _   __    _  _     ___     ______     _____      _____     _  __\n");
    printf("'   ||   '||      |     // \\   //       \\ || //      || \\     ||     ||     \\  //     \\   //     \\   || //\n");
    printf("    ||    ||      |    //   \\  ||         ||//       ||   \\   ||     ||     || ||     ||  ||     ||  ||//\n");
    printf("    ||    || ____/    //_____\\ ||         ||\\     _  ||    \\  ||  _  ||_____/  ||     ||  ||     ||  ||\\\n");
    printf("    ||    ||      \\  //       \\ \\         || \\       ||     \\ ||     ||     || ||     ||  ||     ||  || \\ \n");
    printf("   _||_   ||       \\//         \\ \\______/_||_ \\__   _||_     _||_    ||_____/   \\____//    \\____//  _||_ \\__\n");
    printf("___________________________________________________________________________________________________________\n");
    //History check krne ke liye ek kam krna naam ke sath save krna , isse log in ka kuch toh use ajayega
    //make a array of string with places within nagpur and make a adjency matrix 
    //set ditance and use arr as an adjacency matrix 
    struct node* AquaHead = aqua();
    struct node* OrangeHead = orange();
    struct stack* history = (struct stack*)malloc(sizeof(struct stack));
    history = NULL;
    struct queue* notifs = (struct queue*)malloc(sizeof(struct queue));
    notifs = NULL;
    while(1){
        printf("\n1. Sign Up\n");
        printf("2. Log In\n");
        printf("3. Exit\n");
        printf("4. Veiw History of users\n");
        printf("5. Veiw Notifications\n\n");
        printf("Enter Choice : ");
        int choice;
        scanf("%d",&choice);
        printf("\n");
        if(choice==1){
            char username[100];
            char password1[100];
            char password2[100];
            printf("Enter UserName(without space) : ");
            scanf("%s",username);
            printf("Enter Password : ");
            scanf("%s",password1);
            printf("Enter Password Again : ");
            scanf("%s",password2);
            int exist = 0;
            //if i find the username already in the notepad file , make exist 1
            if(strcmp(password1, password2) == 0 && exist!=1){
                printf("\nSign in now\n");
            }
            else{
                printf("\nUser already exists or password does not match, Try again.\n");
            }
        }
        else if(choice==2){
            char username[50];
            char password1[50];
            printf("Enter username(without space) : ");
            scanf("%s",username);
            printf("Enter Password : ");
            scanf("%s",password1);
            history = push(history,username);
            if(strcmp(username,"admin")==0 && strcmp(password1,"#pas123")==0){
                while(true){
                    printf("\n\nWhat would you like to do today?");
                    printf("\n1. Add a Station in Orange Line");
                    printf("\n2. Add a Station in Aqua Line");
                    printf("\n3. Veiw users");
                    printf("\n4. Send Notification");
                    printf("\n5. Delete Notification");
                    printf("\n6. Log Out");
                    int choice3;
                    printf("\nEnter Choice : ");
                    scanf("%d",&choice3);
                    if(choice3==1){
                        printLL(OrangeHead);
                        printf("\nEnter number of stops after which you want to insert : ");
                        //ab insert stop then insert at pos banao , 
                        //insert at beg and end ko alag se banado 
                    }
                    else if(choice3==4){
                        char str[500]; 
                        printf("\nEnter message : ");
                        char c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        fgets(str,sizeof(str),stdin);
                        notifs = insertatbeg(str,notifs);
                        printf("message sent succesfully.");
                    }
                    //choice == 3 pe pura notepad ka data print krdo 
                    else if(choice3==5){
                        printf("\nWould you like to delete all the notifs(Y) or one notif(N)?(Y/N) : ");
                        char h;
                        char c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        scanf("%c",&h);
                        if(h=='N'){
                            if(notifs!=NULL){
                                notifs = delfrombeg(notifs);
                            }
                            printf("\nLast message deleted succesfully.");
                        }
                        else{
                            while(notifs!=NULL){
                                notifs = delfrombeg(notifs);
                            }
                            printf("\nAll messages deleted succesfully.");
                        }
                    }
                    else if(choice3==6){
                        break;
                    }
                    else{
                        printf("\nEnter values from 1-4.");
                    }
                }
                continue;
            }
            //check if these are in notepad or not
            int exist = 0;
            if(exist!=1){
                int choice1 = 0;
                int flag = 1;
                while(choice1!=7){
                    printf("\nWelcome %s",username);
                    printf("\n\nWhat would you like to do today?");
                    printf("\n1. Book a Cab");
                    printf("\n2. Book a Bus");
                    printf("\n3. Book a Metro");
                    printf("\n4. Shortest Path Calculator");
                    printf("\n5. Veiw last Booking");
                    printf("\n6. Hide ID from history");
                    printf("\n7. Log out");
                    printf("\n\nEnter choice : ");
                    scanf("%d",&choice1);
                    //shortest path calculator mai dijikistra algo lagane 
                    //aur options ke bade soche asap
                    if(choice1==1){
                        continue;
                    }
                    else if(choice1==3){
                        printf("\nStart Point : ");
                        printf("\n1. Aqua Line");
                        printf("\n2. Orange Line");
                        printf("\nEnter Choice : ");
                        int line;
                        scanf("%d",&line);
                        int line1st = -1;
                        int line2st = -1;
                        if(line==1){
                            printLL(AquaHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line1st);
                        }
                        else{
                            printLL(OrangeHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line2st);
                        }
                        printf("\nEnd Point : ");
                        printf("\n1. Aqua Line");
                        printf("\n2. Orange Line");
                        printf("\nEnter Choice : ");
                        scanf("%d",&line);
                        int line1ed = -1;
                        int line2ed = -1;
                        if(line==1){
                            printLL(AquaHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line1ed);
                        }
                        else{
                            printLL(OrangeHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line2ed);
                        }
                        if(line1ed!=-1 && line1st!=-1){
                            printf("\nThe cost is : %d",5*(abs(line1ed-line1st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line1ed-line1st)));
                            //add confirmation to book the ticket 
                        }
                        else if(line2ed!=-1 && line2st!=-1){
                            printf("\nThe cost is : %d",5*(abs(line2ed-line2st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line2ed-line2st)));
                        }
                        else if(line2st==-1 && line1ed==-1){
                            printf("\nThe cost is : %d",5*(abs(line2ed-8)+abs(10-line1st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line2ed-8)+abs(10-line1st)));
                        }
                        else{
                            printf("\nThe cost is : %d",5*(abs(line1ed-10)+abs(8-line2st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line1ed-10)+abs(8-line2st)));
                        }
                        printf("\n");
                    }
                    else if(choice1==4){
                        int startpoint;
                        print(locations);
                        printf("\n\nEnter Start Point : ");
                        scanf("%d",&startpoint);
                        int endpoint;
                        printf("\nEnter End Point : ");        
                        scanf("%d",&endpoint);
                        //apply algo here
                        dijkstra(arr,startpoint-1,endpoint-1);
                    }
                    else if(choice1==6 && flag==1){
                        //pop krdo stack se idhar(remove from ending lagao matlab)
                        flag = 0;
                        history = pop(history);
                        printf("\nRemoved your ID from history successfully.\n");
                    }
                    else if(choice1==6 && flag==0){
                        printf("\nYour username has already been removed.\n");
                    }
                    else if(choice1==7){
                        break;
                    }
                    else{
                        printf("\nPlease enter from 1 to 6\n");
                    }
                }
            }
            else{
                printf("\nWrong Username or Password please enter again.");
            }
            printf("\n");
        }
        else if(choice==3){
            printf("Thank You\n");
            break;
        }
        else if(choice==4){
            printS(history);
        }
        else if(choice==5){
            //dequeue krte jao elements ko ;) and sare print kardo.
            //dequeue krte vakt use new queue mai dalte jao and then use orignal bando  
            printq(notifs);
        }
        else{
            printf("Enter Choice from 1-3\n");
        }
    }
}