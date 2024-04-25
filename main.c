/*
int main starts from line : 340
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define N 10
//Double Linked List
struct node{
    char name[50];
    struct node* next;
    struct node* prev;
};
//Stack made using LL.
struct stack{
    char name[50];
    struct stack* next;
};
//Queue made using LL.
struct queue{
    char name[500];
    struct queue* next;
};
//Function to add a new node in a queue.
struct queue* newnodeq(char name1[500]){
    struct queue* head = (struct queue*)malloc(sizeof(struct queue));
    head->next = NULL;
    strcpy(head->name,name1);
    return head;
}
//Function to insert a node at beginning in a queue.
//(Enqueue)
struct queue* insertatbeg(char name1[500],struct queue* head){
    struct queue* head1 = newnodeq(name1);
    head1->next = head;
    return head1;
}
//Function to delete from beginning in a queue.
//(Dequeue)
struct queue* delfromend(struct queue* head){
    struct queue* head2 = head;
    if(head->next==NULL){
        return NULL;
    }
    while(head->next->next!=NULL){
        head = head->next;
    }
    struct queue* head1 = head->next;
    head->next = NULL;
    free(head1);
    return head2;
}
//Function to print the contents of a queue.
void printq(struct queue* head){
    int i = 0;
    if(head==NULL){
        printf("Empty");
        printf("\n");
        return;
    }
    while(head!=NULL){
        printf("%d. %s\n",i+1,head->name);
        head=head->next;
        i++;
    }
    printf("\n");
    return;
}
//Function to print the contents of a stack.
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
//Function to create a new node of a stack.
struct stack* newnode(char name1[50]){
    struct stack* head = (struct stack*)malloc(sizeof(struct stack));
    strcpy(head->name,name1);
    head->next = NULL;
    return head;
}
//Function to push a ndoe in a stack containing the value name1.
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
//Function to print a LinkedList.
void printLL(struct node* head){
    int i = 0;
    while(head!=NULL){
        printf("\n%d. %s",i+1,head->name);
        head = head->next;
        i++;
    }
}
//Function to print the list of vertices in the graph meaning the places in the array.
void print(char arr[N][20]){
    for(int i=0;i<N;i++){
        printf("\n%d. %s",i+1,arr[i]);
    }
}
//Function to create a new node for the double linked list.
struct node* createnode(char name[]){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    strcpy(new->name,name);
    new->next=NULL;
    new->prev=NULL;
    return new;
}
//Function used to calculate the minDistance for the Dijikistras algorithm.
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX;
    int mini;
    for (int v = 0; v < N; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            mini = v;
        }
    }
    return mini;
}
//Graphs of locations in Nagpur along with distances.
char locations[N][20] = {"IIITN","BUTIBORI","VR MALL","ETERNITY MALL","EMPRESS MALL","MAHARAJBAG ZOO","FUTALA LAKE","AMBAZARI LAKE","VNIT","GOREWADA ZOO"};
int arr[N][N] = {
    {0,3,0,0,0,0,0,0,0,27},
    {3,0,25,0,0,0,0,0,22,0},
    {0,25,0,2,2,3,0,5,0,0},
    {0,0,2,0,1,1,4,0,4,9},
    {0,0,2,1,0,0,0,5,5,0},
    {0,0,3,1,0,0,3,3,3,9},
    {0,0,0,4,0,3,0,3,3,0},
    {0,0,5,0,5,3,3,0,0,8},
    {0,22,0,4,5,3,3,0,0,3},
    {27,0,0,9,0,9,0,8,3,0}
};
//dijikistras algorithm to calculate the minimum distance between two points.
int dijkstra(int graph[N][N], int src,int dest)
{
    int dist[N]; 
    bool sptSet[N];
    for (int i = 0; i < N; i++){
        dist[i] = INT_MAX; 
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < N; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
    }
    return dist[dest];
}
//Function to count the number of nodes in the double linked list.
int count1(struct node* head){
    int count = 0;
    while(head!=NULL){
        head=head->next;
        count += 1;
    }
    return count;
}
//Function to create a message that will be kept in history telling the source and destination station.
struct queue* booking(struct node* AquaHead,struct node* OrangeHead,struct queue* bookings,int line1st,int line1ed,int line2st,int line2ed){
    //the string starts with you booked ticket from 
    char str1[500] = "You Booked Ticket from ";
    //checks whethe the starting point is in orange line or aqua line and adds the name of the station 
    //to the string accoring to it.
    if(line1st==-1){
        line2st -= 1;
        while(line2st>0){
            OrangeHead = OrangeHead->next;
            line2st -= 1;
        }
        strcat(str1,OrangeHead->name);
    }
    else{
        line1st -= 1;
        while(line1st>0){
            AquaHead = AquaHead->next;
            line1st -= 1;
        }
        strcat(str1,AquaHead->name);
    }
    //after concatenating the name of the station , we concatenate to.
    char str2[5] = " to ";
    strcat(str1,str2);
    //we do the same thing for the destination station and then concatenate it.
    if(line1ed==-1){
        line2ed -= 1;
        while(line2ed>0){
            OrangeHead = OrangeHead->next;
            line2ed -= 1;
        }
        strcat(str1,OrangeHead->name);
    }
    else{
        line1ed -= 1;
        while(line1ed>0){
            AquaHead = AquaHead->next;
            line1ed -= 1;
        }
        strcat(str1,AquaHead->name);
    }
    char str23[20] = " by Train.";
    strcat(str1,str23);
    //we add it to a queue named booking that can be seen later on as history.
    bookings = insertatbeg(str1,bookings);
    return bookings;
}
//function if booking is done by some other method.
struct queue* bookingo(struct queue* bookings,int method,int st,int ed){
    char str1[500];
    //checking is booking is done for cab or for bus.
    if(method==1){
        strcat(str1,"You Booked Cab from ");
    }
    else{
        strcat(str1,"You Booked Bus from ");
    }
    strcat(str1,locations[st]);
    char str2[5] = " to ";
    strcat(str1,str2);
    strcat(str1,locations[ed]);
    char str23[2] = ".";
    strcat(str1,str23);
    //we add it to a queue named booking that can be seen later on as history.
    bookings = insertatbeg(str1,bookings);
    return bookings;
}
//function to enter node at position in double linked list. For metro stations.
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
//function to add node in double linked list for creating orange and aqua lines.
struct node* add(struct node *head,char name[])
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
//Function to pop in a stack.
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
//Function to create the Aqua Line for metro station.
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
//Function to create the orange line for metro stations.
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
//Main code starts here.
//To use the code , first sign up and make a account or you could use the admin account.
int main(){
    printf(" ________  _______        _       ______  _   __    _  _     ___     ______     _____      _____     _  __\n");
    printf("'   ||   '||      |     // \\   //       \\ || //      || \\     ||     ||     \\  //     \\   //     \\   || //\n");
    printf("    ||    ||      |    //   \\  ||         ||//       ||   \\   ||     ||     || ||     ||  ||     ||  ||//\n");
    printf("    ||    || ____/    //_____\\ ||         ||\\     _  ||    \\  ||  _  ||_____/  ||     ||  ||     ||  ||\\\n");
    printf("    ||    ||      \\  //       \\ \\         || \\       ||     \\ ||     ||     || ||     ||  ||     ||  || \\ \n");
    printf("   _||_   ||       \\//         \\ \\______/_||_ \\__   _||_     _||_    ||_____/   \\____//    \\____//  _||_ \\__\n");
    printf("___________________________________________________________________________________________________________\n"); 
    //Creating the Aqua and orange line at the start of the code, so that it stays the same until 
    //we exit the code.
    struct node* AquaHead = aqua();
    struct node* OrangeHead = orange();
    //Creating a history stack, that saves the history of users that loginned.
    struct stack* history = (struct stack*)malloc(sizeof(struct stack));
    history = NULL;
    //Create a Notifications queue, that saves the message sent from admin for everyone.
    struct queue* notifs = (struct queue*)malloc(sizeof(struct queue));
    notifs = NULL;
    //Loop goes on until we exit.
    while(1){
        printf("\n1. Sign Up\n");
        printf("2. Log In\n");
        printf("3. Veiw Notifications\n");
        printf("4. Veiw History of users\n");
        printf("5. Exit\n\n");
        printf("Enter Choice : ");
        int choice;
        scanf("%d",&choice);
        printf("\n");
        if(choice==1){
            char username[100];
            char password1[100];
            char password2[100];
            //asks user to enter username and password
            printf("Enter UserName(without space) : ");
            scanf("%s",username);
            printf("Enter Password : ");
            scanf("%s",password1);
            printf("Enter Password Again : ");
            scanf("%s",password2);
            int exist = 0;
            FILE* fptr1;
            fptr1 = fopen("username.txt","r");
            char ch;
            int i1 = 0;
            char username1[100];
            //checks if the username already exists.
            while ((ch = fgetc(fptr1)) != EOF) {
                if (ch == '\n') {
                    username1[i1] = '\0';
                    if(strcmp(username1,username)==0){
                        exist = 1;
                        break;
                    }
                    i1 = 0;
                    continue;
                }
                username1[i1] = ch;
                i1 += 1;
            }
            fclose(fptr1);
            //checks if the first password inputted and the second password inputted are the same or not.
            //if they are same and the username already does not exists, it creates the new username and password.
            if(strcmp(password1, password2) == 0 && exist!=1){
                FILE* fptr;
                fptr = fopen("username.txt", "a+");
                fprintf(fptr,"%s\n",username);
                printf("\nSign in now\n");
                fclose(fptr);
                fptr = fopen("password.txt", "a+");
                fprintf(fptr,"%s\n",password1);
                fclose(fptr);
            }
            else{
                printf("\nUser already exists or password does not match, Try again.\n");
            }
        }
        else if(choice==2){
            char username[50];
            char password1[50];
            //Asks for username and password.
            printf("Enter username(without space) : ");
            scanf("%s",username);
            printf("Enter Password : ");
            scanf("%s",password1);
            //Pushes the input in the history stack that can be later seen by others to 
            //check who has previously loginned.
            history = push(history,username);
            //if the username is admin and the password is #pas123 , the user is loginned as admin.
            if(strcmp(username,"admin")==0 && strcmp(password1,"#pas123")==0){
                //Loop goes on until the user selects Log Out.
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
                    //To insert a station in Orange Line.
                    if(choice3==1){
                        printLL(OrangeHead);
                        printf("\n\nEnter Name of the Station you want to insert : ");
                        char station[50];
                        char c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        fgets(station,sizeof(station),stdin);
                        OrangeHead = add(OrangeHead,station);
                        printLL(OrangeHead);
                    }    
                    //To insert a station in Aqua Line.
                    else if(choice3==2){
                        printLL(AquaHead);
                        printf("\n\nEnter Name of the Station you want to insert : ");
                        char station[50];
                        char c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        fgets(station,sizeof(station),stdin);
                        AquaHead = add(AquaHead,station);
                        printLL(AquaHead);
                    }            
                    //To check the list of users that have signned up.
                    else if(choice3==3){
                        char ch;
                        FILE* fptr1;
                        printf("\n");
                        fptr1 = fopen("username.txt","r");
                        int i = 0;
                        printf("List of Members : \n\n");
                        //Just prints all the usernames in the username database.
                        while ((ch = fgetc(fptr1)) != EOF) {
                            printf("%c",ch);
                        }
                        fclose(fptr1);
                    }
                    //To send message to all the users globally.
                    else if(choice3==4){
                        char str[500]; 
                        printf("\nEnter message : ");
                        char c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        fgets(str,sizeof(str),stdin);
                        //just inserts it into notifs and the prints when asked.
                        notifs = insertatbeg(str,notifs);
                        printf("message sent succesfully.");
                    }
                    //To delete all the notifications or delete a single notifications.
                    //If single then dequeue, else delete the whole queue.
                    else if(choice3==5){
                        printf("\nWould you like to delete all the notifs(Y) or one notif(N)?(Y/N) : ");
                        char h;
                        char c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        scanf("%c",&h);
                        if(h=='N'){
                            if(notifs!=NULL){
                                notifs = delfromend(notifs);
                            }
                            printf("\nLast message deleted succesfully.");
                        }
                        else{
                            while(notifs!=NULL){
                                notifs = delfromend(notifs);
                            }
                            printf("\nAll messages deleted succesfully.");
                        }
                    }
                    //To log out , we just break out of the while loop.
                    else if(choice3==6){
                        break;
                    }
                    else{
                        printf("\nEnter values from 1-6.");
                    }
                }
                continue;
            }
            int exist = 1;
            char ch;
            char ch1;
            FILE* fptr1;
            FILE* fptr2;
            printf("\n");
            fptr1 = fopen("username.txt","r");
            fptr2 = fopen("password.txt","r");
            int i1 = 0;
            char username1[100];
            while(true){
                int exist1 = 0;
                int exist2 = 0;
                //in every while loop, it just analyzes a single line of the txt file 
                //if the corresponding passowrd of the same line and username both are same
                //with the inputted username and password , it logins successfully.
                while ((ch = fgetc(fptr1)) != EOF) {
                    if (ch == '\n') {
                        username1[i1] = '\0';
                        if(strcmp(username1,username)==0){
                            i1 = 0;
                            exist1 = 1;
                            break;
                        }
                        i1 = 0;
                        break;
                    }
                    username1[i1] = ch;
                    i1 += 1;
                }
                while ((ch1 = fgetc(fptr2)) != EOF) {
                    if (ch1 == '\n') {
                        username1[i1] = '\0';
                        if(strcmp(username1,password1)==0){
                            i1 = 0;
                            exist2 = 1;
                            break;
                        }
                        memset(username1, 0, sizeof(username1));
                        i1 = 0;
                        break;
                    }
                    username1[i1] = ch1;
                    i1 += 1;
                }
                if(exist1 && !exist2){
                    break;
                }
                if(exist1 && exist2){
                    //password and username both are same.
                    exist = 0;
                    break;
                }
                if(ch==EOF && ch1==EOF){
                    break;
                }
            }
            fclose(fptr1);
            fclose(fptr2);
            //initialising booking to null in every login 
            struct queue* bookings = (struct queue*)malloc(sizeof(struct queue));
            bookings = NULL;
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
                    printf("\n5. Veiw last Bookings.");
                    printf("\n6. Hide ID from history");
                    printf("\n7. Log out");
                    printf("\n\nEnter choice : ");
                    scanf("%d",&choice1);
                    if(choice1==1){
                        int startpoint;
                        print(locations);
                        printf("\n\nEnter Start Point : ");
                        scanf("%d",&startpoint);
                        int endpoint;
                        printf("\nEnter End Point : ");        
                        scanf("%d",&endpoint);
                        //checks if the given start and end points are possible or not 
                        if(startpoint<=10 && endpoint>0 && startpoint>0 && endpoint<=10){
                            //calcuates the distance between them 
                            int f = dijkstra(arr,startpoint-1,endpoint-1);
                            printf("\nThe Distance form %s to %s is %dkms.",locations[startpoint],locations[endpoint],f);
                            printf("\nThe price is : %d",20*f);
                            char c;
                            char choice;
                            printf("\n\nWould you like to book the ticket (Y/N): ");
                            while ((c = getchar()) != '\n' && c != EOF);
                            scanf("%c",&choice);
                            //adds it to the bookings queue.
                            if(choice=='Y'){
                                printf("\nBooked Successfully.");
                                //the 2nd parameter being 1 means that mode is cab.
                                bookings = bookingo(bookings,1,startpoint-1,endpoint-1);
                            }
                            else if(choice=='N'){
                                printf("\nTicket cancelled Successfully.");
                            }
                            else{
                                printf("\nInvalid choice entered.");
                            }
                        }
                        else{
                            printf("\nInvalid start or end points.");
                        }
                        printf("\n");
                    }
                    else if(choice1==2){
                        int startpoint;
                        print(locations);
                        printf("\n\nEnter Start Point : ");
                        scanf("%d",&startpoint);
                        int endpoint;
                        printf("\nEnter End Point : ");        
                        scanf("%d",&endpoint);
                        //checks if the given start and end points are possible or not 
                        if(startpoint<=10 && endpoint>0 && startpoint>0 && endpoint<=10){
                            //calcuates the distance between them 
                            int f = dijkstra(arr,startpoint-1,endpoint-1);
                            printf("\nThe Distance form %s to %s is %dkms.",locations[startpoint],locations[endpoint],f);
                            printf("\nThe price is : %d",3*f);
                            char choice;
                            printf("\n\nWould you like to book the ticket (Y/N): ");
                            char c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            scanf("%c",&choice);
                            //adds it to the bookings queue.
                            if(choice=='Y'){
                                printf("\nBooked Successfully.");
                                //the 2nd parameter being 2 means that mode is bus.
                                bookings = bookingo(bookings,2,startpoint-1,endpoint-1);
                            }
                            else if(choice=='N'){
                                printf("\nTicket cancelled Successfully.");
                            }
                            else{
                                printf("\nInvalid choice entered.");
                            }
                        }
                        else{
                            printf("\nInvalid start or end points.");
                        }
                        printf("\n");
                    }
                    else if(choice1==3){
                        //Asks whether you are starting from aqua line or orange line.
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
                            if(line1st>count1(AquaHead) || line1st<=0){
                                printf("\nInvalid Input entered.");
                                continue;
                            }
                        }
                        else{
                            printLL(OrangeHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line2st);
                            if(line2st>count1(OrangeHead) || line2st<=0){
                                printf("\nInvalid Input entered.");
                                continue;
                            }
                        }
                        //checks whether the input is invalid
                        //If invalid, then it ends here.
                        printf("\nEnd Point : ");
                        //Asks for the end point.
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
                            if(line1ed>count1(AquaHead)||line1ed<=0){
                                printf("\nInvalid Input entered.");
                                continue;
                            }
                        }
                        else{
                            printLL(OrangeHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line2ed);
                            if(line2ed>count1(OrangeHead)||line2ed<=0){
                                printf("\nInvalid Input entered");
                                continue;
                            }
                        }
                        char choice;
                        //Here onwards, checks the number of station needed to be travelled(going through sitabuldi)
                        //The cost is number of stations multiplied by 5.
                        //Asks for a confirmation to book the ticket.
                        //Adds the booking to the booking queue.
                        //Which can be printed later.
                        if(line1ed!=-1 && line1st!=-1){
                            printf("\nThe cost is : %d",5*(abs(line1ed-line1st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line1ed-line1st)));
                            printf("\n\nWould you like to book the ticket (Y/N): ");
                            char c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            scanf("%c",&choice);
                            if(choice=='Y'){
                                printf("\nBooked Successfully.");
                            }
                            else if(choice=='N'){
                                printf("\nTicket cancelled Successfully.");
                            }
                            else{
                                printf("\nInvalid choice entered.");
                            }
                        }
                        else if(line2ed!=-1 && line2st!=-1){
                            printf("\nThe cost is : %d",5*(abs(line2ed-line2st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line2ed-line2st)));
                            printf("\n\nWould you like to book the ticket (Y/N): ");
                            char c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            scanf("%c",&choice);
                            if(choice=='Y'){
                                printf("\nBooked Successfully.");
                            }
                            else if(choice=='N'){
                                printf("\nTicket cancelled Successfully.");
                            }
                            else{
                                printf("\nInvalid choice entered.");
                            }
                        }
                        else if(line2st==-1 && line1ed==-1){
                            printf("\nThe cost is : %d",5*(abs(line2ed-8)+abs(10-line1st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line2ed-8)+abs(10-line1st)));
                            printf("\n\nWould you like to book the ticket (Y/N): ");
                            char c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            scanf("%c",&choice);
                            if(choice=='Y'){
                                printf("\nBooked Successfully.");
                            }
                            else if(choice=='N'){
                                printf("\nTicket cancelled Successfully.");
                            }
                            else{
                                printf("\nInvalid choice entered.");
                            }
                        }
                        else if(line2st!=-1 && line1ed!=-1){
                            printf("\nThe cost is : %d",5*(abs(line1ed-10)+abs(8-line2st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line1ed-10)+abs(8-line2st)));
                            printf("\n\nWould you like to book the ticket (Y/N): ");
                            char c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            scanf("%c",&choice);
                            if(choice=='Y'){
                                printf("\nBooked Successfully.");
                            }
                            else if(choice=='N'){
                                printf("\nTicket cancelled Successfully.");
                            }
                            else{
                                printf("\nInvalid choice entered.");
                            }
                        }
                        if(choice=='Y'){
                            bookings = booking(AquaHead,OrangeHead,bookings,line1st,line1ed,line2st,line2ed);
                        }
                        printf("\n");
                    }
                    //krna hain
                    else if(choice1==4){
                        int startpoint;
                        print(locations);
                        printf("\n\nEnter Start Point : ");
                        scanf("%d",&startpoint);
                        int endpoint;
                        printf("\nEnter End Point : ");        
                        scanf("%d",&endpoint);
                        //you dijikistras algo to check distance between two places.
                        if(startpoint<=10 && endpoint>0 && startpoint>0 && endpoint<=10){
                            int f = dijkstra(arr,startpoint-1,endpoint-1);
                            printf("\nThe Distance form %s to %s is %dkms.",locations[startpoint-1],locations[endpoint-1],f);
                        }
                        else{
                            printf("\nInvalid start or end points.");
                        }
                        printf("\n");
                    }
                    //Just prints the list of previous bookings.
                    else if(choice1==5){
                        printf("\n");
                        printq(bookings);
                    }
                    //Makes the ID Private
                    //That is removes it from the history os users stack.
                    else if(choice1==6 && flag==1){
                        flag = 0;
                        history = pop(history);
                        printf("\nRemoved your ID from history successfully.\n");
                    }
                    //If the ID is already removed then prints that 
                    //it is already removed.
                    else if(choice1==6 && flag==0){
                        printf("\nYour username has already been removed.\n");
                    }
                    //Logs out.
                    else if(choice1==7){
                        break;
                    }
                    else{
                        printf("\nPlease enter from 1 to 7\n");
                    }
                }
            }
            else{
                printf("\nWrong Username or Password please enter again.");
            }
            printf("\n");
        }
        //Prints the list of messages sent by the admin.
        else if(choice==3){
            printq(notifs);
        }
        //Prints the history of users who have previosuly loginned.
        else if(choice==4){
            printS(history);
        }
        //Exits the program.
        else if(choice==5){
            printf("Thank You\n");
            break;
        }
        else{
            printf("Enter Choice from 1-5\n");
        }
    }
}